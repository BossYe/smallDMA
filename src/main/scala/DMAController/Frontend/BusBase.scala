package DMAController.Frontend
import DMAController.Bus._
import DMAController.CSR.{CSR, CSRBusBundle}
import DMAController.Worker.{WorkerCSRWrapper, XferDescBundle}
import DMAUtils.DMAModule
import chisel3._
import chisel3.util._
import DMAController.DMADriver
import DMAController.DMAConfig._

abstract class IOBus[T <: Bundle](config: DMAConfig) extends DMAModule(config) {
  val io : Bundle {
    val bus : T
    val dataIO : DecoupledIO[UInt]
    val xfer : XferDescBundle
  }
}

abstract class CSRBus[T <: Bundle] (config: DMAConfig) extends DMAModule(config) {
  val io : Bundle {
    val bus : CSRBusBundle
    val ctl : T
  }
}

class Bus(config: DMAConfig) {
  import DMAConfig.{AXI, AXIL, AXIS}

  def getCSR(busType: Int) = busType match {
    case AXIL => new AXI4LiteCSR(config.addrWidth, config.controlDataWidth, config.controlRegCount, config)
  }

  def getReader(busType: Int) = busType match {
    case AXI => new AXI4Reader(config.addrWidth, config.readDataWidth, config)
    case AXIS => new AXIStreamSlave(config.addrWidth, config.readDataWidth, config)
  }

  def getWriter(busType: Int) = busType match {
    case AXI => new AXI4Writer(config.addrWidth, config.readDataWidth, config)
    case AXIS => new AXIStreamMaster(config.addrWidth, config.readDataWidth, config)
  }

  def getControlBus(busType: Int) = busType match {
    case AXIL => Flipped(new AXI4Lite(config.controlAddrWidth, config.controlDataWidth))
  }

  def getReaderBus(busType: Int) =  busType match {
    case AXI => new AXI4(config.addrWidth, config.readDataWidth)
    case AXIS => Flipped(new AXIStream(config.readDataWidth))
  }

  def getWriterBus(busType: Int) =  busType match {
    case AXI => new AXI4(config.addrWidth, config.readDataWidth)
    case AXIS => new AXIStream(config.readDataWidth)
  }
}
