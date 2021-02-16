
#ifndef _PLAYER_H_
#define _PLAYER_H_

/* Includes ------------------------------------------------------------------*/
#include "utility.h"
#include "bullet.h"

/* Structs ------------------------------------------------------------------ */

/* Exported functions ------------------------------------------------------- */
void init_player(struct player *p);

void player_make(struct player *p);

void player_del(struct player *p);

void player_input(struct player *p);

void player_update(struct player *p,struct bullet *o,struct bullet *o2);

void scoredis(struct player *p);

void hpcounter(struct player *p);

void respawn_player(struct player *p);

void player_joystick(struct bullet *o3,struct bullet *o4,struct bullet *o5,struct player *p);


#endif /* _PLAYER_H_ */
