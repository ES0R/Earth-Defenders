
#ifndef _TIME_H_
#define _TIME_H_

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Structs ------------------------------------------------------------------*/
struct Timer {

   volatile uint8_t h;
   volatile uint8_t m;
   volatile uint8_t s;
   volatile uint8_t hs;
   volatile uint8_t ms;
   volatile uint8_t flag;

};

struct Timer T;
struct Timer T1;
struct Timer T_player;
struct Timer T_enemy;
struct Timer T_bullet;
struct Timer T_enemybullet;
struct Timer T_score;
struct Timer T_powerup;
struct Timer T_asteroid;
struct Timer T_level;
struct Timer T_time;

/* Exported functions ------------------------------------------------------- */
void init_timer2();

void init_timepoint();

#endif

