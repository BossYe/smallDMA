// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDMATopAXI_AXIL_AXI.h for the primary calling header

#include "VDMATopAXI_AXIL_AXI.h"
#include "VDMATopAXI_AXIL_AXI__Syms.h"

//==========

VL_CTOR_IMP(VDMATopAXI_AXIL_AXI) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = __VlSymsp = new VDMATopAXI_AXIL_AXI__Syms(this, name());
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDMATopAXI_AXIL_AXI::__Vconfigure(VDMATopAXI_AXIL_AXI__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VDMATopAXI_AXIL_AXI::~VDMATopAXI_AXIL_AXI() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

// Coverage
#ifndef CHISEL_VL_COVER_INSERT
#define CHISEL_VL_COVER_INSERT(countp, ...) \
    VL_IF_COVER(VerilatedCov::_inserti(countp); VerilatedCov::_insertf(__FILE__, __LINE__); \
                chisel_insertp("hier", name(), __VA_ARGS__))

#ifdef VM_COVERAGE
static void chisel_insertp(
  const char* key0, const char* valp0, const char* key1, const char* valp1,
  const char* key2, int lineno, const char* key3, int column,
  const char* key4, const std::string& hier_str,
  const char* key5, const char* valp5, const char* key6, const char* valp6,
  const char* key7 = nullptr, const char* valp7 = nullptr) {

    std::string val2str = vlCovCvtToStr(lineno);
    std::string val3str = vlCovCvtToStr(column);
    VerilatedCov::_insertp(
        key0, valp0, key1, valp1, key2, val2str.c_str(),
        key3, val3str.c_str(), key4, hier_str.c_str(),
        key5, valp5, key6, valp6, key7, valp7,
        // turn on per instance cover points
        "per_instance", "1");
}
#endif // VM_COVERAGE
#endif // CHISEL_VL_COVER_INSERT


void VDMATopAXI_AXIL_AXI::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    CHISEL_VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void VDMATopAXI_AXIL_AXI::_initial__TOP__1(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_initial__TOP__1\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_control_b_bresp = 0U;
    vlTOPp->io_control_r_rresp = 0U;
    vlTOPp->io_readMem_aw_awid = 0U;
    vlTOPp->io_readMem_aw_awaddr = 0U;
    vlTOPp->io_readMem_aw_awlen = 0U;
    vlTOPp->io_readMem_aw_awsize = 0U;
    vlTOPp->io_readMem_aw_awburst = 0U;
    vlTOPp->io_readMem_aw_awlock = 0U;
    vlTOPp->io_readMem_aw_awcache = 0U;
    vlTOPp->io_readMem_aw_awprot = 0U;
    vlTOPp->io_readMem_aw_awqos = 0U;
    vlTOPp->io_readMem_aw_awvalid = 0U;
    vlTOPp->io_readMem_w_wdata = 0U;
    vlTOPp->io_readMem_w_wstrb = 0U;
    vlTOPp->io_readMem_w_wlast = 0U;
    vlTOPp->io_readMem_w_wvalid = 0U;
    vlTOPp->io_readMem_b_bready = 0U;
    vlTOPp->io_readMem_ar_arid = 0U;
    vlTOPp->io_readMem_ar_arsize = 2U;
    vlTOPp->io_readMem_ar_arburst = 1U;
    vlTOPp->io_readMem_ar_arlock = 0U;
    vlTOPp->io_readMem_ar_arcache = 2U;
    vlTOPp->io_readMem_ar_arprot = 0U;
    vlTOPp->io_readMem_ar_arqos = 0U;
    vlTOPp->io_writeSlave1_aw_awid = 0U;
    vlTOPp->io_writeSlave1_aw_awsize = 2U;
    vlTOPp->io_writeSlave1_aw_awburst = 1U;
    vlTOPp->io_writeSlave1_aw_awlock = 0U;
    vlTOPp->io_writeSlave1_aw_awcache = 2U;
    vlTOPp->io_writeSlave1_aw_awprot = 0U;
    vlTOPp->io_writeSlave1_aw_awqos = 0U;
    vlTOPp->io_writeSlave1_w_wstrb = 0xfU;
    vlTOPp->io_writeSlave1_ar_arid = 0U;
    vlTOPp->io_writeSlave1_ar_araddr = 0U;
    vlTOPp->io_writeSlave1_ar_arlen = 0U;
    vlTOPp->io_writeSlave1_ar_arsize = 0U;
    vlTOPp->io_writeSlave1_ar_arburst = 0U;
    vlTOPp->io_writeSlave1_ar_arlock = 0U;
    vlTOPp->io_writeSlave1_ar_arcache = 0U;
    vlTOPp->io_writeSlave1_ar_arprot = 0U;
    vlTOPp->io_writeSlave1_ar_arqos = 0U;
    vlTOPp->io_writeSlave1_ar_arvalid = 0U;
    vlTOPp->io_writeSlave1_r_rready = 0U;
    vlTOPp->io_writeSlave2_aw_awid = 0U;
    vlTOPp->io_writeSlave2_aw_awsize = 2U;
    vlTOPp->io_writeSlave2_aw_awburst = 1U;
    vlTOPp->io_writeSlave2_aw_awlock = 0U;
    vlTOPp->io_writeSlave2_aw_awcache = 2U;
    vlTOPp->io_writeSlave2_aw_awprot = 0U;
    vlTOPp->io_writeSlave2_aw_awqos = 0U;
    vlTOPp->io_writeSlave2_w_wstrb = 0xfU;
    vlTOPp->io_writeSlave2_ar_arid = 0U;
    vlTOPp->io_writeSlave2_ar_araddr = 0U;
    vlTOPp->io_writeSlave2_ar_arlen = 0U;
    vlTOPp->io_writeSlave2_ar_arsize = 0U;
    vlTOPp->io_writeSlave2_ar_arburst = 0U;
    vlTOPp->io_writeSlave2_ar_arlock = 0U;
    vlTOPp->io_writeSlave2_ar_arcache = 0U;
    vlTOPp->io_writeSlave2_ar_arprot = 0U;
    vlTOPp->io_writeSlave2_ar_arqos = 0U;
    vlTOPp->io_writeSlave2_ar_arvalid = 0U;
    vlTOPp->io_writeSlave2_r_rready = 0U;
}

void VDMATopAXI_AXIL_AXI::_settle__TOP__3(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_settle__TOP__3\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_readMem_ar_araddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr;
    vlTOPp->io_readMem_ar_arlen = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen;
    vlTOPp->io_readMem_ar_arvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
    vlTOPp->io_writeSlave1_aw_awaddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr;
    vlTOPp->io_writeSlave1_aw_awlen = (0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen);
    vlTOPp->io_writeSlave1_aw_awvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    vlTOPp->io_writeSlave1_w_wlast = (1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length);
    vlTOPp->io_writeSlave1_b_bready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready;
    vlTOPp->io_writeSlave2_aw_awaddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr;
    vlTOPp->io_writeSlave2_aw_awlen = (0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen);
    vlTOPp->io_writeSlave2_aw_awvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    vlTOPp->io_writeSlave2_w_wlast = (1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length);
    vlTOPp->io_writeSlave2_b_bready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready;
    vlTOPp->io_irq_readerDone = (1U & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
                                       >> 1U));
    vlTOPp->io_irq_writerDone = (1U & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_);
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_12 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3 
        = ((1U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length)
            ? (vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length 
               - (IData)(1U)) : vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length);
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_14 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_3 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_11 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready 
        = ((IData)(vlTOPp->io_writeSlave2_w_wready) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    if ((1U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length)) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5 
            = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable) 
               & 1U);
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4 = 2U;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5 = 0U;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_6 
        = ((1U >= vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_11 
        = ((~ ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready) 
               & (IData)(vlTOPp->io_writeSlave2_b_bvalid))) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_13 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_34 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done)
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_6 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid) 
            & (IData)(vlTOPp->io_readMem_ar_arready)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_12 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready) 
            & (IData)(vlTOPp->io_writeSlave2_b_bvalid))
            ? 3U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram
        [vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value];
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq) 
            << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid 
        = ((IData)(vlTOPp->io_readMem_r_rvalid) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___length_i_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
           - (IData)(0x10U));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_1 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_2 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_30 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_17 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid)));
    if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_9 
            = ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i)
                ? 1U : 0U);
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_10 
            = ((0U >= vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i) 
               | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done));
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_9 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_10 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value) 
           == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___lineCount_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount 
           - (IData)(1U));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___lineCount_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount 
           - (IData)(1U));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_1 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_12 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_12 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_8 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done)
            ? ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount)
                ? 1U : 0U) : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_8 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done)
            ? ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount)
                ? 1U : 0U) : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state));
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26 = 0U;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35 = 0ULL;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29 = 0ULL;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29 = 0ULL;
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26 
            = ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))
                ? ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid)
                    ? (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o 
                       - (IData)(1U)) : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen))
                : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35 
            = (0x7ffffffffULL & ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))
                                  ? (QData)((IData)(
                                                    ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid)
                                                      ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o
                                                      : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i)))
                                  : ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))
                                      ? ((0x10U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i)
                                          ? (QData)((IData)(
                                                            ((IData)(0x40U) 
                                                             + vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i)))
                                          : ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i)) 
                                             + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i)) 
                                                << 2U)))
                                      : (QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i)))));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29 
            = (0x7ffffffffULL & ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))
                                  ? (QData)((IData)(
                                                    ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart)
                                                      ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_
                                                      : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i)))
                                  : ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))
                                      ? (((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i)) 
                                          + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i)) 
                                             << 2U)) 
                                         + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap)) 
                                            << 2U))
                                      : (QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i)))));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29 
            = (0x7ffffffffULL & ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))
                                  ? (QData)((IData)(
                                                    ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)
                                                      ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_
                                                      : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i)))
                                  : ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))
                                      ? (((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i)) 
                                          + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i)) 
                                             << 2U)) 
                                         + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap)) 
                                            << 2U))
                                      : (QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i)))));
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT___reg_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
           & (~ ((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                   << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                 & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                       >> 4U)))));
    vlTOPp->io_control_aw_awready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready;
    vlTOPp->io_control_w_wready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready;
    vlTOPp->io_control_b_bvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid;
    vlTOPp->io_control_ar_arready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
    vlTOPp->io_control_r_rvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_2 
        = ((IData)(vlTOPp->io_control_ar_arvalid) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_5 
        = ((IData)(vlTOPp->io_control_aw_awvalid) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_9 
        = (((IData)(vlTOPp->io_control_ar_arvalid) 
            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_26 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
            ? ((~ ((IData)(vlTOPp->io_control_aw_awvalid) 
                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready))) 
               & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready))
            : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T 
        = ((IData)(vlTOPp->io_control_w_wvalid) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T 
        = ((IData)(vlTOPp->io_control_r_rready) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
    vlTOPp->io_writeSlave1_w_wdata = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data;
    vlTOPp->io_writeSlave2_w_wdata = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_3 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match) 
           & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full));
    if ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_28 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_27 
            = (((IData)(vlTOPp->io_control_aw_awvalid) 
                & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready)) 
               | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_28 
            = ((4U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                ? ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T) 
                   | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid))
                : ((5U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                    ? ((~ ((IData)(vlTOPp->io_control_b_bready) 
                           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid))) 
                       & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid))
                    : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid)));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_27 
            = ((4U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                ? ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T)) 
                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready))
                : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_2 
        = ((vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
            & (~ (((3U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                   ? vlTOPp->io_control_w_wdata : 0U))) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_25 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
            ? (((IData)(vlTOPp->io_control_aw_awvalid) 
                & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready))
                ? 4U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
            : ((4U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                ? ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T)
                    ? 5U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                : ((5U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                    ? (((IData)(vlTOPp->io_control_b_bready) 
                        & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid))
                        ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                    : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_10 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T)
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_11 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csr__DOT___GEN_36 
        = (((9U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
            ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_
            : (((8U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_
                : (((7U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                    ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_
                    : (((6U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                        & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                        ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_
                        : (((5U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                            ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_
                            : (((4U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_
                                : (((3U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                    ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_
                                    : (((2U == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                        & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                        ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_
                                        : (((1U == 
                                             (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                            ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_
                                            : (((0U 
                                                 == 
                                                 (0xfU 
                                                  & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                                & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                                ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_
                                                : 0U))))))))));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq 
        = (((IData)(vlTOPp->io_writeSlave2_w_wready) 
            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable)) 
           & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    vlTOPp->io_readMem_r_rready = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->io_control_r_rdata = (((0xfU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                   ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_
                                   : (((0xeU == (0xfU 
                                                 & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                       & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                       ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_
                                       : (((0xdU == 
                                            (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                           ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_
                                           : (((0xcU 
                                                == 
                                                (0xfU 
                                                 & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                               & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                               ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_
                                               : ((
                                                   (0xbU 
                                                    == 
                                                    (0xfU 
                                                     & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                                   ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_
                                                   : 
                                                  (((0xaU 
                                                     == 
                                                     (0xfU 
                                                      & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                                    ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_
                                                    : vlTOPp->DMATopAXI_AXIL_AXI__DOT__csr__DOT___GEN_36))))));
    vlTOPp->io_writeSlave1_w_wvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid;
    vlTOPp->io_writeSlave2_w_wvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid;
    if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready) 
         & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid))) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_9 
            = ((IData)(vlTOPp->io_readMem_r_rlast) ? 3U
                : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_10 
            = ((~ (IData)(vlTOPp->io_readMem_r_rlast)) 
               & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_9 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_10 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable;
    }
}

void VDMATopAXI_AXIL_AXI::_eval_initial(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_eval_initial\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VDMATopAXI_AXIL_AXI::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::final\n"); );
    // Variables
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDMATopAXI_AXIL_AXI::_eval_settle(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_eval_settle\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VDMATopAXI_AXIL_AXI::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_control_aw_awaddr = VL_RAND_RESET_I(32);
    io_control_aw_awprot = VL_RAND_RESET_I(3);
    io_control_aw_awvalid = VL_RAND_RESET_I(1);
    io_control_aw_awready = VL_RAND_RESET_I(1);
    io_control_w_wdata = VL_RAND_RESET_I(32);
    io_control_w_wstrb = VL_RAND_RESET_I(4);
    io_control_w_wvalid = VL_RAND_RESET_I(1);
    io_control_w_wready = VL_RAND_RESET_I(1);
    io_control_b_bresp = VL_RAND_RESET_I(2);
    io_control_b_bvalid = VL_RAND_RESET_I(1);
    io_control_b_bready = VL_RAND_RESET_I(1);
    io_control_ar_araddr = VL_RAND_RESET_I(32);
    io_control_ar_arprot = VL_RAND_RESET_I(3);
    io_control_ar_arvalid = VL_RAND_RESET_I(1);
    io_control_ar_arready = VL_RAND_RESET_I(1);
    io_control_r_rdata = VL_RAND_RESET_I(32);
    io_control_r_rresp = VL_RAND_RESET_I(2);
    io_control_r_rvalid = VL_RAND_RESET_I(1);
    io_control_r_rready = VL_RAND_RESET_I(1);
    io_readMem_aw_awid = VL_RAND_RESET_I(4);
    io_readMem_aw_awaddr = VL_RAND_RESET_I(32);
    io_readMem_aw_awlen = VL_RAND_RESET_I(8);
    io_readMem_aw_awsize = VL_RAND_RESET_I(3);
    io_readMem_aw_awburst = VL_RAND_RESET_I(2);
    io_readMem_aw_awlock = VL_RAND_RESET_I(1);
    io_readMem_aw_awcache = VL_RAND_RESET_I(4);
    io_readMem_aw_awprot = VL_RAND_RESET_I(3);
    io_readMem_aw_awqos = VL_RAND_RESET_I(4);
    io_readMem_aw_awvalid = VL_RAND_RESET_I(1);
    io_readMem_aw_awready = VL_RAND_RESET_I(1);
    io_readMem_w_wdata = VL_RAND_RESET_I(32);
    io_readMem_w_wstrb = VL_RAND_RESET_I(4);
    io_readMem_w_wlast = VL_RAND_RESET_I(1);
    io_readMem_w_wvalid = VL_RAND_RESET_I(1);
    io_readMem_w_wready = VL_RAND_RESET_I(1);
    io_readMem_b_bid = VL_RAND_RESET_I(4);
    io_readMem_b_bresp = VL_RAND_RESET_I(2);
    io_readMem_b_bvalid = VL_RAND_RESET_I(1);
    io_readMem_b_bready = VL_RAND_RESET_I(1);
    io_readMem_ar_arid = VL_RAND_RESET_I(4);
    io_readMem_ar_araddr = VL_RAND_RESET_I(32);
    io_readMem_ar_arlen = VL_RAND_RESET_I(8);
    io_readMem_ar_arsize = VL_RAND_RESET_I(3);
    io_readMem_ar_arburst = VL_RAND_RESET_I(2);
    io_readMem_ar_arlock = VL_RAND_RESET_I(1);
    io_readMem_ar_arcache = VL_RAND_RESET_I(4);
    io_readMem_ar_arprot = VL_RAND_RESET_I(3);
    io_readMem_ar_arqos = VL_RAND_RESET_I(4);
    io_readMem_ar_arvalid = VL_RAND_RESET_I(1);
    io_readMem_ar_arready = VL_RAND_RESET_I(1);
    io_readMem_r_rid = VL_RAND_RESET_I(4);
    io_readMem_r_rdata = VL_RAND_RESET_I(32);
    io_readMem_r_rresp = VL_RAND_RESET_I(2);
    io_readMem_r_rlast = VL_RAND_RESET_I(1);
    io_readMem_r_rvalid = VL_RAND_RESET_I(1);
    io_readMem_r_rready = VL_RAND_RESET_I(1);
    io_writeSlave1_aw_awid = VL_RAND_RESET_I(4);
    io_writeSlave1_aw_awaddr = VL_RAND_RESET_I(32);
    io_writeSlave1_aw_awlen = VL_RAND_RESET_I(8);
    io_writeSlave1_aw_awsize = VL_RAND_RESET_I(3);
    io_writeSlave1_aw_awburst = VL_RAND_RESET_I(2);
    io_writeSlave1_aw_awlock = VL_RAND_RESET_I(1);
    io_writeSlave1_aw_awcache = VL_RAND_RESET_I(4);
    io_writeSlave1_aw_awprot = VL_RAND_RESET_I(3);
    io_writeSlave1_aw_awqos = VL_RAND_RESET_I(4);
    io_writeSlave1_aw_awvalid = VL_RAND_RESET_I(1);
    io_writeSlave1_aw_awready = VL_RAND_RESET_I(1);
    io_writeSlave1_w_wdata = VL_RAND_RESET_I(32);
    io_writeSlave1_w_wstrb = VL_RAND_RESET_I(4);
    io_writeSlave1_w_wlast = VL_RAND_RESET_I(1);
    io_writeSlave1_w_wvalid = VL_RAND_RESET_I(1);
    io_writeSlave1_w_wready = VL_RAND_RESET_I(1);
    io_writeSlave1_b_bid = VL_RAND_RESET_I(4);
    io_writeSlave1_b_bresp = VL_RAND_RESET_I(2);
    io_writeSlave1_b_bvalid = VL_RAND_RESET_I(1);
    io_writeSlave1_b_bready = VL_RAND_RESET_I(1);
    io_writeSlave1_ar_arid = VL_RAND_RESET_I(4);
    io_writeSlave1_ar_araddr = VL_RAND_RESET_I(32);
    io_writeSlave1_ar_arlen = VL_RAND_RESET_I(8);
    io_writeSlave1_ar_arsize = VL_RAND_RESET_I(3);
    io_writeSlave1_ar_arburst = VL_RAND_RESET_I(2);
    io_writeSlave1_ar_arlock = VL_RAND_RESET_I(1);
    io_writeSlave1_ar_arcache = VL_RAND_RESET_I(4);
    io_writeSlave1_ar_arprot = VL_RAND_RESET_I(3);
    io_writeSlave1_ar_arqos = VL_RAND_RESET_I(4);
    io_writeSlave1_ar_arvalid = VL_RAND_RESET_I(1);
    io_writeSlave1_ar_arready = VL_RAND_RESET_I(1);
    io_writeSlave1_r_rid = VL_RAND_RESET_I(4);
    io_writeSlave1_r_rdata = VL_RAND_RESET_I(32);
    io_writeSlave1_r_rresp = VL_RAND_RESET_I(2);
    io_writeSlave1_r_rlast = VL_RAND_RESET_I(1);
    io_writeSlave1_r_rvalid = VL_RAND_RESET_I(1);
    io_writeSlave1_r_rready = VL_RAND_RESET_I(1);
    io_writeSlave2_aw_awid = VL_RAND_RESET_I(4);
    io_writeSlave2_aw_awaddr = VL_RAND_RESET_I(32);
    io_writeSlave2_aw_awlen = VL_RAND_RESET_I(8);
    io_writeSlave2_aw_awsize = VL_RAND_RESET_I(3);
    io_writeSlave2_aw_awburst = VL_RAND_RESET_I(2);
    io_writeSlave2_aw_awlock = VL_RAND_RESET_I(1);
    io_writeSlave2_aw_awcache = VL_RAND_RESET_I(4);
    io_writeSlave2_aw_awprot = VL_RAND_RESET_I(3);
    io_writeSlave2_aw_awqos = VL_RAND_RESET_I(4);
    io_writeSlave2_aw_awvalid = VL_RAND_RESET_I(1);
    io_writeSlave2_aw_awready = VL_RAND_RESET_I(1);
    io_writeSlave2_w_wdata = VL_RAND_RESET_I(32);
    io_writeSlave2_w_wstrb = VL_RAND_RESET_I(4);
    io_writeSlave2_w_wlast = VL_RAND_RESET_I(1);
    io_writeSlave2_w_wvalid = VL_RAND_RESET_I(1);
    io_writeSlave2_w_wready = VL_RAND_RESET_I(1);
    io_writeSlave2_b_bid = VL_RAND_RESET_I(4);
    io_writeSlave2_b_bresp = VL_RAND_RESET_I(2);
    io_writeSlave2_b_bvalid = VL_RAND_RESET_I(1);
    io_writeSlave2_b_bready = VL_RAND_RESET_I(1);
    io_writeSlave2_ar_arid = VL_RAND_RESET_I(4);
    io_writeSlave2_ar_araddr = VL_RAND_RESET_I(32);
    io_writeSlave2_ar_arlen = VL_RAND_RESET_I(8);
    io_writeSlave2_ar_arsize = VL_RAND_RESET_I(3);
    io_writeSlave2_ar_arburst = VL_RAND_RESET_I(2);
    io_writeSlave2_ar_arlock = VL_RAND_RESET_I(1);
    io_writeSlave2_ar_arcache = VL_RAND_RESET_I(4);
    io_writeSlave2_ar_arprot = VL_RAND_RESET_I(3);
    io_writeSlave2_ar_arqos = VL_RAND_RESET_I(4);
    io_writeSlave2_ar_arvalid = VL_RAND_RESET_I(1);
    io_writeSlave2_ar_arready = VL_RAND_RESET_I(1);
    io_writeSlave2_r_rid = VL_RAND_RESET_I(4);
    io_writeSlave2_r_rdata = VL_RAND_RESET_I(32);
    io_writeSlave2_r_rresp = VL_RAND_RESET_I(2);
    io_writeSlave2_r_rlast = VL_RAND_RESET_I(1);
    io_writeSlave2_r_rvalid = VL_RAND_RESET_I(1);
    io_writeSlave2_r_rready = VL_RAND_RESET_I(1);
    io_irq_readerDone = VL_RAND_RESET_I(1);
    io_irq_writerDone = VL_RAND_RESET_I(1);
    io_sync_readerSync = VL_RAND_RESET_I(1);
    io_sync_writerSync = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state = VL_RAND_RESET_I(3);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_2 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_5 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_9 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_10 = VL_RAND_RESET_I(3);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_11 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_25 = VL_RAND_RESET_I(3);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_26 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_27 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_28 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen = VL_RAND_RESET_I(8);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_1 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_6 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_9 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_10 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_11 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_12 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_2 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_6 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_11 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_12 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_13 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_14 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_30 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_34 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__csr__DOT___GEN_36 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___lineCount_T_1 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_8 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_12 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29 = VL_RAND_RESET_Q(35);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___lineCount_T_1 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_8 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_12 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29 = VL_RAND_RESET_Q(35);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___length_i_T_1 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_9 = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_10 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_17 = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35 = VL_RAND_RESET_Q(35);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT___reg_T_1 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq = VL_RAND_RESET_I(2);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_2 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_3 = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_ = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_ = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<512; ++__Vi0) {
            DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram[__Vi0] = VL_RAND_RESET_I(32);
    }}
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data = VL_RAND_RESET_I(32);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value = VL_RAND_RESET_I(9);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value = VL_RAND_RESET_I(9);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq = VL_RAND_RESET_I(1);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_1 = VL_RAND_RESET_I(9);
    DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_3 = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}

void VDMATopAXI_AXIL_AXI::_configure_coverage(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
}