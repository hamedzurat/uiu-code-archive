`timescale 1ns/1ps

// Four-word, eight-bit single-port RAM with synchronous read and write.
module synchronous_ram (
    input clk,
    input reset,
    input write_enable,
    input [1:0] address,
    input [7:0] write_data,
    output reg [7:0] read_data
);

reg [7:0] memory [0:3];
integer i;

always @ (posedge clk or posedge reset) begin
    if (reset) begin
        read_data <= 8'b0;
        for (i = 0; i < 4; i = i + 1)
            memory[i] <= 8'b0;
    end else begin
        if (write_enable)
            memory[address] <= write_data;
        read_data <= memory[address];
    end
end

endmodule
