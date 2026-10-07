`timescale 1ns/1ps
module d_latch_test;
reg d, en;
wire q, qbar;
d_latch uut (.d(d), .en(en), .q(q), .qbar(qbar));
initial begin
    $monitor("Time = %0t | d = %b | en = %b | q = %b | qbar = %b", $time, d, en, q, qbar);
    d = 0; en = 1; #10;
    d = 1; en = 1; #10;
    d = 0; en = 0; #10;
    d = 1; en = 0; #10;
    d = 0; en = 1; #10;
    assert ((q === 1'b0) && (qbar === 1'b1))
        else $fatal(1, "d_latch failed: q=%b qbar=%b", q, qbar);
    $finish;
end
endmodule
