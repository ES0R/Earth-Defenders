#include "utility.h"
#include "player.h"
#include "enemy.h"
#include "powerup.h"
#include "bullet.h"

//This function initializes bullets and sets there values I.E type and velocity
void init_bullet(struct bullet *o,struct bullet *o2,struct bullet *o3,struct bullet *o4,struct bullet *o5,struct bullet *b1,struct bullet *b2,struct bullet *b3,struct bullet *b4,struct bullet *b5,struct bullet *b6,struct bullet *b7,struct bullet *b8,struct bullet *b9,struct bullet *b10,struct bullet *b11,struct bullet *b12,struct bullet *b13,struct bullet *b14){

    o->x = 0;
    o->y = 0;
    o->vx = 1;
    o->vy = 0;
    o->shot = 0;

    o2->x = 0;
    o2->y = 0;
    o2->vx = 1;
    o2->vy = 0;
    o2->shot = 0;


    o3->x = 0;
    o3->y = 0;
    o3->vx = 1;
    o3->vy = 0;
    o3->shot = 0;

    o4->x = 0;
    o4->y = 0;
    o4->vx = 0;
    o4->vy = 1;
    o4->shot = 0;

    o5->x = 0;
    o5->y = 0;
    o5->vx = 0;
    o5->vy = -1;
    o5->shot = 0;

    b1->x = 27;
    b1->y = 35;
    b1->vx = -2;
    b1->vy = 0;
    b1->shot = 0;

    b2->x = 27;
    b2->y = 50;
    b2->vx = -2;
    b2->vy = 0;
    b2->shot= 0;

    b3->x = 27;
    b3->y = 45;
    b3->vx = -2;
    b3->vy = 0;
    b3->shot = 0;

    b4->x = 27;
    b4->y = 3;
    b4->vx = -2;
    b4->vy = 0;
    b4->shot = 0;

    b5->x = 27;
    b5->y = 11;
    b5->vx = -2;
    b5->vy = 0;
    b5->shot = 0;
    b5->type = 1;

    b6->x =27;
    b6->y =35;
    b6->vx =- 2;
    b6->vy =0;
    b6->shot =0;

    b7->x = 27;
    b7->y = 35;
    b7->vx = -2;
    b7->vy = 0;
    b7->shot = 0;

    b8->x = 27;
    b8->y = 35;
    b8->vx = -2;
    b8->vy = 0;
    b8->shot = 0;
    b8->type = 1;

    b9->x = 27;
    b9->y = 35;
    b9->vx = -2;
    b9->vy = 0;
    b9->shot=0;

    b10->x = 27;
    b10->y = 35;
    b10->vx = -2;
    b10->vy = 0;
    b10->shot = 0;
    b10->type = 1;

    b11->x = 27;
    b11->y = 35;
    b11->vx = -2;
    b11->vy = 0;
    b11->shot = 0;

    b12->x = 27;
    b12->y = 35;
    b12->vx = -2;
    b12->vy = 0;
    b12->shot = 0;
    b12->type = 1;

    b13->x = 27;
    b13->y = 35;
    b13->vx = -2;
    b13->vy = 0;
    b13->shot = 0;
    b13->type = 2;

    b14->x = 27;
    b14->y = 35;
    b14->vx = -2;
    b14->vy = 0;
    b14->shot = 0;
}

//This function updates the bullet position based on its velocity if the bullet is active
void bullet_update(struct bullet *o){

    if (o->shot == 1){
        o->x += o->vx;
        o->y += o->vy;
    }
}

//This function prints the bullet if it is active with the use of one printf-function. It also deletes the last bullet and is only used for enemies
void bullet_make_enemy(struct bullet *o) {

    //Works by printing a bullet and two blank spaces to both print a new bullet and delete the old one. This only works for bullets traveling right to left
    if (o->shot == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c",
            ESC,o->y,o->x,ESC,1,37,111,255,255);
    }
}

//This function checks if the player hits a small enemy
void bullet_small_enemy_hitbox(struct bullet *o, struct enemy *e,struct player *p){

    //The function includes a hit box which if hit sets the health of the enemy to zero, gives points, activates the LED and deletes the bullet
    if (o->shot == 1){
        if (o->x - e->x  >=  1 && o->x - e->x  <= 12 && o->y - e->y <=3 && o->y - e->y >= 0){

            if (e->HP >0){

            e->HP=0;
            p->score+=10;
            o->shot=0;
            setLed(2);

            printf("%c[%d;%dH%c",ESC,o->y,o->x +1,127);
            printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
               ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
               ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
               ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,255);
            }
        }
    }
}

