`timescale 1ns/1ps

module full_adder (
    input a,
    input b,
    input cin,
    output sum,
    output cout
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
    .b(cin),
    .sum(sum),
    .carry(carry_second)
);

assign cout = carry_first | carry_second;

endmodule
