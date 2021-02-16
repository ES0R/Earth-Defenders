#include "enemy.h"
#include "utility.h"

//Initialize all enemies as dead
void init_enemy(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON){

    ES1->type=0;
    ES1->x=0;
    ES1->y=0;
    ES1->vx=0;
    ES1->vy=0;
    ES1->HP=-1;
    ES1->init=0;
    ES1->index=0;

    ES2->type=0;
    ES2->x=0;
    ES2->y=0;
    ES2->vx=0;
    ES2->vy=0;
    ES2->HP=-1;
    ES2->init=0;
    ES2->index=0;

    ES3->type = 0;
    ES3->x = 0;
    ES3->y = 0;
    ES3->vx = 0;
    ES3->vy = 0;
    ES3->HP = -1;
    ES3->init = 0;
    ES3->index = 0;

    ES4->type = 0;
    ES4->x = 0;
    ES4->y = 0;
    ES4->vx = 0;
    ES4->vy = 0;
    ES4->HP = -1;
    ES4->index = 0;
    ES4->init = 0;

    ES5->type = 0;
    ES5->x = 0;
    ES5->y = 0;
    ES5->vx = 0;
    ES5->vy = 0;
    ES5->HP = -1;
    ES5->index = 0;
    ES5->init = 0;

    EB1->type = 0;
    EB1->x = 0;
    EB1->y = 0;
    EB1->vx = 0;
    EB1->vy = 0;
    EB1->HP = -1;
    EB1->init = 0;
    EB1->index = 0;

    EB2->type = 0;
    EB2->x = 0;
    EB2->y = 0;
    EB2->vx = 0;
    EB2->vy = 0;
    EB2->HP = -1;
    EB2->index = 0;
    EB2->init = 0;

    EB3->type = 0;
    EB3->x = 0;
    EB3->y = 0;
    EB3->vx = 0;
    EB3->vy = 0;
    EB3->HP = -1;
    EB3->index = 0;
    EB3->init = 0;

    ELON->type = 0;
    ELON->x = 0;
    ELON->y = 0;
    ELON->vx = 0;
    ELON->vy = 0;
    ELON->HP = -1;
    ELON->index = 0;
    ELON->init = 0;
}

//Initialize final boss
void init_enemy_ELON(struct enemy *e){

        e->type=0;
        e->x=200;
        e->y=15;
        e->vx=0;
        e->vy=0;
        e->HP=10;
        e->index=0;
        e->init = 1;
}

//Initialize small enemy 1
void init_enemy_small1(struct enemy *ES1, int *random_lanes, int number_of_enemies){

        ES1->type=0;
        ES1->x=200;
        ES1->y=12*random_lanes[0]+3; //Chooses a randomly assigned lane for the enemy to spawn on
        ES1->vx=0;
        ES1->vy=0;
        ES1->HP=1;
        ES1->index=0;
        ES1->init = 1;
}

//Initialize small enemy 2
void init_enemy_small2(struct enemy *ES1,struct enemy *ES2,int *random_lanes, int number_of_enemies){

    //Here the function that initializes enemy 1 is called.
    //Now both ES1 and ES2 are initialized.
    init_enemy_small1(ES1,random_lanes,number_of_enemies);

    ES2->type=0;
    ES2->x=200;
    ES2->y=12*random_lanes[1]+3;
    ES2->vx=0;
    ES2->vy=0;
    ES2->HP=1;
    ES2->index=0;
    ES2->init = 1;
}

//Initialize small enemy 3
void init_enemy_small3(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3,int *random_lanes, int number_of_enemies){

    init_enemy_small2(ES1,ES2,random_lanes,number_of_enemies);

    ES3->type = 0;
    ES3->x = 200;
    ES3->y = 12*random_lanes[2]+3;
    ES3->vx = 0;
    ES3->vy = 0;
    ES3->HP = 1;
    ES3->index = 0;
    ES3->init = 1;
}

//Initialize small enemy 4 using "overloading functions"
void init_enemy_small4(struct enemy *ES1, struct enemy *ES2, struct enemy *ES3, struct enemy *ES4, int *random_lanes, int number_of_enemies){

    init_enemy_small3(ES1,ES2,ES3,random_lanes,number_of_enemies);

    ES4->type = 0;
    ES4->x = 200;
    ES4->y = 12*random_lanes[3]+3;
    ES4->vx = 0;
    ES4->vy = 0;
    ES4->HP = 1;
    ES4->index = 0;
    ES4->init = 1;
}

