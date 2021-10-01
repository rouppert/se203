ENTRY(_start)

MEMORY {
    flash(wx) : ORIGIN = 0x08000000, LENGTH = 1MB
    sram1(wx) : ORIGIN = 0x20000000,LENGTH = 96kB
    sram2(wx) : ORIGIN = 0x10000000, LENGTH = 32kB   
}

SECTIONS {
    .text : {
        *(.text)
    } > sram1

    .rodata : {
        *(.rodata)
    } > sram1

    .data : {
        *(.data)
    } > sram1

    .bss : {
        *(.bss) *(COMMON)
    } > sram1

    .stack : {
        *(.stack)
    } > sram2
}