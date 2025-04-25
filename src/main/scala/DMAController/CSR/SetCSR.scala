package DMAController.CSR

import chisel3._
import DMAUtils.DMAModule
import DMAController.DMADriver
import DMAController.DMAConfig._

class SetCSR(dmaConfig: DMAConfig) extends DMAModule(dmaConfig) {
  val io = IO(new Bundle {
    val csr = Flipped(new CSRRegBundle(dmaConfig.controlDataWidth))
    val value = Output(UInt(dmaConfig.controlDataWidth.W))
    val set = Input(UInt(dmaConfig.controlDataWidth.W))
  })

  val reg = RegInit(0.U(dmaConfig.controlDataWidth.W))

  io.csr.dataIn := reg
  io.value := reg

  when(io.csr.dataWrite) {
    reg := (reg & (~io.csr.dataOut).asUInt) | io.set
  }.otherwise {
    reg := reg | io.set
  }

}

object SetCSR {
  def apply(set: UInt, csrCtl: CSRRegBundle, dmaConfig: DMAConfig): UInt = {
    val csr = Module(new SetCSR(dmaConfig))

    csr.io.set := set

    csr.io.csr <> csrCtl

    csr.io.value
  }
}
