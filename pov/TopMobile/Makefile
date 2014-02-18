DESIGN          = top_movil
PINS            = $(DESIGN).ucf
DEVICE          = XC6SLX16-CSG324-3
BGFLAGS         = -g TdoPin:PULLNONE -g DonePin:PULLUP \
                  -g CRC:enable -g StartUpClk:CCLK

SIM_CMD         = vsim 
SIM_COMP_SCRIPT = simulation/$(DESIGN)_TB.do
SIMGEN_OPTIONS  = -p $(FPGA_ARCH) -lang $(LANGUAGE)
IVERILOG        = iverilog

SAKC_IP         = 192.168.1.1

SRC             = $(DESIGN).v ./TopReceiver/Char.v ./TopReceiver/CharComparator.v ./TopReceiver/counter.v ./TopReceiver/control_o.v ./TopReceiver/mstring.v ./TopReceiver/Parity.v ./TopReceiver/StringComparator.v ./TopReceiver/Wait.v ./TopReceiver/test.v ./TopReceiver/top_receptor.v ./LEDS/acc_1.v  ./LEDS/cont_col.v ./LEDS/lslA.v  ./LEDS/top_ASCCI.v ./LEDS/acc_2.v   ./LEDS/cont_ram.v   ./LEDS/lsrB.v  ./LEDS/top_col.v ./LEDS/acumulador.v  ./LEDS/control_ascci.v ./LEDS/m_plexor.v   ./LEDS/comp_1.v ./LEDS/control_leer.v  ./LEDS/ram.v ./LEDS/top_multiplicador.v ./LEDS/comp_2.v ./LEDS/control.v ./LEDS/recorrido_col.v  ./LEDS/comp_ascci.v ./LEDS/dir_ascci.v  ./LEDS/rom.v  ./LEDS/top_RAM.v  ./LEDS/comp.v   ./LEDS/divisorFrecuencia.v  ./LEDS/select_efect.v ./LEDS/cont_ascci.v  ./LEDS/impresion.v ./LEDS/top_efect1.v ./LEDS/top_efect2.v ./LEDS/top_efect4.v ./LEDS/top_efect5.v ./LEDS/select_dir.v  ./LEDS/top_leds.v

SIM_SRC = $(DESIGN)_TB.v          \
	sim/unisims/BUFG.v        \
	sim/unisims/DCM.v         \
	sim/unisims/FDDRRSE.v


 
all:            bits

remake:         clean-build all

clean:
	rm -f *~ */*~ a.out *.log *.key *.edf *.ps trace.dat 
	rm -f *.bit

cleanall: clean
	rm -rf build simulation

bits:           $(DESIGN).bit

#
# Synthesis
#
build/project.src:
	@[ -d build ] || mkdir build
	@[ -d simulation ] || mkdir simulation 
	@rm -f $@
	for i in $(SRC); do echo verilog work ../$$i >> $@; done
	for i in $(SRC_HDL); do echo VHDL work ../$$i >> $@; done

build/project.xst: build/project.src
	echo "run" > $@
	echo "-top $(DESIGN) " >> $@
	echo "-p $(DEVICE)" >> $@
	echo "-opt_mode Area" >> $@
	echo "-opt_level 1" >> $@
	echo "-ifn project.src" >> $@
	echo "-ifmt mixed" >> $@
	echo "-ofn project.ngc" >> $@
	echo "-ofmt NGC" >> $@
	echo "-rtlview yes" >> $@

build/project.ngc: build/project.xst $(SRC)
	cd build && xst -ifn project.xst -ofn project.log

build/project.ngd: build/project.ngc $(PINS)
	cd build && ngdbuild -p $(DEVICE) project.ngc -uc ../$(PINS)

build/project.ncd: build/project.ngd
	cd build && map -pr b -p $(DEVICE) project

build/project_r.ncd: build/project.ncd
	cd build && par -w project project_r.ncd

build/project_r.twr: build/project_r.ncd
	cd build && trce -v 25 project_r.ncd project.pcf

$(DESIGN).bit:  build/project_r.ncd build/project_r.twr
	cd build && bitgen project_r.ncd -l -w $(BGFLAGS)
	@mv -f build/project_r.bit $@

build/project_r.v: build/project_r.ncd
	cd build &&  ngd2ver project.ngd  -w project.v

modelsim: 
	cd simulation; $(SIM_CMD) -do $(DESIGN)_TB.do

timesim: build/project_r.v
	cd simulation; $(SIM_CMD) -do $(DESIGN)_TIMING_TB.do

iversim: build/project.src
	$(IVERILOG) -o simulation/$(DESIGN)_TB $(DESIGN)_TB.v $(SRC) 
	vvp simulation/$(DESIGN)_TB -vcd; mv $(DESIGN)_TB.vcd simulation/
	gtkwave simulation/$(DESIGN)_TB.vcd&

upload: $(DESIGN).bit
	scp $(DESIGN).bit root@$(SAKC_IP): 
