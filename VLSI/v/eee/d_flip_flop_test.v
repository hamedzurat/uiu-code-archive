`timescale 1ns/1ps
module d_flip_flop_test;
reg d, clk, reset;
wire q, qbar;
d_flip_flop uut (.d(d), .clk(clk), .reset(reset), .q(q), .qbar(qbar));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | d = %b | reset = %b | q = %b | qbar = %b", $time, d, reset, q, qbar);
    clk = 0; d = 0; reset = 1; #3;
    reset = 0; d = 1; #10;
    d = 0; #10;
    reset = 1; #3;
    reset = 0; d = 1; #10;
    if (!((q === 1'b1) && (qbar === 1'b0))) begin
        $display("d_flip_flop failed: q=%b qbar=%b", q, qbar);
        $finish;
    end
    $finish;
end
endmodule
