`timescale 1ns/1ps

module saturating_counter4 (
    input clk,
    input reset,
    input enable,
    output reg [3:0] q
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 4'b0000;
    else if (enable && q != 4'b1111)
        q <= q + 4'b0001;
end

endmodule
