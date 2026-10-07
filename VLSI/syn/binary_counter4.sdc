# ####################################################################

#  Created by Encounter(R) RTL Compiler v12.10-s012_1 on Sun Sep 27 08:36:51 +0600 2026

# ####################################################################

set sdc_version 1.7

set_units -capacitance 1000.0fF
set_units -time 1000.0ps

# Set the current design
current_design binary_counter4

create_clock -name "clk" -add -period 10.0 -waveform {0.0 5.0} [get_ports clk]
set_clock_transition -rise 0.1 [get_clocks clk]
set_clock_gating_check -setup 0.0 
set_wire_load_mode "enclosed"
set_dont_use [get_lib_cells gpdk045bc/HOLDX1]
set_clock_uncertainty -setup 0.1 [get_clocks clk]
set_clock_uncertainty -hold 0.1 [get_clocks clk]