//Initialize small enemy 5 using "overloading functions"
void init_enemy_small5(struct enemy *ES1, struct enemy *ES2, struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, int *random_lanes, int number_of_enemies){

    init_enemy_small4(ES1,ES2,ES3,ES4,random_lanes,number_of_enemies);

    ES5->type = 0;
    ES5->x = 200;
    ES5->y = 12*random_lanes[4]+3;
    ES5->vx = 0;
    ES5->vy = 0;
    ES5->HP = 1;
    ES5->index = 0;
    ES5->init = 1;
}

//Initialize big enemy 1
void init_enemy_big1(struct enemy *EB1,int *random_lanes, int number_of_enemies){

        EB1->type=0;
        EB1->x=200;
        EB1->y=12*(random_lanes[number_of_enemies - 1])+3; //Instead of choosing the first element. The big enemies start from the last elements and goes towards the first.
        EB1->vx=0;
        EB1->vy=0;
        EB1->HP=3;
        EB1->index=0;
        EB1->init = 1;
}

//Initialize big enemy 2 using "overloading functions"
void init_enemy_big2(struct enemy *EB1, struct enemy *EB2, int *random_lanes, int number_of_enemies){

    init_enemy_big1(EB1,random_lanes,number_of_enemies);

    EB2->type = 0;
    EB2->x = 200;
    EB2->y = 12*random_lanes[number_of_enemies - 2]+3;
    EB2->vx = 0;
    EB2->vy = 0;
    EB2->HP = 3;
    EB2->index = 0;
    EB2->init = 1;
}

//Initialize big enemy 3 using "overloading functions"
void init_enemy_big3(struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, int *random_lanes, int number_of_enemies){

    init_enemy_big2(EB1,EB2,random_lanes,number_of_enemies);

    EB3->type = 0;
    EB3->x = 200;
    EB3->y = 12*random_lanes[number_of_enemies - 3]+3;
    EB3->vx = 0;
    EB3->vy = 0;
    EB3->HP = 3;
    EB3->index = 0;
    EB3->init = 1;
}

//Function updates enemy movement so it moves up and down without for or while loop
int enemy_update(struct enemy *e, int val, int maxY){

    //After going up and down the index is set to 0
    //Meaning that the motion will repeat itself indefinitely  (atleast until index overflows)
    if (e->index >= maxY * 2){
        return 0;
    }

    //Increments enemy y-position with positive val until it reaches maxY (Going down)
    if (e->index < maxY){
        e->y += val;

        e->index++;

        return e->index;
    }
    //Increments enemy y-posit wit negative val until it reaches its spawning point (Going up)
    else{
        e->y -= val;

        e->index++;

        return e->index;
    }
}

//Removes small enemy model
void enemy_dead(struct enemy *e) {

    printf("%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c",
        ESC,e->y,e->x,255,ESC,1,30,255,ESC,1,37,255,255,255,255,255,255,255,ESC,1,30,255,255,ESC,22,31,255,
        ESC,e->y+1,e->x,ESC,1,30,255,255,ESC,1,37,255,ESC,1,30,255,ESC,1,37,255,255,255,255,255,255,255,255,
        ESC,e->y+2,e->x,255,ESC,1,30,255,ESC,1,37,255,255,255,255,255,255,255,ESC,1,30,255,255,ESC,22,31,255);
}

