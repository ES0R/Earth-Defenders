#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "utility.h"
#include "level.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "world.h"
#include "lcdmenu.h"
#include "time.h"
#include <stdio.h>

int main(void) {

    uart_init(115200); // Initialize USB serial at 115200 baud
    reset_high_score();   /*****Only use if high score in hardware kit needs to be reset. Explained in user manual. On by default*****/

    clrscr();

    //Initialize LCD struct l
    struct LCD l;
    l.option = 1;
    l.noption = 0;
    l.gr = 0;

    clrlcd();

    /*****Menu on LCD. Game will not start until you have chosen play*****/
    menu:
    while(1){
        menu_joystick(joystick_antispam(readJoystick(),&l),&l);
        menu_disp(&l); //LCD Menu
        if (l.gr == 1) {
            break;
        }
    }

    //Initializing timers
    init_timer2();
    init_timepoint();

    //Declaring variables
    uint8_t val = 1;
    int8_t diff_counter = 0;
    int8_t enemy_speed_counter = 0;
    int8_t bullet_increase = 0;
    int8_t level = 1;
    int level_flag = 0;
    int8_t ES_movement = 8;
    int8_t EB_movement = 4;
    int8_t ELON_movement = 40;
    uint8_t enemy_small;
    uint8_t enemy_big;
    uint8_t number_of_enemies;
    int *random_lanes;

    //Declaring structs
    struct player p;
    struct enemy ES1;
    struct enemy ES2;
    struct enemy ES3;
    struct enemy ES4;
    struct enemy ES5;
    struct enemy EB1;
    struct enemy EB2;
    struct enemy EB3;
    struct enemy ELON;
    struct bullet o;
    struct bullet o2;
    struct bullet o3;
    struct bullet o4;
    struct bullet o5;
    struct bullet b1;
    struct bullet b2;
    struct bullet b3;
    struct bullet b4;
    struct bullet b5;
    struct bullet b6;
    struct bullet b7;
    struct bullet b8;
    struct bullet b9;
    struct bullet b10;
    struct bullet b11;
    struct bullet b12;
    struct bullet b13;
    struct bullet b14;
    struct powerup lifeplus;
    struct powerup bulletplus;
    struct powerup rocket;
    struct asteroid c1;

    //Initializing game elements
    init_player(&p);
    init_bullet(&o,&o2,&o3,&o4,&o5,&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8,&b9,&b10,&b11,&b12,&b13,&b14);
    init_powerup(&lifeplus,&bulletplus,&rocket);
    init_asteroid(&c1);
    init_enemy(&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON);

    //Boss key return position
    start:
        game_window();
        if (level >= 6){
            earth_window();
        }
        player_make(&p);

    /*****Game loop*****/
    while(1){

        //Turn off LED
        setLed(0);

        //Level system. Here you can choose the # of small and big enemies.
        //It should be noted that there can be 5 enemies total on 1 level at any given time
        //Furthermore, there are 5 small enemies are 3 big ones. These values cannot be exceeded
        if (level == 1 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 1;
            enemy_big = 0;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 2 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 2;
            enemy_big = 0;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);


            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 3 && level_flag == 0){
            /*****Number of enemies*****/
            enemy_small = 3;
            enemy_big = 0;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 4 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 4;
            enemy_big = 0;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 5 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 5;
            enemy_big = 0;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 6 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 1;
            enemy_big = 1;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            /*****World*****/
            earth_window();

            bullet_increase = -1;

            level_flag = 1;
        }

        else if(level == 7 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 2;
            enemy_big = 1;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 8 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 3;
            enemy_big = 1;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 9 && level_flag == 0){

            /*****Number of enemies*****/
            enemy_small = 4;
            enemy_big = 1;
            number_of_enemies = enemy_small + enemy_big;

            /*****Random lane*****/
            random_lanes = lanes(&p,number_of_enemies);

            /*****Enemy initializer*****/
            init_all_enemy_small(&ES1,&ES2,&ES3,&ES4,&ES5,enemy_small,random_lanes,number_of_enemies);
            init_all_enemy_big(&EB1,&EB2,&EB3,enemy_big,random_lanes,number_of_enemies);

            level_flag = 1;
        }

        else if(level == 10 && level_flag == 0){

            init_enemy_ELON(&ELON); //Final level is different as it only has the final boss and does not need random spawning position

            level_flag = 1;
        }

        else if(level == 11 && level_flag == 0){

            //Level 11 is the victory screen after killing the final boss
            level_flag = 1;
            clrscr();
            game_won();
            p.time=T_time.flag;
            T_time.flag = 0;
            while(T_time.flag < 2){} //Waits 2 seconds before checking if there is a high score, to stop from accidentally clicking player movement keys
            check_if_high_score(&p);
            l.gr=0;
            goto menu;
        }

        level = level_up(&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,level,&level_flag); //Increments the level, if it is complete

        /*****Player interaction*****/
        if (T_player.flag == 1){
            player_input(&p);
            player_joystick(&o3,&o4,&o5,&p);
            player_update(&p,&o,&o2);
            player_del(&p);
            player_make(&p);
            T_player.flag = 0;
        }

        //Boss key section
        if (p.im == 6){
            //Player stuck in while loop until 'b' key is pressed again. Effectively pausing the game
            while(1){
                clrscr();
                player_input(&p);
                if (p.im == 6){
                    break;
                }
            }
            p.im = 1;
            p.oscore = 0;
            goto start;
        }

        //Player loses all their health = Game over
        if (p.HP == 0) {
            game_over();
            p.time=T_time.flag;
            T_time.flag = 0;
            while(T_time.flag < 2){} //Waits 2 seconds before checking if there is a high score, to stop from accidentally clicking player movement keys
            check_if_high_score(&p);
            l.gr = 0;
            goto menu;
        }

        //Checks if score is different and updates if so
        if (T_score.flag == 1){
            scoredis(&p);
            T_score.flag = 0;
        }

        /*****Player bullets*****/
        if (T_bullet.flag == 1){

            bullet_player(&o,&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,&p,&lifeplus,&bulletplus,&rocket);

            bullet_player(&o2,&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,&p,&lifeplus,&bulletplus,&rocket);

            bullet_player_rocket(&o3,&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,&p,&lifeplus,&bulletplus,&rocket);

            bullet_player_rocket_up(&o4,&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,&p,&lifeplus,&bulletplus,&rocket);

            bullet_player_rocket_down(&o5,&ES1,&ES2,&ES3,&ES4,&ES5,&EB1,&EB2,&EB3,&ELON,&p,&lifeplus,&bulletplus,&rocket);

            T_bullet.flag = 0;
        }

        /*****Enemy AI*****/
        if (T_enemy.flag == 1){

            diff_counter += 1;

            //Game increasing update speed with level. Enemy movement becomes faster with level progression
            if (diff_counter >= 25-level){

                /*****Small enemy movement & bullet activate*****/
                //Checks if enemy has health and is initialized
                //If so the enemy can move and be displayed properly
                //As well as being able to shoot
                if ((ES1.HP > 0) && (ES1.init == 1)){
                    enemy_dead(&ES1);
                    ES1.index = enemy_update(&ES1,val,ES_movement);
                    display_enemy(&ES1);
                    b1.shot = 1;
                }
                if ((ES2.HP > 0) && (ES2.init == 1)){
                    enemy_dead(&ES2);
                    ES2.index = enemy_update(&ES2,val,ES_movement);
                    display_enemy(&ES2);
                    b2.shot = 1;
                }
                if ((ES3.HP > 0) && (ES3.init == 1)){
                    enemy_dead(&ES3);
                    ES3.index = enemy_update(&ES3,val,ES_movement);
                    display_enemy(&ES3);
                    b3.shot = 1;
                }
                if ((ES4.HP > 0) && (ES4.init == 1)){
                    enemy_dead(&ES4);
                    ES4.index = enemy_update(&ES4,val,ES_movement);
                    display_enemy(&ES4);
                    b6.shot = 1;
                }
                if ((ES5.HP > 0) && (ES5.init == 1)){
                    enemy_dead(&ES5);
                    ES5.index = enemy_update(&ES5,val,ES_movement);
                    display_enemy(&ES5);
                    b14.shot = 1;
                }

                /*****Big enemy movement & bullet activate*****/
                if ((EB1.HP > 0) && (EB1.init == 1)){
                    enemy_dead_big(&EB1);
                    EB1.index = enemy_update(&EB1,val,EB_movement);
                    display_big_enemy(&EB1);
                    b4.shot = 1;
                    b5.shot = 1;
                }

                if ((EB2.HP > 0) && (EB2.init == 1)){
                    enemy_dead_big(&EB2);
                    EB2.index = enemy_update(&EB2,val,EB_movement);
                    display_big_enemy(&EB2);
                    b7.shot = 1;
                    b8.shot = 1;
                }

                if ((EB3.HP > 0) && (EB3.init == 1)){
                    enemy_dead_big(&EB3);
                    EB3.index = enemy_update(&EB3,val,EB_movement);
                    display_big_enemy(&EB3);
                    b9.shot = 1;
                    b10.shot = 1;
                }

                /*****Boss movement & bullet activate*****/
                if ((ELON.HP > 0) && (ELON.init == 1)){
                    enemy_dead_ELON(&ELON);
                    ELON.index = enemy_update(&ELON,val,ELON_movement);
                    display_ELON(&ELON);
                    b11.shot = 1;
                    b12.shot = 1;
                    b13.shot = 1;
                }

                /*****Small enemy death*****/
                if (ES1.HP == 0){
                    ES1.HP=-1;
                    enemy_dead(&ES1);
                }

                if (ES2.HP == 0){
                    ES2.HP=-1;
                    enemy_dead(&ES2);
                }

                if (ES3.HP == 0){
                    ES3.HP = -1;
                    enemy_dead(&ES3);
                }

                if (ES4.HP == 0){
                    ES4.HP = -1;
                    enemy_dead(&ES4);
                }

                if (ES5.HP == 0){
                    ES5.HP = -1;
                    enemy_dead(&ES5);
                }

                /*****Big enemy death*****/
                if (EB1.HP == 0){
                    EB1.HP = -1;
                    enemy_dead_big(&EB1);
                }

                if (EB2.HP == 0){
                    EB2.HP = -1;
                    enemy_dead_big(&EB2);
                }

                if (EB2.HP == 0){
                    EB2.HP = -1;
                    enemy_dead_big(&EB2);
                }

                /*****Boss death*****/
                if (ELON.HP == 0){
                    ELON.HP = -1;
                    enemy_dead_ELON(&ELON);
                }
                diff_counter = 0;
            }
            T_enemy.flag = 0;
        }

        /*****Enemy bullets*****/
        if (T_enemybullet.flag == 1){

            enemy_speed_counter += 1;

            //Enemy bullet update speed is increased when player reaches level 6. Increasing difficulty with level progression.
            if (enemy_speed_counter >= 4 - bullet_increase){

                bullet_enemy(&b1,&ES1,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b2,&ES2,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b3,&ES3,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b4,&EB1,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b5,&EB1,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b6,&ES4,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b7,&EB2,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b8,&EB2,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b9,&EB3,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b10,&EB3,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b11,&ELON,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b12,&ELON,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b13,&ELON,&p,&lifeplus,&bulletplus,&rocket);

                bullet_enemy(&b14,&ES5,&p,&lifeplus,&bulletplus,&rocket);

                enemy_speed_counter = 0;
            }
            T_enemybullet.flag = 0;
        }

        /*****Power ups*****/
        if (T_powerup.s == 30){
            powerup_activate(&rocket,&p);
            disp_powerup(&rocket);
            T_powerup.s+=1;
        }

        if (T_powerup.s == 60){
            powerup_activate(&lifeplus,&p);
            disp_powerup(&lifeplus);
            T_powerup.s=0;
        }

        if (T.s == 10 && T.m == 1){
            powerup_activate(&bulletplus,&p);
            disp_powerup(&bulletplus);

        }

        /*****Asteroid****/
        if (T_asteroid.s== 5){

            reset_asteroid(&c1,&p);
        }

        if (T_asteroid.flag == 1){
            asteroid_del(&c1);
            asteroid_update(&c1);
            asteroid_make(&c1);
            asteroid_check_wall(&c1);
            asteroid_hit_player(&c1,&p);
            respawn_player(&p);
            T_asteroid.flag =0;
        }
    }

    while(1){}
}

