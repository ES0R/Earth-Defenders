#include "utility.h"
#include "level.h"
#include "powerup.h"

//Function that activates power-up with random y-position
void powerup_activate(struct powerup *pow,struct player *p){

    if (pow->active == 0){
        pow->x=170;
        pow->y=rng(p, 55)+5;
        pow->active=1;
    }
}

//This function removes the power-up model
void delete_powerup(struct powerup *pow){

    printf("%c[%d;%dH%c%c%c%c[%d;%dH%c%c%c",
        ESC,pow->y,pow->x,255,255,255,ESC,pow->y+1,pow->x,255,255,255);
}

//Function that displays the different power-up models
void disp_powerup(struct powerup *pow){

    if (pow->powertype == 1){

        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dH%c%c%c",
            ESC,pow->y,pow->x,ESC,22,31,220,219,220,ESC,pow->y+1,pow->x,255,223,255);
    }

    if (pow->powertype == 2){

        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c",
            ESC,pow->y+1,pow->x,ESC,22,33,219,255,219,ESC,pow->y,pow->x,ESC,1,30,220,255,220);
    }

    if (pow->powertype == 3){

        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c",
            ESC,pow->y+1,pow->x,ESC,22,31,219,255,219,ESC,pow->y,pow->x,ESC,1,30,220,255,220);
    }
}

//Initializes the 3 different power-ups
void init_powerup(struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){

    lifeplus->x = 5;
    lifeplus->y = 10;
    lifeplus->powertype = 1;
    lifeplus->active = 0;

    bulletplus->x = 5;
    bulletplus->y = 10;
    bulletplus->powertype = 2;
    bulletplus->active = 0;

    rocket->x = 5;
    rocket->y = 10;
    rocket->powertype = 3;
    rocket->active = 0;
}
