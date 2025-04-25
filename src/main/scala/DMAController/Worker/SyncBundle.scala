package DMAController.Worker

import chisel3._

class SyncBundle extends Bundle{
  val readerSync = Input(Bool())
  val writerSync = Input(Bool())
}
