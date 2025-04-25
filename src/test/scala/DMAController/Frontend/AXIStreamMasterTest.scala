package DMAController.Frontend

import chiseltest.iotesters.PeekPokeTester
import DMAController.TestUtil.WaitRange._

class AXIStreamMasterTest(dut : AXIStreamMaster) extends PeekPokeTester(dut){
  val maxStep = 500
  val data = 0x12345678

  poke(dut.io.bus.tready, 1)
  poke(dut.io.dataIO.valid, 1)
  poke(dut.io.dataIO.bits, data)
  poke(dut.io.xfer.length, 300)
  poke(dut.io.xfer.valid, 0)

  step(10)

  poke(dut.io.xfer.valid, 1)

  step(1)

  poke(dut.io.xfer.valid, 0)

  assert(waitRange(0, maxStep, {() =>
    step(1)
    peek(dut.io.xfer.done) == 1
  }))
  assert(peek(dut.io.bus.tdata) == data)
}
