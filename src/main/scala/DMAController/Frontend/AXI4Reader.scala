package DMAController.Frontend

import DMAController.Bus._
import DMAController.Worker.{XferDescBundle, WorkerCSRWrapper}
import DMAController.CSR.CSR
import chisel3._
import chisel3.util._
import DMAController.DMAConfig.DMAConfig

class AXI4Reader(val addrWidth: Int, val dataWidth: Int, dmaConfig: DMAConfig)
    extends IOBus[AXI4](dmaConfig) {
  val io = IO(new Bundle {
    val bus = new AXI4(addrWidth, dataWidth)

    val dataIO = EnqIO(UInt(dataWidth.W))

    val xfer = Flipped(new XferDescBundle(addrWidth))
  })

  val sIdle :: sAddr :: sTransfer :: sDone :: Nil = Enum(4)

  val state = RegInit(sIdle)

  val done = RegInit(false.B)
  val enable = RegInit(false.B)
  val last = RegInit(false.B)
  val araddr = RegInit(0.U(addrWidth.W))
  val arlen = RegInit(0.U(AXI4.lenWidth.W))
  val arvalid = RegInit(false.B)
  val arsize = WireInit(log2Ceil(dataWidth / 8).U)

  val ready = WireInit(io.dataIO.ready && enable)
  val valid = WireInit(io.bus.r.rvalid && enable)

  io.bus.aw <> AXI4AW.tieOff(addrWidth)
  io.bus.w <> AXI4W.tieOff(dataWidth)
  io.bus.b <> AXI4B.tieOff()
  io.bus.ar <> AXI4AR(araddr, arlen, arsize, arvalid)
  io.bus.r <> AXI4R(dataWidth, ready)

  io.dataIO.valid := valid
  io.dataIO.bits := io.bus.r.rdata
  io.xfer.done := done

  switch(state) {
    is(sIdle) {
      done := false.B
      when(io.xfer.valid) {
        state := sAddr
        arvalid := true.B
        araddr := io.xfer.address
        arlen := io.xfer.length - 1.U
      }
    }
    is(sAddr) {
      when(arvalid && io.bus.ar.arready) {
        state := sTransfer
        arvalid := false.B
        enable := true.B
      }
    }
    is(sTransfer) {
      when(ready && valid) {
        when(io.bus.r.rlast) {
          state := sDone
          enable := false.B
        }
      }
    }
    is(sDone) {
      done := true.B
      state := sIdle
    }
  }

}
