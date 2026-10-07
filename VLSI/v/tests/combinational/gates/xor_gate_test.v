`timescale 1ns/1ps
module xor_gate_test;
reg a, b;
wire y;
xor_gate uut (.a(a), .b(b), .y(y));
initial begin
    $monitor("Time = %0t | a = %b | b = %b | y = %b", $time, a, b, y);
    a = 0; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 0; #10;
    a = 1; b = 1; #10;
    assert (y === 1'b0) else $fatal(1, "xor_gate failed: y=%b", y);
    $finish;
end
endmodule
