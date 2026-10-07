`timescale 1ns/1ps
module or_gate_test;
reg a, b;
wire y;
or_gate uut (.a(a), .b(b), .y(y));
initial begin
    $monitor("Time = %0t | a = %b | b = %b | y = %b", $time, a, b, y);
    a = 0; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 0; #10;
    a = 1; b = 1; #10;
    assert (y === 1'b1) else $fatal(1, "or_gate failed: y=%b", y);
    $finish;
end
endmodule
