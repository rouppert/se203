.syntax unified
.global _start
//.section .memfunc_section
.thumb

_start:
    ldr sp, =_stack
    bl init_bss
    bl main
_exit:
    b _exit
