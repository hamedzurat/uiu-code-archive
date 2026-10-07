set_attr lib_search_path ./lib/
set_attr hdl_search_path ./rtl/
set_attr library slow.lib

read_hdl -v2001 binary_counter4.v 
elaborate binary_counter4
read_sdc ./binary_counter4.g

synthesize -to_mapped -effort medium
report timing
report power

write_hdl > binary_counter4_netlist.v
write_sdc > binary_counter4.sdc

