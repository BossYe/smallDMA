package DMAController.Worker

import chisel3._

class XferDescBundle(val addrWidth : Int) extends Bundle{
  val done = Input(Bool())
  val address = Output(UInt(addrWidth.W))
  val length = Output(UInt(addrWidth.W))
  val valid = Output(Bool())
  val first = Output(Bool())
}
