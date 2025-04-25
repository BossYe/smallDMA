package DMAController.CSR

import DMAUtils.DMAModule
import DMAController.DMADriver
import chisel3._
import DMAController.DMAConfig._

class StatusCSR(dmaConfig: DMAConfig) extends DMAModule(dmaConfig){
  val io = IO(new Bundle{
    val csr = Flipped(new CSRRegBundle(dmaConfig.controlDataWidth))
    val value = Input(UInt(dmaConfig.controlDataWidth.W))
  })

  val reg = RegNext(io.value)

  io.csr.dataIn := reg
}

object StatusCSR{
  def apply(status : UInt, csrCtl : CSRRegBundle, dmaConfig: DMAConfig): Unit = {
    val csr = Module(new StatusCSR(dmaConfig))

    csr.io.csr <> csrCtl

    csr.io.value := status
  }
}
