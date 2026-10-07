`timescale 1ns/1ps

module half_subtractor (
    input a,
    input b,
    output difference,
    output borrow
);

assign difference = a ^ b;
assign borrow = ~a & b;

endmodule
