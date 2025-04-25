# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f VDMATopAXI_AXIL_AXI.mk

default: VDMATopAXI_AXIL_AXI

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = VDMATopAXI_AXIL_AXI
# Module prefix (from --prefix)
VM_MODPREFIX = VDMATopAXI_AXIL_AXI
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-O1 -DVL_USER_STOP -DVL_USER_FATAL -DVL_USER_FINISH -DTOP_TYPE=VDMATopAXI_AXIL_AXI -include VDMATopAXI_AXIL_AXI.h -fPIC -shared -I'/usr/lib/jvm/java-11-openjdk-amd64/include' -I'/usr/lib/jvm/java-11-openjdk-amd64/include/linux' -fvisibility=hidden \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-shared -dynamiclib -fvisibility=hidden \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	DMATopAXI_AXIL_AXI-harness \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	. \


### Default rules...
# Include list of all generated classes
include VDMATopAXI_AXIL_AXI_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

DMATopAXI_AXIL_AXI-harness.o: DMATopAXI_AXIL_AXI-harness.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
VDMATopAXI_AXIL_AXI: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
