`timescale 1ns/1ps
module sr_flip_flop_test;
reg s, r, clk;
wire q, qbar;
sr_flip_flop uut (.s(s), .r(r), .clk(clk), .q(q), .qbar(qbar));
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | s = %b | r = %b | q = %b | qbar = %b", $time, s, r, q, qbar);
    clk = 0; s = 0; r = 1; #10;
    s = 0; r = 0; #10;
    s = 1; r = 0; #10;
    s = 0; r = 0; #10;
    assert ((q === 1'b1) && (qbar === 1'b0))
        else $fatal(1, "sr_flip_flop failed: q=%b qbar=%b", q, qbar);
    $finish;
end
endmodule
