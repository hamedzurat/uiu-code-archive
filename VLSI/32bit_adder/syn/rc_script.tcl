# RTL Compiler synthesis script for adder32.
# Run this file from the syn directory with: rc -f rc_script.tcl

set_attr lib_search_path ../lib/
set_attr hdl_search_path ../rtl/
set_attr library slow.lib

read_hdl -v2001 {half_adder.v full_adder.v adder32.v}
elaborate adder32
read_sdc ./adder32.g

synthesize -to_mapped -effort medium
report timing > adder32_timing.rpt
report power > adder32_power.rpt

write_hdl > adder32_netlist.v
write_sdc > adder32.sdc
