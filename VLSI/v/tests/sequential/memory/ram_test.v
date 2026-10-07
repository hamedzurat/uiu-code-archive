`timescale 1ns/1ps
module ram_test;
reg clk, reset, write_enable;
reg [1:0] write_address, read_address_a, read_address_b;
reg [7:0] write_data;
wire [7:0] read_data_a, read_data_b;
ram uut (
    .clk(clk), .reset(reset), .write_enable(write_enable),
    .write_address(write_address), .read_address_a(read_address_a),
    .read_address_b(read_address_b), .write_data(write_data),
    .read_data_a(read_data_a), .read_data_b(read_data_b)
);
always #5 clk = ~clk;
initial begin
    $monitor("Time = %0t | we = %b | wa = %b | wd = %h | ra = %b | rb = %b | da = %h | db = %h",
             $time, write_enable, write_address, write_data, read_address_a,
             read_address_b, read_data_a, read_data_b);
    clk = 0; reset = 1; write_enable = 0; write_address = 0;
    read_address_a = 0; read_address_b = 0; write_data = 0; #3;
    reset = 0; write_enable = 1; write_address = 0; write_data = 8'hA5; #10;
    write_address = 1; write_data = 8'h3C; #10;
    write_enable = 0; read_address_a = 0; read_address_b = 1; #10;
    assert ((read_data_a === 8'hA5) && (read_data_b === 8'h3C))
        else $fatal(1, "ram failed: read_data_a=%h read_data_b=%h", read_data_a, read_data_b);
    $finish;
end
endmodule
