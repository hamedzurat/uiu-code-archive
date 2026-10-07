`timescale 1ns/1ps

// 32-bit Kogge-Stone parallel-prefix adder.
// The prefix network computes carries in log2(32) stages rather than
// rippling a carry through all 32 bits. This favors speed over area/wiring.
module adder32 (
    input  wire [31:0] a,
    input  wire [31:0] b,
    input  wire        carry_in,
    output wire [31:0] sum,
    output wire        carry_out
);

    wire [31:0] propagate [0:5];
    wire [31:0] generate_carry [0:5];

    assign propagate[0] = a ^ b;
    assign generate_carry[0] = a & b;

    genvar stage;
    genvar bit_number;
    generate
        for (stage = 1; stage <= 5; stage = stage + 1) begin : prefix_stage
            for (bit_number = 0; bit_number < 32; bit_number = bit_number + 1) begin : bit_group
                if (bit_number >= (1 << (stage - 1))) begin : combine
                    assign generate_carry[stage][bit_number] =
                        generate_carry[stage-1][bit_number] |
                        (propagate[stage-1][bit_number] &
                         generate_carry[stage-1][bit_number - (1 << (stage - 1))]);
                    assign propagate[stage][bit_number] =
                        propagate[stage-1][bit_number] &
                        propagate[stage-1][bit_number - (1 << (stage - 1))];
                end else begin : pass_through
                    assign generate_carry[stage][bit_number] = generate_carry[stage-1][bit_number];
                    assign propagate[stage][bit_number] = propagate[stage-1][bit_number];
                end
            end
        end
    endgenerate

    assign sum[0] = propagate[0][0] ^ carry_in;

    genvar sum_bit;
    generate
        for (sum_bit = 1; sum_bit < 32; sum_bit = sum_bit + 1) begin : sum_bits
            assign sum[sum_bit] = propagate[0][sum_bit] ^
                (generate_carry[5][sum_bit-1] |
                 (propagate[5][sum_bit-1] & carry_in));
        end
    endgenerate

    assign carry_out = generate_carry[5][31] |
        (propagate[5][31] & carry_in);

endmodule
