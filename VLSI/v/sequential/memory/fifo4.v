`timescale 1ns/1ps

// Four-entry, eight-bit synchronous FIFO.
module fifo4 (
    input clk,
    input reset,
    input write_enable,
    input read_enable,
    input [7:0] write_data,
    output reg [7:0] read_data,
    output full,
    output empty
);

reg [7:0] memory [0:3];
reg [1:0] write_pointer;
reg [1:0] read_pointer;
reg [2:0] count;

assign full = (count == 3'd4);
assign empty = (count == 3'd0);

always @ (posedge clk or posedge reset) begin
    if (reset) begin
        write_pointer <= 2'b00;
        read_pointer <= 2'b00;
        count <= 3'b000;
        read_data <= 8'b0;
    end else begin
        case ({write_enable && !full, read_enable && !empty})
            2'b10: begin
                memory[write_pointer] <= write_data;
                write_pointer <= write_pointer + 2'b01;
                count <= count + 3'b001;
            end
            2'b01: begin
                read_data <= memory[read_pointer];
                read_pointer <= read_pointer + 2'b01;
                count <= count - 3'b001;
            end
            2'b11: begin
                memory[write_pointer] <= write_data;
                read_data <= memory[read_pointer];
                write_pointer <= write_pointer + 2'b01;
                read_pointer <= read_pointer + 2'b01;
            end
        endcase
    end
end

endmodule
