`timescale 1ns/1ps

module full_subtractor (
    input a,
    input b,
    input bin,
    output difference,
    output bout
);

wire difference_first;
wire borrow_first;
wire borrow_second;

half_subtractor hs0 (
    .a(a), .b(b),
    .difference(difference_first), .borrow(borrow_first)
);

half_subtractor hs1 (
    .a(difference_first), .b(bin),
    .difference(difference), .borrow(borrow_second)
);

assign bout = borrow_first | borrow_second;

endmodule
