package DMAController.Frontend

import chiseltest.iotesters.PeekPokeTester
import DMAController.TestUtil.WaitRange._

class AXI4ReaderTest(dut: AXI4Reader) extends PeekPokeTester(dut){
  val maxStep = 100
  val data = 0x45671234
  val transferLen = 4
  var currentLen = 0

  poke(dut.io.xfer.valid, 0)
  poke(dut.io.xfer.address, 0x40000000)
  poke(dut.io.xfer.length, transferLen)

  poke(dut.io.dataIO.ready, 0)

  poke(dut.io.bus.ar.arready, 0)

  poke(dut.io.bus.r.rvalid, 0)
  poke(dut.io.bus.r.rdata, data)
  poke(dut.io.bus.r.rlast, 0)

  step(5)

  poke(dut.io.xfer.valid, 1)

  step(1)

  poke(dut.io.bus.ar.arready, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.bus.ar.arvalid) == 1
    step(1)
    cond
  }))

  poke(dut.io.bus.ar.arready, 0)

  step(1)

  poke(dut.io.dataIO.ready, 1)
  poke(dut.io.bus.r.rvalid, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = transferLen > (currentLen + 1)
    if(peek(dut.io.bus.r.rready) == 1){
      currentLen += 1
    }
    step(1)
    cond
  }))

  poke(dut.io.bus.r.rlast, 1)

  assert(waitRange(0, maxStep, {() =>
    val cond = peek(dut.io.bus.r.rready) == 1
    step(1)
    cond
  }))

  poke(dut.io.bus.r.rvalid, 0)
  poke(dut.io.bus.r.rlast, 0)

  assert(waitRange(0, maxStep, {() =>
    step(1)
    peek(dut.io.xfer.done) == 1
  }))

  assert(peek(dut.io.dataIO.bits) == data)
}
