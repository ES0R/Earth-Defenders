#include "time.h"
#include "utility.h"

//Initializes timer number 2
void init_timer2() {

    //With the chosen reload value and prescale value this timer is set to interrupt the interrupt-handler every 100 of a second
    RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
    TIM2->ARR = 6138; // Set reload value
    TIM2->PSC = 100; // Set prescale value
    TIM2->CR1=0;

    TIM2->CR1 |= (0x0000 << (11));  //UIREMAP
    TIM2->CR1 |= (0x0000 << (8));   //CKD
    TIM2->CR1 |= (0x0000 << (9));   //CKD
    TIM2->CR1 |= (0x0000 << (7));   //ARPE
    TIM2->CR1 |= (0x0000 << (5));   //CMS
    TIM2->CR1 |= (0x0000 << (6));   //CMS
    TIM2->CR1 |= (0x0000 << (4));   //DIR
    TIM2->CR1 |= (0x0000 << (3));   //OPM
    TIM2->CR1 |= (0x0000 << (2));   //URS
    TIM2->CR1 |= (0x0000 << (1));   //UDIS
    TIM2->CR1 |= (0x0001 << (0));   //COUNTER ENABLE
    TIM2->DIER |= 0x0001;

    NVIC_SetPriority(TIM2_IRQn, 1); //Set interrupt priority
    NVIC_EnableIRQ(TIM2_IRQn); //Enable interrupt
}

//Time iteration and time flags
void TIM2_IRQHandler(void) {

    //Creating an individual timer for every component updating independently
    T_player.hs+=1;
    T_bullet.hs+=1;
    T_enemy.hs+=1;
    T_enemybullet.hs+=1;
    T_score.hs+=1;
    T_asteroid.hs+=1;
    T_time.hs+=1;
    T.hs+=1;
    T1.hs+=1;

    if (T_player.hs == 2){
        T_player.hs=0;
        T_player.flag = 1;
    }

    if (T_bullet.hs == 2){
        T_bullet.hs=0;
        T_bullet.flag = 1;
    }

    if (T_score.hs == 50){
        T_score.hs=0;
        T_score.flag = 1;
    }

    if (T_time.hs == 100){
        T_time.hs=0;
        T_time.flag += 1;
    }

    if (T_level.s == 5){
        T_level.s=0;
        T_level.flag = 0;
    }

    if (T_asteroid.s >=5){

        if (T_asteroid.hs == 20){
            T_asteroid.hs=0;
            T_asteroid.flag = 1;
        }
    }

    if (T_asteroid.s == 20){
        T_asteroid.s=0;
    }


    if (T_enemy.hs == 4){
        T_enemy.hs=0;
        T_enemy.flag = 1;
    }

    if (T_enemybullet.hs == 1){
        T_enemybullet.hs=0;
        T_enemybullet.flag = 1;
    }

    //Game running clock. Keeps track of time since game start.
    if (T.hs >= 99){
        T.s+=1;
        T.hs=0;
        T_asteroid.s+=1;
        T_powerup.s+=1;
        if (T_level.flag == 1){
            T_level.s+=1;
        }
    }

    if (T.s >= 59){
        T.m+=1;
        T.s=0;
    }

    if (T.m >= 59){
        T.h+=1;
        T.m=0;
    }

    TIM2->SR &= ~0x0001; //Clear interrupt bit
 }

//Initializes times to 0
void init_timepoint() {

    T1.h = 0;
    T1.m = 0;
    T1.s = 0;
    T1.hs = 0;

    T_time.flag=0;
    T_time.hs=0;


    T_player.hs=0;
    T_bullet.hs=0;
    T_enemy.hs=0;
    T_enemybullet.hs=0;
    T_score.hs=0;
    T_asteroid.hs=0;
    T_time.hs=0;

    T.h = 0;
    T.m = 0;
    T.s = 0;
    T.hs = 0;
}



