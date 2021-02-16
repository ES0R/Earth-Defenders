#ifndef _LEVEL_H_
#define _LEVEL_H_

/* Includes ------------------------------------------------------------------*/
#include "utility.h"

/* Exported functions ------------------------------------------------------- */
int level_up(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON, int level, int *level_flag);

int * lanes(struct player *p, int ships);

int rng(struct player *p, int maxium);

#endif /* _LEVEL_H_ */
