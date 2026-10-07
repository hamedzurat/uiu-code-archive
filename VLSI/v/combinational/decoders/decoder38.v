`timescale 1ns/1ps

module decoder38 (
    input a,
    input b,
    input c,
    output [7:0] out
);

wire [3:0] low;

decoder24 decoder_low (
    .a(a), .b(b), .out(low)
);

assign out = c ? {low, 4'b0000} : {4'b0000, low};

endmodule
