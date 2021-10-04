CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
AS = arm-none-eabi-as
GDB = gdb-multiarch 

SERVER= JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

LDFLAGS= -nostdlib -T ld_ram.lds
CFLAGS = -g -O1 -mcpu=cortex-m4 -mthumb
ASFLAGS = -g -mcpu=cortex-m4 -mthumb


OBJS = main.o crt0.o init.o
EXE = main

.PHONY: clean

all: $(EXE)

main: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@



clean:
	rm -f $(OBJS)
	rm -f $(EXE)

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug:
	$(GDB) $(EXE)