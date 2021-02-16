#ifndef _LCDMENU_H_
#define _LCDMENU_H_
#define ESC 0x1B

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "utility.h"
#include "stm32f30x_flash.h"

/* Structs ------------------------------------------------------------------ */


/* Exported functions ------------------------------------------------------- */
void clrlcd();

void menu_joystick (char j, struct LCD *l);

uint8_t joystick_antispam (char k, struct LCD *l);

void menu_disp (struct LCD *l);

void check_if_high_score (struct player *p);

void reset_high_score();

#endif /* _POWERUP_H_ */
