package DMAController.Worker

import chisel3._

class InterruptBundle extends Bundle{
  val readerDone = Output(Bool())
  val writerDone = Output(Bool())
}
