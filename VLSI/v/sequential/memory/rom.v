`timescale 1ns/1ps

// Four-word, eight-bit asynchronous ROM.
module rom (
    input [1:0] address,
    output reg [7:0] data
);

always @* begin
    case (address)
        2'b00: data = 8'h12;
        2'b01: data = 8'h34;
        2'b10: data = 8'h56;
        2'b11: data = 8'h78;
        default: data = 8'h00;
    endcase
end

endmodule
