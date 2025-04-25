package DMAController.CSR

import chisel3._

class CSRRegBundle(controlDataWidth: Int) extends Bundle {
  val dataRead = Output(Bool())
  val dataOut = Output(UInt(controlDataWidth.W))
  val dataWrite = Output(Bool())
  val dataIn = Input(UInt(controlDataWidth.W))
}
