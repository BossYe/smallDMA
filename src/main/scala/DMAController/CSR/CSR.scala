package DMAController.CSR

import chisel3._
import DMAUtils.DMAModule
import DMAController.DMAConfig._

class CSR(dmaConfig: DMAConfig) extends DMAModule(dmaConfig) {
  val io = IO(new Bundle {
    val csr = Vec(dmaConfig.controlRegCount, new CSRRegBundle(dmaConfig.controlDataWidth))
    val bus = Flipped(new CSRBusBundle(dmaConfig.controlRegCount, dmaConfig.controlDataWidth))
  })

  val data = WireInit(0.U(dmaConfig.controlDataWidth.W))

  io.bus.dataIn := data

  for (i <- 0 until dmaConfig.controlRegCount) {
    when(io.bus.addr === i.U && io.bus.read){
      data := io.csr(i).dataIn
      io.csr(i).dataRead := true.B
    }.otherwise {
      io.csr(i).dataRead := false.B
    }

    when(io.bus.addr === i.U && io.bus.write) {
      io.csr(i).dataOut := io.bus.dataOut
      io.csr(i).dataWrite := true.B
    }.otherwise {
      io.csr(i).dataWrite := false.B
      io.csr(i).dataOut := 0.U
    }
  }
}
