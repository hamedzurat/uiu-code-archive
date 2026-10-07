`timescale 1ns/1ps
module jk_flip_flop_test;
reg j, k, clk, reset;
wire q, qbar;
jk_flip_flop uut (.j(j), .k(k), .clk(clk), .reset(reset), .q(q), .qbar(qbar));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | j = %b | k = %b | q = %b | qbar = %b", $time, j, k, q, qbar);
    clk = 0; reset = 1; j = 0; k = 0; #3;
    reset = 0; j = 1; k = 0; #10;
    j = 0; k = 1; #10;
    j = 1; k = 1; #20;
    j = 0; k = 0; #10;
    assert ((q === 1'b0) && (qbar === 1'b1))
        else $fatal(1, "jk_flip_flop failed: q=%b qbar=%b", q, qbar);
    $finish;
end
endmodule