//This function checks if the player hits a power up
void bullet_hit_powerup_player(struct bullet *o,struct powerup *pow,struct player *p){

    //A general hitbox for the power up is included.
    if (o->x - pow->x  >=  0 && o->x - pow->x  <= 1  && o->y - pow->y <=1 && o->y - pow->y >= 0){

        //These if statements checks which power up has been hit
        if (pow->powertype == 1){

            //In this power up the player gains a life if not already on full health.
            //The old life is also saved so a change in life can be displayed accordingly
            //Lastly the power up is set as not active
            p->oHP=p->HP;

            if (p->HP <=2){
                p->HP+=1;
            }

            pow->active=0;

            delete_powerup(pow);

            pow->x = 5;
            pow->y = 10;
            pow->ox=pow->x;
            pow->oy=pow->y;
        }

        if (pow->powertype == 2){

            //This power up works as the one before but sets a flag high so the player has access to two bullets now
            p->s2=1;
            pow->active=0;

            delete_powerup(pow);

            pow->x=5;
            pow->y=10;
            pow->ox=pow->x;
            pow->oy=pow->y;
        }

        if (pow->powertype ==3){

            //This power up works as the one before but sets a flag high so the player has access to a rocket now
            p->s3 = 1;
            pow->active = 0;

            delete_powerup(pow);

            pow->x = 5;
            pow->y = 10;
            pow->ox=pow->x;
            pow->oy=pow->y;
        }
    }
}

//This function checks if the enemy hits a power up
void bullet_hit_powerup_enemy(struct bullet *o,struct powerup *pow){

    //It includes a hit box for the power up and if statements which checks which power up has been hit
    //If a power up is hit by an enemy the power up will be displayed again
    if (o->x - pow->x  >=  -2 && o->x - pow->x  <= 0  && o->y - pow->y <2 && o->y - pow->y >= 0){

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
}

//This function checks if the player is hit by an enemy bullet
void bullet_hit_player(struct bullet *o, struct player *p, struct enemy *e){

    //The old life is also saved so a change in life can be displayed accordingly
    if (p->oHP !=p->HP){

        p->oHP=p->HP;
    }

    //The function includes a hit box which checks if the player is hit
    //if the player is not dead it will take a life from the player, activate the LED, delete the bullet, and return the bullet to the enemy based on the type of bullet
    if (o->shot == 1){

        if (o->x - p->x  >=  0 && o->x - p->x  <= 15  && o->y - p->y <3 && o->y - p->y >= 0){

            if (p->HP != 0){

                p->oHP=p->HP;

                p->HP-=1;

                setLed(1);

                printf("%c[%d;%dH%c",ESC,o->y,o->x +1,127);

                if (o->type == 1){

                    o->x=e->x -2;
                    o->y=e->y +8;
                }
                else if (o->type == 2){

                    o->x=e->x -2;
                    o->y=e->y -9;
                }
                else {

                    o->x=e->x - 2;
                    o->y=e->y + 1;
                }

                // The player is sent back to spawn
                p->ox = p->x;
                p->oy = p->y;
                p->x=26;
                p->y=3;

            }
        }
    }
}

//This function checks if the player hits the wall
void bullet_check_wall_player(struct bullet *o){

    //If the shot is active and the bullet is to close to the wall the shot will be set as not active and deleted
    if (o->shot == 1){

        if (o->x >= 229 || o->y >= 63 || o->y <= 3){

        o->shot=0;

        printf("%c[%d;%dH%c",ESC,o->y,o->x +1,127);
        }
    }
}

//This function checks if the enemy hits the wall
void bullet_check_wall_enemy(struct bullet *o,struct enemy *e){

    //This part checks if the bullet is to close to the wall and sets it as no longer active if so
    //It also deletes the bullet and returns it to the enemy based on what type of bullet it is
    if (o->shot == 1){
        if (o->x <= 26){
            o->shot=0;

            printf("%c[%d;%dH%c",ESC,o->y,o->x +1,127);

            if (o->type == 1){

                o->x=e->x -2;
                o->y=e->y +6;
            }
            else if (o->type == 2){

                o->x=e->x -2;
                o->y=e->y -7;
            }
            else {

                o->x=e->x - 2;
                o->y=e->y + 1;
            }
        }
    }
}

//This function prints the bullet if it is active with the use of one printf-function. It also deletes the last bullet and is only used for players
void bullet_make_player(struct bullet *o) {

    // Works by printing a bullet and two blank spaces to both print a new bullet and delete the old one. This only works for bullets traveling left to right
    if (o->shot == 1){
        printf("%c[%d;%dH%c%c[%d;%dm%c",ESC,o->y,o->x,255,ESC,1,37,111);
    }
}

//This function prints the bullet if it is active with the use of one printf-function. It also deletes the last bullet and is only used for players
void bullet_make_playerUP(struct bullet *o) {

    // Works by printing a bullet and two blank spaces to both print a new bullet and delete the old one. This only works for bullets traveling up
    if (o->shot == 1){

        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dH%c",ESC,o->y,o->x,ESC,1,37,111,ESC,o->y-1,o->x,255);
    }
}

//This function prints the bullet if it is active with the use of one printf-function. It also deletes the last bullet and is only used for players
void bullet_make_playerDOWN(struct bullet *o) {

    // Works by printing a bullet and two blank spaces to both print a new bullet and delete the old one. This only works for bullets traveling down
    if (o->shot == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dH%c",ESC,o->y,o->x,ESC,1,37,111,ESC,o->y+1,o->x,255);
    }
}

//This function checks if the player hits the boss
void bullet_hit_boss(struct bullet *o, struct enemy *e,struct player *p){

    //The function includes a hit box to the boss which if hit takes the health of the enemy down by one, gives points, activates the LED and deletes the bullet
    if (o->shot == 1){

        if (o->x - e->x  >=  0 && o->x - e->x  <= 24  && o->y - e->y <=4 && o->y - e->y >= -4){

            if (e->HP > 0){

                e->HP -= 1;
                p->score += 5;
                o->shot = 0;

                setLed(2);

                printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
                       ESC,o->y,o->x,ESC,22,31,255,ESC,1,37,255,255,ESC,1,30,255,
                       ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
                       ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
                       ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,255);
            }
        }
    }
}

