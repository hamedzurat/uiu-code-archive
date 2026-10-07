`timescale 1ns/1ps

module register4 (
    input [3:0] d,
    input clk,
    input reset,
    input enable,
    output reg [3:0] q
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 4'b0000;
    else if (enable)
        q <= d;
end

endmodule
