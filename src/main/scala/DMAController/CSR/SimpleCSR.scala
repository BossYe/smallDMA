package DMAController.CSR

import chisel3._
import DMAUtils.DMAModule
import DMAController.DMADriver
import DMAController.DMAConfig._

class SimpleCSR(config: DMAConfig) extends DMAModule(config) {
  val io = IO(new Bundle {
    val csr = Flipped(new CSRRegBundle(config.controlDataWidth))
    val value = Output(UInt(config.controlDataWidth.W))
  })

  val reg = RegInit(0.U(config.controlDataWidth.W))

  io.csr.dataIn := reg
  io.value := reg

  when(io.csr.dataWrite) {
    reg := io.csr.dataOut
  }

}

object SimpleCSR {
  def apply(csrCtl: CSRRegBundle, config: DMAConfig): UInt = {
    val csr = Module(new SimpleCSR(config))

    csr.io.csr <> csrCtl

    csr.io.value
  }
}
