#include "matrix.h"
#include "stm32l475xx.h"

void matrix_init() {
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN; // enables clock of GPIOA;
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // enables clock of GPIOB;
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN; // enables clock of GPIOC;
    // drivers uses ports 2, 3, 4, 5, 6, 7, 15 on GPIOA
    // drivers uses ports 0, 1, 2 on GPIOB
    // drivers uses ports 3, 4, 5 on GPIOC
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE3_Msk) | GPIO_MODER_MODE3_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_0;
    GPIOA -> MODER = (GPIOA -> MODER & ~GPIO_MODER_MODE15_Msk) | GPIO_MODER_MODE15_0;
    GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE0_Msk) | GPIO_MODER_MODE0_0;
    GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE1_Msk) | GPIO_MODER_MODE1_0;
    GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0;
    GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE3_Msk) | GPIO_MODER_MODE3_0;
    GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0;
    GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0;

    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED2_Msk) | 3 << GPIO_OSPEEDR_OSPEED2_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED3_Msk) | 3 << GPIO_OSPEEDR_OSPEED3_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED4_Msk) | 3 << GPIO_OSPEEDR_OSPEED4_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED5_Msk) | 3 << GPIO_OSPEEDR_OSPEED5_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED6_Msk) | 3 << GPIO_OSPEEDR_OSPEED6_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED7_Msk) | 3 << GPIO_OSPEEDR_OSPEED7_Pos;
    GPIOA -> OSPEEDR = (GPIOA -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED15_Msk) | 3 << GPIO_OSPEEDR_OSPEED15_Pos;
    GPIOB -> OSPEEDR = (GPIOB -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED0_Msk) | 3 << GPIO_OSPEEDR_OSPEED0_Pos;
    GPIOB -> OSPEEDR = (GPIOB -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED1_Msk) | 3 << GPIO_OSPEEDR_OSPEED1_Pos;
    GPIOB -> OSPEEDR = (GPIOB -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED2_Msk) | 3 << GPIO_OSPEEDR_OSPEED2_Pos;
    GPIOC -> OSPEEDR = (GPIOC -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED3_Msk) | 3 << GPIO_OSPEEDR_OSPEED3_Pos;
    GPIOC -> OSPEEDR = (GPIOC -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED4_Msk) | 3 << GPIO_OSPEEDR_OSPEED4_Pos;
    GPIOC -> OSPEEDR = (GPIOC -> OSPEEDR & ~GPIO_OSPEEDR_OSPEED5_Msk) | 3 << GPIO_OSPEEDR_OSPEED5_Pos;

    //GPIOA -> OSPEEDR |= (GPIO_OSPEEDR_OSPEED2_Msk | GPIO_OSPEEDR_OSPEED3_Msk | GPIO_OSPEEDR_OSPEED4_Msk | GPIO_OSPEEDR_OSPEED5_Msk | GPIO_OSPEEDR_OSPEED7_Msk | GPIO_OSPEEDR_OSPEED15_Msk); //Sets ports 2, 3, 4, 5, 6, 7, 15 on GPIOA to 11 (high-speed) (page 304)
    //GPIOB -> OSPEEDR |= (GPIO_OSPEEDR_OSPEED0_Msk | GPIO_OSPEEDR_OSPEED1_Msk | GPIO_OSPEEDR_OSPEED2_Msk); //Sets ports 0, 1, 2 on GPIOB to 11 (high-speed) (page 304)
    //GPIOC -> OSPEEDR |= (GPIO_OSPEEDR_OSPEED3_Msk | GPIO_OSPEEDR_OSPEED4_Msk | GPIO_OSPEEDR_OSPEED5_Msk); //Sets ports 3, 4, 5 on GPIOC to 11 (high-speed) (page 304)
    GPIOC -> BSRR = 1 << 19; //Sets PC3 to 0 (page 306) => sets RST to 0.
    GPIOC -> BSRR = 1 << 4; //Sets PC4 to 1 (page 306) => sets LAT to 1.
    GPIOC -> BSRR = 1 << 5; //Sets PC5 to 1 (page 306) => sets SB to 1.
    GPIOB -> BSRR = 1 << 17; //Sets PB1 to 0 (page 306) => sets SCK to 0.
    GPIOA -> BSRR = 1 << 20; //Sets PA4 to 0 (page 306) => sets SDA to 0.

    for (int i = 0; i<2; i++) {
        asm volatile ("nop");
    }

    GPIOC -> BSRR = 1 << 3; //Sets PC3 to 1 (page 306) => sets RST to 1.

    init_bank0();
    deactivate_rows();
}

void RST(int x) {
    if (x==0) {
        GPIOC -> BSRR = 1 << 19; //Sets PC3 to 0 (page 306) => sets RST to 0.
    }

    else {
        GPIOC -> BSRR = 1 << 3; //Sets PC3 to 1 (page 306) => sets RST to 1.
    }
}

void SB(int x) {
    if (x==0) {
        GPIOC -> BSRR = 1 << 21; //Sets PC5 to 1 (page 306) => sets SB to 0.
    }

    else {
        GPIOC -> BSRR = 1 << 5; //Sets PC5 to 1 (page 306) => sets SB to 1.
    }
}

void LAT(int x) {
    if (x==0) {
        GPIOC -> BSRR = 1 << 20; //Sets PC4 to 1 (page 306) => sets SB to 0.
    }

    else {
        GPIOC -> BSRR = 1 << 4; //Sets PC4 to 1 (page 306) => sets SB to 1.
    }
}

void SCK(int x) {
    if (x==0) {
        GPIOB -> BSRR = 1 << 17; //Sets PB1 to 0 (page 306) => sets SCK to 0.
    }

    else {
        GPIOB -> BSRR = 1 << 1; //Sets PB1 to 1 (page 306) => sets SCK to 1.
    }
}

