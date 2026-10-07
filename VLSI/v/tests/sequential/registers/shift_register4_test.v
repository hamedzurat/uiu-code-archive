`timescale 1ns/1ps
module shift_register4_test;
reg serial_in, clk, reset;
wire [3:0] q;
shift_register4 uut (.serial_in(serial_in), .clk(clk), .reset(reset), .q(q));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | serial_in = %b | q = %b", $time, serial_in, q);
    clk = 0; reset = 1; serial_in = 0; #3;
    reset = 0; serial_in = 1; #10;
    serial_in = 0; #10;
    serial_in = 1; #10;
    serial_in = 1; #10;
    assert (q === 4'b1011)
        else $fatal(1, "shift_register4 failed: q=%b", q);
    $finish;
end
endmodule
