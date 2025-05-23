package DMAController.Bfm

import DMAController.Bus._
import chisel3.Bits

import scala.collection.mutable.ListBuffer

/**
  * Bus functional model for AXI Lite master
  *
  * Instantiation:
  *   provide connection to axi interface (`axi`) and utilities from Chisel
  *   PeekPoke tester
  *
  * Usage (read):
  *   call `readPush` with the desired address, then poll `getResponse`
  *   until you get the response with the data. Multiple commands can
  *   be "chained" one after another, just by calling `readPush` multiple
  *   times.
  *
  * Usage (write):
  *   call `writePush` with the desired address and data, then poll
  *   `getREsponse` until you get the response (with status code). As
  *   with reads commands, miltiple commands can be "chained" together
  *   just by callin `writePush` multiple times.
  *
  * Note:
  *   if both read and write commands are in the queue one after another,
  *   both actions will be performed in parallel.
  */
class AxiLiteMasterBfm(val axi: AXI4Lite,
                       val peek: Bits => BigInt,
                       val poke: (Bits, BigInt) => Unit,
                       val println: String => Unit)
    extends AxiLiteBfm {

  //==========================================================================
  // read interface
  class ReadIf {
    private var currCmd: Cmd = new Cmd(false, 0, 0)

    private object State extends Enumeration {
      type State = Value
      val Idle, ReadAddr, ReadData = Value
    }
    private var state = State.Idle

    private var ar_ready: BigInt = 0
    private var ar_valid: BigInt = 0
    private var r_data: BigInt = 0
    private var r_resp: BigInt = 0
    private var r_ready: BigInt = 0
    private var r_valid: BigInt = 0

    private def peekInputs(): Unit = {
      ar_ready = peek(axi.ar.arready)
      ar_valid = peek(axi.ar.arvalid)
      r_data = peek(axi.r.rdata)
      r_resp = peek(axi.r.rresp)
      r_ready = peek(axi.r.rready)
      r_valid = peek(axi.r.rvalid)
    }

    private def printWithBg(s: String): Unit = {
      // black on cyan
      println("\u001b[30;46m" + s + "\u001b[39;49m")
    }

    def update(t: Long): Unit = {
      state match {
        case State.Idle => {
          if (cmdList.nonEmpty && cmdList(0).is_read) {
            currCmd = cmdList.remove(0)
            printWithBg(f"${t}%5d AxiLiteMasterBfm: read: leaving idle")
            state = State.ReadAddr
          }
        }
        case State.ReadAddr => {
          poke(axi.ar.arvalid, 1)
          poke(axi.ar.araddr, currCmd.addr)
          if (ar_ready != 0 && ar_valid != 0) {
            poke(axi.ar.arvalid, 0)
            state = State.ReadData
          }
        }
        case State.ReadData => {
          poke(axi.r.rready, 1)
          if (r_ready != 0 && r_valid != 0) {
            poke(axi.r.rready, 0)
            printWithBg(f"${t}%5d AxiLiteMasterBfm: read: from addr 0x${currCmd.addr}%x data 0x${r_data}%08x")
            respList += new Resp(r_resp == 0, r_data)
            state = State.Idle
          }
        }
      }

      peekInputs()
    }
  }

  //==========================================================================
  // write interface
  class WriteIf {
    private var currCmd: Cmd = new Cmd(false, 0, 0)

    private object State extends Enumeration {
      type State = Value
      val Idle, WriteAddr, WriteData, WriteWaitResp = Value
    }
    private var state = State.Idle

    private var aw_ready: BigInt = 0
    private var aw_valid: BigInt = 0
    private var w_ready: BigInt = 0
    private var w_valid: BigInt = 0
    private var b_resp: BigInt = 0
    private var b_valid: BigInt = 0
    private var b_ready: BigInt = 0

    private def peekInputs(): Unit = {
      aw_ready = peek(axi.aw.awready)
      aw_valid = peek(axi.aw.awvalid)
      w_ready = peek(axi.w.wready)
      w_valid = peek(axi.w.wvalid)
      b_resp = peek(axi.b.bresp)
      b_ready = peek(axi.b.bready)
      b_valid = peek(axi.b.bvalid)
    }

    private def printWithBg(s: String): Unit = {
      println("\u001b[30;45m" + s + "\u001b[39;49m")
    }

    def update(t: Long): Unit = {
      state match {
        case State.Idle => {
          if (cmdList.nonEmpty && !cmdList(0).is_read) {
            currCmd = cmdList.remove(0)
            printWithBg(f"${t}%5d AxiLiteMasterBfm: write: leaving idle")
            state = State.WriteAddr
          }
        }
        case State.WriteAddr => {
          poke(axi.aw.awvalid, 1)
          poke(axi.aw.awaddr, currCmd.addr)
          if (aw_ready != 0 && aw_valid != 0) {
            poke(axi.aw.awvalid, 0)
            state = State.WriteData
          }
        }
        case State.WriteData => {
          poke(axi.w.wvalid, 1)
          poke(axi.w.wdata, currCmd.wr_data)
          if (w_ready != 0 && w_valid != 0) {
            poke(axi.w.wvalid, 0)
            state = State.WriteWaitResp
          }
        }
        case State.WriteWaitResp => {
          poke(axi.b.bready, 1)
          if (b_ready != 0 && b_valid != 0) {
            val resp_str = if (b_resp == 0) { "OK" } else { "ERR" }
            printWithBg(f"${t}%5d AxiLiteMasterBfm: write: to addr 0x${currCmd.addr}%x resp ${resp_str}")
            poke(axi.b.bready, 0)
            respList += new Resp(b_resp == 0, 0)
            state = State.Idle
          }
        }
      }

      peekInputs()
    }
  }


  class Cmd(val is_read: Boolean, val addr: BigInt, val wr_data: BigInt)
  class Resp(val success: Boolean, val rd_data: BigInt)
  private var cmdList: ListBuffer[Cmd] = new ListBuffer()
  private var respList: ListBuffer[Resp] = new ListBuffer()


  private val read_if = new ReadIf()
  private val write_if = new WriteIf()


  def getResponse(): Option[Resp] = {
    if (respList.isEmpty) {
      None
    } else {
      Some(respList.remove(0))
    }
  }


  def readPush(addr: BigInt): Unit = {
    cmdList += new Cmd(true, addr, 0)
  }

  /** push new write command into the command queue */
  def writePush(addr: BigInt, data: BigInt): Unit = {
    cmdList += new Cmd(false, addr, data)
  }

  /** part of ChiselBFM, should be called every clock cycle */
  def update(t: Long): Unit = {
    read_if.update(t)
    write_if.update(t)
  }
}
