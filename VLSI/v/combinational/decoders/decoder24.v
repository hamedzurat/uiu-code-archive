`timescale 1ns/1ps

module decoder24 (
    input a,
    input b,
    output [3:0] out
);

assign out = 4'b0001 << {b, a};

endmodule
