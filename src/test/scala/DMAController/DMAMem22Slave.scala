package DMAController

import DMAController.Bfm.{AxiLiteMasterBfm, Axi4MemoryBfm}
import DMAController.Bus.{AXI4Lite, AXI4}
import DMAController.Worker.{InterruptBundle, SyncBundle}
import chisel3.{Bits, Bundle}

class DMAMem22Slave(dut: DMATop) extends DMAFull(dut) {
  val width = 256
  val height = 256
  val io = dut.io.asInstanceOf[Bundle{
                                val control: AXI4Lite
                                val readMem: AXI4
                                val writeSlave1: AXI4
                                val writeSlave2: AXI4
                                val irq: InterruptBundle
                                val sync: SyncBundle}]

  val control = new AxiLiteMasterBfm(io.control, peek[Bits], poke[Bits], println)
  val readMem = new Axi4MemoryBfm(io.readMem, width * height, peek[Bits], poke[Bits], println)
  val writeSlave1 = new Axi4MemoryBfm(io.writeSlave1, width * height, peek[Bits], poke[Bits], println)
  val writeSlave2 = new Axi4MemoryBfm(io.writeSlave2, width * height, peek[Bits], poke[Bits], println)
}
