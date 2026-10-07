`timescale 1ns/1ps

module sr_flip_flop (
    input s,
    input r,
    input clk,
    output reg q,
    output qbar
);

always @ (posedge clk) begin
    if (s && !r) begin
        q <= 1'b1;
    end else if (!s && r) begin
        q <= 1'b0;
    end else if (s && r) begin
        q <= 1'bx;
    end
end

assign qbar = ~q;

endmodule
