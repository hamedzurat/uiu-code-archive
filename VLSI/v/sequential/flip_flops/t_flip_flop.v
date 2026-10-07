`timescale 1ns/1ps

module t_flip_flop (
    input t,
    input clk,
    input reset,
    output reg q,
    output qbar
);

always @ (posedge clk or posedge reset) begin
    if (reset) begin
        q <= 1'b0;
    end else if (t) begin
        q <= ~q;
    end
end

assign qbar = ~q;

endmodule
