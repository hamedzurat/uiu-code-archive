`timescale 1ns/1ps
module not_gate_test;
reg a;
wire y;
not_gate uut (.a(a), .y(y));
initial begin
    $monitor("Time = %0t | a = %b | y = %b", $time, a, y);
    a = 0; #10;
    a = 1; #10;
    assert (y === 1'b0) else $fatal(1, "not_gate failed: y=%b", y);
    $finish;
end
endmodule
