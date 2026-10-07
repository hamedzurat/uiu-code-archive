`timescale 1ns/1ps
module half_subtractor_test;
reg a, b;
wire difference, borrow;
half_subtractor uut (.a(a), .b(b), .difference(difference), .borrow(borrow));
initial begin
    $monitor("Time = %0t | a = %b | b = %b | difference = %b | borrow = %b",
             $time, a, b, difference, borrow);
    a = 0; b = 0; #10;
    a = 0; b = 1; #10;
    a = 1; b = 0; #10;
    a = 1; b = 1; #10;
    assert ((difference === 1'b0) && (borrow === 1'b0))
        else $fatal(1, "half_subtractor failed: difference=%b borrow=%b", difference, borrow);
    $finish;
end
endmodule
