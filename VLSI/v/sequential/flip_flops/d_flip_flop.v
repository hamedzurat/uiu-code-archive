`timescale 1ns/1ps

module d_flip_flop (
    input d,
    input clk,
    input reset,
    output reg q,
    output qbar
);

always @ (posedge clk or posedge reset) begin
    if (reset) begin
        q <= 1'b0;
    end else begin
        q <= d;
    end
end

assign qbar = ~q;

endmodule
