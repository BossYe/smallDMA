#include "VDMATopAXI_AXIL_AXI.h"
#include "verilated.h"

#define TOP_CLASS VDMATopAXI_AXIL_AXI

#ifndef VM_TRACE_FST
#define VM_TRACE_FST 0
#endif

static const bool verbose = false;

#if VM_TRACE
#if VM_TRACE_FST
  #include "verilated_fst_c.h"
  #define VERILATED_C VerilatedFstC
#else // !(VM_TRACE_FST)
  #include "verilated_vcd_c.h"
  #define VERILATED_C VerilatedVcdC
#endif
#else // !(VM_TRACE)
  #define VERILATED_C VerilatedVcdC
#endif
#include <iostream>


// Override Verilator definition so first $finish ends simulation
// Note: VL_USER_FINISH needs to be defined when compiling Verilator code
static bool encounteredFinish = false;
void vl_finish(const char* filename, int linenum, const char* hier) {
  // std::cout << "finish! (" << filename << ", " << linenum << ", " << hier << ")" << std::endl;
  Verilated::runFlushCallbacks();
  encounteredFinish = true;
}


static bool encounteredFatal = false;
void vl_fatal(const char* filename, int linenum, const char* hier, const char* msg) {
  std::cerr << "fatal! (" << filename << ", " << linenum << ", " << hier << ", " << msg << ")" << std::endl;
  Verilated::runFlushCallbacks();
  encounteredFatal = true;
}


static bool encounteredStop = false;
void vl_stop(const char* filename, int linenum, const char* hier) {
  // std::cout << "stop! (" << filename << ", " << linenum << ", " << hier << ")" << std::endl;
  Verilated::runFlushCallbacks();
  encounteredStop = true;
}


// Global because older versions of verilator do not support contexts
static vluint64_t global_time = 0;
double sc_time_stamp () { return global_time; }

static void _startCoverageAndDump(VERILATED_C** tfp, const std::string& dumpfile, TOP_CLASS* top) {

#if VM_TRACE || VM_COVERAGE
    Verilated::traceEverOn(true);
#endif
#if VM_TRACE
    if (verbose) VL_PRINTF("Enabling waves..\n");
    *tfp = new VERILATED_C;
    top->trace(*tfp, 99);
    (*tfp)->open(dumpfile.c_str());
#endif
}

static int64_t _step(VERILATED_C* tfp, TOP_CLASS* top, vluint64_t& main_time) {
    top->clock = 0;
    global_time = main_time;
    top->eval();
#if VM_TRACE
    if (tfp) tfp->dump(main_time);
#endif
    main_time++;
    top->clock = 1;
    global_time = main_time;
    top->eval();
#if VM_TRACE
    if (tfp) tfp->dump(main_time);
#endif
    main_time++;
    if(encounteredStop) {
      // vl_stop is called by verilator when an assertion fails or when the fatal command is executed
      encounteredStop = false;
      encounteredFinish = false;
      return 2;
    } else if(encounteredFinish) {
      // vl_finish is called by verilator when a finish command is executed (stop(0))
      encounteredFinish = false;
      return 1;
    } else if(encounteredFatal) {
      encounteredFatal = false;
      return 3;
    }
    return 0;
}

static void _finish(VERILATED_C* tfp, TOP_CLASS* top) {
#if VM_TRACE
  if (tfp) tfp->close();
  delete tfp;
#endif
#if VM_COVERAGE
  VerilatedCov::write(R"(/home/yxy/smallDMA/test_run_dir/ControllerSpec_should_perform_2D_MM2MM_transfer_with_stride_mem_to_mem/coverage.dat)");
#endif
  top->final();
  // TODO: re-enable!
  // delete top;
}

struct sim_state {
  TOP_CLASS* dut;
  VERILATED_C* tfp;
  vluint64_t main_time;

  sim_state() :
    dut(new TOP_CLASS),
    tfp(nullptr),
    main_time(0)
  {
    // std::cout << "Allocating! " << ((long long) dut) << std::endl;
  }