//This function checks if the player hits the ISS
void bullet_big_enemy_hitbox(struct bullet *o, struct enemy *e,struct player *p){

    //The function includes a hit box to ISS enemy which if hit takes the health of the enemy down by one, gives points, activates the LED and deletes the bullet
    if (o->shot == 1){

        if (o->x - e->x  >=  2 && o->x - e->x  <= 16  && o->y - e->y <=8 && o->y - e->y >= 0){

            if (e->HP >0){
                e->HP -= 1;
                p->score += 10;
                o->shot = 0;

                setLed(2);

                printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
                       ESC,o->y,o->x,ESC,22,31,255,ESC,1,37,255,255,ESC,1,30,255,
                       ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
                       ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
                       ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,255);
            }
        }
    }
}

//This function displays the rocket if used by the player
void bullet_make_rocket(struct bullet *o) {

    if (o->shot == 1){
        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
            ESC,o->y,o->x,ESC,22,31,219,ESC,1,37,219,219,ESC,1,30,219,
            ESC,o->y,o->x-3,ESC,22,31,219,ESC,1,31,219,ESC,1,33,219,
            ESC,o->y-1,o->x-2,ESC,22,31,220,ESC,1,31,220,
            ESC,o->y+1,o->x-2,ESC,22,31,223,ESC,1,31,223);
    }
}

//This function deletes the rocket after it updates position
void bullet_delete_rocket(struct bullet *o) {

    if (o->shot == 1){

        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
            ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
            ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
            ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,2);
    }
}

//This function makes it so the player can hit enemies with the rocket
void bullet_hit_rocket(struct bullet *o, struct enemy *e,struct player *p){

    // The function includes a hit box to the enemies which if hit takes the health of the enemy down by 0, gives points, activates the LED and deletes the bullet
    if (o->shot == 1){

        if (o->x - e->x  >=  1 && o->x - e->x  <= 12 && o->y - e->y <=5 && o->y - e->y >= 0){

            if (e->HP >0){

                p->s3 = 3;
                e->HP = 0;
                p->score += 10;
                o->shot = 0;

                setLed(2);

                 printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
                   ESC,o->y,o->x,ESC,22,31,255,ESC,1,37,255,255,ESC,1,30,255,
                   ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
                   ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
                   ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,255);
            }
        }
    }
}

//This function checks if the player hits the wall with a rocket
void bullet_check_wall_rocket(struct bullet *o,struct player *p){

    //This part checks if the rocket is to close to the wall and sets it as no longer active if so
    //It also deletes the rocket
    if (o->shot == 1){
        if (o->x >= 229 || o->y >= 63 || o->y <= 3){

            o->shot=0;
            p->s3=3;
            printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
                   ESC,o->y,o->x,ESC,22,31,255,ESC,1,37,255,255,ESC,1,30,255,
                   ESC,o->y,o->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
                   ESC,o->y-1,o->x-2,ESC,22,31,255,ESC,1,31,255,
                   ESC,o->y+1,o->x-2,ESC,22,31,255,ESC,1,31,255);

        }
    }
}

