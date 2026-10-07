# RTL Compiler synthesis script for the Kogge-Stone adder.
# Run from this directory with: rc -f rc_script.tcl

# Reuse the educational GPDK library shipped with the sibling 32bit project.
set_attr lib_search_path ../../32bit/lib/
set_attr hdl_search_path ../rtl/
set_attr library slow.lib

read_hdl -sv adder32.v
elaborate adder32
read_sdc ./adder32_constraints.sdc

synthesize -to_mapped -effort high
report timing > adder32_timing.rpt
report power > adder32_power.rpt

write_hdl > adder32_netlist.v
write_sdc > adder32.sdc
