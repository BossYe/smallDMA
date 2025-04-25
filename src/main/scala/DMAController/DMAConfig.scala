package DMAController.DMAConfig

import chisel3._
import DMAController.Bus._
import DMAController.CSR.CSR
import DMAController.Frontend._
import DMAController.Worker.{InterruptBundle, WorkerCSRWrapper, SyncBundle}
import chisel3.util.Queue

class DMAConfig(
    val busConfig: String = "AXI_AXIL_AXI",
    val addrWidth: Int = 32,
    val readDataWidth: Int = 32,
    val writeDataWidth: Int = 32,
    val readMaxBurst: Int = 0,
    val writeMaxBurst: Int = 16,
    val reader4KBarrier: Boolean = false,
    val writer4KBarrier: Boolean = true,
    val controlDataWidth: Int = 32,
    val controlAddrWidth: Int = 32,
    val controlRegCount: Int = 16,
    val fifoDepth: Int = 512
) {
  assert(DMAConfig.isValid(busConfig))
  assert(readDataWidth == writeDataWidth)

  def getBusConfig() = DMAConfig.getBusConfig(busConfig)
}

object DMAConfig {
  /* Supported buses */
  val AXI = 0
  val AXIL = 1
  val AXIS = 2
  val WB = 3
  val PWB = 4

  // DMA configuration options:
  private val configurations = Map(
// AXI4 <-> AXI4Lite <-> AXI4
    "AXI_AXIL_AXI" -> (AXI, AXIL, AXI),
// AXI4 <-> AXI4Lite <-> AXIStream
    "AXI_AXIL_AXIS" -> (AXI, AXIL, AXIS),
// AXIStream <-> AXI4Lite <-> AXIStream
    "AXIS_AXIL_AXIS" -> (AXIS, AXIL, AXIS),
  )

  def getBusConfig(cfg: String): (Int, Int, Int) = {
    try {
      configurations.apply(cfg)
    } catch {
      case ex: Exception =>
        throw new Exception("Unsupported DMA configuration: " + cfg)
    }
  }

  def isValid(config: String): Boolean = {
    configurations.contains(config)
  }
}

object Register {
  val Ctrl = 0x00
  val Status = 0x04
  val InterruptMask = 0x08
  val InterruptStatus = 0x0c
  val ReaderStartAddr = 0x10
  val ReaderLineLen = 0x14
  val ReaderLineCnt = 0x18
  val ReaderStride = 0x1c
  val WriterStartAddr = 0x20
  val WriterLineLen = 0x24
  val WriterLineCnt = 0x28
  val WriterStride = 0x2c
  val Version = 0x30
  val Configuration = 0x34
}
