

#ifndef _UTILITY_H_
#define _UTILITY_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h"
#include <stdio.h>
#include "30010_io.h"
#include <stdint.h>

/* Exported macro ------------------------------------------------------------*/
#define ESC 0x1B

/* Structs ------------------------------------------------------------------ */
struct player {
   uint8_t x;
   uint8_t y;
   uint8_t ox;
   uint8_t oy;
   uint8_t power_ups;
   uint8_t HP;
   uint8_t oHP;
   uint16_t score;
   uint16_t oscore;
   uint8_t s2;
   uint8_t s3;
   uint8_t im;
   uint16_t name1;
   uint16_t name2;
   uint16_t name3;
   uint16_t time;
};

struct enemy {

   uint8_t type;
   uint8_t x;
   uint8_t y;
   uint8_t x2; //bruh
   uint8_t y2; //bruh
   uint8_t vx;
   uint8_t vy; //Tie up to actual velocity?
   int8_t HP;
   uint8_t init;
   uint16_t index;
};

struct LCD {

   volatile uint8_t a;
   volatile uint8_t b;
   volatile uint8_t c;
   volatile uint8_t d;
   uint8_t option;
   uint8_t noption;
   uint8_t ooption;
   uint8_t gr;
};

struct powerup {
   uint8_t x;
   uint8_t y;
   uint8_t ox;
   uint8_t oy;
   uint8_t powertype;
   uint8_t active;
};

/* Exported functions ------------------------------------------------------- */
void clrscr();

void gotoxy(uint8_t x, uint8_t y);

void cursortype(int8_t type);

void setLed(char j);

void life();

void lcd_write_string(char a[],int loc);

char readJoystick();

#endif