void SDA(int x) {
    if (x==0) {
        GPIOA -> BSRR = 1 << 20; //Sets PA4 to 0 (page 306) => sets SDA to 0.
    }

    else {
        GPIOA -> BSRR = 1 << 4; //Sets PA4 to 1 (page 306) => sets SDA to 1.
    }
}

void ROW0(int x) {
    if (x==0) {
        GPIOB -> BSRR |= 1 << 18; //Sets PB2 to 0 (page 306) => sets C0 to 0.
    }

    else {
        GPIOB -> BSRR |= 1 << 2; //Sets PB2 to 1 (page 306) => sets C0 to 1.
    }
}

void ROW1(int x) {
    if (x==0) {
        GPIOA -> BSRR  |= 1 << 31; //Sets PA15 to 0 (page 306) => sets C1 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 15; //Sets PA15 to 1 (page 306) => sets C1 to 1.
    }
}

void ROW2(int x) {
    if(x==0) {
        GPIOA -> BSRR |= 1 << 18; //Sets PA2 to 0 (page 306) => sets C2 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 2; //Sets PA2 to 1 (page 306) => sets C2 to 1.
    }
}

void ROW3(int x) {
    if (x==0) {
        GPIOA -> BSRR |= 1 << 23; //Sets PA7 to 0 (page 306) => sets C3 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 7; //Sets PA7 to 1 (page 306) => sets C3 to 1.
    }
}

void ROW4(int x) {
    if (x==0) {
        GPIOA -> BSRR |= 1 << 22; //Sets PA6 to 0 (page 306) => sets C4 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 6; //Sets PA6 to 1 (page 306) => sets C4 to 1.
    }
}

void ROW5(int x) {
    if(x==0) {
        GPIOA -> BSRR |= 1 << 21; //Sets PA5 to 0 (page 306) => sets C5 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 5; //Sets PA5 to 1 (page 306) => sets C5 to 1.
    }
}

void ROW6(int x) {
    if (x==0) {
        GPIOB -> BSRR |= 1 << 16; //Sets PB0 to 0 (page 306) => sets C6 to 0.
    }

    else {
        GPIOB -> BSRR |= 1 << 0; //Sets PB0 to 0 (page 306) => sets C6 to 0.
    }
}

void ROW7(int x) {
    if (x==0) {
        GPIOA -> BSRR |= 1 << 19; //Sets PA3 to 0 (page 306) => sets C7 to 0.
    }

    else {
        GPIOA -> BSRR |= 1 << 3; //Sets PA3 to 1 (page 306) => sets C7 to 1.
    }
}

void pulse_SCK() {
    SCK(0);
    for (int i = 0; i<20; i++) {
        asm volatile ("nop");
    }
    SCK(1);
    for (int i = 0; i<20; i++) {
        asm volatile ("nop");
    }
    SCK(0);
}

void pulse_LAT() {
    LAT(1);
    for (int i = 0; i<2; i++) {
        asm volatile ("nop");
    }
    LAT(0);
    for (int i = 0; i<2; i++) {
        asm volatile ("nop");
    }
    LAT(1);
}

void deactivate_rows() {
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}

void activate_row(int row) {
    if (row==0) {ROW0(1);};
    if (row==1) {ROW1(1);};
    if (row==2) {ROW2(1);};
    if (row==3) {ROW3(1);};
    if (row==4) {ROW4(1);};
    if (row==5) {ROW5(1);};
    if (row==6) {ROW6(1);};
    if (row==7) {ROW7(1);};
}

void send_byte(uint8_t val, int bank) {
    SB(bank);
    int max = 7;
    if (bank == 0) {
        max = 5;
    }
    for (int i = max; i>=0; i--) {
        SDA((1<<i) & val);
        pulse_SCK();
    }
}

void mat_set_row(int row, const rgb_color *val) {
    for (int i = 7; i>=0;  i--) {
        send_byte(val[i].b, 1);
        send_byte(val[i].g, 1);
        send_byte(val[i].r, 1);
    }
    pulse_LAT();
    activate_row(row);
}

void init_bank0() {
    for (int i = 0; i<24; i++) {
        send_byte(0xFF, 0);
    }
    pulse_LAT();
}

void test_pixels() {
    matrix_init();
    rgb_color blue[8];
    for (int i = 0; i<8; i++) {
        blue[i].b = ((i+1)%2) * 4;
        blue[i].r = (i%2) * 4;
        blue[i].g = 0;
    }
    mat_set_row(3, blue);
}

void display_image(uint8_t image[], int imageLength) {
    uint8_t ch;
    rgb_color rgb;
    rgb_color row[8];
    rgb.b = 0;
    rgb.g = 0;
    rgb.r = 0;
    for (int j=0; j<8; j++) {
        row[j].b = 0;
        row[j].g = 0;
        row[j].r = 0;
    }
    int i = 0;
    int pixelNumber = 0;
    int rowNumber = 0;
    int columnNumber = 0;
    while(pixelNumber < imageLength) {
        ch = image [pixelNumber];
        if (i==3) {
            row[columnNumber] = rgb;
            if (columnNumber==7) {
                deactivate_rows();
                mat_set_row(rowNumber, row);
                if (rowNumber == 7) {
                    rowNumber = 0;
                }
                else {
                    rowNumber ++;
                }
                columnNumber = 0;
            }
            else {
                columnNumber++;
            }
            i = 0;
        }
        else {
            if(i==0){rgb.r = ch;}
            if(i==1){rgb.g = ch;}
            if(i==2){rgb.b = ch;}
            i++;
            pixelNumber++;
        }
    }
    deactivate_rows();
    mat_set_row(rowNumber, row);
}