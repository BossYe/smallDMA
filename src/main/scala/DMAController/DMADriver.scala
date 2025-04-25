package DMAController

import circt.stage.ChiselStage
import DMAConfig._
import DMAUtils.{DMAParseInput, DMALogger}
import DMAController.DMAConfig._

object DMADriver extends App {
  val config =
    if (args.length == 0) {
      DMALogger.warn("No custom configuration was specified.")
      DMALogger.info("Using default parameters and AXI_AXIL_AXI configuration.")
      new DMAConfig()
    } else {
      DMALogger.info("Applying custom configuration")
      DMAParseInput.parseconfig(args(0)) match {
        case Left(x) => x
        case _ => {
          DMALogger.error("Something went wrong when acquiring DMA Parameters")
          throw new Exception("Invalid configuration")
        }
      }
    }

  ChiselStage.emitSystemVerilogFile(new DMATop(config))
}
