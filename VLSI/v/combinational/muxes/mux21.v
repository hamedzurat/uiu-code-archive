`timescale 1ns/1ps

module mux21 (
    input i0,
    input i1,
    input s,
    output out
);

assign out = (s) ? i1 : i0;

endmodule
