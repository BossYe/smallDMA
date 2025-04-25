module AXI4LiteCSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 10:7]
  input         clock, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 10:7]
  input         reset, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 10:7]
  input  [31:0] io_ctl_aw_awaddr, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input         io_ctl_aw_awvalid, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_ctl_aw_awready, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input  [31:0] io_ctl_w_wdata, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input         io_ctl_w_wvalid, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_ctl_w_wready, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_ctl_b_bvalid, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input         io_ctl_b_bready, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input  [31:0] io_ctl_ar_araddr, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input         io_ctl_ar_arvalid, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_ctl_ar_arready, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output [31:0] io_ctl_r_rdata, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_ctl_r_rvalid, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input         io_ctl_r_rready, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output [3:0]  io_bus_addr, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output [31:0] io_bus_dataOut, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  input  [31:0] io_bus_dataIn, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_bus_write, // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
  output        io_bus_read // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 12:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 18:22]
  reg  awready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 20:24]
  reg  wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 21:23]
  reg  bvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 22:23]
  reg  arready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 25:24]
  reg  rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 26:23]
  reg [31:0] addr; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 29:21]
  wire  _io_bus_read_T = io_ctl_r_rready & rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 43:34]
  wire  _io_bus_write_T = io_ctl_w_wvalid & wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 44:35]
  wire  _GEN_2 = io_ctl_ar_arvalid | arready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 54:37 57:17 25:24]
  wire  _GEN_5 = io_ctl_aw_awvalid | awready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 49:31 52:17 20:24]
  wire  _GEN_9 = io_ctl_ar_arvalid & arready | rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 61:42 64:16 26:23]
  wire [2:0] _GEN_10 = _io_bus_read_T ? 3'h0 : state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 68:39 69:15 18:22]
  wire  _GEN_11 = _io_bus_read_T ? 1'h0 : rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 68:39 70:16 26:23]
  wire [2:0] _GEN_12 = io_ctl_aw_awvalid & awready ? 3'h4 : state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 74:42 75:15 18:22]
  wire  _GEN_13 = io_ctl_aw_awvalid & awready ? 1'h0 : awready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 74:42 76:17 20:24]
  wire  _GEN_14 = io_ctl_aw_awvalid & awready | wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 74:42 77:16 21:23]
  wire [2:0] _GEN_15 = _io_bus_write_T ? 3'h5 : state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 81:39 82:15 18:22]
  wire  _GEN_16 = _io_bus_write_T ? 1'h0 : wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 81:39 83:16 21:23]
  wire  _GEN_17 = _io_bus_write_T | bvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 81:39 84:16 22:23]
  wire [2:0] _GEN_18 = io_ctl_b_bready & bvalid ? 3'h0 : state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 88:39 89:15 18:22]
  wire  _GEN_19 = io_ctl_b_bready & bvalid ? 1'h0 : bvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 88:39 90:16 22:23]
  wire [2:0] _GEN_20 = 3'h5 == state ? _GEN_18 : state; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17 18:22]
  wire  _GEN_21 = 3'h5 == state ? _GEN_19 : bvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17 22:23]
  wire [2:0] _GEN_22 = 3'h4 == state ? _GEN_15 : _GEN_20; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
  wire  _GEN_23 = 3'h4 == state ? _GEN_16 : wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17 21:23]
  wire  _GEN_24 = 3'h4 == state ? _GEN_17 : _GEN_21; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
  wire [2:0] _GEN_25 = 3'h3 == state ? _GEN_12 : _GEN_22; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
  wire  _GEN_26 = 3'h3 == state ? _GEN_13 : awready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17 20:24]
  wire  _GEN_27 = 3'h3 == state ? _GEN_14 : _GEN_23; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
  wire  _GEN_28 = 3'h3 == state ? bvalid : _GEN_24; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17 22:23]
  assign io_ctl_aw_awready = awready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 34:21]
  assign io_ctl_w_wready = wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 35:19]
  assign io_ctl_b_bvalid = bvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 36:19]
  assign io_ctl_ar_arready = arready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 39:21]
  assign io_ctl_r_rdata = io_bus_dataIn; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 31:18]
  assign io_ctl_r_rvalid = rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 40:19]
  assign io_bus_addr = addr[3:0]; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 45:15]
  assign io_bus_dataOut = io_ctl_w_wdata; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 32:18]
  assign io_bus_write = io_ctl_w_wvalid & wready; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 44:35]
  assign io_bus_read = io_ctl_r_rready & rvalid; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 43:34]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 18:22]
      state <= 3'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 18:22]
    end else if (3'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (io_ctl_aw_awvalid) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 49:31]
        state <= 3'h3; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 50:15]
      end else if (io_ctl_ar_arvalid) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 54:37]
        state <= 3'h1; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 55:15]
      end
    end else if (3'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (io_ctl_ar_arvalid & arready) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 61:42]
        state <= 3'h2; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 62:15]
      end
    end else if (3'h2 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      state <= _GEN_10;
    end else begin
      state <= _GEN_25;
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 20:24]
      awready <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 20:24]
    end else if (3'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      awready <= _GEN_5;
    end else if (!(3'h1 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (!(3'h2 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
        awready <= _GEN_26;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 21:23]
      wready <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 21:23]
    end else if (!(3'h0 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (!(3'h1 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
        if (!(3'h2 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
          wready <= _GEN_27;
        end
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 22:23]
      bvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 22:23]
    end else if (!(3'h0 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (!(3'h1 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
        if (!(3'h2 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
          bvalid <= _GEN_28;
        end
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 25:24]
      arready <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 25:24]
    end else if (3'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (!(io_ctl_aw_awvalid)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 49:31]
        arready <= _GEN_2;
      end
    end else if (3'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (io_ctl_ar_arvalid & arready) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 61:42]
        arready <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 63:17]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 26:23]
      rvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 26:23]
    end else if (!(3'h0 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (3'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
        rvalid <= _GEN_9;
      end else if (3'h2 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
        rvalid <= _GEN_11;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 29:21]
      addr <= 32'h0; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 29:21]
    end else if (3'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 47:17]
      if (io_ctl_aw_awvalid) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 49:31]
        addr <= {{28'd0}, io_ctl_aw_awaddr[5:2]}; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 51:14]
      end else if (io_ctl_ar_arvalid) begin // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 54:37]
        addr <= {{28'd0}, io_ctl_ar_araddr[5:2]}; // @[src/main/scala/DMAController/Frontend/AXI4LiteCSR.scala 56:14]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[2:0];
  _RAND_1 = {1{`RANDOM}};
  awready = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  wready = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  bvalid = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  arready = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  rvalid = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  addr = _RAND_6[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXI4ReaderAXI_AXIL_AXI( // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 10:7]
  input         clock, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 10:7]
  input         reset, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 10:7]
  output [31:0] io_bus_ar_araddr, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output [7:0]  io_bus_ar_arlen, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output        io_bus_ar_arvalid, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input         io_bus_ar_arready, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input  [31:0] io_bus_r_rdata, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input         io_bus_r_rlast, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input         io_bus_r_rvalid, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output        io_bus_r_rready, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input         io_dataIO_ready, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output        io_dataIO_valid, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output [31:0] io_dataIO_bits, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  output        io_xfer_done, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input  [31:0] io_xfer_address, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input  [31:0] io_xfer_length, // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
  input         io_xfer_valid // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 12:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] state; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 22:22]
  reg  done; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 24:21]
  reg  enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 25:23]
  reg [31:0] araddr; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 27:23]
  reg [7:0] arlen; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 28:22]
  reg  arvalid; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 29:24]
  wire  ready = io_dataIO_ready & enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 32:40]
  wire  valid = io_bus_r_rvalid & enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 33:40]
  wire [31:0] _arlen_T_1 = io_xfer_length - 32'h1; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 52:33]
  wire  _GEN_1 = io_xfer_valid | arvalid; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 48:27 50:17 29:24]
  wire [31:0] _GEN_3 = io_xfer_valid ? _arlen_T_1 : {{24'd0}, arlen}; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 48:27 52:15 28:22]
  wire  _GEN_6 = arvalid & io_bus_ar_arready | enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 56:42 59:16 25:23]
  wire [1:0] _GEN_7 = io_bus_r_rlast ? 2'h3 : state; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 64:30 65:17 22:22]
  wire  _GEN_8 = io_bus_r_rlast ? 1'h0 : enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 64:30 66:18 25:23]
  wire [1:0] _GEN_9 = ready & valid ? _GEN_7 : state; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 22:22 63:28]
  wire  _GEN_10 = ready & valid ? _GEN_8 : enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 25:23 63:28]
  wire  _GEN_11 = 2'h3 == state | done; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17 71:12 24:21]
  wire [1:0] _GEN_12 = 2'h3 == state ? 2'h0 : state; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17 72:13 22:22]
  wire [31:0] _GEN_24 = 2'h0 == state ? _GEN_3 : {{24'd0}, arlen}; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17 28:22]
  wire [31:0] _GEN_26 = reset ? 32'h0 : _GEN_24; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 28:{22,22}]
  assign io_bus_ar_araddr = araddr; // @[src/main/scala/DMAController/Bus/AXI4.scala 113:18 120:15]
  assign io_bus_ar_arlen = arlen; // @[src/main/scala/DMAController/Bus/AXI4.scala 113:18 121:14]
  assign io_bus_ar_arvalid = arvalid; // @[src/main/scala/DMAController/Bus/AXI4.scala 113:18 123:16]
  assign io_bus_r_rready = io_dataIO_ready & enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 32:40]
  assign io_dataIO_valid = io_bus_r_rvalid & enable; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 33:40]
  assign io_dataIO_bits = io_bus_r_rdata; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 42:18]
  assign io_xfer_done = done; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 43:16]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 22:22]
      state <= 2'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 22:22]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 48:27]
        state <= 2'h1; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 49:15]
      end
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (arvalid & io_bus_ar_arready) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 56:42]
        state <= 2'h2; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 57:15]
      end
    end else if (2'h2 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      state <= _GEN_9;
    end else begin
      state <= _GEN_12;
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 24:21]
      done <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 24:21]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      done <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 47:12]
    end else if (!(2'h1 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (!(2'h2 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
        done <= _GEN_11;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 25:23]
      enable <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 25:23]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (2'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
        enable <= _GEN_6;
      end else if (2'h2 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
        enable <= _GEN_10;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 27:23]
      araddr <= 32'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 27:23]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 48:27]
        araddr <= io_xfer_address; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 51:16]
      end
    end
    arlen <= _GEN_26[7:0]; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 28:{22,22}]
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 29:24]
      arvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 29:24]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      arvalid <= _GEN_1;
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 45:17]
      if (arvalid & io_bus_ar_arready) begin // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 56:42]
        arvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Reader.scala 58:17]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  done = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  enable = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  araddr = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  arlen = _RAND_4[7:0];
  _RAND_5 = {1{`RANDOM}};
  arvalid = _RAND_5[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AXI4WriterAXI_AXIL_AXI( // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 10:7]
  input         clock, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 10:7]
  input         reset, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 10:7]
  output [31:0] io_bus_aw_awaddr, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output [7:0]  io_bus_aw_awlen, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_bus_aw_awvalid, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input         io_bus_aw_awready, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output [31:0] io_bus_w_wdata, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_bus_w_wlast, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_bus_w_wvalid, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input         io_bus_w_wready, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input         io_bus_b_bvalid, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_bus_b_bready, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_dataIO_ready, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input         io_dataIO_valid, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input  [31:0] io_dataIO_bits, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  output        io_xfer_done, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input  [31:0] io_xfer_address, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input  [31:0] io_xfer_length, // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
  input         io_xfer_valid // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 12:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] dataState; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 23:26]
  reg [1:0] addrState; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 24:26]
  reg  done; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 26:21]
  reg  enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 27:23]
  reg [31:0] length; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 29:23]
  reg [31:0] awlen; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 30:22]
  reg [31:0] awaddr; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 31:23]
  reg  awvalid; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 35:24]
  reg  bready; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 36:23]
  wire  ready = io_bus_w_wready & enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 38:40]
  wire  valid = io_dataIO_valid & enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 39:40]
  wire  _GEN_2 = io_xfer_valid | enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 56:27 59:16 27:23]
  wire [31:0] _length_T_1 = length - 32'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 65:28]
  wire [31:0] _GEN_3 = length > 32'h1 ? _length_T_1 : length; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 64:28 65:18 29:23]
  wire [1:0] _GEN_4 = length > 32'h1 ? dataState : 2'h2; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 23:26 64:28 67:21]
  wire  _GEN_5 = length > 32'h1 & enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 27:23 64:28 68:18]
  wire  _GEN_6 = length > 32'h1 ? bready : 1'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 36:23 64:28 69:18]
  wire  _GEN_11 = bready & io_bus_b_bvalid ? 1'h0 : bready; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 74:39 75:16 36:23]
  wire [1:0] _GEN_12 = bready & io_bus_b_bvalid ? 2'h3 : dataState; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 74:39 76:19 23:26]
  wire  _GEN_13 = 2'h3 == dataState | done; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21 80:12 26:21]
  wire [1:0] _GEN_14 = 2'h3 == dataState ? 2'h0 : dataState; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21 81:17 23:26]
  wire [31:0] _awlen_T_1 = io_xfer_length - 32'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 89:33]
  wire  _GEN_30 = io_xfer_valid | awvalid; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 87:27 90:17 35:24]
  wire [1:0] _GEN_34 = done ? 2'h0 : addrState; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 101:18 102:19 24:26]
  assign io_bus_aw_awaddr = awaddr; // @[src/main/scala/DMAController/Bus/AXI4.scala 21:18 28:15]
  assign io_bus_aw_awlen = awlen[7:0]; // @[src/main/scala/DMAController/Bus/AXI4.scala 21:18 29:14]
  assign io_bus_aw_awvalid = awvalid; // @[src/main/scala/DMAController/Bus/AXI4.scala 21:18 31:16]
  assign io_bus_w_wdata = io_dataIO_bits; // @[src/main/scala/DMAController/Bus/AXI4.scala 60:17 61:13]
  assign io_bus_w_wlast = length == 32'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 51:18]
  assign io_bus_w_wvalid = io_dataIO_valid & enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 39:40]
  assign io_bus_b_bready = bready; // @[src/main/scala/DMAController/Bus/AXI4.scala 86:17 87:14]
  assign io_dataIO_ready = io_bus_w_wready & enable; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 38:40]
  assign io_xfer_done = done; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 49:16]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 23:26]
      dataState <= 2'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 23:26]
    end else if (2'h0 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 56:27]
        dataState <= 2'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 58:19]
      end
    end else if (2'h1 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (ready & valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 63:28]
        dataState <= _GEN_4;
      end
    end else if (2'h2 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      dataState <= _GEN_12;
    end else begin
      dataState <= _GEN_14;
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 24:26]
      addrState <= 2'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 24:26]
    end else if (2'h0 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 87:27]
        addrState <= 2'h1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 91:19]
      end
    end else if (2'h1 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      if (awvalid & io_bus_aw_awready) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 95:42]
        addrState <= 2'h2; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 96:19]
      end
    end else if (2'h2 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      addrState <= _GEN_34;
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 26:21]
      done <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 26:21]
    end else if (2'h0 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      done <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 55:12]
    end else if (!(2'h1 == dataState)) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (!(2'h2 == dataState)) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
        done <= _GEN_13;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 27:23]
      enable <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 27:23]
    end else if (2'h0 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      enable <= _GEN_2;
    end else if (2'h1 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (ready & valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 63:28]
        enable <= _GEN_5;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 29:23]
      length <= 32'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 29:23]
    end else if (2'h0 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 56:27]
        length <= io_xfer_length; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 57:16]
      end
    end else if (2'h1 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (ready & valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 63:28]
        length <= _GEN_3;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 30:22]
      awlen <= 32'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 30:22]
    end else if (2'h0 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 87:27]
        awlen <= _awlen_T_1; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 89:15]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 31:23]
      awaddr <= 32'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 31:23]
    end else if (2'h0 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      if (io_xfer_valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 87:27]
        awaddr <= io_xfer_address; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 88:16]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 35:24]
      awvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 35:24]
    end else if (2'h0 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      awvalid <= _GEN_30;
    end else if (2'h1 == addrState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 85:21]
      if (awvalid & io_bus_aw_awready) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 95:42]
        awvalid <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 97:17]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 36:23]
      bready <= 1'h0; // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 36:23]
    end else if (!(2'h0 == dataState)) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
      if (2'h1 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
        if (ready & valid) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 63:28]
          bready <= _GEN_6;
        end
      end else if (2'h2 == dataState) begin // @[src/main/scala/DMAController/Frontend/AXI4Writer.scala 53:21]
        bready <= _GEN_11;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  dataState = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  addrState = _RAND_1[1:0];
  _RAND_2 = {1{`RANDOM}};
  done = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  enable = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  length = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  awlen = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  awaddr = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  awvalid = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  bready = _RAND_8[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module CSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/CSR/CSR.scala 7:7]
  output [31:0] io_csr_0_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_0_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_0_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_1_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_2_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_2_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_2_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_3_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_3_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_3_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_4_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_4_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_4_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_5_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_5_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_5_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_6_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_6_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_6_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_7_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_7_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_7_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_8_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_8_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_8_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_9_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_9_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_9_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_10_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_10_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_10_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_11_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_11_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_11_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_12_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_13_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_14_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_14_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_14_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_csr_15_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output        io_csr_15_dataWrite, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_csr_15_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [3:0]  io_bus_addr, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input  [31:0] io_bus_dataOut, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  output [31:0] io_bus_dataIn, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input         io_bus_write, // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
  input         io_bus_read // @[src/main/scala/DMAController/CSR/CSR.scala 8:14]
);
  wire  _T = io_bus_addr == 4'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_0 = io_bus_addr == 4'h0 & io_bus_read ? io_csr_0_dataIn : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12 13:22]
  wire [31:0] _GEN_4 = io_bus_addr == 4'h1 & io_bus_read ? io_csr_1_dataIn : _GEN_0; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_8 = io_bus_addr == 4'h2; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_8 = io_bus_addr == 4'h2 & io_bus_read ? io_csr_2_dataIn : _GEN_4; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_12 = io_bus_addr == 4'h3; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_12 = io_bus_addr == 4'h3 & io_bus_read ? io_csr_3_dataIn : _GEN_8; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_16 = io_bus_addr == 4'h4; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_16 = io_bus_addr == 4'h4 & io_bus_read ? io_csr_4_dataIn : _GEN_12; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_20 = io_bus_addr == 4'h5; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_20 = io_bus_addr == 4'h5 & io_bus_read ? io_csr_5_dataIn : _GEN_16; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_24 = io_bus_addr == 4'h6; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_24 = io_bus_addr == 4'h6 & io_bus_read ? io_csr_6_dataIn : _GEN_20; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_28 = io_bus_addr == 4'h7; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_28 = io_bus_addr == 4'h7 & io_bus_read ? io_csr_7_dataIn : _GEN_24; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_32 = io_bus_addr == 4'h8; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_32 = io_bus_addr == 4'h8 & io_bus_read ? io_csr_8_dataIn : _GEN_28; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_36 = io_bus_addr == 4'h9; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_36 = io_bus_addr == 4'h9 & io_bus_read ? io_csr_9_dataIn : _GEN_32; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_40 = io_bus_addr == 4'ha; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_40 = io_bus_addr == 4'ha & io_bus_read ? io_csr_10_dataIn : _GEN_36; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_44 = io_bus_addr == 4'hb; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_44 = io_bus_addr == 4'hb & io_bus_read ? io_csr_11_dataIn : _GEN_40; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire [31:0] _GEN_48 = io_bus_addr == 4'hc & io_bus_read ? io_csr_12_dataIn : _GEN_44; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire [31:0] _GEN_52 = io_bus_addr == 4'hd & io_bus_read ? io_csr_13_dataIn : _GEN_48; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_56 = io_bus_addr == 4'he; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  wire [31:0] _GEN_56 = io_bus_addr == 4'he & io_bus_read ? io_csr_14_dataIn : _GEN_52; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
  wire  _T_60 = io_bus_addr == 4'hf; // @[src/main/scala/DMAController/CSR/CSR.scala 18:22]
  assign io_csr_0_dataOut = _T & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_0_dataWrite = _T & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_2_dataOut = _T_8 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_2_dataWrite = _T_8 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_3_dataOut = _T_12 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_3_dataWrite = _T_12 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_4_dataOut = _T_16 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_4_dataWrite = _T_16 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_5_dataOut = _T_20 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_5_dataWrite = _T_20 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_6_dataOut = _T_24 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_6_dataWrite = _T_24 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_7_dataOut = _T_28 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_7_dataWrite = _T_28 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_8_dataOut = _T_32 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_8_dataWrite = _T_32 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_9_dataOut = _T_36 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_9_dataWrite = _T_36 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_10_dataOut = _T_40 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_10_dataWrite = _T_40 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_11_dataOut = _T_44 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_11_dataWrite = _T_44 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_14_dataOut = _T_56 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_14_dataWrite = _T_56 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_csr_15_dataOut = _T_60 & io_bus_write ? io_bus_dataOut : 32'h0; // @[src/main/scala/DMAController/CSR/CSR.scala 25:47 26:25 30:25]
  assign io_csr_15_dataWrite = _T_60 & io_bus_write; // @[src/main/scala/DMAController/CSR/CSR.scala 25:30]
  assign io_bus_dataIn = io_bus_addr == 4'hf & io_bus_read ? io_csr_15_dataIn : _GEN_56; // @[src/main/scala/DMAController/CSR/CSR.scala 18:45 19:12]
endmodule
module AddressGeneratorAXI_AXIL_AXI( // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 9:7]
  input         clock, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 9:7]
  input         reset, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 9:7]
  input         io_ctl_start, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  output        io_ctl_busy, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  input  [31:0] io_ctl_startAddress, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  input  [31:0] io_ctl_lineLength, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  input  [31:0] io_ctl_lineCount, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  input  [31:0] io_ctl_lineGap, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  input         io_xfer_done, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  output [31:0] io_xfer_address, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  output [31:0] io_xfer_length, // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
  output        io_xfer_valid // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 11:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
`endif // RANDOMIZE_REG_INIT
  reg [1:0] state; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 18:22]
  reg [31:0] lineCount; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 20:26]
  reg [31:0] lineGap; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 21:24]
  reg [31:0] address_o; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 23:26]
  reg [31:0] address_i; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 24:26]
  reg [31:0] length_o; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 25:25]
  reg [31:0] length_i; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 26:25]
  reg  valid; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 27:22]
  reg  busy; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 29:21]
  wire [31:0] _GEN_2 = io_ctl_start ? io_ctl_startAddress : address_i; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 45:26 48:19 24:26]
  wire [34:0] _address_i_T = length_i * 3'h4; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 60:42]
  wire [34:0] _GEN_28 = {{3'd0}, address_i}; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 60:30]
  wire [34:0] _address_i_T_2 = _GEN_28 + _address_i_T; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 60:30]
  wire [34:0] _address_i_T_3 = lineGap * 3'h4; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 60:74]
  wire [34:0] _address_i_T_5 = _address_i_T_2 + _address_i_T_3; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 60:63]
  wire [31:0] _lineCount_T_1 = lineCount - 32'h1; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 62:30]
  wire [1:0] _GEN_7 = lineCount > 32'h0 ? 2'h1 : 2'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 69:31 70:17 72:17]
  wire [1:0] _GEN_8 = io_xfer_done ? _GEN_7 : state; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 18:22 68:26]
  wire  _GEN_9 = 2'h2 == state ? 1'h0 : valid; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17 66:13 27:22]
  wire  _GEN_12 = 2'h1 == state | _GEN_9; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17 57:13]
  wire [34:0] _GEN_15 = 2'h1 == state ? _address_i_T_5 : {{3'd0}, address_i}; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17 60:17 24:26]
  wire [34:0] _GEN_20 = 2'h0 == state ? {{3'd0}, _GEN_2} : _GEN_15; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
  wire [34:0] _GEN_29 = reset ? 35'h0 : _GEN_20; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 24:{26,26}]
  assign io_ctl_busy = busy; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 35:15]
  assign io_xfer_address = address_o; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 31:19]
  assign io_xfer_length = length_o; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 32:18]
  assign io_xfer_valid = valid; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 33:17]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 18:22]
      state <= 2'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 18:22]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (io_ctl_start) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 45:26]
        state <= 2'h1; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 46:15]
      end
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      state <= 2'h2; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 63:13]
    end else if (2'h2 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      state <= _GEN_8;
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 20:26]
      lineCount <= 32'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 20:26]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (io_ctl_start) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 45:26]
        lineCount <= io_ctl_lineCount; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 50:19]
      end
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      lineCount <= _lineCount_T_1; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 62:17]
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 21:24]
      lineGap <= 32'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 21:24]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (io_ctl_start) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 45:26]
        lineGap <= io_ctl_lineGap; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 51:17]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 23:26]
      address_o <= 32'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 23:26]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
        address_o <= address_i; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 58:17]
      end
    end
    address_i <= _GEN_29[31:0]; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 24:{26,26}]
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 25:25]
      length_o <= 32'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 25:25]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
        length_o <= length_i; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 59:16]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 26:25]
      length_i <= 32'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 26:25]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      if (io_ctl_start) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 45:26]
        length_i <= io_ctl_lineLength; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 49:18]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 27:22]
      valid <= 1'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 27:22]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 43:17]
      valid <= _GEN_12;
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 29:21]
      busy <= 1'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 29:21]
    end else if (state == 2'h0) begin // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 37:25]
      busy <= 1'h0; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 38:10]
    end else begin
      busy <= 1'h1; // @[src/main/scala/DMAController/Worker/AddressGenerator.scala 40:10]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  lineCount = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  lineGap = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  address_o = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  address_i = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  length_o = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  length_i = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  valid = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  busy = _RAND_8[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module TransferSplitterAXI_AXIL_AXI( // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 9:7]
  output        io_xferIn_done, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input  [31:0] io_xferIn_address, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input  [31:0] io_xferIn_length, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input         io_xferIn_valid, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input         io_xferOut_done, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output [31:0] io_xferOut_address, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output [31:0] io_xferOut_length, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output        io_xferOut_valid // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
);
  assign io_xferIn_done = io_xferOut_done; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 113:16]
  assign io_xferOut_address = io_xferIn_address; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 113:16]
  assign io_xferOut_length = io_xferIn_length; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 113:16]
  assign io_xferOut_valid = io_xferIn_valid; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 113:16]
