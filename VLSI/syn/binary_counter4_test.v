`timescale 1ns/1ps

module binary_counter4_test;
reg clk, reset, enable;
wire [3:0] q;
wire carry_out;

binary_counter4 uut (
    .clk(clk),
    .reset(reset),
    .enable(enable),
    .q(q),
    .carry_out(carry_out)
);

always #5 clk = ~clk;

initial begin
    clk = 0;
    reset = 1;
    enable = 1;
    #2;
    if (q !== 4'b0000) begin
        $display("binary_counter4 reset failed: q=%b", q);
        $finish;
    end

    reset = 0;
    repeat (3) @(posedge clk);
    #1;
    if (q !== 4'b0011) begin
        $display("binary_counter4 increment failed: q=%b", q);
        $finish;
    end

    enable = 0;
    @(posedge clk);
    #1;
    if (q !== 4'b0011) begin
        $display("binary_counter4 enable failed: q=%b", q);
        $finish;
    end

    enable = 1;
    repeat (12) @(posedge clk);
    #1;
    if ((q !== 4'b1111) || !carry_out) begin
        $display("binary_counter4 rollover carry failed: q=%b carry=%b", q, carry_out);
        $finish;
    end

    @(posedge clk);
    #1;
    if (q !== 4'b0000) begin
        $display("binary_counter4 rollover failed: q=%b", q);
        $finish;
    end
    $finish;
end

endmodule
