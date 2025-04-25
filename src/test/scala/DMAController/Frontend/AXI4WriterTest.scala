package DMAController.Frontend

import chiseltest.iotesters.PeekPokeTester
import DMAController.TestUtil.WaitRange._

class AXI4WriterTest(dut: AXI4Writer) extends PeekPokeTester(dut){
  val maxStep = 100
  val data = 0x55aa1234
  val transferLength = 4
  var beatCount = 0

  poke(dut.io.bus.aw.awready, 0)
  poke(dut.io.bus.w.wready, 0)
  poke(dut.io.bus.b.bvalid, 0)

  poke(dut.io.dataIO.valid, 0)
  poke(dut.io.dataIO.bits, data)

  poke(dut.io.xfer.address, 0x80000000)
  poke(dut.io.xfer.length, transferLength)
  poke(dut.io.xfer.valid, 0)

  step(5)

  poke(dut.io.xfer.valid, 1)

  step(1)

  poke(dut.io.xfer.valid, 0)

  step(1)

  poke(dut.io.bus.aw.awready, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.bus.aw.awvalid) == 1
    step(1)
    cond
  }))

  step(1)

  poke(dut.io.bus.aw.awready, 0)

  step(1)

  poke(dut.io.dataIO.valid, 1)
  poke(dut.io.bus.w.wready, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.bus.w.wlast) == 1
    if(peek(dut.io.bus.w.wvalid) == 1){
      beatCount = beatCount + 1
    }
    step(1)
    cond
  }))

  beatCount = beatCount + 1
  poke(dut.io.dataIO.valid, 0)
  poke(dut.io.bus.w.wready, 0)

  step(1)

  poke(dut.io.bus.b.bvalid, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.bus.b.bready) == 1
    step(1)
    cond
  }))

  step(1)
  poke(dut.io.bus.b.bvalid, 0)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.xfer.done) == 1
    step(1)
    cond
  }))
  assert(peek(dut.io.bus.w.wdata) == data)
}