endmodule
module TransferSplitterAXI_AXIL_AXI_1( // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 9:7]
  input         clock, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 9:7]
  input         reset, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 9:7]
  output        io_xferIn_done, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input  [31:0] io_xferIn_address, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input  [31:0] io_xferIn_length, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input         io_xferIn_valid, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  input         io_xferOut_done, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output [31:0] io_xferOut_address, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output [31:0] io_xferOut_length, // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
  output        io_xferOut_valid // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 12:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] address_i; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 24:28]
  reg [31:0] length_i; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 25:27]
  reg [31:0] address_o; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 27:28]
  reg [31:0] length_o; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 28:27]
  reg  done; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 33:23]
  reg  valid; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 34:24]
  reg [1:0] state; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 36:24]
  wire [31:0] _GEN_0 = io_xferIn_valid ? io_xferIn_address : address_i; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 49:31 50:21 24:28]
  wire [31:0] _length_i_T_1 = length_i - 32'h10; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 65:34]
  wire [7:0] _address_i_T = 5'h10 * 3'h4; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 66:50]
  wire [31:0] _GEN_33 = {{24'd0}, _address_i_T}; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 66:36]
  wire [31:0] _address_i_T_2 = address_i + _GEN_33; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 66:36]
  wire [34:0] _address_i_T_3 = length_i * 3'h4; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 84:47]
  wire [34:0] _GEN_34 = {{3'd0}, address_i}; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 84:36]
  wire [34:0] _address_i_T_5 = _GEN_34 + _address_i_T_3; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 84:36]
  wire [34:0] _GEN_6 = length_i > 32'h10 ? {{3'd0}, _address_i_T_2} : _address_i_T_5; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 62:38 66:23 84:23]
  wire [1:0] _GEN_7 = length_i > 32'h0 ? 2'h1 : 2'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 103:32 104:19 106:19]
  wire  _GEN_8 = length_i > 32'h0 ? done : 1'h1; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 103:32 107:18 33:23]
  wire [1:0] _GEN_9 = io_xferOut_done ? _GEN_7 : state; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 102:31 36:24]
  wire  _GEN_10 = io_xferOut_done ? _GEN_8 : done; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 102:31 33:23]
  wire  _GEN_11 = 2'h2 == state ? 1'h0 : valid; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 100:15 45:19 34:24]
  wire  _GEN_17 = 2'h1 == state | _GEN_11; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19 59:15]
  wire [34:0] _GEN_21 = 2'h1 == state ? _GEN_6 : {{3'd0}, address_i}; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19 24:28]
  wire [34:0] _GEN_25 = 2'h0 == state ? {{3'd0}, _GEN_0} : _GEN_21; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
  wire [34:0] _GEN_35 = reset ? 35'h0 : _GEN_25; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 24:{28,28}]
  assign io_xferIn_done = done; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 38:20]
  assign io_xferOut_address = address_o; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 42:24]
  assign io_xferOut_length = length_o; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 43:23]
  assign io_xferOut_valid = valid; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 39:22]
  always @(posedge clock) begin
    address_i <= _GEN_35[31:0]; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 24:{28,28}]
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 25:27]
      length_i <= 32'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 25:27]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (io_xferIn_valid) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 49:31]
        length_i <= io_xferIn_length; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 51:20]
      end
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (length_i > 32'h10) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 62:38]
        length_i <= _length_i_T_1; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 65:22]
      end else begin
        length_i <= 32'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 83:22]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 27:28]
      address_o <= 32'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 27:28]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
        address_o <= address_i; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 57:19]
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 28:27]
      length_o <= 32'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 28:27]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
        if (length_i > 32'h10) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 62:38]
          length_o <= 32'h10; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 64:22]
        end else begin
          length_o <= length_i; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 82:22]
        end
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 33:23]
      done <= 1'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 33:23]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      done <= 1'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 47:14]
    end else if (!(2'h1 == state)) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (2'h2 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
        done <= _GEN_10;
      end
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 34:24]
      valid <= 1'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 34:24]
    end else if (!(2'h0 == state)) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      valid <= _GEN_17;
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 36:24]
      state <= 2'h0; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 36:24]
    end else if (2'h0 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      if (io_xferIn_valid) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 49:31]
        state <= 2'h1; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 53:17]
      end
    end else if (2'h1 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      state <= 2'h2; // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 60:15]
    end else if (2'h2 == state) begin // @[src/main/scala/DMAController/Worker/TransferSplitter.scala 45:19]
      state <= _GEN_9;
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  address_i = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  length_i = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  address_o = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  length_o = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  done = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  valid = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  state = _RAND_6[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ClearCSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/CSR/ClearCSR.scala 7:7]
  input         clock, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 7:7]
  input         reset, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 7:7]
  input  [31:0] io_csr_dataOut, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 8:14]
  input         io_csr_dataWrite, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 8:14]
  output [31:0] io_csr_dataIn, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 8:14]
  output [31:0] io_value, // @[src/main/scala/DMAController/CSR/ClearCSR.scala 8:14]
  input  [31:0] io_clear // @[src/main/scala/DMAController/CSR/ClearCSR.scala 8:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] reg_; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 14:20]
  wire [31:0] _reg_T = ~io_clear; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 22:19]
  wire [31:0] _reg_T_1 = reg_ & _reg_T; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 22:16]
  assign io_csr_dataIn = reg_; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 16:17]
  assign io_value = reg_; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 17:12]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/CSR/ClearCSR.scala 14:20]
      reg_ <= 32'h0; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 14:20]
    end else if (io_csr_dataWrite) begin // @[src/main/scala/DMAController/CSR/ClearCSR.scala 19:26]
      reg_ <= io_csr_dataOut; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 20:9]
    end else begin
      reg_ <= _reg_T_1; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 22:9]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  reg_ = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module StatusCSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/CSR/StatusCSR.scala 8:7]
  input         clock, // @[src/main/scala/DMAController/CSR/StatusCSR.scala 8:7]
  output [31:0] io_csr_dataIn, // @[src/main/scala/DMAController/CSR/StatusCSR.scala 9:14]
  input  [31:0] io_value // @[src/main/scala/DMAController/CSR/StatusCSR.scala 9:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] reg_; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 14:20]
  assign io_csr_dataIn = reg_; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 16:17]
  always @(posedge clock) begin
    reg_ <= io_value; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 14:20]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  reg_ = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SimpleCSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 8:7]
  input         clock, // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 8:7]
  input         reset, // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 8:7]
  input  [31:0] io_csr_dataOut, // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 9:14]
  input         io_csr_dataWrite, // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 9:14]
  output [31:0] io_csr_dataIn, // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 9:14]
  output [31:0] io_value // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 9:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] reg_; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 14:20]
  assign io_csr_dataIn = reg_; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 16:17]
  assign io_value = reg_; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 17:12]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 14:20]
      reg_ <= 32'h0; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 14:20]
    end else if (io_csr_dataWrite) begin // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 19:26]
      reg_ <= io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 20:9]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  reg_ = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SetCSRAXI_AXIL_AXI( // @[src/main/scala/DMAController/CSR/SetCSR.scala 8:7]
  input         clock, // @[src/main/scala/DMAController/CSR/SetCSR.scala 8:7]
  input         reset, // @[src/main/scala/DMAController/CSR/SetCSR.scala 8:7]
  input  [31:0] io_csr_dataOut, // @[src/main/scala/DMAController/CSR/SetCSR.scala 9:14]
  input         io_csr_dataWrite, // @[src/main/scala/DMAController/CSR/SetCSR.scala 9:14]
  output [31:0] io_csr_dataIn, // @[src/main/scala/DMAController/CSR/SetCSR.scala 9:14]
  output [31:0] io_value, // @[src/main/scala/DMAController/CSR/SetCSR.scala 9:14]
  input  [31:0] io_set // @[src/main/scala/DMAController/CSR/SetCSR.scala 9:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] reg_; // @[src/main/scala/DMAController/CSR/SetCSR.scala 15:20]
  wire [31:0] _reg_T = ~io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SetCSR.scala 21:20]
  wire [31:0] _reg_T_1 = reg_ & _reg_T; // @[src/main/scala/DMAController/CSR/SetCSR.scala 21:17]
  wire [31:0] _reg_T_2 = _reg_T_1 | io_set; // @[src/main/scala/DMAController/CSR/SetCSR.scala 21:45]
  wire [31:0] _reg_T_3 = reg_ | io_set; // @[src/main/scala/DMAController/CSR/SetCSR.scala 23:16]
  assign io_csr_dataIn = reg_; // @[src/main/scala/DMAController/CSR/SetCSR.scala 17:17]
  assign io_value = reg_; // @[src/main/scala/DMAController/CSR/SetCSR.scala 18:12]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/DMAController/CSR/SetCSR.scala 15:20]
      reg_ <= 32'h0; // @[src/main/scala/DMAController/CSR/SetCSR.scala 15:20]
    end else if (io_csr_dataWrite) begin // @[src/main/scala/DMAController/CSR/SetCSR.scala 20:26]
      reg_ <= _reg_T_2; // @[src/main/scala/DMAController/CSR/SetCSR.scala 21:9]
    end else begin
      reg_ <= _reg_T_3; // @[src/main/scala/DMAController/CSR/SetCSR.scala 23:9]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  reg_ = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module InterruptControllerAXI_AXIL_AXI( // @[src/main/scala/DMAController/Worker/InterruptController.scala 10:7]
  input         clock, // @[src/main/scala/DMAController/Worker/InterruptController.scala 10:7]
  input         reset, // @[src/main/scala/DMAController/Worker/InterruptController.scala 10:7]
  output        io_irq_readerDone, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  output        io_irq_writerDone, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input         io_readBusy, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input         io_writeBusy, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input  [31:0] io_imr_dataOut, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input         io_imr_dataWrite, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  output [31:0] io_imr_dataIn, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input  [31:0] io_isr_dataOut, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  input         io_isr_dataWrite, // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
  output [31:0] io_isr_dataIn // @[src/main/scala/DMAController/Worker/InterruptController.scala 11:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  wire  mask_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  mask_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] mask_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  mask_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] mask_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] mask_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  isr_csr_clock; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire  isr_csr_reset; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire [31:0] isr_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire  isr_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire [31:0] isr_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire [31:0] isr_csr_io_value; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  wire [31:0] isr_csr_io_set; // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
  reg  readBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 21:25]
  reg  readBusyOld; // @[src/main/scala/DMAController/Worker/InterruptController.scala 22:28]
  reg  writeBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 24:26]
  reg  writeBusyOld; // @[src/main/scala/DMAController/Worker/InterruptController.scala 25:29]
  reg  writeBusyIrq; // @[src/main/scala/DMAController/Worker/InterruptController.scala 27:29]
  reg  readBusyIrq; // @[src/main/scala/DMAController/Worker/InterruptController.scala 28:28]
  wire [31:0] mask = mask_csr_io_value; // @[src/main/scala/DMAController/Worker/InterruptController.scala 19:{22,22}]
  wire [1:0] irq = {readBusyIrq,writeBusyIrq}; // @[src/main/scala/DMAController/Worker/InterruptController.scala 33:25]
  wire [31:0] isr = isr_csr_io_value; // @[src/main/scala/DMAController/Worker/InterruptController.scala 35:{21,21}]
  SimpleCSRAXI_AXIL_AXI mask_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(mask_csr_clock),
    .reset(mask_csr_reset),
    .io_csr_dataOut(mask_csr_io_csr_dataOut),
    .io_csr_dataWrite(mask_csr_io_csr_dataWrite),
    .io_csr_dataIn(mask_csr_io_csr_dataIn),
    .io_value(mask_csr_io_value)
  );
  SetCSRAXI_AXIL_AXI isr_csr ( // @[src/main/scala/DMAController/CSR/SetCSR.scala 30:21]
    .clock(isr_csr_clock),
    .reset(isr_csr_reset),
    .io_csr_dataOut(isr_csr_io_csr_dataOut),
    .io_csr_dataWrite(isr_csr_io_csr_dataWrite),
    .io_csr_dataIn(isr_csr_io_csr_dataIn),
    .io_value(isr_csr_io_value),
    .io_set(isr_csr_io_set)
  );
  assign io_irq_readerDone = isr[1]; // @[src/main/scala/DMAController/Worker/InterruptController.scala 38:27]
  assign io_irq_writerDone = isr[0]; // @[src/main/scala/DMAController/Worker/InterruptController.scala 37:27]
  assign io_imr_dataIn = mask_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_isr_dataIn = isr_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SetCSR.scala 34:16]
  assign mask_csr_clock = clock;
  assign mask_csr_reset = reset;
  assign mask_csr_io_csr_dataOut = io_imr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign mask_csr_io_csr_dataWrite = io_imr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign isr_csr_clock = clock;
  assign isr_csr_reset = reset;
  assign isr_csr_io_csr_dataOut = io_isr_dataOut; // @[src/main/scala/DMAController/CSR/SetCSR.scala 34:16]
  assign isr_csr_io_csr_dataWrite = io_isr_dataWrite; // @[src/main/scala/DMAController/CSR/SetCSR.scala 34:16]
  assign isr_csr_io_set = {{30'd0}, irq}; // @[src/main/scala/DMAController/CSR/SetCSR.scala 32:16]
  always @(posedge clock) begin
    readBusy <= io_readBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 21:25]
    readBusyOld <= readBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 22:28]
    writeBusy <= io_writeBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 24:26]
    writeBusyOld <= writeBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 25:29]
    if (reset) begin // @[src/main/scala/DMAController/Worker/InterruptController.scala 27:29]
      writeBusyIrq <= 1'h0; // @[src/main/scala/DMAController/Worker/InterruptController.scala 27:29]
    end else begin
      writeBusyIrq <= writeBusyOld & ~writeBusy & mask[0]; // @[src/main/scala/DMAController/Worker/InterruptController.scala 30:16]
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/InterruptController.scala 28:28]
      readBusyIrq <= 1'h0; // @[src/main/scala/DMAController/Worker/InterruptController.scala 28:28]
    end else begin
      readBusyIrq <= readBusyOld & ~readBusy & mask[1]; // @[src/main/scala/DMAController/Worker/InterruptController.scala 31:15]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  readBusy = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  readBusyOld = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  writeBusy = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  writeBusyOld = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  writeBusyIrq = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  readBusyIrq = _RAND_5[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WorkerCSRWrapperAXI_AXIL_AXI( // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 9:7]
  input         clock, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 9:7]
  input         reset, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 9:7]
  input  [31:0] io_csr_0_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_0_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_0_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_1_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_2_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_2_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_2_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_3_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_3_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_3_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_4_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_4_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_4_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_5_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_5_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_5_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_6_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_6_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_6_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_7_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_7_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_7_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_8_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_8_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_8_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_9_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_9_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_9_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_10_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_10_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_10_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_11_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_11_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_11_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_12_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_13_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_14_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_14_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_14_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input  [31:0] io_csr_15_dataOut, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_csr_15_dataWrite, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_csr_15_dataIn, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output        io_irq_readerDone, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output        io_irq_writerDone, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_sync_readerSync, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_sync_writerSync, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_xferRead_done, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_xferRead_address, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_xferRead_length, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output        io_xferRead_valid, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  input         io_xferWrite_done, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_xferWrite_address, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output [31:0] io_xferWrite_length, // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
  output        io_xferWrite_valid // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 10:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  wire  addressGeneratorRead_clock; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  addressGeneratorRead_reset; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  addressGeneratorRead_io_ctl_start; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  addressGeneratorRead_io_ctl_busy; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_ctl_startAddress; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_ctl_lineLength; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_ctl_lineCount; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_ctl_lineGap; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  addressGeneratorRead_io_xfer_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_xfer_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire [31:0] addressGeneratorRead_io_xfer_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  addressGeneratorRead_io_xfer_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
  wire  transferSplitterRead_io_xferIn_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire [31:0] transferSplitterRead_io_xferIn_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire [31:0] transferSplitterRead_io_xferIn_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire  transferSplitterRead_io_xferIn_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire  transferSplitterRead_io_xferOut_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire [31:0] transferSplitterRead_io_xferOut_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire [31:0] transferSplitterRead_io_xferOut_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire  transferSplitterRead_io_xferOut_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
  wire  addressGeneratorWrite_clock; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  addressGeneratorWrite_reset; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  addressGeneratorWrite_io_ctl_start; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  addressGeneratorWrite_io_ctl_busy; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_ctl_startAddress; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_ctl_lineLength; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_ctl_lineCount; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_ctl_lineGap; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  addressGeneratorWrite_io_xfer_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_xfer_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire [31:0] addressGeneratorWrite_io_xfer_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  addressGeneratorWrite_io_xfer_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
  wire  transferSplitterWrite_clock; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  transferSplitterWrite_reset; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  transferSplitterWrite_io_xferIn_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire [31:0] transferSplitterWrite_io_xferIn_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire [31:0] transferSplitterWrite_io_xferIn_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  transferSplitterWrite_io_xferIn_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  transferSplitterWrite_io_xferOut_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire [31:0] transferSplitterWrite_io_xferOut_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire [31:0] transferSplitterWrite_io_xferOut_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  transferSplitterWrite_io_xferOut_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
  wire  control_csr_clock; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire  control_csr_reset; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire [31:0] control_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire  control_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire [31:0] control_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire [31:0] control_csr_io_value; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire [31:0] control_csr_io_clear; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
  wire  csr_clock; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_io_value; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire  io_irq_irqc_clock; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_reset; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_irq_readerDone; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_irq_writerDone; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_readBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_writeBusy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire [31:0] io_irq_irqc_io_imr_dataOut; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_imr_dataWrite; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire [31:0] io_irq_irqc_io_imr_dataIn; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire [31:0] io_irq_irqc_io_isr_dataOut; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  io_irq_irqc_io_isr_dataWrite; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire [31:0] io_irq_irqc_io_isr_dataIn; // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
  wire  addressGeneratorRead_io_ctl_startAddress_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_startAddress_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_startAddress_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineLength_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineLength_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineLength_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineCount_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineCount_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineCount_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineGap_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineGap_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorRead_io_ctl_lineGap_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_startAddress_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_startAddress_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_startAddress_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineLength_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineLength_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineLength_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineCount_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineCount_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineCount_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineGap_csr_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineGap_csr_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] addressGeneratorWrite_io_ctl_lineGap_csr_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_1_clock; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_1_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_1_io_value; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire  csr_2_clock; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_2_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire [31:0] csr_2_io_value; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
  wire  csr_3_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_3_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_3_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_3_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_3_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_3_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_4_clock; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_4_reset; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_4_io_csr_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire  csr_4_io_csr_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_4_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  wire [31:0] csr_4_io_value; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
  reg [1:0] status; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 25:23]
  reg  readerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 27:27]
  reg  readerSyncOld; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 28:30]
  reg  writerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 30:27]
  reg  writerSyncOld; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 31:30]
  reg  readerStart; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 33:28]
  reg  writerStart; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 34:28]
  wire [1:0] _clear_T = {readerStart,writerStart}; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 52:15]
  wire [31:0] control = control_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 36:21 45:11]
  wire [1:0] _clear_T_3 = {control[5],control[4]}; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 52:48]
  wire [1:0] _clear_T_4 = ~_clear_T_3; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 52:44]
  wire [1:0] clear = _clear_T & _clear_T_4; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 52:42]
  AddressGeneratorAXI_AXIL_AXI addressGeneratorRead ( // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 18:36]
    .clock(addressGeneratorRead_clock),
    .reset(addressGeneratorRead_reset),
    .io_ctl_start(addressGeneratorRead_io_ctl_start),
    .io_ctl_busy(addressGeneratorRead_io_ctl_busy),
    .io_ctl_startAddress(addressGeneratorRead_io_ctl_startAddress),
    .io_ctl_lineLength(addressGeneratorRead_io_ctl_lineLength),
    .io_ctl_lineCount(addressGeneratorRead_io_ctl_lineCount),
    .io_ctl_lineGap(addressGeneratorRead_io_ctl_lineGap),
    .io_xfer_done(addressGeneratorRead_io_xfer_done),
    .io_xfer_address(addressGeneratorRead_io_xfer_address),
    .io_xfer_length(addressGeneratorRead_io_xfer_length),
    .io_xfer_valid(addressGeneratorRead_io_xfer_valid)
  );
  TransferSplitterAXI_AXIL_AXI transferSplitterRead ( // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 19:36]
    .io_xferIn_done(transferSplitterRead_io_xferIn_done),
    .io_xferIn_address(transferSplitterRead_io_xferIn_address),
    .io_xferIn_length(transferSplitterRead_io_xferIn_length),
    .io_xferIn_valid(transferSplitterRead_io_xferIn_valid),
    .io_xferOut_done(transferSplitterRead_io_xferOut_done),
    .io_xferOut_address(transferSplitterRead_io_xferOut_address),
    .io_xferOut_length(transferSplitterRead_io_xferOut_length),
    .io_xferOut_valid(transferSplitterRead_io_xferOut_valid)
  );
  AddressGeneratorAXI_AXIL_AXI addressGeneratorWrite ( // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 21:37]
    .clock(addressGeneratorWrite_clock),
    .reset(addressGeneratorWrite_reset),
    .io_ctl_start(addressGeneratorWrite_io_ctl_start),
    .io_ctl_busy(addressGeneratorWrite_io_ctl_busy),
    .io_ctl_startAddress(addressGeneratorWrite_io_ctl_startAddress),
    .io_ctl_lineLength(addressGeneratorWrite_io_ctl_lineLength),
    .io_ctl_lineCount(addressGeneratorWrite_io_ctl_lineCount),
    .io_ctl_lineGap(addressGeneratorWrite_io_ctl_lineGap),
    .io_xfer_done(addressGeneratorWrite_io_xfer_done),
    .io_xfer_address(addressGeneratorWrite_io_xfer_address),
    .io_xfer_length(addressGeneratorWrite_io_xfer_length),
    .io_xfer_valid(addressGeneratorWrite_io_xfer_valid)
  );
  TransferSplitterAXI_AXIL_AXI_1 transferSplitterWrite ( // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 22:37]
    .clock(transferSplitterWrite_clock),
    .reset(transferSplitterWrite_reset),
    .io_xferIn_done(transferSplitterWrite_io_xferIn_done),
    .io_xferIn_address(transferSplitterWrite_io_xferIn_address),
    .io_xferIn_length(transferSplitterWrite_io_xferIn_length),
    .io_xferIn_valid(transferSplitterWrite_io_xferIn_valid),
    .io_xferOut_done(transferSplitterWrite_io_xferOut_done),
    .io_xferOut_address(transferSplitterWrite_io_xferOut_address),
    .io_xferOut_length(transferSplitterWrite_io_xferOut_length),
    .io_xferOut_valid(transferSplitterWrite_io_xferOut_valid)
  );
  ClearCSRAXI_AXIL_AXI control_csr ( // @[src/main/scala/DMAController/CSR/ClearCSR.scala 28:21]
    .clock(control_csr_clock),
    .reset(control_csr_reset),
    .io_csr_dataOut(control_csr_io_csr_dataOut),
    .io_csr_dataWrite(control_csr_io_csr_dataWrite),
    .io_csr_dataIn(control_csr_io_csr_dataIn),
    .io_value(control_csr_io_value),
    .io_clear(control_csr_io_clear)
  );
  StatusCSRAXI_AXIL_AXI csr ( // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
    .clock(csr_clock),
    .io_csr_dataIn(csr_io_csr_dataIn),
    .io_value(csr_io_value)
  );
  InterruptControllerAXI_AXIL_AXI io_irq_irqc ( // @[src/main/scala/DMAController/Worker/InterruptController.scala 44:22]
    .clock(io_irq_irqc_clock),
    .reset(io_irq_irqc_reset),
    .io_irq_readerDone(io_irq_irqc_io_irq_readerDone),
    .io_irq_writerDone(io_irq_irqc_io_irq_writerDone),
    .io_readBusy(io_irq_irqc_io_readBusy),
    .io_writeBusy(io_irq_irqc_io_writeBusy),
    .io_imr_dataOut(io_irq_irqc_io_imr_dataOut),
    .io_imr_dataWrite(io_irq_irqc_io_imr_dataWrite),
    .io_imr_dataIn(io_irq_irqc_io_imr_dataIn),
    .io_isr_dataOut(io_irq_irqc_io_isr_dataOut),
    .io_isr_dataWrite(io_irq_irqc_io_isr_dataWrite),
    .io_isr_dataIn(io_irq_irqc_io_isr_dataIn)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorRead_io_ctl_startAddress_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorRead_io_ctl_startAddress_csr_clock),
    .reset(addressGeneratorRead_io_ctl_startAddress_csr_reset),
    .io_csr_dataOut(addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataIn),
    .io_value(addressGeneratorRead_io_ctl_startAddress_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorRead_io_ctl_lineLength_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorRead_io_ctl_lineLength_csr_clock),
    .reset(addressGeneratorRead_io_ctl_lineLength_csr_reset),
    .io_csr_dataOut(addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataIn),
    .io_value(addressGeneratorRead_io_ctl_lineLength_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorRead_io_ctl_lineCount_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorRead_io_ctl_lineCount_csr_clock),
    .reset(addressGeneratorRead_io_ctl_lineCount_csr_reset),
    .io_csr_dataOut(addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataIn),
    .io_value(addressGeneratorRead_io_ctl_lineCount_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorRead_io_ctl_lineGap_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorRead_io_ctl_lineGap_csr_clock),
    .reset(addressGeneratorRead_io_ctl_lineGap_csr_reset),
    .io_csr_dataOut(addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataIn),
    .io_value(addressGeneratorRead_io_ctl_lineGap_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorWrite_io_ctl_startAddress_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorWrite_io_ctl_startAddress_csr_clock),
    .reset(addressGeneratorWrite_io_ctl_startAddress_csr_reset),
    .io_csr_dataOut(addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataIn),
    .io_value(addressGeneratorWrite_io_ctl_startAddress_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorWrite_io_ctl_lineLength_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorWrite_io_ctl_lineLength_csr_clock),
    .reset(addressGeneratorWrite_io_ctl_lineLength_csr_reset),
    .io_csr_dataOut(addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataIn),
    .io_value(addressGeneratorWrite_io_ctl_lineLength_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorWrite_io_ctl_lineCount_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorWrite_io_ctl_lineCount_csr_clock),
    .reset(addressGeneratorWrite_io_ctl_lineCount_csr_reset),
    .io_csr_dataOut(addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataIn),
    .io_value(addressGeneratorWrite_io_ctl_lineCount_csr_io_value)
  );
  SimpleCSRAXI_AXIL_AXI addressGeneratorWrite_io_ctl_lineGap_csr ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(addressGeneratorWrite_io_ctl_lineGap_csr_clock),
    .reset(addressGeneratorWrite_io_ctl_lineGap_csr_reset),
    .io_csr_dataOut(addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataOut),
    .io_csr_dataWrite(addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataWrite),
    .io_csr_dataIn(addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataIn),
    .io_value(addressGeneratorWrite_io_ctl_lineGap_csr_io_value)
  );
  StatusCSRAXI_AXIL_AXI csr_1 ( // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
    .clock(csr_1_clock),
    .io_csr_dataIn(csr_1_io_csr_dataIn),
    .io_value(csr_1_io_value)
  );
  StatusCSRAXI_AXIL_AXI csr_2 ( // @[src/main/scala/DMAController/CSR/StatusCSR.scala 21:21]
    .clock(csr_2_clock),
    .io_csr_dataIn(csr_2_io_csr_dataIn),
    .io_value(csr_2_io_value)
  );
  SimpleCSRAXI_AXIL_AXI csr_3 ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(csr_3_clock),
    .reset(csr_3_reset),
    .io_csr_dataOut(csr_3_io_csr_dataOut),
    .io_csr_dataWrite(csr_3_io_csr_dataWrite),
    .io_csr_dataIn(csr_3_io_csr_dataIn),
    .io_value(csr_3_io_value)
  );
  SimpleCSRAXI_AXIL_AXI csr_4 ( // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 27:21]
    .clock(csr_4_clock),
    .reset(csr_4_reset),
    .io_csr_dataOut(csr_4_io_csr_dataOut),
    .io_csr_dataWrite(csr_4_io_csr_dataWrite),
    .io_csr_dataIn(csr_4_io_csr_dataIn),
    .io_value(csr_4_io_value)
  );
  assign io_csr_0_dataIn = control_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 32:16]
  assign io_csr_1_dataIn = csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 23:16]
  assign io_csr_2_dataIn = io_irq_irqc_io_imr_dataIn; // @[src/main/scala/DMAController/Worker/InterruptController.scala 49:17]
  assign io_csr_3_dataIn = io_irq_irqc_io_isr_dataIn; // @[src/main/scala/DMAController/Worker/InterruptController.scala 50:17]
  assign io_csr_4_dataIn = addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_5_dataIn = addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_6_dataIn = addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_7_dataIn = addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_8_dataIn = addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_9_dataIn = addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_10_dataIn = addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_11_dataIn = addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_12_dataIn = csr_1_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 23:16]
  assign io_csr_13_dataIn = csr_2_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 23:16]
  assign io_csr_14_dataIn = csr_3_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_csr_15_dataIn = csr_4_io_csr_dataIn; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign io_irq_readerDone = io_irq_irqc_io_irq_readerDone; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 49:10]
  assign io_irq_writerDone = io_irq_irqc_io_irq_writerDone; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 49:10]
  assign io_xferRead_address = transferSplitterRead_io_xferOut_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 77:15]
  assign io_xferRead_length = transferSplitterRead_io_xferOut_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 77:15]
  assign io_xferRead_valid = transferSplitterRead_io_xferOut_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 77:15]
  assign io_xferWrite_address = transferSplitterWrite_io_xferOut_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 80:16]
  assign io_xferWrite_length = transferSplitterWrite_io_xferOut_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 80:16]
  assign io_xferWrite_valid = transferSplitterWrite_io_xferOut_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 80:16]
  assign addressGeneratorRead_clock = clock;
  assign addressGeneratorRead_reset = reset;
  assign addressGeneratorRead_io_ctl_start = readerStart; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 57:37]
  assign addressGeneratorRead_io_ctl_startAddress = addressGeneratorRead_io_ctl_startAddress_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 58:44]
  assign addressGeneratorRead_io_ctl_lineLength = addressGeneratorRead_io_ctl_lineLength_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 59:42]
  assign addressGeneratorRead_io_ctl_lineCount = addressGeneratorRead_io_ctl_lineCount_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 60:41]
  assign addressGeneratorRead_io_ctl_lineGap = addressGeneratorRead_io_ctl_lineGap_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 61:39]
  assign addressGeneratorRead_io_xfer_done = transferSplitterRead_io_xferIn_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 76:34]
  assign transferSplitterRead_io_xferIn_address = addressGeneratorRead_io_xfer_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 76:34]
  assign transferSplitterRead_io_xferIn_length = addressGeneratorRead_io_xfer_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 76:34]
  assign transferSplitterRead_io_xferIn_valid = addressGeneratorRead_io_xfer_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 76:34]
  assign transferSplitterRead_io_xferOut_done = io_xferRead_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 77:15]
  assign addressGeneratorWrite_clock = clock;
  assign addressGeneratorWrite_reset = reset;
  assign addressGeneratorWrite_io_ctl_start = writerStart; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 63:38]
  assign addressGeneratorWrite_io_ctl_startAddress = addressGeneratorWrite_io_ctl_startAddress_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 64:45]
  assign addressGeneratorWrite_io_ctl_lineLength = addressGeneratorWrite_io_ctl_lineLength_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 65:43]
  assign addressGeneratorWrite_io_ctl_lineCount = addressGeneratorWrite_io_ctl_lineCount_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 66:42]
  assign addressGeneratorWrite_io_ctl_lineGap = addressGeneratorWrite_io_ctl_lineGap_csr_io_value; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 67:40]
  assign addressGeneratorWrite_io_xfer_done = transferSplitterWrite_io_xferIn_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 79:35]
  assign transferSplitterWrite_clock = clock;
  assign transferSplitterWrite_reset = reset;
  assign transferSplitterWrite_io_xferIn_address = addressGeneratorWrite_io_xfer_address; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 79:35]
  assign transferSplitterWrite_io_xferIn_length = addressGeneratorWrite_io_xfer_length; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 79:35]
  assign transferSplitterWrite_io_xferIn_valid = addressGeneratorWrite_io_xfer_valid; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 79:35]
  assign transferSplitterWrite_io_xferOut_done = io_xferWrite_done; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 80:16]
  assign control_csr_clock = clock;
  assign control_csr_reset = reset;
  assign control_csr_io_csr_dataOut = io_csr_0_dataOut; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 32:16]
  assign control_csr_io_csr_dataWrite = io_csr_0_dataWrite; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 32:16]
  assign control_csr_io_clear = {{30'd0}, clear}; // @[src/main/scala/DMAController/CSR/ClearCSR.scala 30:18]
  assign csr_clock = clock;
  assign csr_io_value = {{30'd0}, status}; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 25:18]
  assign io_irq_irqc_clock = clock;
  assign io_irq_irqc_reset = reset;
  assign io_irq_irqc_io_readBusy = addressGeneratorRead_io_ctl_busy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 46:22]
  assign io_irq_irqc_io_writeBusy = addressGeneratorWrite_io_ctl_busy; // @[src/main/scala/DMAController/Worker/InterruptController.scala 47:23]
  assign io_irq_irqc_io_imr_dataOut = io_csr_2_dataOut; // @[src/main/scala/DMAController/Worker/InterruptController.scala 49:17]
  assign io_irq_irqc_io_imr_dataWrite = io_csr_2_dataWrite; // @[src/main/scala/DMAController/Worker/InterruptController.scala 49:17]
  assign io_irq_irqc_io_isr_dataOut = io_csr_3_dataOut; // @[src/main/scala/DMAController/Worker/InterruptController.scala 50:17]
  assign io_irq_irqc_io_isr_dataWrite = io_csr_3_dataWrite; // @[src/main/scala/DMAController/Worker/InterruptController.scala 50:17]
  assign addressGeneratorRead_io_ctl_startAddress_csr_clock = clock;
  assign addressGeneratorRead_io_ctl_startAddress_csr_reset = reset;
  assign addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataOut = io_csr_4_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_startAddress_csr_io_csr_dataWrite = io_csr_4_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineLength_csr_clock = clock;
  assign addressGeneratorRead_io_ctl_lineLength_csr_reset = reset;
  assign addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataOut = io_csr_5_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineLength_csr_io_csr_dataWrite = io_csr_5_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineCount_csr_clock = clock;
  assign addressGeneratorRead_io_ctl_lineCount_csr_reset = reset;
  assign addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataOut = io_csr_6_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineCount_csr_io_csr_dataWrite = io_csr_6_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineGap_csr_clock = clock;
  assign addressGeneratorRead_io_ctl_lineGap_csr_reset = reset;
  assign addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataOut = io_csr_7_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorRead_io_ctl_lineGap_csr_io_csr_dataWrite = io_csr_7_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_startAddress_csr_clock = clock;
  assign addressGeneratorWrite_io_ctl_startAddress_csr_reset = reset;
  assign addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataOut = io_csr_8_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_startAddress_csr_io_csr_dataWrite = io_csr_8_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineLength_csr_clock = clock;
  assign addressGeneratorWrite_io_ctl_lineLength_csr_reset = reset;
  assign addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataOut = io_csr_9_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineLength_csr_io_csr_dataWrite = io_csr_9_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineCount_csr_clock = clock;
  assign addressGeneratorWrite_io_ctl_lineCount_csr_reset = reset;
  assign addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataOut = io_csr_10_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineCount_csr_io_csr_dataWrite = io_csr_10_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineGap_csr_clock = clock;
  assign addressGeneratorWrite_io_ctl_lineGap_csr_reset = reset;
  assign addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataOut = io_csr_11_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign addressGeneratorWrite_io_ctl_lineGap_csr_io_csr_dataWrite = io_csr_11_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign csr_1_clock = clock;
  assign csr_1_io_value = 32'h0; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 25:18]
  assign csr_2_clock = clock;
  assign csr_2_io_value = 32'h10; // @[src/main/scala/DMAController/CSR/StatusCSR.scala 25:18]
  assign csr_3_clock = clock;
  assign csr_3_reset = reset;
  assign csr_3_io_csr_dataOut = io_csr_14_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign csr_3_io_csr_dataWrite = io_csr_14_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign csr_4_clock = clock;
  assign csr_4_reset = reset;
  assign csr_4_io_csr_dataOut = io_csr_15_dataOut; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  assign csr_4_io_csr_dataWrite = io_csr_15_dataWrite; // @[src/main/scala/DMAController/CSR/SimpleCSR.scala 29:16]
  always @(posedge clock) begin
    status <= {addressGeneratorRead_io_ctl_busy,addressGeneratorWrite_io_ctl_busy}; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 25:27]
    readerSync <= io_sync_readerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 27:27]
    readerSyncOld <= readerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 28:30]
    writerSync <= io_sync_writerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 30:27]
    writerSyncOld <= writerSync; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 31:30]
    if (reset) begin // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 33:28]
      readerStart <= 1'h0; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 33:28]
    end else begin
      readerStart <= (~readerSyncOld & readerSync | control[3]) & control[1]; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 54:15]
    end
    if (reset) begin // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 34:28]
      writerStart <= 1'h0; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 34:28]
    end else begin
      writerStart <= (~writerSyncOld & writerSync | control[2]) & control[0]; // @[src/main/scala/DMAController/Worker/WorkerCSRWrapper.scala 55:15]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  status = _RAND_0[1:0];
  _RAND_1 = {1{`RANDOM}};
  readerSync = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  readerSyncOld = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  writerSync = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  writerSyncOld = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  readerStart = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  writerStart = _RAND_6[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module DMAQueueAXI_AXIL_AXI( // @[src/main/scala/DMAUtils/DMAUtils.scala 97:7]
  input         clock, // @[src/main/scala/DMAUtils/DMAUtils.scala 97:7]
  input         reset, // @[src/main/scala/DMAUtils/DMAUtils.scala 97:7]
  output        io_enq_ready, // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
  input         io_enq_valid, // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
  input  [31:0] io_enq_bits, // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
  input         io_deq_ready, // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
  output        io_deq_valid, // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
  output [31:0] io_deq_bits // @[src/main/scala/chisel3/util/Decoupled.scala 255:14]
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] ram [0:511]; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire  ram_io_deq_bits_MPORT_en; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire [8:0] ram_io_deq_bits_MPORT_addr; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire [31:0] ram_io_deq_bits_MPORT_data; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire [31:0] ram_MPORT_data; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire [8:0] ram_MPORT_addr; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire  ram_MPORT_mask; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  wire  ram_MPORT_en; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  reg [8:0] enq_ptr_value; // @[src/main/scala/chisel3/util/Counter.scala 61:40]
  reg [8:0] deq_ptr_value; // @[src/main/scala/chisel3/util/Counter.scala 61:40]
  reg  maybe_full; // @[src/main/scala/chisel3/util/Decoupled.scala 259:27]
  wire  ptr_match = enq_ptr_value == deq_ptr_value; // @[src/main/scala/chisel3/util/Decoupled.scala 260:33]
  wire  empty = ptr_match & ~maybe_full; // @[src/main/scala/chisel3/util/Decoupled.scala 261:25]
  wire  full = ptr_match & maybe_full; // @[src/main/scala/chisel3/util/Decoupled.scala 262:24]
  wire  do_enq = io_enq_ready & io_enq_valid; // @[src/main/scala/chisel3/util/Decoupled.scala 51:35]
  wire  do_deq = io_deq_ready & io_deq_valid; // @[src/main/scala/chisel3/util/Decoupled.scala 51:35]
  wire [8:0] _value_T_1 = enq_ptr_value + 9'h1; // @[src/main/scala/chisel3/util/Counter.scala 77:24]
  wire [8:0] _value_T_3 = deq_ptr_value + 9'h1; // @[src/main/scala/chisel3/util/Counter.scala 77:24]
  assign ram_io_deq_bits_MPORT_en = 1'h1;
  assign ram_io_deq_bits_MPORT_addr = deq_ptr_value;
  assign ram_io_deq_bits_MPORT_data = ram[ram_io_deq_bits_MPORT_addr]; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
  assign ram_MPORT_data = io_enq_bits;
  assign ram_MPORT_addr = enq_ptr_value;
  assign ram_MPORT_mask = 1'h1;
  assign ram_MPORT_en = io_enq_ready & io_enq_valid;
  assign io_enq_ready = ~full; // @[src/main/scala/chisel3/util/Decoupled.scala 286:19]
  assign io_deq_valid = ~empty; // @[src/main/scala/chisel3/util/Decoupled.scala 285:19]
  assign io_deq_bits = ram_io_deq_bits_MPORT_data; // @[src/main/scala/chisel3/util/Decoupled.scala 293:17]
  always @(posedge clock) begin
    if (ram_MPORT_en & ram_MPORT_mask) begin
      ram[ram_MPORT_addr] <= ram_MPORT_data; // @[src/main/scala/chisel3/util/Decoupled.scala 256:91]
    end
    if (reset) begin // @[src/main/scala/chisel3/util/Counter.scala 61:40]
      enq_ptr_value <= 9'h0; // @[src/main/scala/chisel3/util/Counter.scala 61:40]
    end else if (do_enq) begin // @[src/main/scala/chisel3/util/Decoupled.scala 269:16]
      enq_ptr_value <= _value_T_1; // @[src/main/scala/chisel3/util/Counter.scala 77:15]
    end
    if (reset) begin // @[src/main/scala/chisel3/util/Counter.scala 61:40]
      deq_ptr_value <= 9'h0; // @[src/main/scala/chisel3/util/Counter.scala 61:40]
    end else if (do_deq) begin // @[src/main/scala/chisel3/util/Decoupled.scala 273:16]
      deq_ptr_value <= _value_T_3; // @[src/main/scala/chisel3/util/Counter.scala 77:15]
    end
    if (reset) begin // @[src/main/scala/chisel3/util/Decoupled.scala 259:27]
      maybe_full <= 1'h0; // @[src/main/scala/chisel3/util/Decoupled.scala 259:27]
    end else if (do_enq != do_deq) begin // @[src/main/scala/chisel3/util/Decoupled.scala 276:27]
      maybe_full <= do_enq; // @[src/main/scala/chisel3/util/Decoupled.scala 277:16]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    ram[initvar] = _RAND_0[31:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  enq_ptr_value = _RAND_1[8:0];
  _RAND_2 = {1{`RANDOM}};
  deq_ptr_value = _RAND_2[8:0];
  _RAND_3 = {1{`RANDOM}};
  maybe_full = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module DMATopAXI_AXIL_AXI( // @[src/main/scala/DMAController/DMATop.scala 12:7]
  input         clock, // @[src/main/scala/DMAController/DMATop.scala 12:7]
  input         reset, // @[src/main/scala/DMAController/DMATop.scala 12:7]
  input  [31:0] io_control_aw_awaddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [2:0]  io_control_aw_awprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_control_aw_awvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_control_aw_awready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [31:0] io_control_w_wdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_control_w_wstrb, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_control_w_wvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_control_w_wready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_control_b_bresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_control_b_bvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_control_b_bready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [31:0] io_control_ar_araddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [2:0]  io_control_ar_arprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_control_ar_arvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_control_ar_arready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_control_r_rdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_control_r_rresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_control_r_rvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_control_r_rready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_aw_awid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_readMem_aw_awaddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_readMem_aw_awlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_readMem_aw_awsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_readMem_aw_awburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_aw_awlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_aw_awcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_readMem_aw_awprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_aw_awqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_aw_awvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_aw_awready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_readMem_w_wdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_w_wstrb, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_w_wlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_w_wvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_w_wready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_readMem_b_bid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_readMem_b_bresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_b_bvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_b_bready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_ar_arid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_readMem_ar_araddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_readMem_ar_arlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_readMem_ar_arsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_readMem_ar_arburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_ar_arlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_ar_arcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_readMem_ar_arprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_readMem_ar_arqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_ar_arvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_ar_arready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_readMem_r_rid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [31:0] io_readMem_r_rdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_readMem_r_rresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_r_rlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_readMem_r_rvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_readMem_r_rready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_aw_awid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave1_aw_awaddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_writeSlave1_aw_awlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave1_aw_awsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_writeSlave1_aw_awburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_aw_awlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_aw_awcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave1_aw_awprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_aw_awqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_aw_awvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_aw_awready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave1_w_wdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_w_wstrb, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_w_wlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_w_wvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_w_wready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_writeSlave1_b_bid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_writeSlave1_b_bresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_b_bvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_b_bready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_ar_arid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave1_ar_araddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_writeSlave1_ar_arlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave1_ar_arsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_writeSlave1_ar_arburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_ar_arlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_ar_arcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave1_ar_arprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave1_ar_arqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_ar_arvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_ar_arready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_writeSlave1_r_rid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [31:0] io_writeSlave1_r_rdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_writeSlave1_r_rresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_r_rlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave1_r_rvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave1_r_rready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_aw_awid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave2_aw_awaddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_writeSlave2_aw_awlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave2_aw_awsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_writeSlave2_aw_awburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_aw_awlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_aw_awcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave2_aw_awprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_aw_awqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_aw_awvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_aw_awready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave2_w_wdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_w_wstrb, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_w_wlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_w_wvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_w_wready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_writeSlave2_b_bid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_writeSlave2_b_bresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_b_bvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_b_bready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_ar_arid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [31:0] io_writeSlave2_ar_araddr, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [7:0]  io_writeSlave2_ar_arlen, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave2_ar_arsize, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [1:0]  io_writeSlave2_ar_arburst, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_ar_arlock, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_ar_arcache, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [2:0]  io_writeSlave2_ar_arprot, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output [3:0]  io_writeSlave2_ar_arqos, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_ar_arvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_ar_arready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [3:0]  io_writeSlave2_r_rid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [31:0] io_writeSlave2_r_rdata, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input  [1:0]  io_writeSlave2_r_rresp, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_r_rlast, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_writeSlave2_r_rvalid, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_writeSlave2_r_rready, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_irq_readerDone, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  output        io_irq_writerDone, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_sync_readerSync, // @[src/main/scala/DMAController/DMATop.scala 16:14]
  input         io_sync_writerSync // @[src/main/scala/DMAController/DMATop.scala 16:14]
);
  wire  csrFrontend_clock; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_reset; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_ctl_aw_awaddr; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_aw_awvalid; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_aw_awready; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_ctl_w_wdata; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_w_wvalid; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_w_wready; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_b_bvalid; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_b_bready; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_ctl_ar_araddr; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_ar_arvalid; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_ar_arready; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_ctl_r_rdata; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_r_rvalid; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_ctl_r_rready; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [3:0] csrFrontend_io_bus_addr; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_bus_dataOut; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire [31:0] csrFrontend_io_bus_dataIn; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_bus_write; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  csrFrontend_io_bus_read; // @[src/main/scala/DMAController/DMATop.scala 25:27]
  wire  readerFrontend_clock; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_reset; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [31:0] readerFrontend_io_bus_ar_araddr; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [7:0] readerFrontend_io_bus_ar_arlen; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_bus_ar_arvalid; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_bus_ar_arready; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [31:0] readerFrontend_io_bus_r_rdata; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_bus_r_rlast; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_bus_r_rvalid; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_bus_r_rready; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_dataIO_ready; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_dataIO_valid; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [31:0] readerFrontend_io_dataIO_bits; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_xfer_done; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [31:0] readerFrontend_io_xfer_address; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire [31:0] readerFrontend_io_xfer_length; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  readerFrontend_io_xfer_valid; // @[src/main/scala/DMAController/DMATop.scala 27:30]
  wire  writerFrontend_clock; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_reset; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] writerFrontend_io_bus_aw_awaddr; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [7:0] writerFrontend_io_bus_aw_awlen; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_aw_awvalid; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_aw_awready; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] writerFrontend_io_bus_w_wdata; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_w_wlast; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_w_wvalid; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_w_wready; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_b_bvalid; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_bus_b_bready; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_dataIO_ready; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_dataIO_valid; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] writerFrontend_io_dataIO_bits; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_xfer_done; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] writerFrontend_io_xfer_address; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] writerFrontend_io_xfer_length; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire  writerFrontend_io_xfer_valid; // @[src/main/scala/DMAController/DMATop.scala 29:30]
  wire [31:0] csr_io_csr_0_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_0_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_0_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_1_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_2_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_2_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_2_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_3_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_3_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_3_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_4_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_4_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_4_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_5_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_5_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_5_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_6_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_6_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_6_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_7_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_7_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_7_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_8_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_8_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_8_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_9_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_9_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_9_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_10_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_10_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_10_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_11_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_11_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_11_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_12_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_13_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_14_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_14_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_14_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_15_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_csr_15_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_csr_15_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [3:0] csr_io_bus_addr; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_bus_dataOut; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire [31:0] csr_io_bus_dataIn; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_bus_write; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  csr_io_bus_read; // @[src/main/scala/DMAController/DMATop.scala 31:19]
  wire  ctl_clock; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_reset; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_0_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_0_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_0_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_1_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_2_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_2_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_2_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_3_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_3_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_3_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_4_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_4_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_4_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_5_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_5_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_5_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_6_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_6_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_6_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_7_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_7_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_7_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_8_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_8_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_8_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_9_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_9_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_9_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_10_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_10_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_10_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_11_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_11_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_11_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_12_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_13_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_14_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_14_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_14_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_15_dataOut; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_csr_15_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_csr_15_dataIn; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_irq_readerDone; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_irq_writerDone; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_sync_readerSync; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_sync_writerSync; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_xferRead_done; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_xferRead_address; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_xferRead_length; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_xferRead_valid; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_xferWrite_done; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_xferWrite_address; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire [31:0] ctl_io_xferWrite_length; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  ctl_io_xferWrite_valid; // @[src/main/scala/DMAController/DMATop.scala 33:19]
  wire  queue_q_clock; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire  queue_q_reset; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire  queue_q_io_enq_ready; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire  queue_q_io_enq_valid; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire [31:0] queue_q_io_enq_bits; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire  queue_q_io_deq_ready; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire  queue_q_io_deq_valid; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  wire [31:0] queue_q_io_deq_bits; // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
  AXI4LiteCSRAXI_AXIL_AXI csrFrontend ( // @[src/main/scala/DMAController/DMATop.scala 25:27]
    .clock(csrFrontend_clock),
    .reset(csrFrontend_reset),
    .io_ctl_aw_awaddr(csrFrontend_io_ctl_aw_awaddr),
    .io_ctl_aw_awvalid(csrFrontend_io_ctl_aw_awvalid),
    .io_ctl_aw_awready(csrFrontend_io_ctl_aw_awready),
    .io_ctl_w_wdata(csrFrontend_io_ctl_w_wdata),
    .io_ctl_w_wvalid(csrFrontend_io_ctl_w_wvalid),
    .io_ctl_w_wready(csrFrontend_io_ctl_w_wready),
    .io_ctl_b_bvalid(csrFrontend_io_ctl_b_bvalid),
    .io_ctl_b_bready(csrFrontend_io_ctl_b_bready),
    .io_ctl_ar_araddr(csrFrontend_io_ctl_ar_araddr),
    .io_ctl_ar_arvalid(csrFrontend_io_ctl_ar_arvalid),
    .io_ctl_ar_arready(csrFrontend_io_ctl_ar_arready),
    .io_ctl_r_rdata(csrFrontend_io_ctl_r_rdata),
    .io_ctl_r_rvalid(csrFrontend_io_ctl_r_rvalid),
    .io_ctl_r_rready(csrFrontend_io_ctl_r_rready),
    .io_bus_addr(csrFrontend_io_bus_addr),
    .io_bus_dataOut(csrFrontend_io_bus_dataOut),
    .io_bus_dataIn(csrFrontend_io_bus_dataIn),
    .io_bus_write(csrFrontend_io_bus_write),
    .io_bus_read(csrFrontend_io_bus_read)
  );
  AXI4ReaderAXI_AXIL_AXI readerFrontend ( // @[src/main/scala/DMAController/DMATop.scala 27:30]
    .clock(readerFrontend_clock),
    .reset(readerFrontend_reset),
    .io_bus_ar_araddr(readerFrontend_io_bus_ar_araddr),
    .io_bus_ar_arlen(readerFrontend_io_bus_ar_arlen),
    .io_bus_ar_arvalid(readerFrontend_io_bus_ar_arvalid),
    .io_bus_ar_arready(readerFrontend_io_bus_ar_arready),
    .io_bus_r_rdata(readerFrontend_io_bus_r_rdata),
    .io_bus_r_rlast(readerFrontend_io_bus_r_rlast),
    .io_bus_r_rvalid(readerFrontend_io_bus_r_rvalid),
    .io_bus_r_rready(readerFrontend_io_bus_r_rready),
    .io_dataIO_ready(readerFrontend_io_dataIO_ready),
    .io_dataIO_valid(readerFrontend_io_dataIO_valid),
    .io_dataIO_bits(readerFrontend_io_dataIO_bits),
    .io_xfer_done(readerFrontend_io_xfer_done),
    .io_xfer_address(readerFrontend_io_xfer_address),
    .io_xfer_length(readerFrontend_io_xfer_length),
    .io_xfer_valid(readerFrontend_io_xfer_valid)
  );
  AXI4WriterAXI_AXIL_AXI writerFrontend ( // @[src/main/scala/DMAController/DMATop.scala 29:30]
    .clock(writerFrontend_clock),
    .reset(writerFrontend_reset),
    .io_bus_aw_awaddr(writerFrontend_io_bus_aw_awaddr),
    .io_bus_aw_awlen(writerFrontend_io_bus_aw_awlen),
    .io_bus_aw_awvalid(writerFrontend_io_bus_aw_awvalid),
    .io_bus_aw_awready(writerFrontend_io_bus_aw_awready),
    .io_bus_w_wdata(writerFrontend_io_bus_w_wdata),
    .io_bus_w_wlast(writerFrontend_io_bus_w_wlast),
    .io_bus_w_wvalid(writerFrontend_io_bus_w_wvalid),
    .io_bus_w_wready(writerFrontend_io_bus_w_wready),
    .io_bus_b_bvalid(writerFrontend_io_bus_b_bvalid),
    .io_bus_b_bready(writerFrontend_io_bus_b_bready),
    .io_dataIO_ready(writerFrontend_io_dataIO_ready),
    .io_dataIO_valid(writerFrontend_io_dataIO_valid),
    .io_dataIO_bits(writerFrontend_io_dataIO_bits),
    .io_xfer_done(writerFrontend_io_xfer_done),
    .io_xfer_address(writerFrontend_io_xfer_address),
    .io_xfer_length(writerFrontend_io_xfer_length),
    .io_xfer_valid(writerFrontend_io_xfer_valid)
  );
  CSRAXI_AXIL_AXI csr ( // @[src/main/scala/DMAController/DMATop.scala 31:19]
    .io_csr_0_dataOut(csr_io_csr_0_dataOut),
    .io_csr_0_dataWrite(csr_io_csr_0_dataWrite),
    .io_csr_0_dataIn(csr_io_csr_0_dataIn),
    .io_csr_1_dataIn(csr_io_csr_1_dataIn),
    .io_csr_2_dataOut(csr_io_csr_2_dataOut),
    .io_csr_2_dataWrite(csr_io_csr_2_dataWrite),
    .io_csr_2_dataIn(csr_io_csr_2_dataIn),
    .io_csr_3_dataOut(csr_io_csr_3_dataOut),
    .io_csr_3_dataWrite(csr_io_csr_3_dataWrite),
    .io_csr_3_dataIn(csr_io_csr_3_dataIn),
    .io_csr_4_dataOut(csr_io_csr_4_dataOut),
    .io_csr_4_dataWrite(csr_io_csr_4_dataWrite),
    .io_csr_4_dataIn(csr_io_csr_4_dataIn),
    .io_csr_5_dataOut(csr_io_csr_5_dataOut),
    .io_csr_5_dataWrite(csr_io_csr_5_dataWrite),
    .io_csr_5_dataIn(csr_io_csr_5_dataIn),
    .io_csr_6_dataOut(csr_io_csr_6_dataOut),
    .io_csr_6_dataWrite(csr_io_csr_6_dataWrite),
    .io_csr_6_dataIn(csr_io_csr_6_dataIn),
    .io_csr_7_dataOut(csr_io_csr_7_dataOut),
    .io_csr_7_dataWrite(csr_io_csr_7_dataWrite),
    .io_csr_7_dataIn(csr_io_csr_7_dataIn),
    .io_csr_8_dataOut(csr_io_csr_8_dataOut),
    .io_csr_8_dataWrite(csr_io_csr_8_dataWrite),
    .io_csr_8_dataIn(csr_io_csr_8_dataIn),
    .io_csr_9_dataOut(csr_io_csr_9_dataOut),
    .io_csr_9_dataWrite(csr_io_csr_9_dataWrite),
    .io_csr_9_dataIn(csr_io_csr_9_dataIn),
    .io_csr_10_dataOut(csr_io_csr_10_dataOut),
    .io_csr_10_dataWrite(csr_io_csr_10_dataWrite),
    .io_csr_10_dataIn(csr_io_csr_10_dataIn),
    .io_csr_11_dataOut(csr_io_csr_11_dataOut),
    .io_csr_11_dataWrite(csr_io_csr_11_dataWrite),
    .io_csr_11_dataIn(csr_io_csr_11_dataIn),
    .io_csr_12_dataIn(csr_io_csr_12_dataIn),
    .io_csr_13_dataIn(csr_io_csr_13_dataIn),
    .io_csr_14_dataOut(csr_io_csr_14_dataOut),
    .io_csr_14_dataWrite(csr_io_csr_14_dataWrite),
    .io_csr_14_dataIn(csr_io_csr_14_dataIn),
    .io_csr_15_dataOut(csr_io_csr_15_dataOut),
    .io_csr_15_dataWrite(csr_io_csr_15_dataWrite),
    .io_csr_15_dataIn(csr_io_csr_15_dataIn),
    .io_bus_addr(csr_io_bus_addr),
    .io_bus_dataOut(csr_io_bus_dataOut),
    .io_bus_dataIn(csr_io_bus_dataIn),
    .io_bus_write(csr_io_bus_write),
    .io_bus_read(csr_io_bus_read)
  );
  WorkerCSRWrapperAXI_AXIL_AXI ctl ( // @[src/main/scala/DMAController/DMATop.scala 33:19]
    .clock(ctl_clock),
    .reset(ctl_reset),
    .io_csr_0_dataOut(ctl_io_csr_0_dataOut),
    .io_csr_0_dataWrite(ctl_io_csr_0_dataWrite),
    .io_csr_0_dataIn(ctl_io_csr_0_dataIn),
    .io_csr_1_dataIn(ctl_io_csr_1_dataIn),
    .io_csr_2_dataOut(ctl_io_csr_2_dataOut),
    .io_csr_2_dataWrite(ctl_io_csr_2_dataWrite),
    .io_csr_2_dataIn(ctl_io_csr_2_dataIn),
    .io_csr_3_dataOut(ctl_io_csr_3_dataOut),
    .io_csr_3_dataWrite(ctl_io_csr_3_dataWrite),
    .io_csr_3_dataIn(ctl_io_csr_3_dataIn),
    .io_csr_4_dataOut(ctl_io_csr_4_dataOut),
    .io_csr_4_dataWrite(ctl_io_csr_4_dataWrite),
    .io_csr_4_dataIn(ctl_io_csr_4_dataIn),
    .io_csr_5_dataOut(ctl_io_csr_5_dataOut),
    .io_csr_5_dataWrite(ctl_io_csr_5_dataWrite),
    .io_csr_5_dataIn(ctl_io_csr_5_dataIn),
    .io_csr_6_dataOut(ctl_io_csr_6_dataOut),
    .io_csr_6_dataWrite(ctl_io_csr_6_dataWrite),
    .io_csr_6_dataIn(ctl_io_csr_6_dataIn),
    .io_csr_7_dataOut(ctl_io_csr_7_dataOut),
    .io_csr_7_dataWrite(ctl_io_csr_7_dataWrite),
    .io_csr_7_dataIn(ctl_io_csr_7_dataIn),
    .io_csr_8_dataOut(ctl_io_csr_8_dataOut),
    .io_csr_8_dataWrite(ctl_io_csr_8_dataWrite),
    .io_csr_8_dataIn(ctl_io_csr_8_dataIn),
    .io_csr_9_dataOut(ctl_io_csr_9_dataOut),
    .io_csr_9_dataWrite(ctl_io_csr_9_dataWrite),
    .io_csr_9_dataIn(ctl_io_csr_9_dataIn),
    .io_csr_10_dataOut(ctl_io_csr_10_dataOut),
    .io_csr_10_dataWrite(ctl_io_csr_10_dataWrite),
    .io_csr_10_dataIn(ctl_io_csr_10_dataIn),
    .io_csr_11_dataOut(ctl_io_csr_11_dataOut),
    .io_csr_11_dataWrite(ctl_io_csr_11_dataWrite),
    .io_csr_11_dataIn(ctl_io_csr_11_dataIn),
    .io_csr_12_dataIn(ctl_io_csr_12_dataIn),
    .io_csr_13_dataIn(ctl_io_csr_13_dataIn),
    .io_csr_14_dataOut(ctl_io_csr_14_dataOut),
    .io_csr_14_dataWrite(ctl_io_csr_14_dataWrite),
    .io_csr_14_dataIn(ctl_io_csr_14_dataIn),
    .io_csr_15_dataOut(ctl_io_csr_15_dataOut),
    .io_csr_15_dataWrite(ctl_io_csr_15_dataWrite),
    .io_csr_15_dataIn(ctl_io_csr_15_dataIn),
    .io_irq_readerDone(ctl_io_irq_readerDone),
    .io_irq_writerDone(ctl_io_irq_writerDone),
    .io_sync_readerSync(ctl_io_sync_readerSync),
    .io_sync_writerSync(ctl_io_sync_writerSync),
    .io_xferRead_done(ctl_io_xferRead_done),
    .io_xferRead_address(ctl_io_xferRead_address),
    .io_xferRead_length(ctl_io_xferRead_length),
    .io_xferRead_valid(ctl_io_xferRead_valid),
    .io_xferWrite_done(ctl_io_xferWrite_done),
    .io_xferWrite_address(ctl_io_xferWrite_address),
    .io_xferWrite_length(ctl_io_xferWrite_length),
    .io_xferWrite_valid(ctl_io_xferWrite_valid)
  );
  DMAQueueAXI_AXIL_AXI queue_q ( // @[src/main/scala/DMAUtils/DMAUtils.scala 115:23]
    .clock(queue_q_clock),
    .reset(queue_q_reset),
    .io_enq_ready(queue_q_io_enq_ready),
    .io_enq_valid(queue_q_io_enq_valid),
    .io_enq_bits(queue_q_io_enq_bits),
    .io_deq_ready(queue_q_io_deq_ready),
    .io_deq_valid(queue_q_io_deq_valid),
    .io_deq_bits(queue_q_io_deq_bits)
  );
  assign io_control_aw_awready = csrFrontend_io_ctl_aw_awready; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_w_wready = csrFrontend_io_ctl_w_wready; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_b_bresp = 2'h0; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_b_bvalid = csrFrontend_io_ctl_b_bvalid; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_ar_arready = csrFrontend_io_ctl_ar_arready; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_r_rdata = csrFrontend_io_ctl_r_rdata; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_r_rresp = 2'h0; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_control_r_rvalid = csrFrontend_io_ctl_r_rvalid; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign io_readMem_aw_awid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awaddr = 32'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awlen = 8'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awsize = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awburst = 2'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awcache = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_aw_awvalid = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_w_wdata = 32'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_w_wstrb = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_w_wlast = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_w_wvalid = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_b_bready = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_araddr = readerFrontend_io_bus_ar_araddr; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arlen = readerFrontend_io_bus_ar_arlen; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arsize = 3'h2; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arburst = 2'h1; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arcache = 4'h2; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_ar_arvalid = readerFrontend_io_bus_ar_arvalid; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_readMem_r_rready = readerFrontend_io_bus_r_rready; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign io_writeSlave1_aw_awid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awaddr = writerFrontend_io_bus_aw_awaddr; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awlen = writerFrontend_io_bus_aw_awlen; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awsize = 3'h2; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awburst = 2'h1; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awcache = 4'h2; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_aw_awvalid = writerFrontend_io_bus_aw_awvalid; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_w_wdata = writerFrontend_io_bus_w_wdata; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_w_wstrb = 4'hf; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_w_wlast = writerFrontend_io_bus_w_wlast; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_w_wvalid = writerFrontend_io_bus_w_wvalid; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_b_bready = writerFrontend_io_bus_b_bready; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_araddr = 32'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arlen = 8'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arsize = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arburst = 2'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arcache = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_ar_arvalid = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave1_r_rready = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 46:18]
  assign io_writeSlave2_aw_awid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awaddr = writerFrontend_io_bus_aw_awaddr; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awlen = writerFrontend_io_bus_aw_awlen; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awsize = 3'h2; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awburst = 2'h1; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awcache = 4'h2; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_aw_awvalid = writerFrontend_io_bus_aw_awvalid; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_w_wdata = writerFrontend_io_bus_w_wdata; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_w_wstrb = 4'hf; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_w_wlast = writerFrontend_io_bus_w_wlast; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_w_wvalid = writerFrontend_io_bus_w_wvalid; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_b_bready = writerFrontend_io_bus_b_bready; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arid = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_araddr = 32'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arlen = 8'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arsize = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arburst = 2'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arlock = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arcache = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arprot = 3'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arqos = 4'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_ar_arvalid = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_writeSlave2_r_rready = 1'h0; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign io_irq_readerDone = ctl_io_irq_readerDone; // @[src/main/scala/DMAController/DMATop.scala 49:10]
  assign io_irq_writerDone = ctl_io_irq_writerDone; // @[src/main/scala/DMAController/DMATop.scala 49:10]
  assign csrFrontend_clock = clock;
  assign csrFrontend_reset = reset;
  assign csrFrontend_io_ctl_aw_awaddr = io_control_aw_awaddr; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_aw_awvalid = io_control_aw_awvalid; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_w_wdata = io_control_w_wdata; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_w_wvalid = io_control_w_wvalid; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_b_bready = io_control_b_bready; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_ar_araddr = io_control_ar_araddr; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_ar_arvalid = io_control_ar_arvalid; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_ctl_r_rready = io_control_r_rready; // @[src/main/scala/DMAController/DMATop.scala 38:22]
  assign csrFrontend_io_bus_dataIn = csr_io_bus_dataIn; // @[src/main/scala/DMAController/DMATop.scala 39:14]
  assign readerFrontend_clock = clock;
  assign readerFrontend_reset = reset;
  assign readerFrontend_io_bus_ar_arready = io_readMem_ar_arready; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign readerFrontend_io_bus_r_rdata = io_readMem_r_rdata; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign readerFrontend_io_bus_r_rlast = io_readMem_r_rlast; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign readerFrontend_io_bus_r_rvalid = io_readMem_r_rvalid; // @[src/main/scala/DMAController/DMATop.scala 44:14]
  assign readerFrontend_io_dataIO_ready = queue_q_io_enq_ready; // @[src/main/scala/DMAUtils/DMAUtils.scala 119:19]
  assign readerFrontend_io_xfer_address = ctl_io_xferRead_address; // @[src/main/scala/DMAController/DMATop.scala 41:26]
  assign readerFrontend_io_xfer_length = ctl_io_xferRead_length; // @[src/main/scala/DMAController/DMATop.scala 41:26]
  assign readerFrontend_io_xfer_valid = ctl_io_xferRead_valid; // @[src/main/scala/DMAController/DMATop.scala 41:26]
  assign writerFrontend_clock = clock;
  assign writerFrontend_reset = reset;
  assign writerFrontend_io_bus_aw_awready = io_writeSlave2_aw_awready; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign writerFrontend_io_bus_w_wready = io_writeSlave2_w_wready; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign writerFrontend_io_bus_b_bvalid = io_writeSlave2_b_bvalid; // @[src/main/scala/DMAController/DMATop.scala 47:18]
  assign writerFrontend_io_dataIO_valid = queue_q_io_deq_valid; // @[src/main/scala/DMAController/DMATop.scala 36:9]
  assign writerFrontend_io_dataIO_bits = queue_q_io_deq_bits; // @[src/main/scala/DMAController/DMATop.scala 36:9]
  assign writerFrontend_io_xfer_address = ctl_io_xferWrite_address; // @[src/main/scala/DMAController/DMATop.scala 42:26]
  assign writerFrontend_io_xfer_length = ctl_io_xferWrite_length; // @[src/main/scala/DMAController/DMATop.scala 42:26]
  assign writerFrontend_io_xfer_valid = ctl_io_xferWrite_valid; // @[src/main/scala/DMAController/DMATop.scala 42:26]
  assign csr_io_csr_0_dataIn = ctl_io_csr_0_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_1_dataIn = ctl_io_csr_1_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_2_dataIn = ctl_io_csr_2_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_3_dataIn = ctl_io_csr_3_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_4_dataIn = ctl_io_csr_4_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_5_dataIn = ctl_io_csr_5_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_6_dataIn = ctl_io_csr_6_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_7_dataIn = ctl_io_csr_7_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_8_dataIn = ctl_io_csr_8_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_9_dataIn = ctl_io_csr_9_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_10_dataIn = ctl_io_csr_10_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_11_dataIn = ctl_io_csr_11_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_12_dataIn = ctl_io_csr_12_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_13_dataIn = ctl_io_csr_13_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_14_dataIn = ctl_io_csr_14_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_csr_15_dataIn = ctl_io_csr_15_dataIn; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign csr_io_bus_addr = csrFrontend_io_bus_addr; // @[src/main/scala/DMAController/DMATop.scala 39:14]
  assign csr_io_bus_dataOut = csrFrontend_io_bus_dataOut; // @[src/main/scala/DMAController/DMATop.scala 39:14]
  assign csr_io_bus_write = csrFrontend_io_bus_write; // @[src/main/scala/DMAController/DMATop.scala 39:14]
  assign csr_io_bus_read = csrFrontend_io_bus_read; // @[src/main/scala/DMAController/DMATop.scala 39:14]
  assign ctl_clock = clock;
  assign ctl_reset = reset;
  assign ctl_io_csr_0_dataOut = csr_io_csr_0_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_0_dataWrite = csr_io_csr_0_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_2_dataOut = csr_io_csr_2_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_2_dataWrite = csr_io_csr_2_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_3_dataOut = csr_io_csr_3_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_3_dataWrite = csr_io_csr_3_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_4_dataOut = csr_io_csr_4_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_4_dataWrite = csr_io_csr_4_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_5_dataOut = csr_io_csr_5_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_5_dataWrite = csr_io_csr_5_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_6_dataOut = csr_io_csr_6_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_6_dataWrite = csr_io_csr_6_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_7_dataOut = csr_io_csr_7_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_7_dataWrite = csr_io_csr_7_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_8_dataOut = csr_io_csr_8_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_8_dataWrite = csr_io_csr_8_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_9_dataOut = csr_io_csr_9_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_9_dataWrite = csr_io_csr_9_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_10_dataOut = csr_io_csr_10_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_10_dataWrite = csr_io_csr_10_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_11_dataOut = csr_io_csr_11_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_11_dataWrite = csr_io_csr_11_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_14_dataOut = csr_io_csr_14_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_14_dataWrite = csr_io_csr_14_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_15_dataOut = csr_io_csr_15_dataOut; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_csr_15_dataWrite = csr_io_csr_15_dataWrite; // @[src/main/scala/DMAController/DMATop.scala 40:14]
  assign ctl_io_sync_readerSync = io_sync_readerSync; // @[src/main/scala/DMAController/DMATop.scala 50:11]
  assign ctl_io_sync_writerSync = io_sync_writerSync; // @[src/main/scala/DMAController/DMATop.scala 50:11]
  assign ctl_io_xferRead_done = readerFrontend_io_xfer_done; // @[src/main/scala/DMAController/DMATop.scala 41:26]
  assign ctl_io_xferWrite_done = writerFrontend_io_xfer_done; // @[src/main/scala/DMAController/DMATop.scala 42:26]
  assign queue_q_clock = clock;
  assign queue_q_reset = reset;
  assign queue_q_io_enq_valid = readerFrontend_io_dataIO_valid; // @[src/main/scala/DMAUtils/DMAUtils.scala 117:24]
  assign queue_q_io_enq_bits = readerFrontend_io_dataIO_bits; // @[src/main/scala/DMAUtils/DMAUtils.scala 118:23]
  assign queue_q_io_deq_ready = writerFrontend_io_dataIO_ready; // @[src/main/scala/DMAController/DMATop.scala 36:9]
endmodule
