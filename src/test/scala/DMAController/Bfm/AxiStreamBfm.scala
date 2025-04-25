package DMAController.Bfm

import DMAController.Bus._

trait AxiStreamBfm extends IOBfm {
  val axi: AXIStream
}
