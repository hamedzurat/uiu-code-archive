`timescale 1ns/1ps
module full_subtractor_test;
reg a, b, bin;
wire difference, bout;
full_subtractor uut (
    .a(a), .b(b), .bin(bin), .difference(difference), .bout(bout)
);
initial begin
    $monitor("Time = %0t | a = %b | b = %b | bin = %b | difference = %b | bout = %b",
             $time, a, b, bin, difference, bout);
    a = 0; b = 0; bin = 0; #10;
    a = 0; b = 1; bin = 0; #10;
    a = 1; b = 0; bin = 1; #10;
    a = 1; b = 1; bin = 1; #10;
    assert ((difference === 1'b1) && (bout === 1'b1))
        else $fatal(1, "full_subtractor failed: difference=%b bout=%b", difference, bout);
    $finish;
end
endmodule