//Removes big enemy model. The model is different based on HP therefor it has to be accounted for.
void enemy_dead_big(struct enemy *e) {

    if (e->HP == 3){
        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c",
            ESC,e->y,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+1,e->x+7,255,255,
            ESC,e->y+2,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+3,e->x+7,255,255,
            ESC,e->y+4,e->x+6,ESC,1,37,255,255,255,255,
            ESC,e->y+5,e->x+7,ESC,22,37,255,255,
            ESC,e->y+6,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+7,e->x+7,255,255,
            ESC,e->y+8,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255);
    }
    else if (e->HP == 2){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c",
            ESC,e->y-3,e->x+3,ESC,22,31,255,255,255,255,255,
            ESC,e->y-2,e->x+1,ESC,22,31,255,255,255,ESC,1,31,255,ESC,1,33,255,255,ESC,22,31,255,255,
            ESC,e->y-1,e->x,ESC,22,31,255,255,ESC,1,31,255,ESC,1,33,255,255,255,255,ESC,1,31,255,ESC,22,31,255,
            ESC,e->y,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+1,e->x+7,255,255,
            ESC,e->y+2,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+3,e->x+7,255,255,
            ESC,e->y+4,e->x+6,ESC,1,37,255,255,255,255,
            ESC,e->y+5,e->x+7,ESC,22,37,255,255,
            ESC,e->y+6,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+7,e->x+7,255,255,
            ESC,e->y+8,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255);
    }
    else if (e->HP == 1  || e->HP == -1){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c%c",
            ESC,e->y-3,e->x+3,ESC,22,31,255,255,255,255,255,
            ESC,e->y-2,e->x+1,ESC,22,31,255,255,255,ESC,1,31,255,ESC,1,33,255,255,ESC,22,31,255,255,
            ESC,e->y-1,e->x,ESC,22,31,255,255,ESC,1,31,255,ESC,1,33,255,255,255,255,ESC,1,31,255,ESC,22,31,255,
            ESC,e->y,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+1,e->x+7,255,255,
            ESC,e->y+2,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+3,e->x+7,255,255,
            ESC,e->y+4,e->x+6,ESC,1,37,255,255,255,255,
            ESC,e->y+5,e->x+7,ESC,22,37,255,255,
            ESC,e->y+6,e->x,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,255,255,255,ESC,22,37,255,
            ESC,e->y+7,e->x+7,255,255,ESC,1,33,255,ESC,1,31,255,ESC,22,31,255,255,
            ESC,e->y+8,e->x,ESC,22,37,255,255,255,255,255,ESC,22,34,255,255,255,255,ESC,22,37,255,ESC,22,34,255,ESC,1,33,255,ESC,1,33,255,255,ESC,1,31,255,ESC,22,31,255,
            ESC,e->y+9,e->x+7,ESC,22,31,255,255,255,255,255,255,255,255);
    }
}

//Removes final boss model
void enemy_dead_ELON(struct enemy *e){

    printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c%c%c%c",
        ESC,e->y-3,e->x+9,ESC,1,30,255,ESC,1,37,255,
        ESC,e->y-2,e->x+3,ESC,22,36,255,255,255,255,255,255,ESC,1,37,255,255,
        ESC,e->y-1,e->x+1,ESC,22,36,255,255,ESC,22,37,255,255,255,255,255,255,ESC,1,37,255,255,ESC,22,37,255,255,255,255,255,255,255,255,ESC,22,31,255,255,
        ESC,e->y,e->x-4,ESC,22,31,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
        ESC,e->y+1,e->x-6,ESC,22,31,255,255,255,255,255,255,ESC,1,30,255,255,ESC,22,37,255,255,ESC,1,30,255,255,ESC,22,31,255,255,255,255,255,255,255,255,255,ESC,1,30,255,255,ESC,22,37,255,255,ESC,1,30,255,255,ESC,22,31,255,
        ESC,e->y+2,e->x+1,ESC,1,30,255,255,255,255,
        ESC,e->y+2,e->x+16,255,255,255,255);
}

//Shows small enemy model
void display_enemy(struct enemy *e){

    printf("%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c",
        ESC,e->y,e->x,255,ESC,1,30,220,ESC,1,37,220,220,220,220,220,220,220,ESC,1,30,219,219,ESC,22,31,219,
        ESC,e->y+1,e->x,ESC,1,30,219,219,ESC,1,37,219,ESC,1,30,219,ESC,1,37,219,219,219,219,219,255,255,255,
        ESC,e->y+2,e->x,255,ESC,1,30,223,ESC,1,37,223,223,223,223,223,223,223,ESC,1,30,219,219,ESC,22,31,219);
}

