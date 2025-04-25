package DMAController.Bfm

import DMAController.Bus._

trait AxiLiteBfm extends ControlBfm {
  val axi: AXI4Lite
}
