# smallDMA

1. 项目内容：

   1个memory master向2个slaves传输数据（比如图片），通过基于AXI接口的DMA控制器来实现数据的搬运。

2. 项目实现：

   项目参考AXI DMA IP核的原理以及fastvdma library.

- [x] 代码可综合

- [x] 基础的数据传输功能(写死地址和长度)
- [ ] 高性能，fully-pipelined，无气泡
- [x] 可动态配置的DMA传输请求(动态给定地址和长度)
- [ ] 支持不同类型的burst传输
- [x] 支持不同的burst size
- [ ] 两个slave支持不同的位宽
- [x] 支持跨越4kB地址边界的传输请求(拆分为多个请求)
- [x] 可排队多个传输请求，依次执行

   1）AXI-Lite 传输所配置的控制寄存器内容

   ​	  控制寄存器包含14个

   | 寄存器名称      | 地址 |
   | --------------- | ---- |
   | Ctrl            | 0x00 |
   | Status          | 0x04 |
   | InterrputMask   | 0x08 |
   | InterruptStatus | 0x0c |
   | ReaderStartAddr | 0x10 |
   | ReaderLineLen   | 0x14 |
   | ReaderLineCnt   | 0x18 |
   | ReaderStride    | 0x1c |
   | WriterStartAddr | 0x20 |
   | WriterLineLen   | 0x24 |
   | WriterLineCnt   | 0x28 |
   | WriterStride    | 0x2c |
   | Version         | 0x30 |
   | Configuration   | 0x34 |

   2) DMA控制器由AXI4读取Memory的图片数据到内部的FIFO缓存

   3) DMA控制器由AXI4将FIFO缓存的数据写入2个slaves

3. 项目路径：

   ```
   ./src/
   ├── main
   │   └── scala
   │       ├── DMAController
   │       │   ├── Bus  //定义AXI的三种接口
   │       │   │   ├── AXI4.scala
   │       │   │   ├── AXI4Lite.scala
   │       │   │   └── AXIStream.scala
   │       │   ├── CSR
   │       │   │   ├── CSR.scala
   │       │   │   ├── CSRBusBundle.scala
   │       │   │   ├── CSRRegBundle.scala
   │       │   │   ├── ClearCSR.scala
   │       │   │   ├── SetCSR.scala
   │       │   │   ├── SimpleCSR.scala
   │       │   │   └── StatusCSR.scala
   │       │   ├── DMAConfig.scala //配置文件，可配置master/slaves与DMA连接的AXI接口类型（三种） ；读写地址数据位宽，FIFO深度
   │       │   ├── DMADriver.scala
   │       │   ├── DMATop.scala //DMATop文件
   │       │   ├── Frontend 
   			// 基于AXI接口编写读写逻辑。对应IP核
   			AXI-Lite;AXI4存储器映射Read;AXI存储器映射Write; AIX4S Master(MM2); AXI4S slave (S2MM)
   │       │   │   ├── AXI4LiteCSR.scala
   │       │   │   ├── AXI4LiteWriter.scala
   │       │   │   ├── AXI4Reader.scala
   │       │   │   ├── AXI4Writer.scala
   │       │   │   ├── AXIStreamMaster.scala
   │       │   │   ├── AXIStreamSlave.scala
   │       │   │   └── BusBase.scala
   │       │   └── Worker
   			//包含地址生成
   			//中断控制
   			//信号同步
   			//传输拆分
   │       │       ├── AddressGenerator.scala
   │       │       ├── AddressGeneratorCtlBundle.scala
   │       │       ├── InterruptBundle.scala
   │       │       ├── InterruptController.scala
   │       │       ├── SyncBundle.scala
   │       │       ├── TransferSplitter.scala
   │       │       ├── WorkerCSRWrapper.scala
   │       │       └── XferDescBundle.scala
   │       └── DMAUtils
   │           └── DMAUtils.scala
   └── test
       └── scala
           └── DMAController
               ├── Bfm
               │   ├── Axi4Bfm.scala
               │   ├── Axi4SlaveBfm.scala
               │   ├── AxiLiteBfm.scala
               │   ├── AxiLiteMasterBfm.scala
               │   ├── AxiStreamBfm.scala
               │   ├── AxiStreamMasterBfm.scala
               │   ├── AxiStreamSlaveBfm.scala
               │   └── ChiselBfm.scala
               ├── ComponentSpec.scala
               ├── ControllerSpec.scala
               ├── DMAFull.scala
               ├── DMAMem22Slave.scala
               ├── Frontend
               │   ├── AXI4ReaderTest.scala
               │   ├── AXI4WriterTest.scala
               │   ├── AXIStreamMasterTest.scala
               │   └── AXIStreamSlaveTest.scala
               ├── ImageTransfer.scala
               ├── TestUtil.scala
               └── Worker
                   ├── AddressGeneratorTest.scala
                   ├── InterruptControllerTest.scala
                   └── TransferSplitterTest.scala
   ```

4. 项目运行：

   ```shell
   make testM22Slave
   ```

   运行后，将会在路径下生成2个slave接收的图片


5. 参考资料：

   https://cloud.tencent.com/developer/article/1652913

   https://cloud.tencent.com/developer/article/1807365?policyId=1004

   https://cloud.tencent.com/developer/article/1813652?policyId=1004

   https://blog.csdn.net/crjmail/article/details/124703321

   https://zhuanlan.zhihu.com/p/608277782

   https://antmicro.com/blog/2019/09/fastvdma-open-dma-controller/

   https://github.com/gednyengs/dma/tree/main

   https://github.com/antmicro/fastvdma/tree/main

   

