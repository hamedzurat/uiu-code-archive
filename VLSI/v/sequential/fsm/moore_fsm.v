`timescale 1ns/1ps

// Two-state Moore FSM. busy depends only on the current state.
module moore_fsm (
    input clk,
    input reset,
    input start,
    input done,
    output reg busy
);

localparam IDLE = 1'b0;
localparam RUN = 1'b1;
reg state;
reg next_state;

always @* begin
    case (state)
        IDLE:    next_state = start ? RUN : IDLE;
        RUN:     next_state = done ? IDLE : RUN;
        default: next_state = IDLE;
    endcase
end

always @ (posedge clk or posedge reset) begin
    if (reset)
        state <= IDLE;
    else
        state <= next_state;
end

always @* begin
    busy = (state == RUN);
end

endmodule
