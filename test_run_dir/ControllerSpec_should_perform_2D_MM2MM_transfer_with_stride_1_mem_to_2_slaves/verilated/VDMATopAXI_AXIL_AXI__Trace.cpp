// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDMATopAXI_AXIL_AXI__Syms.h"


void VDMATopAXI_AXIL_AXI::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VDMATopAXI_AXIL_AXI::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
            tracep->chgBit(oldp+1,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
            tracep->chgBit(oldp+2,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid));
            tracep->chgBit(oldp+3,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready));
            tracep->chgBit(oldp+4,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
            tracep->chgCData(oldp+5,((0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)),4);
            tracep->chgIData(oldp+6,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr),32);
            tracep->chgCData(oldp+7,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen),8);
            tracep->chgBit(oldp+8,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid));
            tracep->chgBit(oldp+9,(((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable))));
            tracep->chgBit(oldp+10,((1U & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)))));
            tracep->chgBit(oldp+11,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done));
            tracep->chgIData(oldp+12,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_o),32);
            tracep->chgIData(oldp+13,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_o),32);
            tracep->chgBit(oldp+14,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid));
            tracep->chgIData(oldp+15,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr),32);
            tracep->chgCData(oldp+16,((0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen)),8);
            tracep->chgBit(oldp+17,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid));
            tracep->chgIData(oldp+18,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data),32);
            tracep->chgBit(oldp+19,((1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length)));
            tracep->chgBit(oldp+20,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid));
            tracep->chgBit(oldp+21,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
            tracep->chgBit(oldp+22,((1U & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)))));
            tracep->chgBit(oldp+23,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done));
            tracep->chgIData(oldp+24,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o),32);
            tracep->chgIData(oldp+25,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o),32);
            tracep->chgBit(oldp+26,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid));
            tracep->chgIData(oldp+27,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_),32);
            tracep->chgIData(oldp+28,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_),32);
            tracep->chgIData(oldp+29,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_),32);
            tracep->chgIData(oldp+30,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_),32);
            tracep->chgIData(oldp+31,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_),32);
            tracep->chgIData(oldp+32,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_),32);
            tracep->chgIData(oldp+33,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_),32);
            tracep->chgIData(oldp+34,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_),32);
            tracep->chgIData(oldp+35,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_),32);
            tracep->chgIData(oldp+36,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_),32);
            tracep->chgIData(oldp+37,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_),32);
            tracep->chgIData(oldp+38,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_),32);
            tracep->chgIData(oldp+39,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_),32);
            tracep->chgIData(oldp+40,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_),32);
            tracep->chgIData(oldp+41,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_),32);
            tracep->chgIData(oldp+42,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_),32);
            tracep->chgBit(oldp+43,((1U & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
                                           >> 1U))));
            tracep->chgBit(oldp+44,((1U & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_)));
            tracep->chgCData(oldp+45,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state),3);
            tracep->chgIData(oldp+46,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr),32);
            tracep->chgCData(oldp+47,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state),2);
            tracep->chgBit(oldp+48,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
            tracep->chgBit(oldp+49,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready));
            tracep->chgCData(oldp+50,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState),2);
            tracep->chgCData(oldp+51,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState),2);
            tracep->chgBit(oldp+52,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
            tracep->chgIData(oldp+53,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length),32);
            tracep->chgIData(oldp+54,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen),32);
            tracep->chgBit(oldp+55,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart));
            tracep->chgBit(oldp+56,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy));
            tracep->chgBit(oldp+57,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done));
            tracep->chgIData(oldp+58,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o),32);
            tracep->chgIData(oldp+59,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o),32);
            tracep->chgBit(oldp+60,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid));
            tracep->chgBit(oldp+61,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart));
            tracep->chgBit(oldp+62,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy));
            tracep->chgBit(oldp+63,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done));
            tracep->chgIData(oldp+64,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o),32);
            tracep->chgIData(oldp+65,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o),32);
            tracep->chgBit(oldp+66,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid));
            tracep->chgIData(oldp+67,(((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                                         << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                                       & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                             >> 4U)))),32);
            tracep->chgIData(oldp+68,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status),32);
            tracep->chgCData(oldp+69,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status),2);
            tracep->chgBit(oldp+70,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync));
            tracep->chgBit(oldp+71,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld));
            tracep->chgBit(oldp+72,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync));
            tracep->chgBit(oldp+73,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld));
            tracep->chgCData(oldp+74,(((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                                         << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                                       & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                             >> 4U)))),2);
            tracep->chgCData(oldp+75,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state),2);
            tracep->chgIData(oldp+76,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount),32);
            tracep->chgIData(oldp+77,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap),32);
            tracep->chgIData(oldp+78,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i),32);
            tracep->chgIData(oldp+79,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i),32);
            tracep->chgIData(oldp+80,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i),32);
            tracep->chgIData(oldp+81,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i),32);
            tracep->chgCData(oldp+82,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state),2);
            tracep->chgCData(oldp+83,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state),2);
            tracep->chgIData(oldp+84,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount),32);
            tracep->chgIData(oldp+85,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap),32);
            tracep->chgIData(oldp+86,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i),32);
            tracep->chgIData(oldp+87,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i),32);
            tracep->chgIData(oldp+88,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i),32);
            tracep->chgIData(oldp+89,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i),32);
            tracep->chgCData(oldp+90,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state),2);
            tracep->chgIData(oldp+91,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq),32);
            tracep->chgBit(oldp+92,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy));
            tracep->chgBit(oldp+93,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld));
            tracep->chgBit(oldp+94,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy));
            tracep->chgBit(oldp+95,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld));
            tracep->chgBit(oldp+96,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq));
            tracep->chgBit(oldp+97,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq));
            tracep->chgCData(oldp+98,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq),2);
            tracep->chgSData(oldp+99,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value),9);
            tracep->chgSData(oldp+100,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value),9);
            tracep->chgBit(oldp+101,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full));
            tracep->chgBit(oldp+102,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match));
            tracep->chgBit(oldp+103,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty));
            tracep->chgBit(oldp+104,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full));
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [2U]))) {
            tracep->chgIData(oldp+105,((((0xfU == (0xfU 
                                                   & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                         & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                         ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_
                                         : (((0xeU 
                                              == (0xfU 
                                                  & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                             ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_
                                             : (((0xdU 
                                                  == 
                                                  (0xfU 
                                                   & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                                 & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                                 ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_
                                                 : 
                                                (((0xcU 
                                                   == 
                                                   (0xfU 
                                                    & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                                  & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                                  ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_
                                                  : 
                                                 (((0xbU 
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
                                                    : vlTOPp->DMATopAXI_AXIL_AXI__DOT__csr__DOT___GEN_36))))))),32);
            tracep->chgBit(oldp+106,(((0U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+107,(((2U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+108,(((3U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+109,(((4U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+110,(((5U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+111,(((6U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+112,(((7U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+113,(((8U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+114,(((9U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+115,(((0xaU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+116,(((0xbU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+117,(((0xeU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+118,(((0xfU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
            tracep->chgBit(oldp+119,(((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+120,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T));
            tracep->chgBit(oldp+121,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T));
            tracep->chgBit(oldp+122,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid));
            tracep->chgBit(oldp+123,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready));
            tracep->chgBit(oldp+124,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq));
            tracep->chgBit(oldp+125,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq));
        }
        tracep->chgBit(oldp+126,(vlTOPp->clock));
        tracep->chgBit(oldp+127,(vlTOPp->reset));
        tracep->chgIData(oldp+128,(vlTOPp->io_control_aw_awaddr),32);
        tracep->chgCData(oldp+129,(vlTOPp->io_control_aw_awprot),3);
        tracep->chgBit(oldp+130,(vlTOPp->io_control_aw_awvalid));
        tracep->chgBit(oldp+131,(vlTOPp->io_control_aw_awready));
        tracep->chgIData(oldp+132,(vlTOPp->io_control_w_wdata),32);
        tracep->chgCData(oldp+133,(vlTOPp->io_control_w_wstrb),4);
        tracep->chgBit(oldp+134,(vlTOPp->io_control_w_wvalid));
        tracep->chgBit(oldp+135,(vlTOPp->io_control_w_wready));
        tracep->chgCData(oldp+136,(vlTOPp->io_control_b_bresp),2);
        tracep->chgBit(oldp+137,(vlTOPp->io_control_b_bvalid));
        tracep->chgBit(oldp+138,(vlTOPp->io_control_b_bready));
        tracep->chgIData(oldp+139,(vlTOPp->io_control_ar_araddr),32);
        tracep->chgCData(oldp+140,(vlTOPp->io_control_ar_arprot),3);
        tracep->chgBit(oldp+141,(vlTOPp->io_control_ar_arvalid));
        tracep->chgBit(oldp+142,(vlTOPp->io_control_ar_arready));
        tracep->chgIData(oldp+143,(vlTOPp->io_control_r_rdata),32);
        tracep->chgCData(oldp+144,(vlTOPp->io_control_r_rresp),2);
        tracep->chgBit(oldp+145,(vlTOPp->io_control_r_rvalid));
        tracep->chgBit(oldp+146,(vlTOPp->io_control_r_rready));
        tracep->chgCData(oldp+147,(vlTOPp->io_readMem_aw_awid),4);
        tracep->chgIData(oldp+148,(vlTOPp->io_readMem_aw_awaddr),32);
        tracep->chgCData(oldp+149,(vlTOPp->io_readMem_aw_awlen),8);
        tracep->chgCData(oldp+150,(vlTOPp->io_readMem_aw_awsize),3);
        tracep->chgCData(oldp+151,(vlTOPp->io_readMem_aw_awburst),2);
        tracep->chgBit(oldp+152,(vlTOPp->io_readMem_aw_awlock));
        tracep->chgCData(oldp+153,(vlTOPp->io_readMem_aw_awcache),4);
        tracep->chgCData(oldp+154,(vlTOPp->io_readMem_aw_awprot),3);
        tracep->chgCData(oldp+155,(vlTOPp->io_readMem_aw_awqos),4);
        tracep->chgBit(oldp+156,(vlTOPp->io_readMem_aw_awvalid));
        tracep->chgBit(oldp+157,(vlTOPp->io_readMem_aw_awready));
        tracep->chgIData(oldp+158,(vlTOPp->io_readMem_w_wdata),32);
        tracep->chgCData(oldp+159,(vlTOPp->io_readMem_w_wstrb),4);
        tracep->chgBit(oldp+160,(vlTOPp->io_readMem_w_wlast));
        tracep->chgBit(oldp+161,(vlTOPp->io_readMem_w_wvalid));
        tracep->chgBit(oldp+162,(vlTOPp->io_readMem_w_wready));
        tracep->chgCData(oldp+163,(vlTOPp->io_readMem_b_bid),4);
        tracep->chgCData(oldp+164,(vlTOPp->io_readMem_b_bresp),2);
        tracep->chgBit(oldp+165,(vlTOPp->io_readMem_b_bvalid));
        tracep->chgBit(oldp+166,(vlTOPp->io_readMem_b_bready));
        tracep->chgCData(oldp+167,(vlTOPp->io_readMem_ar_arid),4);
        tracep->chgIData(oldp+168,(vlTOPp->io_readMem_ar_araddr),32);
        tracep->chgCData(oldp+169,(vlTOPp->io_readMem_ar_arlen),8);
        tracep->chgCData(oldp+170,(vlTOPp->io_readMem_ar_arsize),3);
        tracep->chgCData(oldp+171,(vlTOPp->io_readMem_ar_arburst),2);
        tracep->chgBit(oldp+172,(vlTOPp->io_readMem_ar_arlock));
        tracep->chgCData(oldp+173,(vlTOPp->io_readMem_ar_arcache),4);
        tracep->chgCData(oldp+174,(vlTOPp->io_readMem_ar_arprot),3);
        tracep->chgCData(oldp+175,(vlTOPp->io_readMem_ar_arqos),4);
        tracep->chgBit(oldp+176,(vlTOPp->io_readMem_ar_arvalid));
        tracep->chgBit(oldp+177,(vlTOPp->io_readMem_ar_arready));
        tracep->chgCData(oldp+178,(vlTOPp->io_readMem_r_rid),4);
        tracep->chgIData(oldp+179,(vlTOPp->io_readMem_r_rdata),32);
        tracep->chgCData(oldp+180,(vlTOPp->io_readMem_r_rresp),2);
        tracep->chgBit(oldp+181,(vlTOPp->io_readMem_r_rlast));
        tracep->chgBit(oldp+182,(vlTOPp->io_readMem_r_rvalid));
        tracep->chgBit(oldp+183,(vlTOPp->io_readMem_r_rready));
        tracep->chgCData(oldp+184,(vlTOPp->io_writeSlave1_aw_awid),4);
        tracep->chgIData(oldp+185,(vlTOPp->io_writeSlave1_aw_awaddr),32);
        tracep->chgCData(oldp+186,(vlTOPp->io_writeSlave1_aw_awlen),8);
        tracep->chgCData(oldp+187,(vlTOPp->io_writeSlave1_aw_awsize),3);
        tracep->chgCData(oldp+188,(vlTOPp->io_writeSlave1_aw_awburst),2);
        tracep->chgBit(oldp+189,(vlTOPp->io_writeSlave1_aw_awlock));
        tracep->chgCData(oldp+190,(vlTOPp->io_writeSlave1_aw_awcache),4);
        tracep->chgCData(oldp+191,(vlTOPp->io_writeSlave1_aw_awprot),3);
        tracep->chgCData(oldp+192,(vlTOPp->io_writeSlave1_aw_awqos),4);
        tracep->chgBit(oldp+193,(vlTOPp->io_writeSlave1_aw_awvalid));
        tracep->chgBit(oldp+194,(vlTOPp->io_writeSlave1_aw_awready));
        tracep->chgIData(oldp+195,(vlTOPp->io_writeSlave1_w_wdata),32);
        tracep->chgCData(oldp+196,(vlTOPp->io_writeSlave1_w_wstrb),4);
        tracep->chgBit(oldp+197,(vlTOPp->io_writeSlave1_w_wlast));
        tracep->chgBit(oldp+198,(vlTOPp->io_writeSlave1_w_wvalid));
        tracep->chgBit(oldp+199,(vlTOPp->io_writeSlave1_w_wready));
        tracep->chgCData(oldp+200,(vlTOPp->io_writeSlave1_b_bid),4);
        tracep->chgCData(oldp+201,(vlTOPp->io_writeSlave1_b_bresp),2);
        tracep->chgBit(oldp+202,(vlTOPp->io_writeSlave1_b_bvalid));
        tracep->chgBit(oldp+203,(vlTOPp->io_writeSlave1_b_bready));
        tracep->chgCData(oldp+204,(vlTOPp->io_writeSlave1_ar_arid),4);
        tracep->chgIData(oldp+205,(vlTOPp->io_writeSlave1_ar_araddr),32);
        tracep->chgCData(oldp+206,(vlTOPp->io_writeSlave1_ar_arlen),8);
        tracep->chgCData(oldp+207,(vlTOPp->io_writeSlave1_ar_arsize),3);
        tracep->chgCData(oldp+208,(vlTOPp->io_writeSlave1_ar_arburst),2);
        tracep->chgBit(oldp+209,(vlTOPp->io_writeSlave1_ar_arlock));
        tracep->chgCData(oldp+210,(vlTOPp->io_writeSlave1_ar_arcache),4);
        tracep->chgCData(oldp+211,(vlTOPp->io_writeSlave1_ar_arprot),3);
        tracep->chgCData(oldp+212,(vlTOPp->io_writeSlave1_ar_arqos),4);
        tracep->chgBit(oldp+213,(vlTOPp->io_writeSlave1_ar_arvalid));
        tracep->chgBit(oldp+214,(vlTOPp->io_writeSlave1_ar_arready));
        tracep->chgCData(oldp+215,(vlTOPp->io_writeSlave1_r_rid),4);
        tracep->chgIData(oldp+216,(vlTOPp->io_writeSlave1_r_rdata),32);
        tracep->chgCData(oldp+217,(vlTOPp->io_writeSlave1_r_rresp),2);
        tracep->chgBit(oldp+218,(vlTOPp->io_writeSlave1_r_rlast));
        tracep->chgBit(oldp+219,(vlTOPp->io_writeSlave1_r_rvalid));
        tracep->chgBit(oldp+220,(vlTOPp->io_writeSlave1_r_rready));
        tracep->chgCData(oldp+221,(vlTOPp->io_writeSlave2_aw_awid),4);
        tracep->chgIData(oldp+222,(vlTOPp->io_writeSlave2_aw_awaddr),32);
        tracep->chgCData(oldp+223,(vlTOPp->io_writeSlave2_aw_awlen),8);
        tracep->chgCData(oldp+224,(vlTOPp->io_writeSlave2_aw_awsize),3);
        tracep->chgCData(oldp+225,(vlTOPp->io_writeSlave2_aw_awburst),2);
        tracep->chgBit(oldp+226,(vlTOPp->io_writeSlave2_aw_awlock));
        tracep->chgCData(oldp+227,(vlTOPp->io_writeSlave2_aw_awcache),4);
        tracep->chgCData(oldp+228,(vlTOPp->io_writeSlave2_aw_awprot),3);
        tracep->chgCData(oldp+229,(vlTOPp->io_writeSlave2_aw_awqos),4);
        tracep->chgBit(oldp+230,(vlTOPp->io_writeSlave2_aw_awvalid));
        tracep->chgBit(oldp+231,(vlTOPp->io_writeSlave2_aw_awready));
        tracep->chgIData(oldp+232,(vlTOPp->io_writeSlave2_w_wdata),32);
        tracep->chgCData(oldp+233,(vlTOPp->io_writeSlave2_w_wstrb),4);
        tracep->chgBit(oldp+234,(vlTOPp->io_writeSlave2_w_wlast));
        tracep->chgBit(oldp+235,(vlTOPp->io_writeSlave2_w_wvalid));
        tracep->chgBit(oldp+236,(vlTOPp->io_writeSlave2_w_wready));
        tracep->chgCData(oldp+237,(vlTOPp->io_writeSlave2_b_bid),4);
        tracep->chgCData(oldp+238,(vlTOPp->io_writeSlave2_b_bresp),2);
        tracep->chgBit(oldp+239,(vlTOPp->io_writeSlave2_b_bvalid));
        tracep->chgBit(oldp+240,(vlTOPp->io_writeSlave2_b_bready));
        tracep->chgCData(oldp+241,(vlTOPp->io_writeSlave2_ar_arid),4);
        tracep->chgIData(oldp+242,(vlTOPp->io_writeSlave2_ar_araddr),32);
        tracep->chgCData(oldp+243,(vlTOPp->io_writeSlave2_ar_arlen),8);
        tracep->chgCData(oldp+244,(vlTOPp->io_writeSlave2_ar_arsize),3);
        tracep->chgCData(oldp+245,(vlTOPp->io_writeSlave2_ar_arburst),2);
        tracep->chgBit(oldp+246,(vlTOPp->io_writeSlave2_ar_arlock));
        tracep->chgCData(oldp+247,(vlTOPp->io_writeSlave2_ar_arcache),4);
        tracep->chgCData(oldp+248,(vlTOPp->io_writeSlave2_ar_arprot),3);
        tracep->chgCData(oldp+249,(vlTOPp->io_writeSlave2_ar_arqos),4);
        tracep->chgBit(oldp+250,(vlTOPp->io_writeSlave2_ar_arvalid));
        tracep->chgBit(oldp+251,(vlTOPp->io_writeSlave2_ar_arready));
        tracep->chgCData(oldp+252,(vlTOPp->io_writeSlave2_r_rid),4);
        tracep->chgIData(oldp+253,(vlTOPp->io_writeSlave2_r_rdata),32);
        tracep->chgCData(oldp+254,(vlTOPp->io_writeSlave2_r_rresp),2);
        tracep->chgBit(oldp+255,(vlTOPp->io_writeSlave2_r_rlast));
        tracep->chgBit(oldp+256,(vlTOPp->io_writeSlave2_r_rvalid));
        tracep->chgBit(oldp+257,(vlTOPp->io_writeSlave2_r_rready));
        tracep->chgBit(oldp+258,(vlTOPp->io_irq_readerDone));
        tracep->chgBit(oldp+259,(vlTOPp->io_irq_writerDone));
        tracep->chgBit(oldp+260,(vlTOPp->io_sync_readerSync));
        tracep->chgBit(oldp+261,(vlTOPp->io_sync_writerSync));
        tracep->chgBit(oldp+262,(((IData)(vlTOPp->io_writeSlave2_w_wready) 
                                  & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable))));
        tracep->chgIData(oldp+263,((((0U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+264,((((2U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+265,((((3U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+266,((((4U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+267,((((5U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+268,((((6U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+269,((((7U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+270,((((8U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+271,((((9U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+272,((((0xaU == (0xfU 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+273,((((0xbU == (0xfU 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+274,((((0xeU == (0xfU 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
        tracep->chgIData(oldp+275,((((0xfU == (0xfU 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                     ? vlTOPp->io_control_w_wdata
                                     : 0U)),32);
    }
}

void VDMATopAXI_AXIL_AXI::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