  inline int64_t step(int32_t cycles) {
    for(int32_t i = 0; i < cycles; i++) {
      const int64_t status = _step(tfp, dut, main_time);
      if(status > 0) {
        // early exit on failure
        return (status << 32) | ((int64_t)(i + 1));
      }
    }
    return (int64_t)cycles;
  }
  inline void update() { dut->eval(); }
  inline void finish() {
    dut->eval();
    _finish(tfp, dut);
  }
  inline void resetCoverage() { VerilatedCov::zero(); }
  inline void writeCoverage(const char* filename) {
    VerilatedCov::write(filename);
  }
  inline void poke(int32_t id, int64_t value) {
    const uint64_t u = value;
    // std::cout << "poking: " << std::hex << u << std::endl;
    switch(id) {
      case 0 : dut->reset = u; break;
      case 1 : dut->io_control_aw_awaddr = u; break;
      case 2 : dut->io_control_aw_awprot = u; break;
      case 3 : dut->io_control_aw_awvalid = u; break;
      case 4 : dut->io_control_w_wdata = u; break;
      case 5 : dut->io_control_w_wstrb = u; break;
      case 6 : dut->io_control_w_wvalid = u; break;
      case 7 : dut->io_control_b_bready = u; break;
      case 8 : dut->io_control_ar_araddr = u; break;
      case 9 : dut->io_control_ar_arprot = u; break;
      case 10 : dut->io_control_ar_arvalid = u; break;
      case 11 : dut->io_control_r_rready = u; break;
      case 12 : dut->io_readMem_aw_awready = u; break;
      case 13 : dut->io_readMem_w_wready = u; break;
      case 14 : dut->io_readMem_b_bid = u; break;
      case 15 : dut->io_readMem_b_bresp = u; break;
      case 16 : dut->io_readMem_b_bvalid = u; break;
      case 17 : dut->io_readMem_ar_arready = u; break;
      case 18 : dut->io_readMem_r_rid = u; break;
      case 19 : dut->io_readMem_r_rdata = u; break;
      case 20 : dut->io_readMem_r_rresp = u; break;
      case 21 : dut->io_readMem_r_rlast = u; break;
      case 22 : dut->io_readMem_r_rvalid = u; break;
      case 23 : dut->io_writeSlave1_aw_awready = u; break;
      case 24 : dut->io_writeSlave1_w_wready = u; break;
      case 25 : dut->io_writeSlave1_b_bid = u; break;
      case 26 : dut->io_writeSlave1_b_bresp = u; break;
      case 27 : dut->io_writeSlave1_b_bvalid = u; break;
      case 28 : dut->io_writeSlave1_ar_arready = u; break;
      case 29 : dut->io_writeSlave1_r_rid = u; break;
      case 30 : dut->io_writeSlave1_r_rdata = u; break;
      case 31 : dut->io_writeSlave1_r_rresp = u; break;
      case 32 : dut->io_writeSlave1_r_rlast = u; break;
      case 33 : dut->io_writeSlave1_r_rvalid = u; break;
      case 34 : dut->io_writeSlave2_aw_awready = u; break;
      case 35 : dut->io_writeSlave2_w_wready = u; break;
      case 36 : dut->io_writeSlave2_b_bid = u; break;
      case 37 : dut->io_writeSlave2_b_bresp = u; break;
      case 38 : dut->io_writeSlave2_b_bvalid = u; break;
      case 39 : dut->io_writeSlave2_ar_arready = u; break;
      case 40 : dut->io_writeSlave2_r_rid = u; break;
      case 41 : dut->io_writeSlave2_r_rdata = u; break;
      case 42 : dut->io_writeSlave2_r_rresp = u; break;
      case 43 : dut->io_writeSlave2_r_rlast = u; break;
      case 44 : dut->io_writeSlave2_r_rvalid = u; break;
      case 45 : dut->io_sync_readerSync = u; break;
      case 46 : dut->io_sync_writerSync = u; break;

    default:
      std::cerr << "Cannot find the object of id = " << id << std::endl;
      finish();
      break;
    }
  }
  inline int64_t peek(int32_t id) {
    uint64_t value = 0;
    switch(id) {
      case 0 : value = dut->reset; break;
      case 1 : value = dut->io_control_aw_awaddr; break;
      case 2 : value = dut->io_control_aw_awprot; break;
      case 3 : value = dut->io_control_aw_awvalid; break;
      case 4 : value = dut->io_control_w_wdata; break;
      case 5 : value = dut->io_control_w_wstrb; break;
      case 6 : value = dut->io_control_w_wvalid; break;
      case 7 : value = dut->io_control_b_bready; break;
      case 8 : value = dut->io_control_ar_araddr; break;
      case 9 : value = dut->io_control_ar_arprot; break;
      case 10 : value = dut->io_control_ar_arvalid; break;
      case 11 : value = dut->io_control_r_rready; break;
      case 12 : value = dut->io_readMem_aw_awready; break;
      case 13 : value = dut->io_readMem_w_wready; break;
      case 14 : value = dut->io_readMem_b_bid; break;
      case 15 : value = dut->io_readMem_b_bresp; break;
      case 16 : value = dut->io_readMem_b_bvalid; break;
      case 17 : value = dut->io_readMem_ar_arready; break;
      case 18 : value = dut->io_readMem_r_rid; break;
      case 19 : value = dut->io_readMem_r_rdata; break;
      case 20 : value = dut->io_readMem_r_rresp; break;
      case 21 : value = dut->io_readMem_r_rlast; break;
      case 22 : value = dut->io_readMem_r_rvalid; break;
      case 23 : value = dut->io_writeSlave1_aw_awready; break;
      case 24 : value = dut->io_writeSlave1_w_wready; break;
      case 25 : value = dut->io_writeSlave1_b_bid; break;
      case 26 : value = dut->io_writeSlave1_b_bresp; break;
      case 27 : value = dut->io_writeSlave1_b_bvalid; break;
      case 28 : value = dut->io_writeSlave1_ar_arready; break;
      case 29 : value = dut->io_writeSlave1_r_rid; break;
      case 30 : value = dut->io_writeSlave1_r_rdata; break;
      case 31 : value = dut->io_writeSlave1_r_rresp; break;
      case 32 : value = dut->io_writeSlave1_r_rlast; break;
      case 33 : value = dut->io_writeSlave1_r_rvalid; break;
      case 34 : value = dut->io_writeSlave2_aw_awready; break;
      case 35 : value = dut->io_writeSlave2_w_wready; break;
      case 36 : value = dut->io_writeSlave2_b_bid; break;
      case 37 : value = dut->io_writeSlave2_b_bresp; break;
      case 38 : value = dut->io_writeSlave2_b_bvalid; break;
      case 39 : value = dut->io_writeSlave2_ar_arready; break;
      case 40 : value = dut->io_writeSlave2_r_rid; break;
      case 41 : value = dut->io_writeSlave2_r_rdata; break;
      case 42 : value = dut->io_writeSlave2_r_rresp; break;
      case 43 : value = dut->io_writeSlave2_r_rlast; break;
      case 44 : value = dut->io_writeSlave2_r_rvalid; break;
      case 45 : value = dut->io_sync_readerSync; break;
      case 46 : value = dut->io_sync_writerSync; break;
      case 47 : value = dut->io_control_aw_awready; break;
      case 48 : value = dut->io_control_w_wready; break;
      case 49 : value = dut->io_control_b_bresp; break;
      case 50 : value = dut->io_control_b_bvalid; break;
      case 51 : value = dut->io_control_ar_arready; break;
      case 52 : value = dut->io_control_r_rdata; break;
      case 53 : value = dut->io_control_r_rresp; break;
      case 54 : value = dut->io_control_r_rvalid; break;
      case 55 : value = dut->io_readMem_aw_awid; break;
      case 56 : value = dut->io_readMem_aw_awaddr; break;
      case 57 : value = dut->io_readMem_aw_awlen; break;
      case 58 : value = dut->io_readMem_aw_awsize; break;
      case 59 : value = dut->io_readMem_aw_awburst; break;
      case 60 : value = dut->io_readMem_aw_awlock; break;
      case 61 : value = dut->io_readMem_aw_awcache; break;
      case 62 : value = dut->io_readMem_aw_awprot; break;
      case 63 : value = dut->io_readMem_aw_awqos; break;
      case 64 : value = dut->io_readMem_aw_awvalid; break;
      case 65 : value = dut->io_readMem_w_wdata; break;
      case 66 : value = dut->io_readMem_w_wstrb; break;
      case 67 : value = dut->io_readMem_w_wlast; break;
      case 68 : value = dut->io_readMem_w_wvalid; break;
      case 69 : value = dut->io_readMem_b_bready; break;
      case 70 : value = dut->io_readMem_ar_arid; break;
      case 71 : value = dut->io_readMem_ar_araddr; break;
      case 72 : value = dut->io_readMem_ar_arlen; break;
      case 73 : value = dut->io_readMem_ar_arsize; break;
      case 74 : value = dut->io_readMem_ar_arburst; break;
      case 75 : value = dut->io_readMem_ar_arlock; break;
      case 76 : value = dut->io_readMem_ar_arcache; break;
      case 77 : value = dut->io_readMem_ar_arprot; break;
      case 78 : value = dut->io_readMem_ar_arqos; break;
      case 79 : value = dut->io_readMem_ar_arvalid; break;
      case 80 : value = dut->io_readMem_r_rready; break;
      case 81 : value = dut->io_writeSlave1_aw_awid; break;
      case 82 : value = dut->io_writeSlave1_aw_awaddr; break;
      case 83 : value = dut->io_writeSlave1_aw_awlen; break;
      case 84 : value = dut->io_writeSlave1_aw_awsize; break;
      case 85 : value = dut->io_writeSlave1_aw_awburst; break;
      case 86 : value = dut->io_writeSlave1_aw_awlock; break;
      case 87 : value = dut->io_writeSlave1_aw_awcache; break;
      case 88 : value = dut->io_writeSlave1_aw_awprot; break;
      case 89 : value = dut->io_writeSlave1_aw_awqos; break;
      case 90 : value = dut->io_writeSlave1_aw_awvalid; break;
      case 91 : value = dut->io_writeSlave1_w_wdata; break;
      case 92 : value = dut->io_writeSlave1_w_wstrb; break;
      case 93 : value = dut->io_writeSlave1_w_wlast; break;
      case 94 : value = dut->io_writeSlave1_w_wvalid; break;
      case 95 : value = dut->io_writeSlave1_b_bready; break;
      case 96 : value = dut->io_writeSlave1_ar_arid; break;
      case 97 : value = dut->io_writeSlave1_ar_araddr; break;
      case 98 : value = dut->io_writeSlave1_ar_arlen; break;
      case 99 : value = dut->io_writeSlave1_ar_arsize; break;
      case 100 : value = dut->io_writeSlave1_ar_arburst; break;
      case 101 : value = dut->io_writeSlave1_ar_arlock; break;
      case 102 : value = dut->io_writeSlave1_ar_arcache; break;
      case 103 : value = dut->io_writeSlave1_ar_arprot; break;
      case 104 : value = dut->io_writeSlave1_ar_arqos; break;
      case 105 : value = dut->io_writeSlave1_ar_arvalid; break;
      case 106 : value = dut->io_writeSlave1_r_rready; break;
      case 107 : value = dut->io_writeSlave2_aw_awid; break;
      case 108 : value = dut->io_writeSlave2_aw_awaddr; break;
      case 109 : value = dut->io_writeSlave2_aw_awlen; break;
      case 110 : value = dut->io_writeSlave2_aw_awsize; break;
      case 111 : value = dut->io_writeSlave2_aw_awburst; break;
      case 112 : value = dut->io_writeSlave2_aw_awlock; break;
      case 113 : value = dut->io_writeSlave2_aw_awcache; break;
      case 114 : value = dut->io_writeSlave2_aw_awprot; break;
      case 115 : value = dut->io_writeSlave2_aw_awqos; break;
      case 116 : value = dut->io_writeSlave2_aw_awvalid; break;
      case 117 : value = dut->io_writeSlave2_w_wdata; break;
      case 118 : value = dut->io_writeSlave2_w_wstrb; break;
      case 119 : value = dut->io_writeSlave2_w_wlast; break;
      case 120 : value = dut->io_writeSlave2_w_wvalid; break;
      case 121 : value = dut->io_writeSlave2_b_bready; break;
      case 122 : value = dut->io_writeSlave2_ar_arid; break;
      case 123 : value = dut->io_writeSlave2_ar_araddr; break;
      case 124 : value = dut->io_writeSlave2_ar_arlen; break;
      case 125 : value = dut->io_writeSlave2_ar_arsize; break;
      case 126 : value = dut->io_writeSlave2_ar_arburst; break;
      case 127 : value = dut->io_writeSlave2_ar_arlock; break;
      case 128 : value = dut->io_writeSlave2_ar_arcache; break;
      case 129 : value = dut->io_writeSlave2_ar_arprot; break;
      case 130 : value = dut->io_writeSlave2_ar_arqos; break;
      case 131 : value = dut->io_writeSlave2_ar_arvalid; break;
      case 132 : value = dut->io_writeSlave2_r_rready; break;
      case 133 : value = dut->io_irq_readerDone; break;
      case 134 : value = dut->io_irq_writerDone; break;

    default:
      std::cerr << "Cannot find the object of id = " << id << std::endl;
      finish();
      return -1;
    }
    // std::cout << "peeking: " << std::hex << value << std::endl;
    return value;
  }
  inline void poke_wide(int32_t id, int32_t offset, int64_t value) {
    const uint64_t u = value;
    WData* data = nullptr;
    size_t words = 0;
    switch(id) {

    default:
      std::cerr << "Cannot find the object of id = " << id << std::endl;
      finish();
      break;
    }
    const size_t firstWord = offset * 2;
    const size_t secondWord = firstWord + 1;
    if(firstWord >= words || firstWord < 0) {
      std::cerr << "Out of bounds index for id = " << id << " index = " << offset << std::endl;
      finish();
    } else if(secondWord >= words) {
      data[firstWord] = u;
    } else {
      data[firstWord] = u & 0xffffffffu;
      data[secondWord] = (u >> 32) & 0xffffffffu;
    }
  }
  inline int64_t peek_wide(int32_t id, int32_t offset) {
    WData* data = nullptr;
    size_t words = 0;
    switch(id) {

    default:
      std::cerr << "Cannot find the object of id = " << id << std::endl;
      finish();
      return -1;
    }
    const size_t firstWord = offset * 2;
    const size_t secondWord = firstWord + 1;
    if(firstWord >= words || firstWord < 0) {
      std::cerr << "Out of bounds index for id = " << id << " index = " << offset << std::endl;
      finish();
      return -1;
    } else if(secondWord >= words) {
      return (uint64_t)data[firstWord];
    } else {
      return (((uint64_t)data[secondWord]) << 32) | ((uint64_t)data[firstWord]);
    }
  }

