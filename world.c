#include "utility.h"
#include "world.h"
#include "level.h"
#include "player.h"

//Creates the game window and additionally: clears screen, sets cursor type, shows world and player info
void game_window() {

    clrscr();
    fgcolor(15);
    cursortype(1);

    uint8_t x_1=25;
    uint8_t x_2=237;
    uint8_t y_1=0;
    uint8_t y_2=70;

    uint8_t a= x_2 - x_1+1;
    uint8_t b= y_2 - y_1;
    uint8_t i;

    gotoxy(x_1-1,y_1);
    for (i = 1; i <= a; i++) {
        printf("%c",220);
    }

    gotoxy(x_1,y_2);
    for (i = 1; i <= a; i++) {
        printf("%c",220);
    }

    gotoxy(x_1,y_1);
    for (i = 1; i <= b; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    mars_window();
    life();

    gotoxy(x_2,y_1);
    fgcolor(15);
    for (i = 1; i <= b; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    gotoxy(x_2,y_2);
    printf(" ");
}

//Creates earth model
void earth_window(){
    uint8_t x_2=237;
    uint8_t y_1=0;
    uint8_t y_2=70;

    uint8_t b= y_2 - y_1;
    uint8_t i;
    uint8_t j;

    gotoxy(x_2-5,y_1+8);
    fgcolor(4);
    for (i = 1; i <= b-22; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    gotoxy(x_2-4,y_1+4);
    fgcolor(4);
    for (i = 1; i <= b-14; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    for (j = 1; j <= 3; j++){
        gotoxy(x_2-j,y_1);
        fgcolor(4);
        for (i = 1; i <= b-8; i++) {
            printf("%c[%dB", ESC, 1);
            printf("%c[%dD", ESC, 1);
            printf("%c",219);
        }
    }


    gotoxy(x_2-5,y_1+8);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+9);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-4,y_1+9);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+15);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+16);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-4,y_1+15);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-3,y_1+14);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+13);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+42);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+43);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+44);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+45);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+46);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+47);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+51);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+52);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+53);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+52);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+53);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+31);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+32);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-1,y_1+33);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+32);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+33);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+34);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+35);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-2,y_1+36);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+23);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);

    gotoxy(x_2-5,y_1+24);
    fgcolor(2);
    printf("%c[%dB", ESC, 1);
    printf("%c[%dD", ESC, 1);
    printf("%c",219);
}

//Creates mars model
void mars_window(){

    uint8_t x_2=237;
    uint8_t y_1=0;
    uint8_t y_2=70;

    uint8_t b= y_2 - y_1;
    uint8_t i;
    uint8_t j;

    gotoxy(x_2-5,y_1+8);
    fgcolor(9);
    for (i = 1; i <= b-22; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    gotoxy(x_2-4,y_1+4);
    fgcolor(9);
    for (i = 1; i <= b-14; i++) {
        printf("%c[%dB", ESC, 1);
        printf("%c[%dD", ESC, 1);
        printf("%c",219);
    }

    for (j = 1; j <= 3; j++){
        gotoxy(x_2-j,y_1);
        fgcolor(9);
        for (i = 1; i <= b-8; i++) {
            printf("%c[%dB", ESC, 1);
            printf("%c[%dD", ESC, 1);
            printf("%c",219);
        }
    }


    printf("%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dH%c%c[%d;%dH%c",
        ESC,46,233,ESC,22,37,219,219,
        ESC,47,232,219,ESC,1,30,219,219,
        ESC,48,234,219,
        ESC,48,234,219);

    printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c",
        ESC,30,231,ESC,22,37,219,219,219,219,219,
        ESC,31,231,ESC,1,30,219,219,219,219,219,
        ESC,32,231,ESC,1,30,219,219,219,219,219,
        ESC,33,231,ESC,22,37,219,219,219,219,219);

    printf("%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c",
        ESC,56,233,ESC,1,37,219,219,
        ESC,57,233,219,219,
        ESC,58,234,219,
        ESC,58,234,219,
        ESC,59,234,219,
        ESC,60,234,219,
        ESC,61,234,219);

    printf("%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c%c",
        ESC,10,232,ESC,1,30,219,219,
        ESC,11,232,219,219,
        ESC,17,234,219,
        ESC,18,234,219,
        ESC,19,234,219,
        ESC,20,234,219,
        ESC,21,233,219,219);
}

