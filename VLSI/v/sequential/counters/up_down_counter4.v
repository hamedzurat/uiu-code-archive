`timescale 1ns/1ps

module up_down_counter4 (
    input clk,
    input reset,
    input enable,
    input up,
    output reg [3:0] q
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 4'b0000;
    else if (enable && up)
        q <= q + 4'b0001;
    else if (enable && !up)
        q <= q - 4'b0001;
end

endmodule
