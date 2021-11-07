#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "stm32l475xx.h"

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

void matrix_init();
void RST(int x);
void SB(int x);
void LAT(int x);
void SCK(int x);
void ROW0(int x);
void ROW1(int x);
void ROW2(int x);
void ROW3(int x);
void ROW4(int x);
void ROW5(int x);
void ROW6(int x);
void ROW7(int x);
void pulse_SCK();
void pulse_LAD();
void deactivate_rows();
void activate_row(int row);
void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color *val);
void init_bank0();
void test_pixels();
void display_image(uint8_t* image, int imageLength);

#endif