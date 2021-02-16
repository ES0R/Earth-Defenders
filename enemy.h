#ifndef _ENEMY_H_
#define _ENEMY_H_

/* Includes ------------------------------------------------------------------*/
#include "utility.h"


/* Structs ------------------------------------------------------------------ */


/* Exported functions ------------------------------------------------------- */
void init_enemy(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON);

void init_enemy_ELON(struct enemy *e);

int enemy_update(struct enemy *ES1, int val, int maxY);

void enemy_dead(struct enemy *e);

void enemy_dead_big(struct enemy *e);

void enemy_dead_ELON(struct enemy *e);

void display_enemy(struct enemy *e);

void display_big_enemy(struct enemy *e);

void display_ELON(struct enemy *e);

void init_all_enemy_small(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, int enemy_small,int *random_lanes, int number_of_enemies);

void init_all_enemy_big(struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, int enemy_big, int *random_lanes, int number_of_enemies);

#endif /* _ENEMY_H_ */
