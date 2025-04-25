package DMAController

import DMAController.Bfm.ChiselBfm
import DMAController.Worker.{InterruptBundle, SyncBundle}
import chiseltest.iotesters.PeekPokeTester
import chisel3.Bits
import DMAController.DMAConfig._

class ImageTransfer(dut: DMATop, dmamem22slave: DMAMem22Slave, dmaConfig: DMAConfig) extends PeekPokeTester(dut){
  val width = 256
  val height = 256
  val min = 0
  val max = width * height * 2
  var cnt: Int = 0

  def waitRange(data: Bits, exp: Int, min: Int, max: Int) : Unit = {
    var cnt = 0

    while(peek(data) != exp && cnt < max){
      step(1)
      cnt += 1
    }

    assert(cnt < max)
    assert(cnt >= min)
  }

  val reader = dmamem22slave.readMem
  val writerDevie1 = dmamem22slave.writeSlave1
  val writerDevie2 = dmamem22slave.writeSlave2
  val control = dmamem22slave.control

  def stepSingle(): Unit = {
    reader.update(cnt)
    writerDevie1.update(cnt)
    writerDevie2.update(cnt)    
    control.update(cnt)
    super.step(1)
  }

  override def step(n: Int): Unit = {
    for(_ <- 0 until n) {
      stepSingle()
    }
  }

  reader.loadFromFile("./img0.rgba")
  writerDevie1.loadFromFile("./img1.rgba")
  writerDevie2.loadFromFile("./img2.rgba")

  control.writePush(Register.ReaderStartAddr, 0)
  control.writePush(Register.ReaderLineLen, width)
  control.writePush(Register.ReaderLineCnt, height)
  control.writePush(Register.ReaderStride, 0)

  control.writePush(Register.WriterStartAddr, height * width * 4 + width * 2)
  control.writePush(Register.WriterLineLen, width)
  control.writePush(Register.WriterLineCnt, height)
  control.writePush(Register.WriterStride, width)

  step(100)

  control.writePush(Register.InterruptMask, 3)

  control.writePush(Register.Ctrl, 0xf)

  waitRange(dut.io.irq.writerDone, 1, min, max)

  expect(dut.io.irq.writerDone, 1)
  expect(dut.io.irq.readerDone, 1)

  writerDevie1.saveToFile(f"./outDevice1${dmaConfig.busConfig}.rgba")
  writerDevie2.saveToFile(f"./outDevice2${dmaConfig.busConfig}.rgba")
}
