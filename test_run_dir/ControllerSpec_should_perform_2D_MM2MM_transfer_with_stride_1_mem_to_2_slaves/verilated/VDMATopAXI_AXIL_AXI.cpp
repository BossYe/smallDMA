// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDMATopAXI_AXIL_AXI.h for the primary calling header

#include "VDMATopAXI_AXIL_AXI.h"
#include "VDMATopAXI_AXIL_AXI__Syms.h"

//==========

void VDMATopAXI_AXIL_AXI::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDMATopAXI_AXIL_AXI::eval\n"); );
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DMATopAXI_AXIL_AXI.sv", 2311, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDMATopAXI_AXIL_AXI::_eval_initial_loop(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DMATopAXI_AXIL_AXI.sv", 2311, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDMATopAXI_AXIL_AXI::_sequent__TOP__2(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_sequent__TOP__2\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state;
    CData/*0:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state;
    CData/*0:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState;
    CData/*0:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state;
    CData/*1:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state;
    CData/*0:0*/ __Vdlyvset__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0;
    SData/*8:0*/ __Vdlyvdim0__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0;
    IData/*31:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i;
    IData/*31:0*/ __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i;
    IData/*31:0*/ __Vdlyvval__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0;
    // Body
    __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state;
    __Vdlyvset__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0 = 0U;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState;
    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_ = 0U;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_ = 0x10U;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen 
        = (0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26);
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full = 0U;
    } else {
        if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq) 
             != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_ = 0U;
    } else {
        if (((0xeU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_ 
                = (((0xeU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_ = 0U;
    } else {
        if (((0xfU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_ 
                = (((0xfU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_ = 0U;
    } else {
        if (((4U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_ 
                = (((4U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_ = 0U;
    } else {
        if (((8U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_ 
                = (((8U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
        = ((IData)(vlTOPp->reset) ? 0U : (((3U == (0xfU 
                                                   & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                           ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_2
                                           : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_3));
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value = 0U;
    } else {
        if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_3;
        }
    }
    if (((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
         & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid))) {
        __Vdlyvval__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0 
            = vlTOPp->io_readMem_r_rdata;
        __Vdlyvset__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0 = 1U;
        __Vdlyvdim0__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq 
        = ((~ (IData)(vlTOPp->reset)) & (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld) 
                                          & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy))) 
                                         & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq 
        = ((~ (IData)(vlTOPp->reset)) & (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld) 
                                          & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy))) 
                                         & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_ 
                                            >> 1U)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_ 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status;
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4;
                }
            } else {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState 
                    = ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))
                        ? (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_12)
                        : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_14));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                if ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_13;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_2;
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_6;
                }
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_11;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid) 
                     & (IData)(vlTOPp->io_readMem_ar_arready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state = 2U;
                }
            } else {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state 
                    = ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))
                        ? (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_9)
                        : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_12));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                if ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_11;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_6;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_10;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_o;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
            __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_1;
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid) 
                     & (IData)(vlTOPp->io_readMem_ar_arready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid) 
                     & (IData)(vlTOPp->io_writeSlave2_aw_awready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState = 2U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_34;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen 
                    = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o 
                       - (IData)(1U));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o;
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
            __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_30;
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState))) {
                if (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid) 
                     & (IData)(vlTOPp->io_writeSlave2_aw_awready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid = 0U;
                }
            }
        }
    }
    if (__Vdlyvset__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram[__Vdlyvdim0__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0] 
            = __Vdlyvval__DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram__v0;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    vlTOPp->io_readMem_ar_arlen = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen;
    vlTOPp->io_irq_readerDone = (1U & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
                                       >> 1U));
    vlTOPp->io_irq_writerDone = (1U & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_);
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_3 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram
        [vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value];
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value = 0U;
    } else {
        if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_1;
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq) 
            << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq));
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_ = 0U;
    } else {
        if (((2U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_ 
                = (((2U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy) 
            << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_14 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState))
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_13 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done));
    vlTOPp->io_writeSlave1_b_bready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready;
    vlTOPp->io_writeSlave2_b_bready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready;
    vlTOPp->io_writeSlave1_w_wlast = (1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length);
    vlTOPp->io_writeSlave2_w_wlast = (1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length);
    if ((1U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length)) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3 
            = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length 
               - (IData)(1U));
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState;
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_3 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_4 = 2U;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_6 
        = ((1U >= vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_5 
        = ((1U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    vlTOPp->io_readMem_ar_araddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr;
    vlTOPp->io_readMem_ar_arvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_12 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_11 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done));
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i 
                    = ((8U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i)
                        ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___length_i_T_1
                        : 0U);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_o 
                    = ((8U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i)
                        ? 8U : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_10;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_17;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_9;
                }
            }
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_34 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done)
            ? 0U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState));
    vlTOPp->io_writeSlave1_aw_awlen = (0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen);
    vlTOPp->io_writeSlave2_aw_awlen = (0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen);
    vlTOPp->io_writeSlave1_aw_awaddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr;
    vlTOPp->io_writeSlave2_aw_awaddr = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr;
    vlTOPp->io_writeSlave1_aw_awvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    vlTOPp->io_writeSlave2_aw_awvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid;
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
                    = ((0x10U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i)
                        ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___length_i_T_1
                        : 0U);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o 
                    = ((0x10U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i)
                        ? 0x10U : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i);
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done = 0U;
        } else {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_10;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_17;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_9;
                }
            }
        }
    }
    vlTOPp->io_writeSlave1_w_wdata = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data;
    vlTOPp->io_writeSlave2_w_wdata = vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT___reg_T_3 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT___value_T_1 
        = (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value) 
           == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_1 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_17 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___length_i_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i 
           - (IData)(8U));
    if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_9 
            = ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i)
                ? 1U : 0U);
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_10 
            = ((0U >= vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i) 
               | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done));
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_9 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_10 
            = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done;
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i 
        = (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_35);
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_8;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___lineCount_T_1;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_12;
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy 
        = ((~ (IData)(vlTOPp->reset)) & (0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state)));
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
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___length_i_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i 
           - (IData)(0x10U));
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
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i 
        = (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35);
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_8;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___lineCount_T_1;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            if (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_12;
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy 
        = ((~ (IData)(vlTOPp->reset)) & (0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match) 
           & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    vlTOPp->io_readMem_r_rready = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___lineCount_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount 
           - (IData)(1U));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_12 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_8 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__done)
            ? ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount)
                ? 1U : 0U) : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i 
        = (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29);
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_ = 0U;
    } else {
        if (((6U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_ 
                = (((6U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_ = 0U;
    } else {
        if (((7U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_ 
                = (((7U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_ = 0U;
    } else {
        if (((5U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_ 
                = (((5U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart 
        = (1U & ((~ (IData)(vlTOPp->reset)) & ((((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld)) 
                                                 & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync)) 
                                                | (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                                   >> 3U)) 
                                               & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                                  >> 1U))));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___lineCount_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount 
           - (IData)(1U));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_12 
        = ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state)) 
           | ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state)) 
              & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_8 
        = ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done)
            ? ((0U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount)
                ? 1U : 0U) : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i 
        = (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29);
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_ = 0U;
    } else {
        if (((0xaU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_ 
                = (((0xaU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_ = 0U;
    } else {
        if (((0xbU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_ 
                = (((0xbU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_ = 0U;
    } else {
        if (((9U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_ 
                = (((9U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                    & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                    ? vlTOPp->io_control_w_wdata : 0U);
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart 
        = (1U & ((~ (IData)(vlTOPp->reset)) & ((((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld)) 
                                                 & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync)) 
                                                | (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                                   >> 2U)) 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld 
        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync;
    vlTOPp->io_writeSlave1_w_wvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid;
    vlTOPp->io_writeSlave2_w_wvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync 
        = vlTOPp->io_sync_readerSync;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync 
        = vlTOPp->io_sync_writerSync;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
        = ((IData)(vlTOPp->reset) ? 0U : (((0U == (0xfU 
                                                   & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                           ? (((0U 
                                                == 
                                                (0xfU 
                                                 & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                               & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                               ? vlTOPp->io_control_w_wdata
                                               : 0U)
                                           : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT___reg_T_1));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT___reg_T_1 
        = (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
           & (~ ((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                   << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                 & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                       >> 4U)))));
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if (vlTOPp->io_control_aw_awvalid) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state = 3U;
            } else {
                if (vlTOPp->io_control_ar_arvalid) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state = 1U;
                }
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                if (((IData)(vlTOPp->io_control_ar_arvalid) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state = 2U;
                }
            } else {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state 
                    = ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
                        ? (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_10)
                        : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_25));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready 
                = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_5;
        } else {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                if ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_26;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                if ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_27;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if ((1U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                if ((2U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_28;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if ((1U & (~ (IData)(vlTOPp->io_control_aw_awvalid)))) {
                __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_2;
            }
        } else {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                if (((IData)(vlTOPp->io_control_ar_arvalid) 
                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready))) {
                    __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid 
                    = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_9;
            } else {
                if ((2U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid 
                        = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_11;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))) {
            if (vlTOPp->io_control_aw_awvalid) {
                vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr 
                    = (0xfU & (vlTOPp->io_control_aw_awaddr 
                               >> 2U));
            } else {
                if (vlTOPp->io_control_ar_arvalid) {
                    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr 
                        = (0xfU & (vlTOPp->io_control_ar_araddr 
                                   >> 2U));
                }
            }
        }
    }
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state 
        = __Vdly__DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state;
    vlTOPp->io_control_ar_arready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready;
    vlTOPp->io_control_b_bvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid;
    vlTOPp->io_control_aw_awready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready;
    vlTOPp->io_control_w_wready = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready;
    vlTOPp->io_control_r_rvalid = vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid;
}

VL_INLINE_OPT void VDMATopAXI_AXIL_AXI::_combo__TOP__4(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_combo__TOP__4\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_11 
        = ((~ ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready) 
               & (IData)(vlTOPp->io_writeSlave2_b_bvalid))) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT___GEN_12 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready) 
            & (IData)(vlTOPp->io_writeSlave2_b_bvalid))
            ? 3U : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready 
        = ((IData)(vlTOPp->io_writeSlave2_w_wready) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_6 
        = (((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid) 
            & (IData)(vlTOPp->io_readMem_ar_arready)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid 
        = ((IData)(vlTOPp->io_readMem_r_rvalid) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT___GEN_26 
        = ((IData)(vlTOPp->reset) ? 0U : ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state))
                                           ? ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__valid)
                                               ? (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_o 
                                                  - (IData)(1U))
                                               : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen))
                                           : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen)));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq 
        = (((IData)(vlTOPp->io_writeSlave2_w_wready) 
            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable)) 
           & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)));
    if (vlTOPp->reset) {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_35 = 0ULL;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT___GEN_35 = 0ULL;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT___GEN_29 = 0ULL;
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT___GEN_29 = 0ULL;
    } else {
        vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT___GEN_35 
            = (0x7ffffffffULL & ((0U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))
                                  ? (QData)((IData)(
                                                    ((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid)
                                                      ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o
                                                      : vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i)))
                                  : ((1U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__state))
                                      ? ((8U < vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i)
                                          ? (QData)((IData)(
                                                            ((IData)(0x20U) 
                                                             + vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i)))
                                          : ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i)) 
                                             + ((QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__length_i)) 
                                                << 2U)))
                                      : (QData)((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterRead__DOT__address_i)))));
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
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_2 
        = ((IData)(vlTOPp->io_control_ar_arvalid) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_5 
        = ((IData)(vlTOPp->io_control_aw_awvalid) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_26 
        = ((3U == (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state))
            ? ((~ ((IData)(vlTOPp->io_control_aw_awvalid) 
                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready))) 
               & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready))
            : (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T 
        = ((IData)(vlTOPp->io_control_w_wvalid) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___GEN_9 
        = (((IData)(vlTOPp->io_control_ar_arvalid) 
            & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready)) 
           | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T 
        = ((IData)(vlTOPp->io_control_r_rready) & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
    vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq 
        = ((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
           & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid));
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
}

void VDMATopAXI_AXIL_AXI::_eval(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_eval\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VDMATopAXI_AXIL_AXI::_change_request(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_change_request\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDMATopAXI_AXIL_AXI::_change_request_1(VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_change_request_1\n"); );
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VDMATopAXI_AXIL_AXI::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDMATopAXI_AXIL_AXI::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_control_aw_awprot & 0xf8U))) {
        Verilated::overWidthError("io_control_aw_awprot");}
    if (VL_UNLIKELY((io_control_aw_awvalid & 0xfeU))) {
        Verilated::overWidthError("io_control_aw_awvalid");}
    if (VL_UNLIKELY((io_control_w_wstrb & 0xf0U))) {
        Verilated::overWidthError("io_control_w_wstrb");}
    if (VL_UNLIKELY((io_control_w_wvalid & 0xfeU))) {
        Verilated::overWidthError("io_control_w_wvalid");}
    if (VL_UNLIKELY((io_control_b_bready & 0xfeU))) {
        Verilated::overWidthError("io_control_b_bready");}
    if (VL_UNLIKELY((io_control_ar_arprot & 0xf8U))) {
        Verilated::overWidthError("io_control_ar_arprot");}
    if (VL_UNLIKELY((io_control_ar_arvalid & 0xfeU))) {
        Verilated::overWidthError("io_control_ar_arvalid");}
    if (VL_UNLIKELY((io_control_r_rready & 0xfeU))) {
        Verilated::overWidthError("io_control_r_rready");}
    if (VL_UNLIKELY((io_readMem_aw_awready & 0xfeU))) {
        Verilated::overWidthError("io_readMem_aw_awready");}
    if (VL_UNLIKELY((io_readMem_w_wready & 0xfeU))) {
        Verilated::overWidthError("io_readMem_w_wready");}
    if (VL_UNLIKELY((io_readMem_b_bid & 0xf0U))) {
        Verilated::overWidthError("io_readMem_b_bid");}
    if (VL_UNLIKELY((io_readMem_b_bresp & 0xfcU))) {
        Verilated::overWidthError("io_readMem_b_bresp");}
    if (VL_UNLIKELY((io_readMem_b_bvalid & 0xfeU))) {
        Verilated::overWidthError("io_readMem_b_bvalid");}
    if (VL_UNLIKELY((io_readMem_ar_arready & 0xfeU))) {
        Verilated::overWidthError("io_readMem_ar_arready");}
    if (VL_UNLIKELY((io_readMem_r_rid & 0xf0U))) {
        Verilated::overWidthError("io_readMem_r_rid");}
    if (VL_UNLIKELY((io_readMem_r_rresp & 0xfcU))) {
        Verilated::overWidthError("io_readMem_r_rresp");}
    if (VL_UNLIKELY((io_readMem_r_rlast & 0xfeU))) {
        Verilated::overWidthError("io_readMem_r_rlast");}
    if (VL_UNLIKELY((io_readMem_r_rvalid & 0xfeU))) {
        Verilated::overWidthError("io_readMem_r_rvalid");}
    if (VL_UNLIKELY((io_writeSlave1_aw_awready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_aw_awready");}
    if (VL_UNLIKELY((io_writeSlave1_w_wready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_w_wready");}
    if (VL_UNLIKELY((io_writeSlave1_b_bid & 0xf0U))) {
        Verilated::overWidthError("io_writeSlave1_b_bid");}
    if (VL_UNLIKELY((io_writeSlave1_b_bresp & 0xfcU))) {
        Verilated::overWidthError("io_writeSlave1_b_bresp");}
    if (VL_UNLIKELY((io_writeSlave1_b_bvalid & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_b_bvalid");}
    if (VL_UNLIKELY((io_writeSlave1_ar_arready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_ar_arready");}
    if (VL_UNLIKELY((io_writeSlave1_r_rid & 0xf0U))) {
        Verilated::overWidthError("io_writeSlave1_r_rid");}
    if (VL_UNLIKELY((io_writeSlave1_r_rresp & 0xfcU))) {
        Verilated::overWidthError("io_writeSlave1_r_rresp");}
    if (VL_UNLIKELY((io_writeSlave1_r_rlast & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_r_rlast");}
    if (VL_UNLIKELY((io_writeSlave1_r_rvalid & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave1_r_rvalid");}
    if (VL_UNLIKELY((io_writeSlave2_aw_awready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_aw_awready");}
    if (VL_UNLIKELY((io_writeSlave2_w_wready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_w_wready");}
    if (VL_UNLIKELY((io_writeSlave2_b_bid & 0xf0U))) {
        Verilated::overWidthError("io_writeSlave2_b_bid");}
    if (VL_UNLIKELY((io_writeSlave2_b_bresp & 0xfcU))) {
        Verilated::overWidthError("io_writeSlave2_b_bresp");}
    if (VL_UNLIKELY((io_writeSlave2_b_bvalid & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_b_bvalid");}
    if (VL_UNLIKELY((io_writeSlave2_ar_arready & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_ar_arready");}
    if (VL_UNLIKELY((io_writeSlave2_r_rid & 0xf0U))) {
        Verilated::overWidthError("io_writeSlave2_r_rid");}
    if (VL_UNLIKELY((io_writeSlave2_r_rresp & 0xfcU))) {
        Verilated::overWidthError("io_writeSlave2_r_rresp");}
    if (VL_UNLIKELY((io_writeSlave2_r_rlast & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_r_rlast");}
    if (VL_UNLIKELY((io_writeSlave2_r_rvalid & 0xfeU))) {
        Verilated::overWidthError("io_writeSlave2_r_rvalid");}
    if (VL_UNLIKELY((io_sync_readerSync & 0xfeU))) {
        Verilated::overWidthError("io_sync_readerSync");}
    if (VL_UNLIKELY((io_sync_writerSync & 0xfeU))) {
        Verilated::overWidthError("io_sync_writerSync");}
}
#endif  // VL_DEBUG
