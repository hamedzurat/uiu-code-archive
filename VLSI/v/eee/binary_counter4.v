`timescale 1ns/1ps

// Four-bit binary up-counter.
// carry_out is asserted when an enabled increment will wrap this counter.
module binary_counter4 (
    input clk,
    input reset,
    input enable,
    output reg [3:0] q,
    output carry_out
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 4'b0000;
    else if (enable)
        q <= q + 4'b0001;
end

assign carry_out = enable && (q == 4'b1111);

endmodule
