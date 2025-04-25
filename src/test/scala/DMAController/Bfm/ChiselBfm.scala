package DMAController.Bfm

import chisel3.Bits

trait ChiselBfm {
  val peek: Bits => BigInt
  val poke: (Bits, BigInt) => Unit
  val println: String => Unit

  def update(t: Long): Unit
}

trait ControlBfm extends ChiselBfm {
  def readPush (addr: BigInt): Unit
  def writePush (addr: BigInt, data: BigInt): Unit
}

trait IOBfm extends ChiselBfm {
  def loadFromFile(filename: String): Unit
  def saveToFile(filename: String): Unit
}
