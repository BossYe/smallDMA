// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDMATOPAXI_AXIL_AXI_H_
#define _VDMATOPAXI_AXIL_AXI_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"

//==========

class VDMATopAXI_AXIL_AXI__Syms;
class VDMATopAXI_AXIL_AXI_VerilatedVcd;


//----------

VL_MODULE(VDMATopAXI_AXIL_AXI) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_control_aw_awprot,2,0);
    VL_IN8(io_control_aw_awvalid,0,0);
    VL_OUT8(io_control_aw_awready,0,0);
    VL_IN8(io_control_w_wstrb,3,0);
    VL_IN8(io_control_w_wvalid,0,0);
    VL_OUT8(io_control_w_wready,0,0);
    VL_OUT8(io_control_b_bresp,1,0);
    VL_OUT8(io_control_b_bvalid,0,0);
    VL_IN8(io_control_b_bready,0,0);
    VL_IN8(io_control_ar_arprot,2,0);
    VL_IN8(io_control_ar_arvalid,0,0);
    VL_OUT8(io_control_ar_arready,0,0);
    VL_OUT8(io_control_r_rresp,1,0);
    VL_OUT8(io_control_r_rvalid,0,0);
    VL_IN8(io_control_r_rready,0,0);
    VL_OUT8(io_readMem_aw_awid,3,0);
    VL_OUT8(io_readMem_aw_awlen,7,0);
    VL_OUT8(io_readMem_aw_awsize,2,0);
    VL_OUT8(io_readMem_aw_awburst,1,0);
    VL_OUT8(io_readMem_aw_awlock,0,0);
    VL_OUT8(io_readMem_aw_awcache,3,0);
    VL_OUT8(io_readMem_aw_awprot,2,0);
    VL_OUT8(io_readMem_aw_awqos,3,0);
    VL_OUT8(io_readMem_aw_awvalid,0,0);
    VL_IN8(io_readMem_aw_awready,0,0);
    VL_OUT8(io_readMem_w_wstrb,3,0);
    VL_OUT8(io_readMem_w_wlast,0,0);
    VL_OUT8(io_readMem_w_wvalid,0,0);
    VL_IN8(io_readMem_w_wready,0,0);
    VL_IN8(io_readMem_b_bid,3,0);
    VL_IN8(io_readMem_b_bresp,1,0);
    VL_IN8(io_readMem_b_bvalid,0,0);
    VL_OUT8(io_readMem_b_bready,0,0);
    VL_OUT8(io_readMem_ar_arid,3,0);
    VL_OUT8(io_readMem_ar_arlen,7,0);
    VL_OUT8(io_readMem_ar_arsize,2,0);
    VL_OUT8(io_readMem_ar_arburst,1,0);
    VL_OUT8(io_readMem_ar_arlock,0,0);
    VL_OUT8(io_readMem_ar_arcache,3,0);
    VL_OUT8(io_readMem_ar_arprot,2,0);
    VL_OUT8(io_readMem_ar_arqos,3,0);
    VL_OUT8(io_readMem_ar_arvalid,0,0);
    VL_IN8(io_readMem_ar_arready,0,0);
    VL_IN8(io_readMem_r_rid,3,0);
    VL_IN8(io_readMem_r_rresp,1,0);
    VL_IN8(io_readMem_r_rlast,0,0);
    VL_IN8(io_readMem_r_rvalid,0,0);
    VL_OUT8(io_readMem_r_rready,0,0);
    VL_OUT8(io_writeSlave1_aw_awid,3,0);
    VL_OUT8(io_writeSlave1_aw_awlen,7,0);
    VL_OUT8(io_writeSlave1_aw_awsize,2,0);
    VL_OUT8(io_writeSlave1_aw_awburst,1,0);
    VL_OUT8(io_writeSlave1_aw_awlock,0,0);
    VL_OUT8(io_writeSlave1_aw_awcache,3,0);
    VL_OUT8(io_writeSlave1_aw_awprot,2,0);
    VL_OUT8(io_writeSlave1_aw_awqos,3,0);
    VL_OUT8(io_writeSlave1_aw_awvalid,0,0);
    VL_IN8(io_writeSlave1_aw_awready,0,0);
    VL_OUT8(io_writeSlave1_w_wstrb,3,0);
    VL_OUT8(io_writeSlave1_w_wlast,0,0);
    VL_OUT8(io_writeSlave1_w_wvalid,0,0);
    VL_IN8(io_writeSlave1_w_wready,0,0);
    VL_IN8(io_writeSlave1_b_bid,3,0);
    VL_IN8(io_writeSlave1_b_bresp,1,0);
    VL_IN8(io_writeSlave1_b_bvalid,0,0);
    VL_OUT8(io_writeSlave1_b_bready,0,0);
    VL_OUT8(io_writeSlave1_ar_arid,3,0);
    VL_OUT8(io_writeSlave1_ar_arlen,7,0);
    VL_OUT8(io_writeSlave1_ar_arsize,2,0);
    VL_OUT8(io_writeSlave1_ar_arburst,1,0);
    VL_OUT8(io_writeSlave1_ar_arlock,0,0);
    VL_OUT8(io_writeSlave1_ar_arcache,3,0);
    VL_OUT8(io_writeSlave1_ar_arprot,2,0);
    VL_OUT8(io_writeSlave1_ar_arqos,3,0);
    VL_OUT8(io_writeSlave1_ar_arvalid,0,0);
    VL_IN8(io_writeSlave1_ar_arready,0,0);
    VL_IN8(io_writeSlave1_r_rid,3,0);
    VL_IN8(io_writeSlave1_r_rresp,1,0);
    VL_IN8(io_writeSlave1_r_rlast,0,0);
    VL_IN8(io_writeSlave1_r_rvalid,0,0);
    VL_OUT8(io_writeSlave1_r_rready,0,0);
    VL_OUT8(io_writeSlave2_aw_awid,3,0);
    VL_OUT8(io_writeSlave2_aw_awlen,7,0);
    VL_OUT8(io_writeSlave2_aw_awsize,2,0);
    VL_OUT8(io_writeSlave2_aw_awburst,1,0);
    VL_OUT8(io_writeSlave2_aw_awlock,0,0);
    VL_OUT8(io_writeSlave2_aw_awcache,3,0);
    VL_OUT8(io_writeSlave2_aw_awprot,2,0);
    VL_OUT8(io_writeSlave2_aw_awqos,3,0);
    VL_OUT8(io_writeSlave2_aw_awvalid,0,0);
    VL_IN8(io_writeSlave2_aw_awready,0,0);
    VL_OUT8(io_writeSlave2_w_wstrb,3,0);
    VL_OUT8(io_writeSlave2_w_wlast,0,0);
    VL_OUT8(io_writeSlave2_w_wvalid,0,0);
    VL_IN8(io_writeSlave2_w_wready,0,0);
    VL_IN8(io_writeSlave2_b_bid,3,0);
    VL_IN8(io_writeSlave2_b_bresp,1,0);
    VL_IN8(io_writeSlave2_b_bvalid,0,0);
    VL_OUT8(io_writeSlave2_b_bready,0,0);
    VL_OUT8(io_writeSlave2_ar_arid,3,0);
    VL_OUT8(io_writeSlave2_ar_arlen,7,0);
    VL_OUT8(io_writeSlave2_ar_arsize,2,0);
    VL_OUT8(io_writeSlave2_ar_arburst,1,0);
    VL_OUT8(io_writeSlave2_ar_arlock,0,0);
    VL_OUT8(io_writeSlave2_ar_arcache,3,0);
    VL_OUT8(io_writeSlave2_ar_arprot,2,0);
    VL_OUT8(io_writeSlave2_ar_arqos,3,0);
    VL_OUT8(io_writeSlave2_ar_arvalid,0,0);
    VL_IN8(io_writeSlave2_ar_arready,0,0);
    VL_IN8(io_writeSlave2_r_rid,3,0);
    VL_IN8(io_writeSlave2_r_rresp,1,0);
    VL_IN8(io_writeSlave2_r_rlast,0,0);
    VL_IN8(io_writeSlave2_r_rvalid,0,0);
    VL_OUT8(io_writeSlave2_r_rready,0,0);
    VL_OUT8(io_irq_readerDone,0,0);
    VL_OUT8(io_irq_writerDone,0,0);
    VL_IN8(io_sync_readerSync,0,0);
    VL_IN8(io_sync_writerSync,0,0);
    VL_IN(io_control_aw_awaddr,31,0);
    VL_IN(io_control_w_wdata,31,0);
    VL_IN(io_control_ar_araddr,31,0);
    VL_OUT(io_control_r_rdata,31,0);
    VL_OUT(io_readMem_aw_awaddr,31,0);
    VL_OUT(io_readMem_w_wdata,31,0);
    VL_OUT(io_readMem_ar_araddr,31,0);
    VL_IN(io_readMem_r_rdata,31,0);
    VL_OUT(io_writeSlave1_aw_awaddr,31,0);
    VL_OUT(io_writeSlave1_w_wdata,31,0);
    VL_OUT(io_writeSlave1_ar_araddr,31,0);
    VL_IN(io_writeSlave1_r_rdata,31,0);
    VL_OUT(io_writeSlave2_aw_awaddr,31,0);
    VL_OUT(io_writeSlave2_w_wdata,31,0);
    VL_OUT(io_writeSlave2_ar_araddr,31,0);
    VL_IN(io_writeSlave2_r_rdata,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*2:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_2;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_5;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_9;
        CData/*2:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_10;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_11;
        CData/*2:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_25;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_26;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_27;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_28;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable;
        CData/*7:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_1;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_6;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_9;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_10;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_11;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_12;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_2;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_6;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_11;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_12;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_13;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_14;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_30;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_34;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_8;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_12;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_9;
    };
    struct {
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_10;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_17;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_8;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_12;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_9;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_10;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_17;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq;
        CData/*1:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq;
        CData/*0:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq;
        SData/*8:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value;
        SData/*8:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value;
        SData/*8:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_1;
        SData/*8:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_3;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__csr__DOT___GEN_36;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___lineCount_T_1;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___length_i_T_1;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___lineCount_T_1;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___length_i_T_1;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT___reg_T_1;
    };
    struct {
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_2;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_3;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data;
        QData/*34:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29;
        QData/*34:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_35;
        QData/*34:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29;
        QData/*34:0*/ DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35;
        IData/*31:0*/ DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram[512];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VDMATopAXI_AXIL_AXI__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VDMATopAXI_AXIL_AXI);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VDMATopAXI_AXIL_AXI(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VDMATopAXI_AXIL_AXI();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VDMATopAXI_AXIL_AXI__Syms* symsp, bool first);
  private:
    static QData _change_request(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
    static QData _change_request_1(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
