`timescale 1ns/1ps

module demux12 (
    input din,
    input s,
    output y0,
    output y1
);

assign y0 = din & ~s;
assign y1 = din & s;

endmodule
