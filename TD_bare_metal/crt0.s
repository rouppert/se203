.syntax unified
.global _start
.thumb

_start:
    ldr sp, =_stack
    bl init_bss
    bl main
_exit:
    b _exit
