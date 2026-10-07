.PHONY: test synth clean

# Incisive is installed in the VM; iverilog is not.
IRUN ?= irun
RC ?= rc
IRUN_FLAGS ?= -clean -sv -access +rwc

RTL_SOURCES = rtl/half_adder.v rtl/full_adder.v rtl/adder32.v
TESTBENCH = tb/adder32_test.v

test:
	mkdir -p build
	$(IRUN) $(IRUN_FLAGS) -top adder32_test \
		-log build/adder32_test.log $(RTL_SOURCES) $(TESTBENCH)

synth:
	cd syn && $(RC) -f rc_script.tcl

clean:
	rm -rf build/* syn/adder32_netlist.v syn/adder32.sdc \
		syn/adder32_timing.rpt syn/adder32_power.rpt
