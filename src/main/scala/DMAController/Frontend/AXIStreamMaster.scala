package DMAController.Frontend

import DMAController.Bus.AXIStream
import DMAController.Worker.{XferDescBundle, WorkerCSRWrapper}
import DMAController.CSR.CSR
import chisel3._
import chisel3.util._
import DMAController.DMAConfig._

class AXIStreamMaster(val addrWidth: Int, val dataWidth: Int, dmaConfig: DMAConfig)
    extends IOBus[AXIStream](dmaConfig) {
  val io = IO(new Bundle {
    val bus = new AXIStream(dataWidth)

    val dataIO = DeqIO(UInt(dataWidth.W))

    val xfer = Flipped(new XferDescBundle(addrWidth))
  })

  val sIdle :: sTransfer :: sDone :: Nil = Enum(3)

  val state = RegInit(sIdle)

  val done = RegInit(false.B)

  val enable = RegInit(false.B)
  val last = WireInit(false.B)
  val user = RegInit(false.B)

  val length = RegInit(0.U(addrWidth.W))

  val ready = WireInit(io.bus.tready && enable)
  val valid = WireInit(io.dataIO.valid && enable)

  io.bus.tvalid := valid
  io.dataIO.ready := ready

  io.bus.tdata := io.dataIO.bits
  io.bus.tlast := last
  io.bus.tuser := user

  io.xfer.done := done

  last := length === 1.U

  switch(state) {
    is(sIdle) {
      done := false.B
      enable := false.B

      when(io.xfer.valid) {
        user := io.xfer.first
        state := sTransfer
        length := io.xfer.length
        enable := true.B
      }
    }
    is(sTransfer) {
      when(ready && valid) {
        user := false.B
        length := length - 1.U
        when(length === 1.U) {
          state := sDone
          enable := false.B
        }
      }
    }
    is(sDone) {
      state := sIdle
      done := true.B
    }
  }

}
