#ifndef _WORLD_H_
#define _WORLD_H_

/* Includes ------------------------------------------------------------------*/
#include "enemy.h"
#include "player.h"

/* Exported macro ------------------------------------------------------------*/
#define ESC 0x1B

/* Structs ------------------------------------------------------- */

struct asteroid {

   uint8_t x;
   uint8_t y;
   uint8_t vx;
   uint8_t vy;
   uint8_t HP;
   uint8_t active;
};



/* Exported functions ------------------------------------------------------- */
void game_window();

void earth_window();

void mars_window();

void init_asteroid(struct asteroid *c);

void asteroid_del(struct asteroid *c);

void asteroid_update(struct asteroid *c);

void asteroid_make(struct asteroid *c);

void asteroid_check_wall(struct asteroid *c);

void reset_asteroid(struct asteroid *c,struct player *p);

void asteroid_hit_player(struct asteroid *c,struct player *p);

void game_over();

void game_won();

void fgcolor(uint8_t foreground);

#endif /* _WORLD_H_ */
