ENTRY(_start)

MEMORY {
    flash(rx) : ORIGIN = 0x08000000, LENGTH = 1M
    sram1(wx) : ORIGIN = 0x20000000, LENGTH = 96K
    sram2(wx) : ORIGIN = 0x10000000, LENGTH = 32K 
}

_stack = ORIGIN(sram2)  + LENGTH(sram2) ;

SECTIONS {
    .text : {
        *(.text)
    } > flash

    .rodata : {
        *(.rodata)
    } > flash

    .data : {
        *(.data)
    } > sram1 AT> flash

    .bss : {
        _sbss = . ;
        *(.bss) *(COMMON)
        _ebss = . ;
    } > sram1

    .stack : {
        *(.stack)
    } > sram2
}