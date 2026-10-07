`timescale 1ns/1ps

// Structural 32-bit ripple-carry adder.
// The result is a + b + carry_in; carry_out is the carry beyond bit 31.
module adder32 (
    input  [31:0] a,
    input  [31:0] b,
    input         carry_in,
    output [31:0] sum,
    output        carry_out
);

wire [32:0] carry;

assign carry[0] = carry_in;
assign carry_out = carry[32];

genvar bit_number;
generate
    for (bit_number = 0; bit_number < 32; bit_number = bit_number + 1) begin : gen_full_adders
        full_adder fa (
            .a(a[bit_number]),
            .b(b[bit_number]),
            .carry_in(carry[bit_number]),
            .sum(sum[bit_number]),
            .carry_out(carry[bit_number + 1])
        );
    end
endgenerate

endmodule
