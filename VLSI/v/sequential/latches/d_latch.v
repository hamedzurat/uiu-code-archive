`timescale 1ns/1ps

module d_latch (
    input d,
    input en,
    output reg q,
    output reg qbar
);

always @ (d or en) begin
    if (en) begin
        q = d;
        qbar = ~d;
    end
end

endmodule
