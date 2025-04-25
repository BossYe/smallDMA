package DMAController.Worker

import chisel3._

class AddressGeneratorCtlBundle(val addrWidth : Int) extends Bundle{
  val start = Input(Bool())
  val busy = Output(Bool())
  val startAddress = Input(UInt(addrWidth.W))
  val lineLength = Input(UInt(addrWidth.W))
  val lineCount = Input(UInt(addrWidth.W))
  val lineGap = Input(UInt(addrWidth.W))
}
