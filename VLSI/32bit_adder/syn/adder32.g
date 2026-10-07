# Timing constraints for the combinational 32-bit adder.
# A virtual 10 ns clock gives RC a timing reference without adding a clock port.

create_clock -name virtual_clk -period 10 -waveform {0 5}
set_clock_transition -rise 0.1 [get_clocks virtual_clk]
set_clock_transition -fall 0.1 [get_clocks virtual_clk]
set_clock_uncertainty 0.1 [get_clocks virtual_clk]

set_input_delay -max 1.0 -clock [get_clocks virtual_clk] [get_ports {a[*] b[*] carry_in}]
set_output_delay -max 1.0 -clock [get_clocks virtual_clk] [get_ports {sum[*] carry_out}]
