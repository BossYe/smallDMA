package DMAController

import DMAController.Bfm.{ControlBfm, IOBfm}
import DMAController.Worker.{InterruptBundle, SyncBundle}
import chiseltest.iotesters.PeekPokeTester

abstract class DMAFull(dut: DMATop) extends PeekPokeTester(dut){
  val control: ControlBfm
  val readMem: IOBfm
  val writeSlave1: IOBfm
  val writeSlave2: IOBfm
}
