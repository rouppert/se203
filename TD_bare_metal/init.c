extern char _sbss;
extern char _ebss;

void init_bss();

void init_bss() {
    for (char* i=&_sbss; i<&_ebss; i+=sizeof(i)) {
        *i = 0;
    }
}