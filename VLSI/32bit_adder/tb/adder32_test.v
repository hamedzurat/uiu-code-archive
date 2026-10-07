`timescale 1ns/1ps

module adder32_test;

reg  [31:0] a;
reg  [31:0] b;
reg         carry_in;
wire [31:0] sum;
wire        carry_out;
reg  [32:0] expected;
integer    test_number;

adder32 dut (
    .a(a),
    .b(b),
    .carry_in(carry_in),
    .sum(sum),
    .carry_out(carry_out)
);

task check;
    input [31:0] test_a;
    input [31:0] test_b;
    input        test_carry_in;
    begin
        a = test_a;
        b = test_b;
        carry_in = test_carry_in;
        #1;
        expected = {1'b0, test_a} + {1'b0, test_b} + test_carry_in;
        assert ({carry_out, sum} === expected)
        else begin
            $display("FAIL a=%h b=%h carry_in=%b got=%h expected=%h",
                     test_a, test_b, test_carry_in, {carry_out, sum}, expected);
            $fatal(1, "adder32 mismatch on test %0d", test_number + 1);
        end
        test_number = test_number + 1;
    end
endtask

initial begin
    $shm_open("build/adder32.shm");
    $shm_probe("AS");
    test_number = 0;
    check(32'h00000000, 32'h00000000, 1'b0);
    check(32'h00000001, 32'h00000001, 1'b0);
    check(32'hffffffff, 32'h00000001, 1'b0);
    check(32'h55555555, 32'haaaaaaaa, 1'b0);
    check(32'h00000000, 32'h00000000, 1'b1);
    $display("PASS: %0d adder32 tests", test_number);
    $finish;
end

endmodule
