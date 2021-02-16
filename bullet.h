#ifndef _BULLET_H_
#define _BULLET_H_

/* Includes ------------------------------------------------------------------*/
#include "enemy.h"
#include "utility.h"
#include "player.h"
#include "powerup.h"



/* Structs ------------------------------------------------------------------ */
struct bullet {

   uint8_t x;
   uint8_t y;
   uint8_t vx;
   uint8_t vy;
   uint8_t shot;
   uint8_t type;

};

/* Exported functions ------------------------------------------------------- */
void init_bullet(struct bullet *o,struct bullet *o2,struct bullet *o3,struct bullet *o4,struct bullet *o5,struct bullet *b1,struct bullet *b2,struct bullet *b3,struct bullet *b4,struct bullet *b5,struct bullet *b6,struct bullet *b7,struct bullet *b8,struct bullet *b9,struct bullet *b10,struct bullet *b11,struct bullet *b12,struct bullet *b13,struct bullet *b14);

void bullet_player(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3,struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

void bullet_player_rocket(struct bullet *o3,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

void bullet_enemy(struct bullet *b,struct enemy *e,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

void bullet_player_rocket_up(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

void bullet_player_rocket_down(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

#endif /* _bullet_H_ */

