`timescale 1ns/1ps

module demux14 (
    input din,
    input s0,
    input s1,
    output [3:0] out
);

wire low;
wire high;

demux12 demux_low (
    .din(din), .s(s1), .y0(low), .y1(high)
);

demux12 demux0 (
    .din(low), .s(s0), .y0(out[0]), .y1(out[1])
);

demux12 demux1 (
    .din(high), .s(s0), .y0(out[2]), .y1(out[3])
);

endmodule
