`timescale 1ns/1ps
module sequence_detector101_test;
reg bit_in, clk, reset;
wire detected;
sequence_detector101 uut (.bit_in(bit_in), .clk(clk), .reset(reset), .detected(detected));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | bit_in = %b | detected = %b", $time, bit_in, detected);
    clk = 0; reset = 1; bit_in = 0; #3;
    reset = 0;
    bit_in = 1; #10;
    bit_in = 0; #10;
    bit_in = 1; #10;
    bit_in = 1; #10;
    bit_in = 0; #10;
    bit_in = 1; #10;
    assert (detected === 1'b0)
        else $fatal(1, "sequence_detector101 failed: detected=%b", detected);
    $finish;
end
endmodule
