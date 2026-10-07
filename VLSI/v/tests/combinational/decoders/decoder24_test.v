`timescale 1ns/1ps
module decoder24_test;
reg a, b;
wire [3:0] out;
decoder24 uut (.a(a), .b(b), .out(out));
initial begin
    $monitor("Time = %0t | a = %b | b = %b | out = %b", $time, a, b, out);
    a = 0; b = 0; #10;
    a = 1; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 1; #10;
    assert (out === 4'b1000)
        else $fatal(1, "decoder24 failed: out=%b", out);
    $finish;
end
endmodule