//Displays initial HP (the hearts)
void life(){

    printf("%c[%d;%dH%c[%d;%dmHEALTH",ESC,6,6,ESC,1,37);

    printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
           ESC,8,12,ESC,1,37,219,219,255,219,219,
           ESC,9,11,219,ESC,2,31,219,219,ESC,1,37,219,ESC,2,31,219,219,ESC,1,37,219,
           ESC,10,11,219,ESC,2,31,219,219,219,219,219,ESC,1,37,219,
           ESC,11,12,219,ESC,2,31,219,219,219,ESC,1,37,219,
           ESC,12,13,219,ESC,2,31,219,ESC,1,37,219,
           ESC,13,14,219,
           ESC,15,12,ESC,1,37,219,219,255,219,219,
           ESC,16,11,219,ESC,2,31,219,219,ESC,1,37,219,ESC,2,31,219,219,ESC,1,37,219,
           ESC,17,11,219,ESC,2,31,219,219,219,219,219,ESC,1,37,219,
           ESC,18,12,219,ESC,2,31,219,219,219,ESC,1,37,219,
           ESC,19,13,219,ESC,2,31,219,ESC,1,37,219,
           ESC,20,14,219,
           ESC,22,12,ESC,1,37,219,219,255,219,219,
           ESC,23,11,219,ESC,2,31,219,219,ESC,1,37,219,ESC,2,31,219,219,ESC,1,37,219,
           ESC,24,11,219,ESC,2,31,219,219,219,219,219,ESC,1,37,219,
           ESC,25,12,219,ESC,2,31,219,219,219,ESC,1,37,219,
           ESC,26,13,219,ESC,2,31,219,ESC,1,37,219,
           ESC,27,14,219);
}

//Initializes asteroid
void init_asteroid(struct asteroid *c){

    c->x=150;
    c->y=50;
    c->vx=- 2;
    c->vy=0;
    c->active=0;
}

//Removes lingering pixels from asteroid model
void asteroid_del(struct asteroid *c) {

    if (c->active == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c",
            ESC,c->y-1,c->x-2,ESC,22,37,255,255,255,255,255,255,ESC,22,31,255,255,255,
            ESC,c->y,c->x-3,ESC,22,37,219,ESC,1,30,219,219,219,219,219,ESC,22,37,219,ESC,1,33,219,ESC,1,31,255,ESC,22,31,255,
            ESC,c->y+1,c->x-2,ESC,22,37,219,ESC,1,30,219,219,219,219,ESC,22,37,219,ESC,1,33,255,ESC,22,31,255,255,
            ESC,c->y+2,c->x-1,ESC,22,37,255,255,255,255,255,ESC,22,31,255,255);
    }
}

//Completely removes the asteroids model
void asteroid_remove(struct asteroid *c){

    printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c",
        ESC,c->y-1,c->x-2,ESC,22,37,255,255,255,255,255,255,ESC,22,31,255,255,255,
        ESC,c->y,c->x-3,ESC,22,37,255,ESC,1,30,255,255,255,255,255,ESC,22,37,255,ESC,1,33,255,ESC,1,31,255,ESC,22,31,255,
        ESC,c->y+1,c->x-2,ESC,22,37,255,ESC,1,30,255,255,255,255,ESC,22,37,255,ESC,1,33,255,ESC,22,31,255,255,
        ESC,c->y+2,c->x-1,ESC,22,37,255,255,255,255,255,ESC,22,31,255,255);
}

//Updates asteroid position
void asteroid_update(struct asteroid *c){

    if (c->active == 1){
        c->x += c->vx;
        c->y += c->vy;
    }
}

//Displays asteroid model
void asteroid_make(struct asteroid *c) {

    if (c->active == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c",
            ESC,c->y-1,c->x-2,ESC,22,37,220,220,220,220,220,255,ESC,22,31,220,220,220,
            ESC,c->y,c->x-3,ESC,22,37,219,ESC,1,30,219,219,219,219,219,ESC,22,37,219,ESC,1,33,219,ESC,1,31,219,ESC,22,31,219,
            ESC,c->y+1,c->x-2,ESC,22,37,219,ESC,1,30,219,219,219,219,ESC,22,37,219,ESC,1,33,219,ESC,22,31,219,223,
            ESC,c->y+2,c->x-1,ESC,22,37,223,223,223,223,255,ESC,22,31,223,223);
    }
}

//Function that checks if the asteroid has hit a wall and deletes if so.
void asteroid_check_wall(struct asteroid *c){

    if (c->active == 1){

        if (c->x <= 29 || c->y >= 60 || c->y <= 3){

            c->active = 0; //Sets the asteroid as inactive so it will not interact

            asteroid_remove(c);

            c->x = 10;
            c->y = 10;

        }
    }
}

//Function that resets the asteroid and randomly chooses the x position as well whether it comes from below or above
void reset_asteroid(struct asteroid *c,struct player *p){

    if (c->active == 0){

        c->x=100 + rng(p, 50);
        if (rng(p, 2) > 0){
            c->y=4;
            c->vy=1;
        }
        else {
            c->y=60;
            c->vy=-1;
        }
        c->active=1;
    }
}

//Function that checks if the asteroid hits the player
void asteroid_hit_player(struct asteroid *c,struct player *p){

    //Function also decrements HP with 1 and makes LED red
    if (c->x - p->x  >=  -2 && c->x - p->x  <= 17  && c->y - p->y <5 && c->y - p->y >= -2){

        if (p->HP != 0){

            p->oHP=p->HP;
            p->HP-=1;

            setLed(1);

            c->active = 0;

            asteroid_remove(c);

            c->x = 10;
            c->y = 10;

            p->ox = p->x;
            p->oy = p->y;
            p->x = 26;
            p->y = 3;
        }
    }
}

