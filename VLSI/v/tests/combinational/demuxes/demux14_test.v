`timescale 1ns/1ps
module demux14_test;
reg din, s0, s1;
wire [3:0] out;
demux14 uut (.din(din), .s0(s0), .s1(s1), .out(out));
initial begin
    $monitor("Time = %0t | din = %b | s1 = %b | s0 = %b | out = %b", $time, din, s1, s0, out);
    din = 1; s1 = 0; s0 = 0; #10;
    s1 = 0; s0 = 1; #10;
    s1 = 1; s0 = 0; #10;
    s1 = 1; s0 = 1; #10;
    assert (out === 4'b1000)
        else $fatal(1, "demux14 failed: out=%b", out);
    $finish;
end
endmodule
