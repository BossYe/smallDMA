package DMAController.Bfm

import DMAController.Bus._
import chisel3.Bits

import java.nio._

import scala.collection.mutable.ListBuffer

class AxiStreamMasterBfm(val axi: AXIStream,
                        val packetLen: Int,
                        val peek: Bits => BigInt,
                        val poke: (Bits, BigInt) => Unit,
                        val println: String => Unit) 
extends AxiStreamBfm {

  private var txList: ListBuffer[Int] = new ListBuffer()

  private object State extends Enumeration {
    type State = Value
    val Idle, WriteData= Value
  }

  private var state = State.Idle

  private var wordCnt: Int = 0

  private var tready: BigInt = 0

  def loadFromFile(filename: String): Unit = {
    val path = file.Paths.get(filename)
    val buffer = file.Files.readAllBytes(path)
    val bb = ByteBuffer.wrap(buffer)
    //bb.order(ByteOrder.nativeOrder)
    var buf = new Array[Int](buffer.length/4)
    bb.asIntBuffer.get(buf)
    for(i <- 0 until buf.length) {
      txList += buf(i)
    }
    println("AXI Stream BFM, file %s, %d words".format(filename, buf.length))
  }

  def saveToFile(filename: String): Unit = {
  }

  private def peekInputs(): Unit = {
    tready = peek(axi.tready)
  }

  private def putData(): Unit = {
    poke(axi.tdata, txList.remove(0))
  }

  private def updateTlast(): Unit = {
    if(wordCnt == packetLen - 1) {
      poke(axi.tlast, 1)
    } else {
      poke(axi.tlast, 0)
    }
  }

  def update(t: Long): Unit = {
    state match {
      case State.Idle => {
        if(txList.nonEmpty) {
          poke(axi.tvalid, 1)
          state = State.WriteData
          putData()
          updateTlast()
        }
      }
      case State.WriteData => {
        if(tready != 0) {
          if(txList.nonEmpty) {
            putData()
            updateTlast()
            if(wordCnt == packetLen) {
              wordCnt = 0
            } else {
              wordCnt += 1
            }
          } else {
            poke(axi.tvalid, 0)
            state = State.Idle
          }
        }
      }
    }
    peekInputs()
  }
}
