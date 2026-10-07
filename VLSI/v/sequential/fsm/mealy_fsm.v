`timescale 1ns/1ps

// Two-state Mealy FSM. accepted depends on the state and start input.
module mealy_fsm (
    input clk,
    input reset,
    input start,
    input done,
    output reg busy,
    output reg accepted
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
    accepted = (state == IDLE) && start;
end

endmodule
