`timescale 1ns/1ps

module mux21_test;

reg i0;
reg i1;
reg s;
wire out;

mux21 uut (
    .i0(i0), .i1(i1), .s(s), .out(out)
);

initial begin
    $monitor("Time = %0t | i0 = %b | i1 = %b | s = %b | out = %b",
             $time, i0, i1, s, out);

    i0 = 0; i1 = 1; s = 0; #10;
    i0 = 1; i1 = 0; s = 0; #10;
    i0 = 0; i1 = 1; s = 1; #10;
    i0 = 1; i1 = 0; s = 1; #10;
    i0 = 0; i1 = 0; s = 0; #10;
    i0 = 1; i1 = 1; s = 1; #10;

    assert (out === 1'b1) else $fatal(1, "mux21 failed: out=%b", out);

    $finish;
end

endmodule
