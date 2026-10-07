`timescale 1ns/1ps

module shift_register4 (
    input serial_in,
    input clk,
    input reset,
    output reg [3:0] q
);

always @ (posedge clk or posedge reset) begin
    if (reset)
        q <= 4'b0000;
    else
        q <= {q[2:0], serial_in};
end

endmodule