//Shows big enemy model
void display_big_enemy(struct enemy *e){

    if (e->HP == 3){
        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c",
            ESC,e->y,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+1,e->x+7,219,219,
            ESC,e->y+2,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+3,e->x+7,219,219,
            ESC,e->y+4,e->x+6,ESC,1,37,219,219,219,219,
            ESC,e->y+5,e->x+7,ESC,22,37,219,219,
            ESC,e->y+6,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+7,e->x+7,219,219,
            ESC,e->y+8,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219);
    }

    else if (e->HP == 2){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c",
            ESC,e->y-3,e->x+3,ESC,22,31,220,220,220,220,219,
            ESC,e->y-2,e->x+1,ESC,22,31,220,220,219,ESC,1,31,219,ESC,1,33,219,219,ESC,22,31,219,220,
            ESC,e->y-1,e->x,ESC,22,31,220,219,ESC,1,31,219,ESC,1,33,219,219,219,219,ESC,1,31,219,ESC,22,31,219,
            ESC,e->y,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+1,e->x+7,219,219,
            ESC,e->y+2,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+3,e->x+7,219,219,
            ESC,e->y+4,e->x+6,ESC,1,37,219,219,219,219,
            ESC,e->y+5,e->x+7,ESC,22,37,219,219,
            ESC,e->y+6,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+7,e->x+7,219,219,
            ESC,e->y+8,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219);

    }
    else if (e->HP == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c",
            ESC,e->y-3,e->x+3,ESC,22,31,220,220,220,220,219,
            ESC,e->y-2,e->x+1,ESC,22,31,220,220,219,ESC,1,31,219,ESC,1,33,219,219,ESC,22,31,219,220,
            ESC,e->y-1,e->x,ESC,22,31,220,219,ESC,1,31,219,ESC,1,33,219,219,219,219,ESC,1,31,219,ESC,22,31,219,
            ESC,e->y,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+1,e->x+7,219,219,
            ESC,e->y+2,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+3,e->x+7,219,219,
            ESC,e->y+4,e->x+6,ESC,1,37,219,219,219,219,
            ESC,e->y+5,e->x+7,ESC,22,37,219,219,
            ESC,e->y+6,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,
            ESC,e->y+7,e->x+7,219,219,ESC,1,33,219,ESC,1,31,219,ESC,22,31,219,223,
            ESC,e->y+8,e->x,ESC,22,37,219,ESC,22,34,219,219,219,219,ESC,22,37,219,ESC,22,34,219,ESC,1,33,219,ESC,1,33,219,219,ESC,1,31,219,ESC,22,31,219,
            ESC,e->y+9,e->x+7,ESC,22,31,223,219,223,223);
    }
}

//Shows final boss model
void display_ELON(struct enemy *e){

        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c%c%c%c%c%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c%c%c%c[%d;%dH%c%c%c%c",
        ESC,e->y-3,e->x+9,ESC,1,30,220,ESC,1,37,220,
        ESC,e->y-2,e->x+3,ESC,22,36,220,223,255,255,255,255,ESC,1,37,219,219,
        ESC,e->y-1,e->x+1,ESC,22,36,220,219,ESC,22,37,220,220,220,220,220,220,ESC,1,37,219,219,ESC,22,37,220,220,220,220,220,220,220,220,ESC,22,31,220,220,
        ESC,e->y,e->x-4,ESC,22,31,220,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
        ESC,e->y+1,e->x-6,ESC,22,31,219,219,219,219,219,219,ESC,1,30,219,219,ESC,22,37,219,219,ESC,1,30,219,219,ESC,22,31,219,219,219,219,219,219,219,219,219,ESC,1,30,219,219,ESC,22,37,219,219,ESC,1,30,219,219,ESC,22,31,223,
        ESC,e->y+2,e->x+1,ESC,1,30,223,219,219,223,
        ESC,e->y+2,e->x+16,223,219,219,223);

}

//Function initializes how many small enemies there is needed for the level
void init_all_enemy_small(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, int enemy_small,int *random_lanes, int number_of_enemies){

    switch(enemy_small){
        case 1:
            init_enemy_small1(ES1,random_lanes,number_of_enemies);
        break;

        case 2:
            init_enemy_small2(ES1,ES2,random_lanes,number_of_enemies);
        break;

        case 3:
            init_enemy_small3(ES1,ES2,ES3,random_lanes,number_of_enemies);
        break;

        case 4:
            init_enemy_small4(ES1,ES2,ES3,ES4,random_lanes,number_of_enemies);
        break;

        case 5:
            init_enemy_small5(ES1,ES2,ES3,ES4,ES5,random_lanes,number_of_enemies);
        break;
    }
}

//Function initializes how many big enemies there is needed for the level
void init_all_enemy_big(struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, int enemy_big, int *random_lanes, int number_of_enemies){

    switch(enemy_big){
        case 0:

        break;

        case 1:
            init_enemy_big1(EB1, random_lanes,number_of_enemies);
        break;

        case 2:
            init_enemy_big2(EB1,EB2, random_lanes,number_of_enemies);
        break;

        case 3:
            init_enemy_big3(EB1,EB2, EB3, random_lanes, number_of_enemies);
        break;
    }
}








