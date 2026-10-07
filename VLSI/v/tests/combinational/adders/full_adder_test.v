`timescale 1ns/1ps

module full_adder_test;

reg a;
reg b;
reg cin;

wire sum;
wire cout;

full_adder uut (
    .a(a),
    .b(b),
    .cin(cin),
    .sum(sum),
    .cout(cout)
);

task check_case;
    input expected_a;
    input expected_b;
    input expected_cin;
    input expected_sum;
    input expected_cout;
    begin
        a = expected_a;
        b = expected_b;
        cin = expected_cin;
        #1;

        assert ((sum === expected_sum) && (cout === expected_cout))
            else $fatal(1,
                        "full_adder failed: a=%b b=%b cin=%b sum=%b/%b cout=%b/%b",
                        a, b, cin, sum, expected_sum, cout, expected_cout);
    end
endtask

initial begin
    check_case(0, 0, 0, 0, 0);
    check_case(0, 0, 1, 1, 0);
    check_case(0, 1, 0, 1, 0);
    check_case(0, 1, 1, 0, 1);
    check_case(1, 0, 0, 1, 0);
    check_case(1, 0, 1, 0, 1);
    check_case(1, 1, 0, 0, 1);
    check_case(1, 1, 1, 1, 1);

    $display("full_adder: all 8 cases passed");
    $finish;
end

endmodule
