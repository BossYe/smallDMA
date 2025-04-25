package DMAController.TestUtil

import chisel3.iotesters._

object WaitRange {
  def waitRange(init: Int, max: Int, cond: () => Boolean): Boolean = {
    for(i <- init to max) {
      if (cond())
        return true
    }
    return false
  }
}
