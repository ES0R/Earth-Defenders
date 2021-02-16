#ifndef _POWERUP_H_
#define _POWERUP_H_

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "player.h"


/* Structs ------------------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */
void powerup_activate(struct powerup *pow,struct player *p);

void delete_powerup(struct powerup *pow);

void disp_powerup(struct powerup *pow);

void init_powerup(struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket);

#endif /* _POWERUP_H_ */
