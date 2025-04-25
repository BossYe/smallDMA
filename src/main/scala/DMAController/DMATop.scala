package DMAController

import chisel3._
import chisel3.util._
import DMAController.Bus._
import DMAController.CSR._
import DMAController.Frontend._
import DMAController.Worker.{InterruptBundle, WorkerCSRWrapper, SyncBundle}
import DMAController.DMAConfig._
import DMAUtils._

class DMATop(dmaConfig: DMAConfig) extends DMAModule(dmaConfig) {
  val (reader, ccsr, writer) = dmaConfig.getBusConfig()
  val Bus = new Bus(dmaConfig)

  val io = IO(new Bundle {
    val control = Bus.getControlBus(ccsr)
    val readMem = Bus.getReaderBus(reader)
    val writeSlave1 = Bus.getWriterBus(writer)
    val writeSlave2 = Bus.getWriterBus(writer)
    val irq = new InterruptBundle
    val sync = new SyncBundle
  })

  val csrFrontend = Module(Bus.getCSR(ccsr))

  val readerFrontend = Module(Bus.getReader(reader))

  val writerFrontend = Module(Bus.getWriter(writer))

  val csr = Module(new CSR(dmaConfig))

  val ctl = Module(new WorkerCSRWrapper(dmaConfig))

  val queue = DMAQueue(readerFrontend.io.dataIO, dmaConfig)
  queue <> writerFrontend.io.dataIO

  csrFrontend.io.ctl <> io.control
  csr.io.bus <> csrFrontend.io.bus
  ctl.io.csr <> csr.io.csr
  readerFrontend.io.xfer <> ctl.io.xferRead
  writerFrontend.io.xfer <> ctl.io.xferWrite

  io.readMem <> readerFrontend.io.bus
  
  io.writeSlave1 <> writerFrontend.io.bus
  io.writeSlave2 <> writerFrontend.io.bus

  io.irq <> ctl.io.irq
  io.sync <> ctl.io.sync

}