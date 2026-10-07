`timescale 1ns/1ps
module demux12_test;
reg din, s;
wire y0, y1;
demux12 uut (.din(din), .s(s), .y0(y0), .y1(y1));
initial begin
    $monitor("Time = %0t | din = %b | s = %b | y0 = %b | y1 = %b", $time, din, s, y0, y1);
    din = 0; s = 0; #10;
    din = 1; s = 0; #10;
    din = 1; s = 1; #10;
    din = 0; s = 1; #10;
    assert ((y0 === 1'b0) && (y1 === 1'b0))
        else $fatal(1, "demux12 failed: y0=%b y1=%b", y0, y1);
    $finish;
end
endmodule
