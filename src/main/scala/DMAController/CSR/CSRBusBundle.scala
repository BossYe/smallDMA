package DMAController.CSR

import chisel3._
import chisel3.util.log2Ceil

class CSRBusBundle(controlRegCount: Int, controlDataWidth: Int) extends Bundle {
  val addr = Output(UInt(log2Ceil(controlRegCount).W))
  val dataOut = Output(UInt(controlDataWidth.W))
  val dataIn = Input(UInt(controlDataWidth.W))
  val write = Output(Bool())
  val read = Output(Bool())
}
