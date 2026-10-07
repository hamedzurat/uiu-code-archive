`timescale 1ns/1ps

// Four-state traffic-light controller. advance moves to the next phase.
module traffic_light_fsm (
    input clk,
    input reset,
    input advance,
    output reg [2:0] north_south,
    output reg [2:0] east_west
);

localparam NS_GREEN = 2'b00;
localparam NS_YELLOW = 2'b01;
localparam EW_GREEN = 2'b10;
localparam EW_YELLOW = 2'b11;
reg [1:0] state;
reg [1:0] next_state;

always @* begin
    case (state)
        NS_GREEN:  next_state = advance ? NS_YELLOW : NS_GREEN;
        NS_YELLOW: next_state = advance ? EW_GREEN : NS_YELLOW;
        EW_GREEN:  next_state = advance ? EW_YELLOW : EW_GREEN;
        EW_YELLOW: next_state = advance ? NS_GREEN : EW_YELLOW;
        default:   next_state = NS_GREEN;
    endcase
end

always @ (posedge clk or posedge reset) begin
    if (reset)
        state <= NS_GREEN;
    else
        state <= next_state;
end

always @* begin
    north_south = 3'b100;
    east_west = 3'b100;

    case (state)
        NS_GREEN: begin
            north_south = 3'b001;
            east_west = 3'b100;
        end
        NS_YELLOW: begin
            north_south = 3'b010;
            east_west = 3'b100;
        end
        EW_GREEN: begin
            north_south = 3'b100;
            east_west = 3'b001;
        end
        EW_YELLOW: begin
            north_south = 3'b100;
            east_west = 3'b010;
        end
    endcase
end

endmodule
