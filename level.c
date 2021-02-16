#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "player.h"
#include "level.h"
#include "enemy.h"

//Returns the sum of all enemy HP
int sum_HP(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON){

    return ES1->HP + ES2->HP + ES3->HP + ES4->HP + ES5->HP + EB1->HP + EB2->HP + EB3->HP + ELON->HP;
}

//Updates level with +1 if all enemies are dead. Level 11 is victory screen.
int level_up(struct enemy *ES1,struct enemy *ES2,struct enemy *ES3, struct enemy *ES4, struct enemy *ES5, struct enemy *EB1, struct enemy *EB2, struct enemy *EB3, struct enemy *ELON, int level, int *level_flag){

    if (sum_HP(ES1,ES2,ES3,ES4,ES5,EB1,EB2,EB3,ELON) == -9 && level <= 10){
        level += 1;
        *level_flag = 0;
        return level;
    }
    else if(level == 11){
        *level_flag = 1;
    }
    return level;
}

//Returns an array with random lanes for enemies. This makes enemies spawn "randomly"
int * lanes(struct player *p, int ships){

    int i,j,max_enemy, pos;
    max_enemy = 5;

    int numbers[5];

    //Creates an array where the element is equal to the position
    for (i = 0; i <= max_enemy; i++)
    {
        numbers[i] = i;
    }

    static int random_lanes[5];

    for (j = 0; j < ships; j++)
    {
        //Chooses a random number between 0 and max_enemy
        //This number refers the possible spawning points for the enemy
        //As max_enemy = 5, there are 5 'lanes' where the enemy can spawn
        pos = rng(p, max_enemy);

        //The random_lane variable stores the randomly chosen lane in an array
        random_lanes[j] = numbers[pos];

        //This for loop deletes the element which contained the lane
        //This make it so enemies can't spawn at the same lane
        for (i = pos; i < max_enemy - 1; i++)
        {
            numbers[i] = numbers[i + 1];
        }

        max_enemy--;
    }
    return random_lanes;
}

//Returns a "random value" with a maximum
int rng(struct player *p, int maxium){
    //Using player information, the seed should never be the same thus more random.
    srand(p->x+p->y+p->oy-p->ox+p->score);
    return rand() % maxium;
}
