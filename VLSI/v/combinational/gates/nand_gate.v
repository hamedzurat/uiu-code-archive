`timescale 1ns/1ps

module nand_gate (input a, input b, output y);
assign y = ~(a & b);
endmodule
