`timescale 1ns/1ps
module decoder38_test;
reg a, b, c;
wire [7:0] out;
decoder38 uut (.a(a), .b(b), .c(c), .out(out));
initial begin
    $monitor("Time = %0t | c = %b | b = %b | a = %b | out = %b", $time, c, b, a, out);
    c = 0; b = 0; a = 0; #10;
    c = 0; b = 1; a = 1; #10;
    c = 1; b = 0; a = 0; #10;
    c = 1; b = 1; a = 1; #10;
    assert (out === 8'b10000000)
        else $fatal(1, "decoder38 failed: out=%b", out);
    $finish;
end
endmodule
