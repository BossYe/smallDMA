package DMAController.Worker

import DMAController.CSR.{CSRRegBundle, SetCSR, SimpleCSR}
import chisel3._
import chisel3.util.Cat
import DMAUtils.DMAModule
import DMAController.DMADriver
import DMAController.DMAConfig._

class InterruptController(dmaConfig: DMAConfig) extends DMAModule(dmaConfig) {
  val io = IO(new Bundle {
    val irq = new InterruptBundle
    val readBusy = Input(Bool())
    val writeBusy = Input(Bool())
    val imr = Flipped(new CSRRegBundle(dmaConfig.controlDataWidth))
    val isr = Flipped(new CSRRegBundle(dmaConfig.controlDataWidth))
  })

  val mask = WireInit(SimpleCSR(io.imr, dmaConfig))

  val readBusy = RegNext(io.readBusy)
  val readBusyOld = RegNext(readBusy)

  val writeBusy = RegNext(io.writeBusy)
  val writeBusyOld = RegNext(writeBusy)

  val writeBusyIrq = RegInit(false.B)
  val readBusyIrq = RegInit(false.B)

  writeBusyIrq := writeBusyOld && !writeBusy && mask(0)
  readBusyIrq := readBusyOld && !readBusy && mask(1)

  val irq = WireInit(Cat(readBusyIrq, writeBusyIrq))

  val isr = WireInit(SetCSR(irq, io.isr, dmaConfig))

  io.irq.writerDone := isr(0)
  io.irq.readerDone := isr(1)
}

object InterruptController {
  def apply(readBusy: Bool, writeBusy: Bool, imr: CSRRegBundle, isr: CSRRegBundle,
            dmaConfig: DMAConfig): InterruptBundle = {
    val irqc = Module(new InterruptController(dmaConfig))

    irqc.io.readBusy := readBusy
    irqc.io.writeBusy := writeBusy

    irqc.io.imr <> imr
    irqc.io.isr <> isr

    irqc.io.irq
  }
}
