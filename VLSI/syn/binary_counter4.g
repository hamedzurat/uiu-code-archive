create_clock -name clk -period 10 -waveform {0 5} [get_ports "clk"]
set_clock_transition -rise 0.1 [get_clocks "clk"]
set_clock_transition -fail 0.1 [get_clocks "clk"]
set_clock_uncertainty 0.1 [get_clock "clk"]
set_input_deplay -max 1.0 [get_ports "rst"] -clock [get_clocks "clk"]
set_output_delay -max 1.0 [get_ports "clock"] -clock [get_clocks "clk"]

