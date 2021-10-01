PREFIX= arm-none-eabi-
CC = $(PREFIX)-gcc
LD = $(PREFIX)-gcc
DB = gdb-multiarch

SERVER= JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

LDLIBDS= -lm
CFLAGS = -mthumb -mcpu=cortex-m4

OBJS = t1.o t2.o main.o
EXE = main.elf

.PHONY: clean

all: $(EXE)

main: $(OBJS)
	$(LD) $^ -o $@ $(LDLIBDS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)