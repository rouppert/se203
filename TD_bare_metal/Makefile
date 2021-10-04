CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
DB = gdb-multiarch 

SERVER= JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

LDFLAGS= -nostdlib
CFLAGS = -c -g -O1 -mcpu=cortex-m4 -mthumb

LINKERS = ld_ram.lds
OBJS = main.o
EXE = main

.PHONY: clean

all: $(EXE)

main: $(LINKERS) $(OBJS)
	$(LD) $(LDFLAGS) -T $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug:
	gdb-multiarch $(EXE)