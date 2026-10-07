.PHONY: test synth clean

IRUN ?= irun
RC ?= rc
IRUN_FLAGS ?= -clean -sv -access +rwc

test:
	mkdir -p build
	$(IRUN) $(IRUN_FLAGS) -top adder32_test \
		-log build/adder32_test.log rtl/adder32.v tb/adder32_test.v

synth:
	cd syn && $(RC) -f rc_script.tcl

clean:
	rm -rf build/* INCA_libs syn/adder32_netlist.v syn/adder32.sdc \
		syn/adder32_timing.rpt syn/adder32_power.rpt
