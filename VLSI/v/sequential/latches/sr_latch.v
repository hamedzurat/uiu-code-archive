`timescale 1ns/1ps

module sr_latch (
    input s,
    input r,
    output reg q,
    output reg qbar
);

always @ (s or r) begin
    if (s && !r) begin
        q = 1'b1;
        qbar = 1'b0;
    end else if (!s && r) begin
        q = 1'b0;
        qbar = 1'b1;
    end else if (s && r) begin
        q = 1'bx;
        qbar = 1'bx;
    end
end

endmodule
