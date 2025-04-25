package DMAController

import chiseltest.ChiselScalatestTester
import org.scalatest.flatspec.AnyFlatSpec
import DMAController.DMAConfig._
import chiseltest._

class ControllerSpec extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "ControllerSpec"
  val dmaConfigM22Slave = new DMAConfig("AXI_AXIL_AXI")
  it should "perform 2D MM2MM transfer with stride 1 mem to 2 slaves" in {
    test(new DMATop(dmaConfigM22Slave))
      .withAnnotations(Seq(WriteVcdAnnotation,VerilatorBackendAnnotation))
      .runPeekPoke(dut =>
        new ImageTransfer(dut, new DMAMem22Slave(dut), dmaConfigM22Slave)
      )
  }
}