/**These are the five functions which calls on all other functions for each type of bullets in the game**/
void bullet_player(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3,struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){

    //This is used for normal player bullets checking for all enemies, walls, power ups ect.
    bullet_make_player(o);
    bullet_update(o);
    bullet_small_enemy_hitbox(o,ES2,p);
    bullet_small_enemy_hitbox(o,ES1,p);
    bullet_small_enemy_hitbox(o,ES3,p);
    bullet_small_enemy_hitbox(o,ES4,p);
    bullet_small_enemy_hitbox(o,ES5,p);
    bullet_big_enemy_hitbox(o,EB1,p);
    bullet_big_enemy_hitbox(o,EB2,p);
    bullet_big_enemy_hitbox(o,EB3,p);
    bullet_hit_boss(o,ELON,p);
    bullet_hit_powerup_player(o,bulletplus,p);
    bullet_hit_powerup_player(o,lifeplus,p);
    bullet_hit_powerup_player(o,rocket,p);
    hpcounter(p);
    bullet_check_wall_player(o);
}

void bullet_player_rocket(struct bullet *o3,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){

    //This is used for rockets fired from the player checking for all enemies, walls, power ups ect.
    bullet_delete_rocket(o3);
    bullet_update(o3);
    bullet_make_rocket(o3);
    bullet_hit_rocket(o3,ES2,p);
    bullet_hit_rocket(o3,ES1,p);
    bullet_hit_rocket(o3,ES3,p);
    bullet_hit_rocket(o3,ES4,p);
    bullet_hit_rocket(o3,ES5,p);
    bullet_big_enemy_hitbox(o3,EB1,p);
    bullet_big_enemy_hitbox(o3,EB2,p);
    bullet_big_enemy_hitbox(o3,EB3,p);
    bullet_hit_boss(o3,ELON,p);
    bullet_hit_powerup_player(o3,bulletplus,p);
    bullet_hit_powerup_player(o3,lifeplus,p);
    bullet_hit_powerup_player(o3,rocket,p);
    hpcounter(p);
    bullet_check_wall_rocket(o3,p);
}

void bullet_enemy(struct bullet *b,struct enemy *e,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){
    //This is used for all enemy bullets checking for player, walls, power ups ect.
    bullet_update(b);
    bullet_make_enemy(b);
    bullet_hit_player(b,p,e);
    bullet_check_wall_enemy(b,e);
    bullet_hit_powerup_enemy(b,lifeplus);
    bullet_hit_powerup_enemy(b,bulletplus);
    bullet_hit_powerup_enemy(b,rocket);
    hpcounter(p);
    respawn_player(p);
}

void bullet_player_rocket_up(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){

    //This is used for  player bullets going up checking for all enemies, walls, power ups ect.
    bullet_update(o);
    bullet_make_playerUP(o);
    bullet_small_enemy_hitbox(o,ES2,p);
    bullet_small_enemy_hitbox(o,ES1,p);
    bullet_small_enemy_hitbox(o,ES3,p);
    bullet_small_enemy_hitbox(o,ES4,p);
    bullet_small_enemy_hitbox(o,ES5,p);
    bullet_big_enemy_hitbox(o,EB1,p);
    bullet_big_enemy_hitbox(o,EB2,p);
    bullet_big_enemy_hitbox(o,EB3,p);
    bullet_hit_boss(o,ELON,p);
    bullet_hit_powerup_player(o,bulletplus,p);
    bullet_hit_powerup_player(o,lifeplus,p);
    bullet_hit_powerup_player(o,rocket,p);
    hpcounter(p);
    bullet_check_wall_player(o);


}

void bullet_player_rocket_down(struct bullet *o,struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON,struct player *p,struct powerup *lifeplus,struct powerup *bulletplus,struct powerup *rocket){

    //This is used for  player bullets going down checking for all enemies, walls, power ups ect.
    bullet_update(o);
    bullet_make_playerDOWN(o);
    bullet_small_enemy_hitbox(o,ES2,p);
    bullet_small_enemy_hitbox(o,ES1,p);
    bullet_small_enemy_hitbox(o,ES3,p);
    bullet_small_enemy_hitbox(o,ES4,p);
    bullet_small_enemy_hitbox(o,ES5,p);
    bullet_big_enemy_hitbox(o,EB1,p);
    bullet_big_enemy_hitbox(o,EB2,p);
    bullet_big_enemy_hitbox(o,EB3,p);
    bullet_hit_boss(o,ELON,p);
    bullet_hit_powerup_player(o,bulletplus,p);
    bullet_hit_powerup_player(o,lifeplus,p);
    bullet_hit_powerup_player(o,rocket,p);
    hpcounter(p);
    bullet_check_wall_player(o);
}