  inline void set_args(int32_t argc, const char** argv) {
    Verilated::commandArgs(argc, argv);
  }
};

static sim_state* create_sim_state() {
  sim_state *s = new sim_state();
  std::string dumpfile = R"(/home/yxy/smallDMA/test_run_dir/ControllerSpec_should_perform_2D_MM2MM_transfer_with_stride_mem_to_mem/DMATopAXI_AXIL_AXI.vcd)";
  _startCoverageAndDump(&s->tfp, dumpfile, s->dut);
  return s;
}
// we only export the symbols that we prefixed with a unique id
#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__ || defined __MINGW64__
#define _EXPORT __declspec(dllexport)
#else
#define _EXPORT __attribute__((visibility("default")))
#endif
extern "C" {

_EXPORT void* sim_init() {
  // void* ptr = create_sim_state();
  // std::cout << "native ptr: " << std::hex << ptr << std::endl;
  // return ptr;
  return (void*) create_sim_state();
}

_EXPORT int64_t step(void* s, int32_t cycles) {
  return ((sim_state*)s)->step(cycles);
}

_EXPORT void update(void* s) {
  ((sim_state*)s)->update();
}

_EXPORT void finish(void* s) {
  ((sim_state*)s)->finish();
}

_EXPORT void resetCoverage(void* s) {
  ((sim_state*)s)->resetCoverage();
}

_EXPORT void writeCoverage(void* s, const char* filename) {
  ((sim_state*)s)->writeCoverage(filename);
}

_EXPORT void poke(void* s, int32_t id, int64_t value) {
  ((sim_state*)s)->poke(id, value);
}

_EXPORT int64_t peek(void* s, int32_t id) {
  return ((sim_state*)s)->peek(id);
}

_EXPORT void poke_wide(void* s, int32_t id, int32_t offset, int64_t value) {
  ((sim_state*)s)->poke_wide(id, offset, value);
}

_EXPORT int64_t peek_wide(void* s, int32_t id, int32_t offset) {
  return ((sim_state*)s)->peek_wide(id, offset);
}

_EXPORT void set_args(void* s, int32_t argc, const char** argv) {
  ((sim_state*)s)->set_args(argc, argv);
}
} /* extern C */
