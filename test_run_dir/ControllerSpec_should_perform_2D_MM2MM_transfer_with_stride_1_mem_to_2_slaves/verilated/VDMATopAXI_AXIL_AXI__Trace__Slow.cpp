// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VDMATopAXI_AXIL_AXI__Syms.h"


//======================

void VDMATopAXI_AXIL_AXI::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VDMATopAXI_AXIL_AXI::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VDMATopAXI_AXIL_AXI::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VDMATopAXI_AXIL_AXI::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VDMATopAXI_AXIL_AXI::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+120,"clock", false,-1);
        tracep->declBit(c+121,"reset", false,-1);
        tracep->declBus(c+122,"io_control_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+123,"io_control_aw_awprot", false,-1, 2,0);
        tracep->declBit(c+124,"io_control_aw_awvalid", false,-1);
        tracep->declBit(c+125,"io_control_aw_awready", false,-1);
        tracep->declBus(c+126,"io_control_w_wdata", false,-1, 31,0);
        tracep->declBus(c+127,"io_control_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+128,"io_control_w_wvalid", false,-1);
        tracep->declBit(c+129,"io_control_w_wready", false,-1);
        tracep->declBus(c+130,"io_control_b_bresp", false,-1, 1,0);
        tracep->declBit(c+131,"io_control_b_bvalid", false,-1);
        tracep->declBit(c+132,"io_control_b_bready", false,-1);
        tracep->declBus(c+133,"io_control_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+134,"io_control_ar_arprot", false,-1, 2,0);
        tracep->declBit(c+135,"io_control_ar_arvalid", false,-1);
        tracep->declBit(c+136,"io_control_ar_arready", false,-1);
        tracep->declBus(c+137,"io_control_r_rdata", false,-1, 31,0);
        tracep->declBus(c+138,"io_control_r_rresp", false,-1, 1,0);
        tracep->declBit(c+139,"io_control_r_rvalid", false,-1);
        tracep->declBit(c+140,"io_control_r_rready", false,-1);
        tracep->declBus(c+141,"io_readMem_aw_awid", false,-1, 3,0);
        tracep->declBus(c+142,"io_readMem_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+143,"io_readMem_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+144,"io_readMem_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+145,"io_readMem_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+146,"io_readMem_aw_awlock", false,-1);
        tracep->declBus(c+147,"io_readMem_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+148,"io_readMem_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+149,"io_readMem_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+150,"io_readMem_aw_awvalid", false,-1);
        tracep->declBit(c+151,"io_readMem_aw_awready", false,-1);
        tracep->declBus(c+152,"io_readMem_w_wdata", false,-1, 31,0);
        tracep->declBus(c+153,"io_readMem_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+154,"io_readMem_w_wlast", false,-1);
        tracep->declBit(c+155,"io_readMem_w_wvalid", false,-1);
        tracep->declBit(c+156,"io_readMem_w_wready", false,-1);
        tracep->declBus(c+157,"io_readMem_b_bid", false,-1, 3,0);
        tracep->declBus(c+158,"io_readMem_b_bresp", false,-1, 1,0);
        tracep->declBit(c+159,"io_readMem_b_bvalid", false,-1);
        tracep->declBit(c+160,"io_readMem_b_bready", false,-1);
        tracep->declBus(c+161,"io_readMem_ar_arid", false,-1, 3,0);
        tracep->declBus(c+162,"io_readMem_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+163,"io_readMem_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+164,"io_readMem_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+165,"io_readMem_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+166,"io_readMem_ar_arlock", false,-1);
        tracep->declBus(c+167,"io_readMem_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+168,"io_readMem_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+169,"io_readMem_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+170,"io_readMem_ar_arvalid", false,-1);
        tracep->declBit(c+171,"io_readMem_ar_arready", false,-1);
        tracep->declBus(c+172,"io_readMem_r_rid", false,-1, 3,0);
        tracep->declBus(c+173,"io_readMem_r_rdata", false,-1, 31,0);
        tracep->declBus(c+174,"io_readMem_r_rresp", false,-1, 1,0);
        tracep->declBit(c+175,"io_readMem_r_rlast", false,-1);
        tracep->declBit(c+176,"io_readMem_r_rvalid", false,-1);
        tracep->declBit(c+177,"io_readMem_r_rready", false,-1);
        tracep->declBus(c+178,"io_writeSlave1_aw_awid", false,-1, 3,0);
        tracep->declBus(c+179,"io_writeSlave1_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+180,"io_writeSlave1_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+181,"io_writeSlave1_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+182,"io_writeSlave1_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+183,"io_writeSlave1_aw_awlock", false,-1);
        tracep->declBus(c+184,"io_writeSlave1_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+185,"io_writeSlave1_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+186,"io_writeSlave1_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+187,"io_writeSlave1_aw_awvalid", false,-1);
        tracep->declBit(c+188,"io_writeSlave1_aw_awready", false,-1);
        tracep->declBus(c+189,"io_writeSlave1_w_wdata", false,-1, 31,0);
        tracep->declBus(c+190,"io_writeSlave1_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+191,"io_writeSlave1_w_wlast", false,-1);
        tracep->declBit(c+192,"io_writeSlave1_w_wvalid", false,-1);
        tracep->declBit(c+193,"io_writeSlave1_w_wready", false,-1);
        tracep->declBus(c+194,"io_writeSlave1_b_bid", false,-1, 3,0);
        tracep->declBus(c+195,"io_writeSlave1_b_bresp", false,-1, 1,0);
        tracep->declBit(c+196,"io_writeSlave1_b_bvalid", false,-1);
        tracep->declBit(c+197,"io_writeSlave1_b_bready", false,-1);
        tracep->declBus(c+198,"io_writeSlave1_ar_arid", false,-1, 3,0);
        tracep->declBus(c+199,"io_writeSlave1_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+200,"io_writeSlave1_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+201,"io_writeSlave1_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+202,"io_writeSlave1_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+203,"io_writeSlave1_ar_arlock", false,-1);
        tracep->declBus(c+204,"io_writeSlave1_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+205,"io_writeSlave1_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+206,"io_writeSlave1_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+207,"io_writeSlave1_ar_arvalid", false,-1);
        tracep->declBit(c+208,"io_writeSlave1_ar_arready", false,-1);
        tracep->declBus(c+209,"io_writeSlave1_r_rid", false,-1, 3,0);
        tracep->declBus(c+210,"io_writeSlave1_r_rdata", false,-1, 31,0);
        tracep->declBus(c+211,"io_writeSlave1_r_rresp", false,-1, 1,0);
        tracep->declBit(c+212,"io_writeSlave1_r_rlast", false,-1);
        tracep->declBit(c+213,"io_writeSlave1_r_rvalid", false,-1);
        tracep->declBit(c+214,"io_writeSlave1_r_rready", false,-1);
        tracep->declBus(c+215,"io_writeSlave2_aw_awid", false,-1, 3,0);
        tracep->declBus(c+216,"io_writeSlave2_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+217,"io_writeSlave2_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+218,"io_writeSlave2_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+219,"io_writeSlave2_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+220,"io_writeSlave2_aw_awlock", false,-1);
        tracep->declBus(c+221,"io_writeSlave2_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+222,"io_writeSlave2_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+223,"io_writeSlave2_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+224,"io_writeSlave2_aw_awvalid", false,-1);
        tracep->declBit(c+225,"io_writeSlave2_aw_awready", false,-1);
        tracep->declBus(c+226,"io_writeSlave2_w_wdata", false,-1, 31,0);
        tracep->declBus(c+227,"io_writeSlave2_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+228,"io_writeSlave2_w_wlast", false,-1);
        tracep->declBit(c+229,"io_writeSlave2_w_wvalid", false,-1);
        tracep->declBit(c+230,"io_writeSlave2_w_wready", false,-1);
        tracep->declBus(c+231,"io_writeSlave2_b_bid", false,-1, 3,0);
        tracep->declBus(c+232,"io_writeSlave2_b_bresp", false,-1, 1,0);
        tracep->declBit(c+233,"io_writeSlave2_b_bvalid", false,-1);
        tracep->declBit(c+234,"io_writeSlave2_b_bready", false,-1);
        tracep->declBus(c+235,"io_writeSlave2_ar_arid", false,-1, 3,0);
        tracep->declBus(c+236,"io_writeSlave2_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+237,"io_writeSlave2_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+238,"io_writeSlave2_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+239,"io_writeSlave2_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+240,"io_writeSlave2_ar_arlock", false,-1);
        tracep->declBus(c+241,"io_writeSlave2_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+242,"io_writeSlave2_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+243,"io_writeSlave2_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+244,"io_writeSlave2_ar_arvalid", false,-1);
        tracep->declBit(c+245,"io_writeSlave2_ar_arready", false,-1);
        tracep->declBus(c+246,"io_writeSlave2_r_rid", false,-1, 3,0);
        tracep->declBus(c+247,"io_writeSlave2_r_rdata", false,-1, 31,0);
        tracep->declBus(c+248,"io_writeSlave2_r_rresp", false,-1, 1,0);
        tracep->declBit(c+249,"io_writeSlave2_r_rlast", false,-1);
        tracep->declBit(c+250,"io_writeSlave2_r_rvalid", false,-1);
        tracep->declBit(c+251,"io_writeSlave2_r_rready", false,-1);
        tracep->declBit(c+252,"io_irq_readerDone", false,-1);
        tracep->declBit(c+253,"io_irq_writerDone", false,-1);
        tracep->declBit(c+254,"io_sync_readerSync", false,-1);
        tracep->declBit(c+255,"io_sync_writerSync", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI reset", false,-1);
        tracep->declBus(c+122,"DMATopAXI_AXIL_AXI io_control_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+123,"DMATopAXI_AXIL_AXI io_control_aw_awprot", false,-1, 2,0);
        tracep->declBit(c+124,"DMATopAXI_AXIL_AXI io_control_aw_awvalid", false,-1);
        tracep->declBit(c+125,"DMATopAXI_AXIL_AXI io_control_aw_awready", false,-1);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI io_control_w_wdata", false,-1, 31,0);
        tracep->declBus(c+127,"DMATopAXI_AXIL_AXI io_control_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+128,"DMATopAXI_AXIL_AXI io_control_w_wvalid", false,-1);
        tracep->declBit(c+129,"DMATopAXI_AXIL_AXI io_control_w_wready", false,-1);
        tracep->declBus(c+130,"DMATopAXI_AXIL_AXI io_control_b_bresp", false,-1, 1,0);
        tracep->declBit(c+131,"DMATopAXI_AXIL_AXI io_control_b_bvalid", false,-1);
        tracep->declBit(c+132,"DMATopAXI_AXIL_AXI io_control_b_bready", false,-1);
        tracep->declBus(c+133,"DMATopAXI_AXIL_AXI io_control_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+134,"DMATopAXI_AXIL_AXI io_control_ar_arprot", false,-1, 2,0);
        tracep->declBit(c+135,"DMATopAXI_AXIL_AXI io_control_ar_arvalid", false,-1);
        tracep->declBit(c+136,"DMATopAXI_AXIL_AXI io_control_ar_arready", false,-1);
        tracep->declBus(c+137,"DMATopAXI_AXIL_AXI io_control_r_rdata", false,-1, 31,0);
        tracep->declBus(c+138,"DMATopAXI_AXIL_AXI io_control_r_rresp", false,-1, 1,0);
        tracep->declBit(c+139,"DMATopAXI_AXIL_AXI io_control_r_rvalid", false,-1);
        tracep->declBit(c+140,"DMATopAXI_AXIL_AXI io_control_r_rready", false,-1);
        tracep->declBus(c+141,"DMATopAXI_AXIL_AXI io_readMem_aw_awid", false,-1, 3,0);
        tracep->declBus(c+142,"DMATopAXI_AXIL_AXI io_readMem_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+143,"DMATopAXI_AXIL_AXI io_readMem_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+144,"DMATopAXI_AXIL_AXI io_readMem_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+145,"DMATopAXI_AXIL_AXI io_readMem_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+146,"DMATopAXI_AXIL_AXI io_readMem_aw_awlock", false,-1);
        tracep->declBus(c+147,"DMATopAXI_AXIL_AXI io_readMem_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+148,"DMATopAXI_AXIL_AXI io_readMem_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+149,"DMATopAXI_AXIL_AXI io_readMem_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+150,"DMATopAXI_AXIL_AXI io_readMem_aw_awvalid", false,-1);
        tracep->declBit(c+151,"DMATopAXI_AXIL_AXI io_readMem_aw_awready", false,-1);
        tracep->declBus(c+152,"DMATopAXI_AXIL_AXI io_readMem_w_wdata", false,-1, 31,0);
        tracep->declBus(c+153,"DMATopAXI_AXIL_AXI io_readMem_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+154,"DMATopAXI_AXIL_AXI io_readMem_w_wlast", false,-1);
        tracep->declBit(c+155,"DMATopAXI_AXIL_AXI io_readMem_w_wvalid", false,-1);
        tracep->declBit(c+156,"DMATopAXI_AXIL_AXI io_readMem_w_wready", false,-1);
        tracep->declBus(c+157,"DMATopAXI_AXIL_AXI io_readMem_b_bid", false,-1, 3,0);
        tracep->declBus(c+158,"DMATopAXI_AXIL_AXI io_readMem_b_bresp", false,-1, 1,0);
        tracep->declBit(c+159,"DMATopAXI_AXIL_AXI io_readMem_b_bvalid", false,-1);
        tracep->declBit(c+160,"DMATopAXI_AXIL_AXI io_readMem_b_bready", false,-1);
        tracep->declBus(c+161,"DMATopAXI_AXIL_AXI io_readMem_ar_arid", false,-1, 3,0);
        tracep->declBus(c+162,"DMATopAXI_AXIL_AXI io_readMem_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+163,"DMATopAXI_AXIL_AXI io_readMem_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+164,"DMATopAXI_AXIL_AXI io_readMem_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+165,"DMATopAXI_AXIL_AXI io_readMem_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+166,"DMATopAXI_AXIL_AXI io_readMem_ar_arlock", false,-1);
        tracep->declBus(c+167,"DMATopAXI_AXIL_AXI io_readMem_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+168,"DMATopAXI_AXIL_AXI io_readMem_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+169,"DMATopAXI_AXIL_AXI io_readMem_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+170,"DMATopAXI_AXIL_AXI io_readMem_ar_arvalid", false,-1);
        tracep->declBit(c+171,"DMATopAXI_AXIL_AXI io_readMem_ar_arready", false,-1);
        tracep->declBus(c+172,"DMATopAXI_AXIL_AXI io_readMem_r_rid", false,-1, 3,0);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI io_readMem_r_rdata", false,-1, 31,0);
        tracep->declBus(c+174,"DMATopAXI_AXIL_AXI io_readMem_r_rresp", false,-1, 1,0);
        tracep->declBit(c+175,"DMATopAXI_AXIL_AXI io_readMem_r_rlast", false,-1);
        tracep->declBit(c+176,"DMATopAXI_AXIL_AXI io_readMem_r_rvalid", false,-1);
        tracep->declBit(c+177,"DMATopAXI_AXIL_AXI io_readMem_r_rready", false,-1);
        tracep->declBus(c+178,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awid", false,-1, 3,0);
        tracep->declBus(c+179,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+180,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+181,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+182,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+183,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awlock", false,-1);
        tracep->declBus(c+184,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+185,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+186,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+187,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awvalid", false,-1);
        tracep->declBit(c+188,"DMATopAXI_AXIL_AXI io_writeSlave1_aw_awready", false,-1);
        tracep->declBus(c+189,"DMATopAXI_AXIL_AXI io_writeSlave1_w_wdata", false,-1, 31,0);
        tracep->declBus(c+190,"DMATopAXI_AXIL_AXI io_writeSlave1_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+191,"DMATopAXI_AXIL_AXI io_writeSlave1_w_wlast", false,-1);
        tracep->declBit(c+192,"DMATopAXI_AXIL_AXI io_writeSlave1_w_wvalid", false,-1);
        tracep->declBit(c+193,"DMATopAXI_AXIL_AXI io_writeSlave1_w_wready", false,-1);
        tracep->declBus(c+194,"DMATopAXI_AXIL_AXI io_writeSlave1_b_bid", false,-1, 3,0);
        tracep->declBus(c+195,"DMATopAXI_AXIL_AXI io_writeSlave1_b_bresp", false,-1, 1,0);
        tracep->declBit(c+196,"DMATopAXI_AXIL_AXI io_writeSlave1_b_bvalid", false,-1);
        tracep->declBit(c+197,"DMATopAXI_AXIL_AXI io_writeSlave1_b_bready", false,-1);
        tracep->declBus(c+198,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arid", false,-1, 3,0);
        tracep->declBus(c+199,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+200,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+201,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+202,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+203,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arlock", false,-1);
        tracep->declBus(c+204,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+205,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+206,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+207,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arvalid", false,-1);
        tracep->declBit(c+208,"DMATopAXI_AXIL_AXI io_writeSlave1_ar_arready", false,-1);
        tracep->declBus(c+209,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rid", false,-1, 3,0);
        tracep->declBus(c+210,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rdata", false,-1, 31,0);
        tracep->declBus(c+211,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rresp", false,-1, 1,0);
        tracep->declBit(c+212,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rlast", false,-1);
        tracep->declBit(c+213,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rvalid", false,-1);
        tracep->declBit(c+214,"DMATopAXI_AXIL_AXI io_writeSlave1_r_rready", false,-1);
        tracep->declBus(c+215,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awid", false,-1, 3,0);
        tracep->declBus(c+216,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+217,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awlen", false,-1, 7,0);
        tracep->declBus(c+218,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awsize", false,-1, 2,0);
        tracep->declBus(c+219,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awburst", false,-1, 1,0);
        tracep->declBit(c+220,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awlock", false,-1);
        tracep->declBus(c+221,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awcache", false,-1, 3,0);
        tracep->declBus(c+222,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awprot", false,-1, 2,0);
        tracep->declBus(c+223,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awqos", false,-1, 3,0);
        tracep->declBit(c+224,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awvalid", false,-1);
        tracep->declBit(c+225,"DMATopAXI_AXIL_AXI io_writeSlave2_aw_awready", false,-1);
        tracep->declBus(c+226,"DMATopAXI_AXIL_AXI io_writeSlave2_w_wdata", false,-1, 31,0);
        tracep->declBus(c+227,"DMATopAXI_AXIL_AXI io_writeSlave2_w_wstrb", false,-1, 3,0);
        tracep->declBit(c+228,"DMATopAXI_AXIL_AXI io_writeSlave2_w_wlast", false,-1);
        tracep->declBit(c+229,"DMATopAXI_AXIL_AXI io_writeSlave2_w_wvalid", false,-1);
        tracep->declBit(c+230,"DMATopAXI_AXIL_AXI io_writeSlave2_w_wready", false,-1);
        tracep->declBus(c+231,"DMATopAXI_AXIL_AXI io_writeSlave2_b_bid", false,-1, 3,0);
        tracep->declBus(c+232,"DMATopAXI_AXIL_AXI io_writeSlave2_b_bresp", false,-1, 1,0);
        tracep->declBit(c+233,"DMATopAXI_AXIL_AXI io_writeSlave2_b_bvalid", false,-1);
        tracep->declBit(c+234,"DMATopAXI_AXIL_AXI io_writeSlave2_b_bready", false,-1);
        tracep->declBus(c+235,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arid", false,-1, 3,0);
        tracep->declBus(c+236,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+237,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arlen", false,-1, 7,0);
        tracep->declBus(c+238,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arsize", false,-1, 2,0);
        tracep->declBus(c+239,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arburst", false,-1, 1,0);
        tracep->declBit(c+240,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arlock", false,-1);
        tracep->declBus(c+241,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arcache", false,-1, 3,0);
        tracep->declBus(c+242,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arprot", false,-1, 2,0);
        tracep->declBus(c+243,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arqos", false,-1, 3,0);
        tracep->declBit(c+244,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arvalid", false,-1);
        tracep->declBit(c+245,"DMATopAXI_AXIL_AXI io_writeSlave2_ar_arready", false,-1);
        tracep->declBus(c+246,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rid", false,-1, 3,0);
        tracep->declBus(c+247,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rdata", false,-1, 31,0);
        tracep->declBus(c+248,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rresp", false,-1, 1,0);
        tracep->declBit(c+249,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rlast", false,-1);
        tracep->declBit(c+250,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rvalid", false,-1);
        tracep->declBit(c+251,"DMATopAXI_AXIL_AXI io_writeSlave2_r_rready", false,-1);
        tracep->declBit(c+252,"DMATopAXI_AXIL_AXI io_irq_readerDone", false,-1);
        tracep->declBit(c+253,"DMATopAXI_AXIL_AXI io_irq_writerDone", false,-1);
        tracep->declBit(c+254,"DMATopAXI_AXIL_AXI io_sync_readerSync", false,-1);
        tracep->declBit(c+255,"DMATopAXI_AXIL_AXI io_sync_writerSync", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI csrFrontend_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI csrFrontend_reset", false,-1);
        tracep->declBus(c+122,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_aw_awaddr", false,-1, 31,0);
        tracep->declBit(c+124,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_aw_awvalid", false,-1);
        tracep->declBit(c+1,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_aw_awready", false,-1);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_w_wdata", false,-1, 31,0);
        tracep->declBit(c+128,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_w_wvalid", false,-1);
        tracep->declBit(c+2,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_w_wready", false,-1);
        tracep->declBit(c+3,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_b_bvalid", false,-1);
        tracep->declBit(c+132,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_b_bready", false,-1);
        tracep->declBus(c+133,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_ar_araddr", false,-1, 31,0);
        tracep->declBit(c+135,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_ar_arvalid", false,-1);
        tracep->declBit(c+4,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_ar_arready", false,-1);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_r_rdata", false,-1, 31,0);
        tracep->declBit(c+5,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_r_rvalid", false,-1);
        tracep->declBit(c+140,"DMATopAXI_AXIL_AXI csrFrontend_io_ctl_r_rready", false,-1);
        tracep->declBus(c+6,"DMATopAXI_AXIL_AXI csrFrontend_io_bus_addr", false,-1, 3,0);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csrFrontend_io_bus_dataOut", false,-1, 31,0);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csrFrontend_io_bus_dataIn", false,-1, 31,0);
        tracep->declBit(c+114,"DMATopAXI_AXIL_AXI csrFrontend_io_bus_write", false,-1);
        tracep->declBit(c+115,"DMATopAXI_AXIL_AXI csrFrontend_io_bus_read", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI readerFrontend_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI readerFrontend_reset", false,-1);
        tracep->declBus(c+7,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+8,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_ar_arlen", false,-1, 7,0);
        tracep->declBit(c+9,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_ar_arvalid", false,-1);
        tracep->declBit(c+171,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_ar_arready", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_r_rdata", false,-1, 31,0);
        tracep->declBit(c+175,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_r_rlast", false,-1);
        tracep->declBit(c+176,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_r_rvalid", false,-1);
        tracep->declBit(c+10,"DMATopAXI_AXIL_AXI readerFrontend_io_bus_r_rready", false,-1);
        tracep->declBit(c+11,"DMATopAXI_AXIL_AXI readerFrontend_io_dataIO_ready", false,-1);
        tracep->declBit(c+116,"DMATopAXI_AXIL_AXI readerFrontend_io_dataIO_valid", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI readerFrontend_io_dataIO_bits", false,-1, 31,0);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI readerFrontend_io_xfer_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI readerFrontend_io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI readerFrontend_io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI readerFrontend_io_xfer_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI writerFrontend_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI writerFrontend_reset", false,-1);
        tracep->declBus(c+16,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+17,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_aw_awlen", false,-1, 7,0);
        tracep->declBit(c+18,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_aw_awvalid", false,-1);
        tracep->declBit(c+225,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_aw_awready", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_w_wdata", false,-1, 31,0);
        tracep->declBit(c+20,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_w_wlast", false,-1);
        tracep->declBit(c+21,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_w_wvalid", false,-1);
        tracep->declBit(c+230,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_w_wready", false,-1);
        tracep->declBit(c+233,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_b_bvalid", false,-1);
        tracep->declBit(c+22,"DMATopAXI_AXIL_AXI writerFrontend_io_bus_b_bready", false,-1);
        tracep->declBit(c+256,"DMATopAXI_AXIL_AXI writerFrontend_io_dataIO_ready", false,-1);
        tracep->declBit(c+23,"DMATopAXI_AXIL_AXI writerFrontend_io_dataIO_valid", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI writerFrontend_io_dataIO_bits", false,-1, 31,0);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI writerFrontend_io_xfer_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI writerFrontend_io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI writerFrontend_io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI writerFrontend_io_xfer_valid", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI csr_io_csr_0_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI csr_io_csr_0_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI csr_io_csr_0_dataIn", false,-1, 31,0);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI csr_io_csr_1_dataIn", false,-1, 31,0);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI csr_io_csr_2_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI csr_io_csr_2_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI csr_io_csr_2_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI csr_io_csr_3_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI csr_io_csr_3_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI csr_io_csr_3_dataIn", false,-1, 31,0);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI csr_io_csr_4_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI csr_io_csr_4_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI csr_io_csr_4_dataIn", false,-1, 31,0);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI csr_io_csr_5_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI csr_io_csr_5_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI csr_io_csr_5_dataIn", false,-1, 31,0);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI csr_io_csr_6_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI csr_io_csr_6_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI csr_io_csr_6_dataIn", false,-1, 31,0);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI csr_io_csr_7_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI csr_io_csr_7_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI csr_io_csr_7_dataIn", false,-1, 31,0);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI csr_io_csr_8_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI csr_io_csr_8_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI csr_io_csr_8_dataIn", false,-1, 31,0);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI csr_io_csr_9_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI csr_io_csr_9_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI csr_io_csr_9_dataIn", false,-1, 31,0);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI csr_io_csr_10_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI csr_io_csr_10_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI csr_io_csr_10_dataIn", false,-1, 31,0);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI csr_io_csr_11_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI csr_io_csr_11_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI csr_io_csr_11_dataIn", false,-1, 31,0);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI csr_io_csr_12_dataIn", false,-1, 31,0);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI csr_io_csr_13_dataIn", false,-1, 31,0);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI csr_io_csr_14_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI csr_io_csr_14_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI csr_io_csr_14_dataIn", false,-1, 31,0);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI csr_io_csr_15_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI csr_io_csr_15_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI csr_io_csr_15_dataIn", false,-1, 31,0);
        tracep->declBus(c+6,"DMATopAXI_AXIL_AXI csr_io_bus_addr", false,-1, 3,0);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csr_io_bus_dataOut", false,-1, 31,0);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csr_io_bus_dataIn", false,-1, 31,0);
        tracep->declBit(c+114,"DMATopAXI_AXIL_AXI csr_io_bus_write", false,-1);
        tracep->declBit(c+115,"DMATopAXI_AXIL_AXI csr_io_bus_read", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl_reset", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI ctl_io_csr_0_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI ctl_io_csr_0_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl_io_csr_0_dataIn", false,-1, 31,0);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI ctl_io_csr_1_dataIn", false,-1, 31,0);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl_io_csr_2_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl_io_csr_2_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl_io_csr_2_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl_io_csr_3_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl_io_csr_3_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl_io_csr_3_dataIn", false,-1, 31,0);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI ctl_io_csr_4_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI ctl_io_csr_4_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl_io_csr_4_dataIn", false,-1, 31,0);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI ctl_io_csr_5_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI ctl_io_csr_5_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl_io_csr_5_dataIn", false,-1, 31,0);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI ctl_io_csr_6_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI ctl_io_csr_6_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl_io_csr_6_dataIn", false,-1, 31,0);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI ctl_io_csr_7_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI ctl_io_csr_7_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl_io_csr_7_dataIn", false,-1, 31,0);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI ctl_io_csr_8_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI ctl_io_csr_8_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl_io_csr_8_dataIn", false,-1, 31,0);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI ctl_io_csr_9_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI ctl_io_csr_9_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl_io_csr_9_dataIn", false,-1, 31,0);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI ctl_io_csr_10_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI ctl_io_csr_10_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl_io_csr_10_dataIn", false,-1, 31,0);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI ctl_io_csr_11_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI ctl_io_csr_11_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl_io_csr_11_dataIn", false,-1, 31,0);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI ctl_io_csr_12_dataIn", false,-1, 31,0);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI ctl_io_csr_13_dataIn", false,-1, 31,0);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI ctl_io_csr_14_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI ctl_io_csr_14_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl_io_csr_14_dataIn", false,-1, 31,0);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI ctl_io_csr_15_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI ctl_io_csr_15_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl_io_csr_15_dataIn", false,-1, 31,0);
        tracep->declBit(c+44,"DMATopAXI_AXIL_AXI ctl_io_irq_readerDone", false,-1);
        tracep->declBit(c+45,"DMATopAXI_AXIL_AXI ctl_io_irq_writerDone", false,-1);
        tracep->declBit(c+254,"DMATopAXI_AXIL_AXI ctl_io_sync_readerSync", false,-1);
        tracep->declBit(c+255,"DMATopAXI_AXIL_AXI ctl_io_sync_writerSync", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl_io_xferRead_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl_io_xferRead_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl_io_xferRead_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl_io_xferRead_valid", false,-1);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI ctl_io_xferWrite_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI ctl_io_xferWrite_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI ctl_io_xferWrite_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI ctl_io_xferWrite_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI queue_q_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI queue_q_reset", false,-1);
        tracep->declBit(c+11,"DMATopAXI_AXIL_AXI queue_q_io_enq_ready", false,-1);
        tracep->declBit(c+116,"DMATopAXI_AXIL_AXI queue_q_io_enq_valid", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI queue_q_io_enq_bits", false,-1, 31,0);
        tracep->declBit(c+256,"DMATopAXI_AXIL_AXI queue_q_io_deq_ready", false,-1);
        tracep->declBit(c+23,"DMATopAXI_AXIL_AXI queue_q_io_deq_valid", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI queue_q_io_deq_bits", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI csrFrontend clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI csrFrontend reset", false,-1);
        tracep->declBus(c+122,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_aw_awaddr", false,-1, 31,0);
        tracep->declBit(c+124,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_aw_awvalid", false,-1);
        tracep->declBit(c+1,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_aw_awready", false,-1);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_w_wdata", false,-1, 31,0);
        tracep->declBit(c+128,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_w_wvalid", false,-1);
        tracep->declBit(c+2,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_w_wready", false,-1);
        tracep->declBit(c+3,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_b_bvalid", false,-1);
        tracep->declBit(c+132,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_b_bready", false,-1);
        tracep->declBus(c+133,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_ar_araddr", false,-1, 31,0);
        tracep->declBit(c+135,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_ar_arvalid", false,-1);
        tracep->declBit(c+4,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_ar_arready", false,-1);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_r_rdata", false,-1, 31,0);
        tracep->declBit(c+5,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_r_rvalid", false,-1);
        tracep->declBit(c+140,"DMATopAXI_AXIL_AXI csrFrontend io_ctl_r_rready", false,-1);
        tracep->declBus(c+6,"DMATopAXI_AXIL_AXI csrFrontend io_bus_addr", false,-1, 3,0);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csrFrontend io_bus_dataOut", false,-1, 31,0);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csrFrontend io_bus_dataIn", false,-1, 31,0);
        tracep->declBit(c+114,"DMATopAXI_AXIL_AXI csrFrontend io_bus_write", false,-1);
        tracep->declBit(c+115,"DMATopAXI_AXIL_AXI csrFrontend io_bus_read", false,-1);
        tracep->declBus(c+46,"DMATopAXI_AXIL_AXI csrFrontend state", false,-1, 2,0);
        tracep->declBit(c+1,"DMATopAXI_AXIL_AXI csrFrontend awready", false,-1);
        tracep->declBit(c+2,"DMATopAXI_AXIL_AXI csrFrontend wready", false,-1);
        tracep->declBit(c+3,"DMATopAXI_AXIL_AXI csrFrontend bvalid", false,-1);
        tracep->declBit(c+4,"DMATopAXI_AXIL_AXI csrFrontend arready", false,-1);
        tracep->declBit(c+5,"DMATopAXI_AXIL_AXI csrFrontend rvalid", false,-1);
        tracep->declBus(c+47,"DMATopAXI_AXIL_AXI csrFrontend addr", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI readerFrontend clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI readerFrontend reset", false,-1);
        tracep->declBus(c+7,"DMATopAXI_AXIL_AXI readerFrontend io_bus_ar_araddr", false,-1, 31,0);
        tracep->declBus(c+8,"DMATopAXI_AXIL_AXI readerFrontend io_bus_ar_arlen", false,-1, 7,0);
        tracep->declBit(c+9,"DMATopAXI_AXIL_AXI readerFrontend io_bus_ar_arvalid", false,-1);
        tracep->declBit(c+171,"DMATopAXI_AXIL_AXI readerFrontend io_bus_ar_arready", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI readerFrontend io_bus_r_rdata", false,-1, 31,0);
        tracep->declBit(c+175,"DMATopAXI_AXIL_AXI readerFrontend io_bus_r_rlast", false,-1);
        tracep->declBit(c+176,"DMATopAXI_AXIL_AXI readerFrontend io_bus_r_rvalid", false,-1);
        tracep->declBit(c+10,"DMATopAXI_AXIL_AXI readerFrontend io_bus_r_rready", false,-1);
        tracep->declBit(c+11,"DMATopAXI_AXIL_AXI readerFrontend io_dataIO_ready", false,-1);
        tracep->declBit(c+116,"DMATopAXI_AXIL_AXI readerFrontend io_dataIO_valid", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI readerFrontend io_dataIO_bits", false,-1, 31,0);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI readerFrontend io_xfer_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI readerFrontend io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI readerFrontend io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI readerFrontend io_xfer_valid", false,-1);
        tracep->declBus(c+48,"DMATopAXI_AXIL_AXI readerFrontend state", false,-1, 1,0);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI readerFrontend done", false,-1);
        tracep->declBit(c+49,"DMATopAXI_AXIL_AXI readerFrontend enable", false,-1);
        tracep->declBus(c+7,"DMATopAXI_AXIL_AXI readerFrontend araddr", false,-1, 31,0);
        tracep->declBus(c+8,"DMATopAXI_AXIL_AXI readerFrontend arlen", false,-1, 7,0);
        tracep->declBit(c+9,"DMATopAXI_AXIL_AXI readerFrontend arvalid", false,-1);
        tracep->declBit(c+50,"DMATopAXI_AXIL_AXI readerFrontend ready", false,-1);
        tracep->declBit(c+116,"DMATopAXI_AXIL_AXI readerFrontend valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI writerFrontend clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI writerFrontend reset", false,-1);
        tracep->declBus(c+16,"DMATopAXI_AXIL_AXI writerFrontend io_bus_aw_awaddr", false,-1, 31,0);
        tracep->declBus(c+17,"DMATopAXI_AXIL_AXI writerFrontend io_bus_aw_awlen", false,-1, 7,0);
        tracep->declBit(c+18,"DMATopAXI_AXIL_AXI writerFrontend io_bus_aw_awvalid", false,-1);
        tracep->declBit(c+225,"DMATopAXI_AXIL_AXI writerFrontend io_bus_aw_awready", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI writerFrontend io_bus_w_wdata", false,-1, 31,0);
        tracep->declBit(c+20,"DMATopAXI_AXIL_AXI writerFrontend io_bus_w_wlast", false,-1);
        tracep->declBit(c+21,"DMATopAXI_AXIL_AXI writerFrontend io_bus_w_wvalid", false,-1);
        tracep->declBit(c+230,"DMATopAXI_AXIL_AXI writerFrontend io_bus_w_wready", false,-1);
        tracep->declBit(c+233,"DMATopAXI_AXIL_AXI writerFrontend io_bus_b_bvalid", false,-1);
        tracep->declBit(c+22,"DMATopAXI_AXIL_AXI writerFrontend io_bus_b_bready", false,-1);
        tracep->declBit(c+256,"DMATopAXI_AXIL_AXI writerFrontend io_dataIO_ready", false,-1);
        tracep->declBit(c+23,"DMATopAXI_AXIL_AXI writerFrontend io_dataIO_valid", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI writerFrontend io_dataIO_bits", false,-1, 31,0);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI writerFrontend io_xfer_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI writerFrontend io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI writerFrontend io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI writerFrontend io_xfer_valid", false,-1);
        tracep->declBus(c+51,"DMATopAXI_AXIL_AXI writerFrontend dataState", false,-1, 1,0);
        tracep->declBus(c+52,"DMATopAXI_AXIL_AXI writerFrontend addrState", false,-1, 1,0);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI writerFrontend done", false,-1);
        tracep->declBit(c+53,"DMATopAXI_AXIL_AXI writerFrontend enable", false,-1);
        tracep->declBus(c+54,"DMATopAXI_AXIL_AXI writerFrontend length", false,-1, 31,0);
        tracep->declBus(c+55,"DMATopAXI_AXIL_AXI writerFrontend awlen", false,-1, 31,0);
        tracep->declBus(c+16,"DMATopAXI_AXIL_AXI writerFrontend awaddr", false,-1, 31,0);
        tracep->declBit(c+18,"DMATopAXI_AXIL_AXI writerFrontend awvalid", false,-1);
        tracep->declBit(c+22,"DMATopAXI_AXIL_AXI writerFrontend bready", false,-1);
        tracep->declBit(c+117,"DMATopAXI_AXIL_AXI writerFrontend ready", false,-1);
        tracep->declBit(c+21,"DMATopAXI_AXIL_AXI writerFrontend valid", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI csr io_csr_0_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI csr io_csr_0_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI csr io_csr_0_dataIn", false,-1, 31,0);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI csr io_csr_1_dataIn", false,-1, 31,0);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI csr io_csr_2_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI csr io_csr_2_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI csr io_csr_2_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI csr io_csr_3_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI csr io_csr_3_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI csr io_csr_3_dataIn", false,-1, 31,0);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI csr io_csr_4_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI csr io_csr_4_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI csr io_csr_4_dataIn", false,-1, 31,0);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI csr io_csr_5_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI csr io_csr_5_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI csr io_csr_5_dataIn", false,-1, 31,0);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI csr io_csr_6_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI csr io_csr_6_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI csr io_csr_6_dataIn", false,-1, 31,0);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI csr io_csr_7_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI csr io_csr_7_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI csr io_csr_7_dataIn", false,-1, 31,0);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI csr io_csr_8_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI csr io_csr_8_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI csr io_csr_8_dataIn", false,-1, 31,0);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI csr io_csr_9_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI csr io_csr_9_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI csr io_csr_9_dataIn", false,-1, 31,0);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI csr io_csr_10_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI csr io_csr_10_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI csr io_csr_10_dataIn", false,-1, 31,0);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI csr io_csr_11_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI csr io_csr_11_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI csr io_csr_11_dataIn", false,-1, 31,0);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI csr io_csr_12_dataIn", false,-1, 31,0);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI csr io_csr_13_dataIn", false,-1, 31,0);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI csr io_csr_14_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI csr io_csr_14_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI csr io_csr_14_dataIn", false,-1, 31,0);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI csr io_csr_15_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI csr io_csr_15_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI csr io_csr_15_dataIn", false,-1, 31,0);
        tracep->declBus(c+6,"DMATopAXI_AXIL_AXI csr io_bus_addr", false,-1, 3,0);
        tracep->declBus(c+126,"DMATopAXI_AXIL_AXI csr io_bus_dataOut", false,-1, 31,0);
        tracep->declBus(c+99,"DMATopAXI_AXIL_AXI csr io_bus_dataIn", false,-1, 31,0);
        tracep->declBit(c+114,"DMATopAXI_AXIL_AXI csr io_bus_write", false,-1);
        tracep->declBit(c+115,"DMATopAXI_AXIL_AXI csr io_bus_read", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl reset", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI ctl io_csr_0_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI ctl io_csr_0_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl io_csr_0_dataIn", false,-1, 31,0);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI ctl io_csr_1_dataIn", false,-1, 31,0);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl io_csr_2_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl io_csr_2_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_csr_2_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl io_csr_3_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl io_csr_3_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_csr_3_dataIn", false,-1, 31,0);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI ctl io_csr_4_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI ctl io_csr_4_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl io_csr_4_dataIn", false,-1, 31,0);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI ctl io_csr_5_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI ctl io_csr_5_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl io_csr_5_dataIn", false,-1, 31,0);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI ctl io_csr_6_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI ctl io_csr_6_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl io_csr_6_dataIn", false,-1, 31,0);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI ctl io_csr_7_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI ctl io_csr_7_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl io_csr_7_dataIn", false,-1, 31,0);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI ctl io_csr_8_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI ctl io_csr_8_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl io_csr_8_dataIn", false,-1, 31,0);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI ctl io_csr_9_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI ctl io_csr_9_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl io_csr_9_dataIn", false,-1, 31,0);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI ctl io_csr_10_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI ctl io_csr_10_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl io_csr_10_dataIn", false,-1, 31,0);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI ctl io_csr_11_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI ctl io_csr_11_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl io_csr_11_dataIn", false,-1, 31,0);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI ctl io_csr_12_dataIn", false,-1, 31,0);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI ctl io_csr_13_dataIn", false,-1, 31,0);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI ctl io_csr_14_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI ctl io_csr_14_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl io_csr_14_dataIn", false,-1, 31,0);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI ctl io_csr_15_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI ctl io_csr_15_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl io_csr_15_dataIn", false,-1, 31,0);
        tracep->declBit(c+44,"DMATopAXI_AXIL_AXI ctl io_irq_readerDone", false,-1);
        tracep->declBit(c+45,"DMATopAXI_AXIL_AXI ctl io_irq_writerDone", false,-1);
        tracep->declBit(c+254,"DMATopAXI_AXIL_AXI ctl io_sync_readerSync", false,-1);
        tracep->declBit(c+255,"DMATopAXI_AXIL_AXI ctl io_sync_writerSync", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl io_xferRead_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl io_xferRead_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl io_xferRead_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl io_xferRead_valid", false,-1);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI ctl io_xferWrite_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI ctl io_xferWrite_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI ctl io_xferWrite_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI ctl io_xferWrite_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_reset", false,-1);
        tracep->declBit(c+56,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_start", false,-1);
        tracep->declBit(c+57,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_busy", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress", false,-1, 31,0);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength", false,-1, 31,0);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount", false,-1, 31,0);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap", false,-1, 31,0);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_xfer_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_xfer_valid", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferIn_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferIn_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferIn_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferIn_valid", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferOut_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferOut_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferOut_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl transferSplitterRead_io_xferOut_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_reset", false,-1);
        tracep->declBit(c+58,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_start", false,-1);
        tracep->declBit(c+59,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_busy", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress", false,-1, 31,0);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength", false,-1, 31,0);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount", false,-1, 31,0);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap", false,-1, 31,0);
        tracep->declBit(c+60,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_xfer_done", false,-1);
        tracep->declBus(c+61,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+62,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+63,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_xfer_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_reset", false,-1);
        tracep->declBit(c+60,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferIn_done", false,-1);
        tracep->declBus(c+61,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferIn_address", false,-1, 31,0);
        tracep->declBus(c+62,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferIn_length", false,-1, 31,0);
        tracep->declBit(c+63,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferIn_valid", false,-1);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferOut_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferOut_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferOut_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite_io_xferOut_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl control_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl control_csr_reset", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI ctl control_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI ctl control_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control_csr_io_value", false,-1, 31,0);
        tracep->declBus(c+64,"DMATopAXI_AXIL_AXI ctl control_csr_io_clear", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_clock", false,-1);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI ctl csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+65,"DMATopAXI_AXIL_AXI ctl csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_reset", false,-1);
        tracep->declBit(c+44,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_irq_readerDone", false,-1);
        tracep->declBit(c+45,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_irq_writerDone", false,-1);
        tracep->declBit(c+57,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_readBusy", false,-1);
        tracep->declBit(c+59,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_writeBusy", false,-1);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_imr_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_imr_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_imr_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_isr_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_isr_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc_io_isr_dataIn", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_reset", false,-1);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_reset", false,-1);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_reset", false,-1);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_reset", false,-1);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_reset", false,-1);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_reset", false,-1);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_reset", false,-1);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_reset", false,-1);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_1_clock", false,-1);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI ctl csr_1_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+270,"DMATopAXI_AXIL_AXI ctl csr_1_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_2_clock", false,-1);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI ctl csr_2_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+271,"DMATopAXI_AXIL_AXI ctl csr_2_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_3_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl csr_3_reset", false,-1);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI ctl csr_3_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI ctl csr_3_io_csr_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl csr_3_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl csr_3_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_4_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl csr_4_reset", false,-1);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI ctl csr_4_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI ctl csr_4_io_csr_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl csr_4_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl csr_4_io_value", false,-1, 31,0);
        tracep->declBus(c+66,"DMATopAXI_AXIL_AXI ctl status", false,-1, 1,0);
        tracep->declBit(c+67,"DMATopAXI_AXIL_AXI ctl readerSync", false,-1);
        tracep->declBit(c+68,"DMATopAXI_AXIL_AXI ctl readerSyncOld", false,-1);
        tracep->declBit(c+69,"DMATopAXI_AXIL_AXI ctl writerSync", false,-1);
        tracep->declBit(c+70,"DMATopAXI_AXIL_AXI ctl writerSyncOld", false,-1);
        tracep->declBit(c+56,"DMATopAXI_AXIL_AXI ctl readerStart", false,-1);
        tracep->declBit(c+58,"DMATopAXI_AXIL_AXI ctl writerStart", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control", false,-1, 31,0);
        tracep->declBus(c+71,"DMATopAXI_AXIL_AXI ctl clear", false,-1, 1,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead reset", false,-1);
        tracep->declBit(c+56,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_start", false,-1);
        tracep->declBit(c+57,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_busy", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_startAddress", false,-1, 31,0);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_lineLength", false,-1, 31,0);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_lineCount", false,-1, 31,0);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_ctl_lineGap", false,-1, 31,0);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_xfer_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead io_xfer_valid", false,-1);
        tracep->declBus(c+72,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead state", false,-1, 1,0);
        tracep->declBus(c+73,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead lineCount", false,-1, 31,0);
        tracep->declBus(c+74,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead lineGap", false,-1, 31,0);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead address_o", false,-1, 31,0);
        tracep->declBus(c+75,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead address_i", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead length_o", false,-1, 31,0);
        tracep->declBus(c+76,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead length_i", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead valid", false,-1);
        tracep->declBit(c+57,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead busy", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferIn_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferIn_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferIn_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferIn_valid", false,-1);
        tracep->declBit(c+12,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferOut_done", false,-1);
        tracep->declBus(c+13,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferOut_address", false,-1, 31,0);
        tracep->declBus(c+14,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferOut_length", false,-1, 31,0);
        tracep->declBit(c+15,"DMATopAXI_AXIL_AXI ctl transferSplitterRead io_xferOut_valid", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite reset", false,-1);
        tracep->declBit(c+58,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_start", false,-1);
        tracep->declBit(c+59,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_busy", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_startAddress", false,-1, 31,0);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_lineLength", false,-1, 31,0);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_lineCount", false,-1, 31,0);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_ctl_lineGap", false,-1, 31,0);
        tracep->declBit(c+60,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_xfer_done", false,-1);
        tracep->declBus(c+61,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_xfer_address", false,-1, 31,0);
        tracep->declBus(c+62,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_xfer_length", false,-1, 31,0);
        tracep->declBit(c+63,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite io_xfer_valid", false,-1);
        tracep->declBus(c+77,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite state", false,-1, 1,0);
        tracep->declBus(c+78,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite lineCount", false,-1, 31,0);
        tracep->declBus(c+79,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite lineGap", false,-1, 31,0);
        tracep->declBus(c+61,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite address_o", false,-1, 31,0);
        tracep->declBus(c+80,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite address_i", false,-1, 31,0);
        tracep->declBus(c+62,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite length_o", false,-1, 31,0);
        tracep->declBus(c+81,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite length_i", false,-1, 31,0);
        tracep->declBit(c+63,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite valid", false,-1);
        tracep->declBit(c+59,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite busy", false,-1);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite reset", false,-1);
        tracep->declBit(c+60,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferIn_done", false,-1);
        tracep->declBus(c+61,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferIn_address", false,-1, 31,0);
        tracep->declBus(c+62,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferIn_length", false,-1, 31,0);
        tracep->declBit(c+63,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferIn_valid", false,-1);
        tracep->declBit(c+24,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferOut_done", false,-1);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferOut_address", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferOut_length", false,-1, 31,0);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite io_xferOut_valid", false,-1);
        tracep->declBus(c+82,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite address_i", false,-1, 31,0);
        tracep->declBus(c+83,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite length_i", false,-1, 31,0);
        tracep->declBus(c+25,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite address_o", false,-1, 31,0);
        tracep->declBus(c+26,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite length_o", false,-1, 31,0);
        tracep->declBit(c+60,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite done", false,-1);
        tracep->declBit(c+27,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite valid", false,-1);
        tracep->declBus(c+84,"DMATopAXI_AXIL_AXI ctl transferSplitterWrite state", false,-1, 1,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl control_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl control_csr reset", false,-1);
        tracep->declBus(c+257,"DMATopAXI_AXIL_AXI ctl control_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+100,"DMATopAXI_AXIL_AXI ctl control_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control_csr io_value", false,-1, 31,0);
        tracep->declBus(c+64,"DMATopAXI_AXIL_AXI ctl control_csr io_clear", false,-1, 31,0);
        tracep->declBus(c+28,"DMATopAXI_AXIL_AXI ctl control_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr clock", false,-1);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI ctl csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+65,"DMATopAXI_AXIL_AXI ctl csr io_value", false,-1, 31,0);
        tracep->declBus(c+29,"DMATopAXI_AXIL_AXI ctl csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc reset", false,-1);
        tracep->declBit(c+44,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_irq_readerDone", false,-1);
        tracep->declBit(c+45,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_irq_writerDone", false,-1);
        tracep->declBit(c+57,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_readBusy", false,-1);
        tracep->declBit(c+59,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_writeBusy", false,-1);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_imr_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_imr_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_imr_dataIn", false,-1, 31,0);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_isr_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_isr_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc io_isr_dataIn", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_reset", false,-1);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr_io_value", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_reset", false,-1);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_io_csr_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_io_value", false,-1, 31,0);
        tracep->declBus(c+85,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr_io_set", false,-1, 31,0);
        tracep->declBit(c+86,"DMATopAXI_AXIL_AXI ctl io_irq_irqc readBusy", false,-1);
        tracep->declBit(c+87,"DMATopAXI_AXIL_AXI ctl io_irq_irqc readBusyOld", false,-1);
        tracep->declBit(c+88,"DMATopAXI_AXIL_AXI ctl io_irq_irqc writeBusy", false,-1);
        tracep->declBit(c+89,"DMATopAXI_AXIL_AXI ctl io_irq_irqc writeBusyOld", false,-1);
        tracep->declBit(c+90,"DMATopAXI_AXIL_AXI ctl io_irq_irqc writeBusyIrq", false,-1);
        tracep->declBit(c+91,"DMATopAXI_AXIL_AXI ctl io_irq_irqc readBusyIrq", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask", false,-1, 31,0);
        tracep->declBus(c+92,"DMATopAXI_AXIL_AXI ctl io_irq_irqc irq", false,-1, 1,0);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr reset", false,-1);
        tracep->declBus(c+258,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+101,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr io_value", false,-1, 31,0);
        tracep->declBus(c+30,"DMATopAXI_AXIL_AXI ctl io_irq_irqc mask_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr reset", false,-1);
        tracep->declBus(c+259,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+102,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr io_value", false,-1, 31,0);
        tracep->declBus(c+85,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr io_set", false,-1, 31,0);
        tracep->declBus(c+31,"DMATopAXI_AXIL_AXI ctl io_irq_irqc isr_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr reset", false,-1);
        tracep->declBus(c+260,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+103,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr io_value", false,-1, 31,0);
        tracep->declBus(c+32,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_startAddress_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr reset", false,-1);
        tracep->declBus(c+261,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+104,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr io_value", false,-1, 31,0);
        tracep->declBus(c+33,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineLength_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr reset", false,-1);
        tracep->declBus(c+262,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+105,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr io_value", false,-1, 31,0);
        tracep->declBus(c+34,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineCount_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr reset", false,-1);
        tracep->declBus(c+263,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+106,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr io_value", false,-1, 31,0);
        tracep->declBus(c+35,"DMATopAXI_AXIL_AXI ctl addressGeneratorRead_io_ctl_lineGap_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr reset", false,-1);
        tracep->declBus(c+264,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+107,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr io_value", false,-1, 31,0);
        tracep->declBus(c+36,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_startAddress_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr reset", false,-1);
        tracep->declBus(c+265,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+108,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr io_value", false,-1, 31,0);
        tracep->declBus(c+37,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineLength_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr reset", false,-1);
        tracep->declBus(c+266,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+109,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr io_value", false,-1, 31,0);
        tracep->declBus(c+38,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineCount_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr reset", false,-1);
        tracep->declBus(c+267,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+110,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr io_csr_dataWrite", false,-1);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr io_value", false,-1, 31,0);
        tracep->declBus(c+39,"DMATopAXI_AXIL_AXI ctl addressGeneratorWrite_io_ctl_lineGap_csr reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_1 clock", false,-1);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI ctl csr_1 io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+270,"DMATopAXI_AXIL_AXI ctl csr_1 io_value", false,-1, 31,0);
        tracep->declBus(c+40,"DMATopAXI_AXIL_AXI ctl csr_1 reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_2 clock", false,-1);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI ctl csr_2 io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+271,"DMATopAXI_AXIL_AXI ctl csr_2 io_value", false,-1, 31,0);
        tracep->declBus(c+41,"DMATopAXI_AXIL_AXI ctl csr_2 reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_3 clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl csr_3 reset", false,-1);
        tracep->declBus(c+268,"DMATopAXI_AXIL_AXI ctl csr_3 io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+111,"DMATopAXI_AXIL_AXI ctl csr_3 io_csr_dataWrite", false,-1);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl csr_3 io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl csr_3 io_value", false,-1, 31,0);
        tracep->declBus(c+42,"DMATopAXI_AXIL_AXI ctl csr_3 reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI ctl csr_4 clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI ctl csr_4 reset", false,-1);
        tracep->declBus(c+269,"DMATopAXI_AXIL_AXI ctl csr_4 io_csr_dataOut", false,-1, 31,0);
        tracep->declBit(c+112,"DMATopAXI_AXIL_AXI ctl csr_4 io_csr_dataWrite", false,-1);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl csr_4 io_csr_dataIn", false,-1, 31,0);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl csr_4 io_value", false,-1, 31,0);
        tracep->declBus(c+43,"DMATopAXI_AXIL_AXI ctl csr_4 reg_", false,-1, 31,0);
        tracep->declBit(c+120,"DMATopAXI_AXIL_AXI queue_q clock", false,-1);
        tracep->declBit(c+121,"DMATopAXI_AXIL_AXI queue_q reset", false,-1);
        tracep->declBit(c+11,"DMATopAXI_AXIL_AXI queue_q io_enq_ready", false,-1);
        tracep->declBit(c+116,"DMATopAXI_AXIL_AXI queue_q io_enq_valid", false,-1);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI queue_q io_enq_bits", false,-1, 31,0);
        tracep->declBit(c+256,"DMATopAXI_AXIL_AXI queue_q io_deq_ready", false,-1);
        tracep->declBit(c+23,"DMATopAXI_AXIL_AXI queue_q io_deq_valid", false,-1);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI queue_q io_deq_bits", false,-1, 31,0);
        tracep->declBit(c+272,"DMATopAXI_AXIL_AXI queue_q ram_io_deq_bits_MPORT_en", false,-1);
        tracep->declBus(c+93,"DMATopAXI_AXIL_AXI queue_q ram_io_deq_bits_MPORT_addr", false,-1, 8,0);
        tracep->declBus(c+19,"DMATopAXI_AXIL_AXI queue_q ram_io_deq_bits_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+173,"DMATopAXI_AXIL_AXI queue_q ram_MPORT_data", false,-1, 31,0);
        tracep->declBus(c+94,"DMATopAXI_AXIL_AXI queue_q ram_MPORT_addr", false,-1, 8,0);
        tracep->declBit(c+272,"DMATopAXI_AXIL_AXI queue_q ram_MPORT_mask", false,-1);
        tracep->declBit(c+113,"DMATopAXI_AXIL_AXI queue_q ram_MPORT_en", false,-1);
        tracep->declBus(c+94,"DMATopAXI_AXIL_AXI queue_q enq_ptr_value", false,-1, 8,0);
        tracep->declBus(c+93,"DMATopAXI_AXIL_AXI queue_q deq_ptr_value", false,-1, 8,0);
        tracep->declBit(c+95,"DMATopAXI_AXIL_AXI queue_q maybe_full", false,-1);
        tracep->declBit(c+96,"DMATopAXI_AXIL_AXI queue_q ptr_match", false,-1);
        tracep->declBit(c+97,"DMATopAXI_AXIL_AXI queue_q empty", false,-1);
        tracep->declBit(c+98,"DMATopAXI_AXIL_AXI queue_q full", false,-1);
        tracep->declBit(c+118,"DMATopAXI_AXIL_AXI queue_q do_enq", false,-1);
        tracep->declBit(c+119,"DMATopAXI_AXIL_AXI queue_q do_deq", false,-1);
    }
}

void VDMATopAXI_AXIL_AXI::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VDMATopAXI_AXIL_AXI::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VDMATopAXI_AXIL_AXI::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VDMATopAXI_AXIL_AXI__Syms* __restrict vlSymsp = static_cast<VDMATopAXI_AXIL_AXI__Syms*>(userp);
    VDMATopAXI_AXIL_AXI* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__awready));
        tracep->fullBit(oldp+2,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__wready));
        tracep->fullBit(oldp+3,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__bvalid));
        tracep->fullBit(oldp+4,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__arready));
        tracep->fullBit(oldp+5,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__rvalid));
        tracep->fullCData(oldp+6,((0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)),4);
        tracep->fullIData(oldp+7,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__araddr),32);
        tracep->fullCData(oldp+8,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arlen),8);
        tracep->fullBit(oldp+9,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__arvalid));
        tracep->fullBit(oldp+10,(((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                  & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable))));
        tracep->fullBit(oldp+11,((1U & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)))));
        tracep->fullBit(oldp+12,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__done));
        tracep->fullIData(oldp+13,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_o),32);
        tracep->fullIData(oldp+14,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_o),32);
        tracep->fullBit(oldp+15,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__valid));
        tracep->fullIData(oldp+16,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awaddr),32);
        tracep->fullCData(oldp+17,((0xffU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen)),8);
        tracep->fullBit(oldp+18,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awvalid));
        tracep->fullIData(oldp+19,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ram_io_deq_bits_MPORT_data),32);
        tracep->fullBit(oldp+20,((1U == vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length)));
        tracep->fullBit(oldp+21,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__valid));
        tracep->fullBit(oldp+22,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__bready));
        tracep->fullBit(oldp+23,((1U & (~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty)))));
        tracep->fullBit(oldp+24,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__done));
        tracep->fullIData(oldp+25,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_o),32);
        tracep->fullIData(oldp+26,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_o),32);
        tracep->fullBit(oldp+27,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__valid));
        tracep->fullIData(oldp+28,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_),32);
        tracep->fullIData(oldp+29,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr__DOT__reg_),32);
        tracep->fullIData(oldp+30,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__mask_csr__DOT__reg_),32);
        tracep->fullIData(oldp+31,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_),32);
        tracep->fullIData(oldp+32,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_startAddress_csr__DOT__reg_),32);
        tracep->fullIData(oldp+33,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineLength_csr__DOT__reg_),32);
        tracep->fullIData(oldp+34,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineCount_csr__DOT__reg_),32);
        tracep->fullIData(oldp+35,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead_io_ctl_lineGap_csr__DOT__reg_),32);
        tracep->fullIData(oldp+36,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_startAddress_csr__DOT__reg_),32);
        tracep->fullIData(oldp+37,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineLength_csr__DOT__reg_),32);
        tracep->fullIData(oldp+38,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineCount_csr__DOT__reg_),32);
        tracep->fullIData(oldp+39,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite_io_ctl_lineGap_csr__DOT__reg_),32);
        tracep->fullIData(oldp+40,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_1__DOT__reg_),32);
        tracep->fullIData(oldp+41,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_),32);
        tracep->fullIData(oldp+42,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_),32);
        tracep->fullIData(oldp+43,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_),32);
        tracep->fullBit(oldp+44,((1U & (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_ 
                                        >> 1U))));
        tracep->fullBit(oldp+45,((1U & vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__isr_csr__DOT__reg_)));
        tracep->fullCData(oldp+46,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__state),3);
        tracep->fullIData(oldp+47,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr),32);
        tracep->fullCData(oldp+48,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__state),2);
        tracep->fullBit(oldp+49,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__enable));
        tracep->fullBit(oldp+50,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__ready));
        tracep->fullCData(oldp+51,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__dataState),2);
        tracep->fullCData(oldp+52,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__addrState),2);
        tracep->fullBit(oldp+53,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable));
        tracep->fullIData(oldp+54,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__length),32);
        tracep->fullIData(oldp+55,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__awlen),32);
        tracep->fullBit(oldp+56,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart));
        tracep->fullBit(oldp+57,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__busy));
        tracep->fullBit(oldp+58,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart));
        tracep->fullBit(oldp+59,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__busy));
        tracep->fullBit(oldp+60,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__done));
        tracep->fullIData(oldp+61,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_o),32);
        tracep->fullIData(oldp+62,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_o),32);
        tracep->fullBit(oldp+63,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__valid));
        tracep->fullIData(oldp+64,(((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                                      << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                                    & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                          >> 4U)))),32);
        tracep->fullIData(oldp+65,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status),32);
        tracep->fullCData(oldp+66,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__status),2);
        tracep->fullBit(oldp+67,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSync));
        tracep->fullBit(oldp+68,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerSyncOld));
        tracep->fullBit(oldp+69,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSync));
        tracep->fullBit(oldp+70,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerSyncOld));
        tracep->fullCData(oldp+71,(((((IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__readerStart) 
                                      << 1U) | (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__writerStart)) 
                                    & (~ (vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__control_csr__DOT__reg_ 
                                          >> 4U)))),2);
        tracep->fullCData(oldp+72,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__state),2);
        tracep->fullIData(oldp+73,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineCount),32);
        tracep->fullIData(oldp+74,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__lineGap),32);
        tracep->fullIData(oldp+75,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__address_i),32);
        tracep->fullIData(oldp+76,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorRead__DOT__length_i),32);
        tracep->fullCData(oldp+77,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__state),2);
        tracep->fullIData(oldp+78,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineCount),32);
        tracep->fullIData(oldp+79,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__lineGap),32);
        tracep->fullIData(oldp+80,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__address_i),32);
        tracep->fullIData(oldp+81,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__addressGeneratorWrite__DOT__length_i),32);
        tracep->fullIData(oldp+82,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__address_i),32);
        tracep->fullIData(oldp+83,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__length_i),32);
        tracep->fullCData(oldp+84,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__transferSplitterWrite__DOT__state),2);
        tracep->fullIData(oldp+85,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq),32);
        tracep->fullBit(oldp+86,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusy));
        tracep->fullBit(oldp+87,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyOld));
        tracep->fullBit(oldp+88,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusy));
        tracep->fullBit(oldp+89,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyOld));
        tracep->fullBit(oldp+90,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__writeBusyIrq));
        tracep->fullBit(oldp+91,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__readBusyIrq));
        tracep->fullCData(oldp+92,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__io_irq_irqc__DOT__irq),2);
        tracep->fullSData(oldp+93,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__deq_ptr_value),9);
        tracep->fullSData(oldp+94,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__enq_ptr_value),9);
        tracep->fullBit(oldp+95,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__maybe_full));
        tracep->fullBit(oldp+96,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__ptr_match));
        tracep->fullBit(oldp+97,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__empty));
        tracep->fullBit(oldp+98,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full));
        tracep->fullIData(oldp+99,((((0xfU == (0xfU 
                                               & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                     & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                     ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_4__DOT__reg_
                                     : (((0xeU == (0xfU 
                                                   & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                         & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                         ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_3__DOT__reg_
                                         : (((0xdU 
                                              == (0xfU 
                                                  & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                             & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T))
                                             ? vlTOPp->DMATopAXI_AXIL_AXI__DOT__ctl__DOT__csr_2__DOT__reg_
                                             : (((0xcU 
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
        tracep->fullBit(oldp+100,(((0U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+101,(((2U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+102,(((3U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+103,(((4U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+104,(((5U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+105,(((6U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+106,(((7U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+107,(((8U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+108,(((9U == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+109,(((0xaU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+110,(((0xbU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+111,(((0xeU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+112,(((0xfU == (0xfU & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))));
        tracep->fullBit(oldp+113,(((~ (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__full)) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid))));
        tracep->fullBit(oldp+114,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T));
        tracep->fullBit(oldp+115,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_read_T));
        tracep->fullBit(oldp+116,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__readerFrontend__DOT__valid));
        tracep->fullBit(oldp+117,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__ready));
        tracep->fullBit(oldp+118,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_enq));
        tracep->fullBit(oldp+119,(vlTOPp->DMATopAXI_AXIL_AXI__DOT__queue_q__DOT__do_deq));
        tracep->fullBit(oldp+120,(vlTOPp->clock));
        tracep->fullBit(oldp+121,(vlTOPp->reset));
        tracep->fullIData(oldp+122,(vlTOPp->io_control_aw_awaddr),32);
        tracep->fullCData(oldp+123,(vlTOPp->io_control_aw_awprot),3);
        tracep->fullBit(oldp+124,(vlTOPp->io_control_aw_awvalid));
        tracep->fullBit(oldp+125,(vlTOPp->io_control_aw_awready));
        tracep->fullIData(oldp+126,(vlTOPp->io_control_w_wdata),32);
        tracep->fullCData(oldp+127,(vlTOPp->io_control_w_wstrb),4);
        tracep->fullBit(oldp+128,(vlTOPp->io_control_w_wvalid));
        tracep->fullBit(oldp+129,(vlTOPp->io_control_w_wready));
        tracep->fullCData(oldp+130,(vlTOPp->io_control_b_bresp),2);
        tracep->fullBit(oldp+131,(vlTOPp->io_control_b_bvalid));
        tracep->fullBit(oldp+132,(vlTOPp->io_control_b_bready));
        tracep->fullIData(oldp+133,(vlTOPp->io_control_ar_araddr),32);
        tracep->fullCData(oldp+134,(vlTOPp->io_control_ar_arprot),3);
        tracep->fullBit(oldp+135,(vlTOPp->io_control_ar_arvalid));
        tracep->fullBit(oldp+136,(vlTOPp->io_control_ar_arready));
        tracep->fullIData(oldp+137,(vlTOPp->io_control_r_rdata),32);
        tracep->fullCData(oldp+138,(vlTOPp->io_control_r_rresp),2);
        tracep->fullBit(oldp+139,(vlTOPp->io_control_r_rvalid));
        tracep->fullBit(oldp+140,(vlTOPp->io_control_r_rready));
        tracep->fullCData(oldp+141,(vlTOPp->io_readMem_aw_awid),4);
        tracep->fullIData(oldp+142,(vlTOPp->io_readMem_aw_awaddr),32);
        tracep->fullCData(oldp+143,(vlTOPp->io_readMem_aw_awlen),8);
        tracep->fullCData(oldp+144,(vlTOPp->io_readMem_aw_awsize),3);
        tracep->fullCData(oldp+145,(vlTOPp->io_readMem_aw_awburst),2);
        tracep->fullBit(oldp+146,(vlTOPp->io_readMem_aw_awlock));
        tracep->fullCData(oldp+147,(vlTOPp->io_readMem_aw_awcache),4);
        tracep->fullCData(oldp+148,(vlTOPp->io_readMem_aw_awprot),3);
        tracep->fullCData(oldp+149,(vlTOPp->io_readMem_aw_awqos),4);
        tracep->fullBit(oldp+150,(vlTOPp->io_readMem_aw_awvalid));
        tracep->fullBit(oldp+151,(vlTOPp->io_readMem_aw_awready));
        tracep->fullIData(oldp+152,(vlTOPp->io_readMem_w_wdata),32);
        tracep->fullCData(oldp+153,(vlTOPp->io_readMem_w_wstrb),4);
        tracep->fullBit(oldp+154,(vlTOPp->io_readMem_w_wlast));
        tracep->fullBit(oldp+155,(vlTOPp->io_readMem_w_wvalid));
        tracep->fullBit(oldp+156,(vlTOPp->io_readMem_w_wready));
        tracep->fullCData(oldp+157,(vlTOPp->io_readMem_b_bid),4);
        tracep->fullCData(oldp+158,(vlTOPp->io_readMem_b_bresp),2);
        tracep->fullBit(oldp+159,(vlTOPp->io_readMem_b_bvalid));
        tracep->fullBit(oldp+160,(vlTOPp->io_readMem_b_bready));
        tracep->fullCData(oldp+161,(vlTOPp->io_readMem_ar_arid),4);
        tracep->fullIData(oldp+162,(vlTOPp->io_readMem_ar_araddr),32);
        tracep->fullCData(oldp+163,(vlTOPp->io_readMem_ar_arlen),8);
        tracep->fullCData(oldp+164,(vlTOPp->io_readMem_ar_arsize),3);
        tracep->fullCData(oldp+165,(vlTOPp->io_readMem_ar_arburst),2);
        tracep->fullBit(oldp+166,(vlTOPp->io_readMem_ar_arlock));
        tracep->fullCData(oldp+167,(vlTOPp->io_readMem_ar_arcache),4);
        tracep->fullCData(oldp+168,(vlTOPp->io_readMem_ar_arprot),3);
        tracep->fullCData(oldp+169,(vlTOPp->io_readMem_ar_arqos),4);
        tracep->fullBit(oldp+170,(vlTOPp->io_readMem_ar_arvalid));
        tracep->fullBit(oldp+171,(vlTOPp->io_readMem_ar_arready));
        tracep->fullCData(oldp+172,(vlTOPp->io_readMem_r_rid),4);
        tracep->fullIData(oldp+173,(vlTOPp->io_readMem_r_rdata),32);
        tracep->fullCData(oldp+174,(vlTOPp->io_readMem_r_rresp),2);
        tracep->fullBit(oldp+175,(vlTOPp->io_readMem_r_rlast));
        tracep->fullBit(oldp+176,(vlTOPp->io_readMem_r_rvalid));
        tracep->fullBit(oldp+177,(vlTOPp->io_readMem_r_rready));
        tracep->fullCData(oldp+178,(vlTOPp->io_writeSlave1_aw_awid),4);
        tracep->fullIData(oldp+179,(vlTOPp->io_writeSlave1_aw_awaddr),32);
        tracep->fullCData(oldp+180,(vlTOPp->io_writeSlave1_aw_awlen),8);
        tracep->fullCData(oldp+181,(vlTOPp->io_writeSlave1_aw_awsize),3);
        tracep->fullCData(oldp+182,(vlTOPp->io_writeSlave1_aw_awburst),2);
        tracep->fullBit(oldp+183,(vlTOPp->io_writeSlave1_aw_awlock));
        tracep->fullCData(oldp+184,(vlTOPp->io_writeSlave1_aw_awcache),4);
        tracep->fullCData(oldp+185,(vlTOPp->io_writeSlave1_aw_awprot),3);
        tracep->fullCData(oldp+186,(vlTOPp->io_writeSlave1_aw_awqos),4);
        tracep->fullBit(oldp+187,(vlTOPp->io_writeSlave1_aw_awvalid));
        tracep->fullBit(oldp+188,(vlTOPp->io_writeSlave1_aw_awready));
        tracep->fullIData(oldp+189,(vlTOPp->io_writeSlave1_w_wdata),32);
        tracep->fullCData(oldp+190,(vlTOPp->io_writeSlave1_w_wstrb),4);
        tracep->fullBit(oldp+191,(vlTOPp->io_writeSlave1_w_wlast));
        tracep->fullBit(oldp+192,(vlTOPp->io_writeSlave1_w_wvalid));
        tracep->fullBit(oldp+193,(vlTOPp->io_writeSlave1_w_wready));
        tracep->fullCData(oldp+194,(vlTOPp->io_writeSlave1_b_bid),4);
        tracep->fullCData(oldp+195,(vlTOPp->io_writeSlave1_b_bresp),2);
        tracep->fullBit(oldp+196,(vlTOPp->io_writeSlave1_b_bvalid));
        tracep->fullBit(oldp+197,(vlTOPp->io_writeSlave1_b_bready));
        tracep->fullCData(oldp+198,(vlTOPp->io_writeSlave1_ar_arid),4);
        tracep->fullIData(oldp+199,(vlTOPp->io_writeSlave1_ar_araddr),32);
        tracep->fullCData(oldp+200,(vlTOPp->io_writeSlave1_ar_arlen),8);
        tracep->fullCData(oldp+201,(vlTOPp->io_writeSlave1_ar_arsize),3);
        tracep->fullCData(oldp+202,(vlTOPp->io_writeSlave1_ar_arburst),2);
        tracep->fullBit(oldp+203,(vlTOPp->io_writeSlave1_ar_arlock));
        tracep->fullCData(oldp+204,(vlTOPp->io_writeSlave1_ar_arcache),4);
        tracep->fullCData(oldp+205,(vlTOPp->io_writeSlave1_ar_arprot),3);
        tracep->fullCData(oldp+206,(vlTOPp->io_writeSlave1_ar_arqos),4);
        tracep->fullBit(oldp+207,(vlTOPp->io_writeSlave1_ar_arvalid));
        tracep->fullBit(oldp+208,(vlTOPp->io_writeSlave1_ar_arready));
        tracep->fullCData(oldp+209,(vlTOPp->io_writeSlave1_r_rid),4);
        tracep->fullIData(oldp+210,(vlTOPp->io_writeSlave1_r_rdata),32);
        tracep->fullCData(oldp+211,(vlTOPp->io_writeSlave1_r_rresp),2);
        tracep->fullBit(oldp+212,(vlTOPp->io_writeSlave1_r_rlast));
        tracep->fullBit(oldp+213,(vlTOPp->io_writeSlave1_r_rvalid));
        tracep->fullBit(oldp+214,(vlTOPp->io_writeSlave1_r_rready));
        tracep->fullCData(oldp+215,(vlTOPp->io_writeSlave2_aw_awid),4);
        tracep->fullIData(oldp+216,(vlTOPp->io_writeSlave2_aw_awaddr),32);
        tracep->fullCData(oldp+217,(vlTOPp->io_writeSlave2_aw_awlen),8);
        tracep->fullCData(oldp+218,(vlTOPp->io_writeSlave2_aw_awsize),3);
        tracep->fullCData(oldp+219,(vlTOPp->io_writeSlave2_aw_awburst),2);
        tracep->fullBit(oldp+220,(vlTOPp->io_writeSlave2_aw_awlock));
        tracep->fullCData(oldp+221,(vlTOPp->io_writeSlave2_aw_awcache),4);
        tracep->fullCData(oldp+222,(vlTOPp->io_writeSlave2_aw_awprot),3);
        tracep->fullCData(oldp+223,(vlTOPp->io_writeSlave2_aw_awqos),4);
        tracep->fullBit(oldp+224,(vlTOPp->io_writeSlave2_aw_awvalid));
        tracep->fullBit(oldp+225,(vlTOPp->io_writeSlave2_aw_awready));
        tracep->fullIData(oldp+226,(vlTOPp->io_writeSlave2_w_wdata),32);
        tracep->fullCData(oldp+227,(vlTOPp->io_writeSlave2_w_wstrb),4);
        tracep->fullBit(oldp+228,(vlTOPp->io_writeSlave2_w_wlast));
        tracep->fullBit(oldp+229,(vlTOPp->io_writeSlave2_w_wvalid));
        tracep->fullBit(oldp+230,(vlTOPp->io_writeSlave2_w_wready));
        tracep->fullCData(oldp+231,(vlTOPp->io_writeSlave2_b_bid),4);
        tracep->fullCData(oldp+232,(vlTOPp->io_writeSlave2_b_bresp),2);
        tracep->fullBit(oldp+233,(vlTOPp->io_writeSlave2_b_bvalid));
        tracep->fullBit(oldp+234,(vlTOPp->io_writeSlave2_b_bready));
        tracep->fullCData(oldp+235,(vlTOPp->io_writeSlave2_ar_arid),4);
        tracep->fullIData(oldp+236,(vlTOPp->io_writeSlave2_ar_araddr),32);
        tracep->fullCData(oldp+237,(vlTOPp->io_writeSlave2_ar_arlen),8);
        tracep->fullCData(oldp+238,(vlTOPp->io_writeSlave2_ar_arsize),3);
        tracep->fullCData(oldp+239,(vlTOPp->io_writeSlave2_ar_arburst),2);
        tracep->fullBit(oldp+240,(vlTOPp->io_writeSlave2_ar_arlock));
        tracep->fullCData(oldp+241,(vlTOPp->io_writeSlave2_ar_arcache),4);
        tracep->fullCData(oldp+242,(vlTOPp->io_writeSlave2_ar_arprot),3);
        tracep->fullCData(oldp+243,(vlTOPp->io_writeSlave2_ar_arqos),4);
        tracep->fullBit(oldp+244,(vlTOPp->io_writeSlave2_ar_arvalid));
        tracep->fullBit(oldp+245,(vlTOPp->io_writeSlave2_ar_arready));
        tracep->fullCData(oldp+246,(vlTOPp->io_writeSlave2_r_rid),4);
        tracep->fullIData(oldp+247,(vlTOPp->io_writeSlave2_r_rdata),32);
        tracep->fullCData(oldp+248,(vlTOPp->io_writeSlave2_r_rresp),2);
        tracep->fullBit(oldp+249,(vlTOPp->io_writeSlave2_r_rlast));
        tracep->fullBit(oldp+250,(vlTOPp->io_writeSlave2_r_rvalid));
        tracep->fullBit(oldp+251,(vlTOPp->io_writeSlave2_r_rready));
        tracep->fullBit(oldp+252,(vlTOPp->io_irq_readerDone));
        tracep->fullBit(oldp+253,(vlTOPp->io_irq_writerDone));
        tracep->fullBit(oldp+254,(vlTOPp->io_sync_readerSync));
        tracep->fullBit(oldp+255,(vlTOPp->io_sync_writerSync));
        tracep->fullBit(oldp+256,(((IData)(vlTOPp->io_writeSlave2_w_wready) 
                                   & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__writerFrontend__DOT__enable))));
        tracep->fullIData(oldp+257,((((0U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+258,((((2U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+259,((((3U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+260,((((4U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+261,((((5U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+262,((((6U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+263,((((7U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+264,((((8U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+265,((((9U == (0xfU 
                                              & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+266,((((0xaU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+267,((((0xbU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+268,((((0xeU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+269,((((0xfU == (0xfU 
                                                & vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT__addr)) 
                                      & (IData)(vlTOPp->DMATopAXI_AXIL_AXI__DOT__csrFrontend__DOT___io_bus_write_T))
                                      ? vlTOPp->io_control_w_wdata
                                      : 0U)),32);
        tracep->fullIData(oldp+270,(0U),32);
        tracep->fullIData(oldp+271,(0x10U),32);
        tracep->fullBit(oldp+272,(1U));
    }
}
