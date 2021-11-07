CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
AS = arm-none-eabi-as
GDB = gdb-multiarch 


SERVER= JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

LDFLAGS= -nostdlib -T ld_ram.lds
CFLAGS = -g -O1 -mcpu=cortex-m4 -mthumb -ffreestanding -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall
ASFLAGS = -g -mcpu=cortex-m4 -mthumb
CPPFLAGS = -ICMSIS/Include/ -ICMSIS/Device/ST/STM32L4xx/Include/

OBJS = crt0.o init.o led.o buttons.o irq.o matrix.o display_frame.o uart.o irq.o timer.o
TEST_MATRIX = test_matrix
TEST_IRQ = test_IRQ
TEST_IRQ2 = test_IRQ2
TEST_LED = test_LED
TEST_UART = test_uart
TEST_TIMER = test_timer
EXE = main

.PHONY: clean

all: $(EXE)

${TEST_MATRIX}: $(OBJS) clocks.o image.o ${TEST_MATRIX}.o
	$(LD) $(LDFLAGS) $^ -o $@

${TEST_IRQ}: ${TEST_IRQ}.o $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@

${TEST_UART}: ${TEST_UART}.o $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@

${TEST_IRQ2}: ${TEST_IRQ2}_.o $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@

${TEST_LED}: ${TEST_LED}.o $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@

${TEST_TIMER}: ${TEST_TIMER}.o $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@


main: $(OBJS) clocks.o
	$(LD) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug:
	$(GDB) $(EXE)

.%.dep : %.c
	$(CC) $(CPPFLAGS) -MM $< -MF $@
