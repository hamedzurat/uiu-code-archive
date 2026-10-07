`timescale 1ns/1ps
module register4_test;
reg [3:0] d;
reg clk, reset, enable;
wire [3:0] q;
register4 uut (.d(d), .clk(clk), .reset(reset), .enable(enable), .q(q));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | d = %b | reset = %b | enable = %b | q = %b", $time, d, reset, enable, q);
    clk = 0; reset = 1; enable = 0; d = 0; #3;
    reset = 0; enable = 1; d = 4'b1010; #10;
    enable = 0; d = 4'b0101; #10;
    enable = 1; #10;
    assert (q === 4'b0101)
        else $fatal(1, "register4 failed: q=%b", q);
    $finish;
end
endmodule
