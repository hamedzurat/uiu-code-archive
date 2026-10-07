`timescale 1ns/1ps

module sequence_detector101 (
    input bit_in,
    input clk,
    input reset,
    output reg detected
);

localparam NONE = 2'b00;
localparam GOT_1 = 2'b01;
localparam GOT_10 = 2'b10;
reg [1:0] state;
reg [1:0] next_state;

always @* begin
    detected = 1'b0;
    case (state)
        NONE:  next_state = bit_in ? GOT_1 : NONE;
        GOT_1: next_state = bit_in ? GOT_1 : GOT_10;
        GOT_10: begin
            if (bit_in) begin
                next_state = GOT_1;
                detected = 1'b1;
            end else begin
                next_state = NONE;
            end
        end
        default: next_state = NONE;
    endcase
end

always @ (posedge clk or posedge reset) begin
    if (reset)
        state <= NONE;
    else
        state <= next_state;
end

endmodule
