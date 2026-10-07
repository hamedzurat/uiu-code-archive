`timescale 1ns/1ps
module t_flip_flop_test;
reg t, clk, reset;
wire q, qbar;
t_flip_flop uut (.t(t), .clk(clk), .reset(reset), .q(q), .qbar(qbar));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | t = %b | q = %b | qbar = %b", $time, t, q, qbar);
    clk = 0; reset = 1; t = 0; #3;
    reset = 0; t = 1; #30;
    t = 0; #10;
    assert ((q === 1'b1) && (qbar === 1'b0))
        else $fatal(1, "t_flip_flop failed: q=%b qbar=%b", q, qbar);
    $finish;
end
endmodule
