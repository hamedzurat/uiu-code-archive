`timescale 1ns/1ps

module mux41 (
    input i0,
    input i1,
    input i2,
    input i3,
    input s0,
    input s1,
    output out
);

assign out = ({s1, s0} == 2'b00) ? i0 :
             ({s1, s0} == 2'b01) ? i1 :
             ({s1, s0} == 2'b10) ? i2 : i3;

endmodule