//Prints the game over visuals.
void game_over(){

    printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dHNavigate the menu to try again",
        ESC,16,81,ESC,1,375,219,219,219,219,219,255,255,219,219,219,255,255,255,219,255,219,255,255,219,219,219,219,219,
        ESC,17,81,219,255,255,255,255,255,219,255,255,255,219,255,219,255,219,255,219,255,219,255,255,255,255,
        ESC,18,81,219,255,219,219,219,255,219,219,219,219,219,255,219,255,255,255,219,255,219,219,219,219,255,
        ESC,19,81,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,255,
        ESC,20,81,219,219,219,219,219,255,219,255,255,255,219,255,219,255,255,255,219,255,219,219,219,219,219,
        ESC,22,81,219,219,219,219,219,255,219,255,255,255,219,255,219,219,219,219,219,255,219,219,219,219,255,
        ESC,23,81,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,255,255,219,255,255,255,219,
        ESC,24,81,219,255,255,255,219,255,255,219,255,219,255,255,219,219,219,219,255,255,219,219,219,219,255,
        ESC,25,81,219,255,255,255,219,255,255,219,255,219,255,255,219,255,255,255,255,255,219,255,255,255,219,
        ESC,26,81,219,219,219,219,219,255,255,255,219,255,255,255,219,219,219,219,219,255,219,255,255,255,219,
        ESC,29,78);
}

//Prints the game won visuals.
void game_won() {

    printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dHNavigate the menu to try again",
        ESC,16,86,ESC,1,37,255,219,219,219,219,219,255,255,219,219,219,255,255,219,219,219,219,255,255,219,219,219,219,219,255,219,255,255,255,219,
        ESC,17,86,255,219,255,255,255,255,255,219,255,255,255,219,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,255,255,219,
        ESC,18,86,255,219,219,219,219,255,255,219,219,219,219,219,255,219,219,219,219,255,255,255,255,219,255,255,255,219,219,219,219,219,
        ESC,19,86,255,219,255,255,255,255,255,219,255,255,255,219,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,255,255,219,
        ESC,20,86,255,219,219,219,219,219,255,219,255,255,255,219,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,255,255,219,
        ESC,22,80,255,219,219,219,219,219,255,219,255,255,255,219,255,219,255,255,255,219,255,255,219,219,219,255,255,219,219,219,219,255,255,219,219,219,219,219,255,219,219,219,219,255,
        ESC,23,80,255,255,255,219,255,255,255,219,219,255,255,219,255,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,255,255,219,255,255,255,219,
        ESC,24,80,255,255,255,219,255,255,255,219,255,219,255,219,255,255,219,255,219,255,255,219,219,219,219,219,255,219,255,255,255,219,255,219,219,219,219,255,255,219,255,255,255,219,
        ESC,25,80,255,255,255,219,255,255,255,219,255,255,219,219,255,255,219,255,219,255,255,219,255,255,255,219,255,219,255,255,255,219,255,219,255,255,255,255,255,219,255,255,255,219,
        ESC,26,80,255,219,219,219,219,219,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,219,219,219,219,255,255,219,219,219,219,219,255,219,219,219,219,255,
        ESC,28,92,255,219,255,255,255,219,255,219,219,219,219,219,255,219,255,255,255,219,
        ESC,29,92,255,219,219,255,219,219,255,219,255,255,255,219,255,219,255,255,255,219,
        ESC,30,92,255,255,219,219,219,255,255,219,255,255,255,219,255,219,255,255,255,219,
        ESC,31,92,255,255,255,219,255,255,255,219,255,255,255,219,255,219,255,255,255,219,
        ESC,32,92,255,255,255,219,255,255,255,219,219,219,219,219,255,219,219,219,219,219,
        ESC,34,92,255,219,255,255,255,219,255,219,219,219,219,219,255,219,255,255,255,219,
        ESC,35,92,255,219,255,255,255,219,255,255,255,219,255,255,255,219,219,255,255,219,
        ESC,36,92,255,219,255,255,255,219,255,255,255,219,255,255,255,219,255,219,255,219,
        ESC,37,92,255,219,255,219,255,219,255,255,255,219,255,255,255,219,255,255,219,219,
        ESC,38,92,255,255,219,255,219,255,255,219,219,219,219,219,255,219,255,255,255,219,
        ESC,41,87);
}

//Functions provided by the course
void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
    uint8_t type = 22;             // normal text
	if (foreground > 7) {
        type = 1;                // bold text
		foreground -= 8;
	}
    printf("%c[%d;%dm", ESC, type, foreground+30);
}

//Functions provided by the course
void resetbgcolor() {
    //Gray on black text, no underline, no blink, no reverse
    printf("%c[m", ESC);
}
