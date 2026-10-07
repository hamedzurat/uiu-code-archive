`timescale 1ns/1ps
module sr_latch_test;
reg s, r;
wire q, qbar;
sr_latch uut (.s(s), .r(r), .q(q), .qbar(qbar));
initial begin
    $monitor("Time = %0t | s = %b | r = %b | q = %b | qbar = %b", $time, s, r, q, qbar);
    s = 0; r = 1; #10;
    s = 0; r = 0; #10;
    s = 1; r = 0; #10;
    s = 0; r = 0; #10;
    s = 0; r = 1; #10;
    assert ((q === 1'b0) && (qbar === 1'b1))
        else $fatal(1, "sr_latch failed: q=%b qbar=%b", q, qbar);
    $finish;
end
endmodule
