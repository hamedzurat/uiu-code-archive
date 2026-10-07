`timescale 1ns/1ps

module mux41_test;

reg i0;
reg i1;
reg i2;
reg i3;
reg s0;
reg s1;
wire out;

mux41 uut (
    .i0(i0), .i1(i1), .i2(i2), .i3(i3),
    .s0(s0), .s1(s1), .out(out)
);

initial begin
    $monitor("Time = %0t | inputs = %b%b%b%b | select = %b%b | out = %b",
             $time, i3, i2, i1, i0, s1, s0, out);

    i0 = 0; i1 = 1; i2 = 0; i3 = 1; s1 = 0; s0 = 0; #10;
    s1 = 0; s0 = 1; #10;
    s1 = 1; s0 = 0; #10;
    s1 = 1; s0 = 1; #10;

    assert (out === 1'b1) else $fatal(1, "mux41 failed: out=%b", out);

    $finish;
end

endmodule
