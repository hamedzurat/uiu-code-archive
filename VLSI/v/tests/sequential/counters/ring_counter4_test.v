`timescale 1ns/1ps
module ring_counter4_test;
reg clk, reset;
wire [3:0] q;
ring_counter4 uut (.clk(clk), .reset(reset), .q(q));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | reset = %b | q = %b", $time, reset, q);
    clk = 0; reset = 1; #3;
    reset = 0; #50;
    assert (q === 4'b0010)
        else $fatal(1, "ring_counter4 failed: q=%b", q);
    $finish;
end
endmodule
