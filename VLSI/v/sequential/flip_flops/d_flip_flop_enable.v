`timescale 1ns/1ps

module d_flip_flop_enable (
    input d,
    input clk,
    input reset,
    input enable,
    output reg q,
    output qbar
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 1'b0;
    else if (enable)
        q <= d;
end

assign qbar = ~q;

endmodule
