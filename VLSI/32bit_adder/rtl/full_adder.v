`timescale 1ns/1ps

// One-bit full adder, built from two half adders.
module full_adder (
    input  a,
    input  b,
    input  carry_in,
    output sum,
    output carry_out
);

wire sum_first;
wire carry_first;
wire carry_second;

half_adder ha0 (
    .a(a),
    .b(b),
    .sum(sum_first),
    .carry(carry_first)
);

half_adder ha1 (
    .a(sum_first),
    .b(carry_in),
    .sum(sum),
    .carry(carry_second)
);

assign carry_out = carry_first | carry_second;

endmodule
