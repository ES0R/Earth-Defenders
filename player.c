#include "player.h"
#include "bullet.h"
#include "utility.h"

//Initializes player
void init_player(struct player *p){

    //Gives the player some predetermined initial values, determining its statistics upon startup of the game.
    p->x=35;
    p->y=15;
    p->ox = p->x;
    p->oy = p->y;
    p->im = 1;
    p->score = 0;
    p->oscore = 0;
    p->HP = 3;
    p->s2 = 3;
    p->s3 = 3;
    p->name1=0;
    p->name2=0;
    p->name3=0;
    p->time=0;
}

//Displays player model
void player_make(struct player *p) {
    // Prints our given visual for the player controlled UFO based on it's given coordinates.
    // Also makes sure to not fill the outputs with prints, as it will only update the player based on their input.
    if (p->im > 0 && 5 > p->im){
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            ESC,p->y,p->x,ESC,22,37,255,255,255,220,220,ESC,22,36,220,219,219,219,220,ESC,22,37,220,220,255,255,255,
            ESC,p->y+1,p->x,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
            ESC,p->y+2,p->x,255,255,255,223,223,223,219,219,219,223,223,223,255,255,255);
    }
}

//Removes player model
void player_del(struct player *p) {
    //Prints over the player UFO with empty spaces, visually removing it, based on its old coordinates.
    //Each 'im' number represents a direction state, therefor removing less total characters, per print.
    if (p->im == 1) {
        //Moving up removes only the button part of the ship.
        printf("%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            ESC,p->oy+2,p->ox,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255);
    }
    else if (p->im == 2) {
        //moving down removes only the top part of the ship.
        printf("%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            ESC,p->oy,p->ox,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255);

    }
    else if (p->im == 3) {
        //Moving left removes only the right most characters of the ship.
        printf("%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c",
            ESC,p->oy,p->ox+11,255,ESC,p->oy+1,p->ox+14,255,ESC,p->oy+2,p->ox+11,255);
    }

    else if (p->im == 4) {
        //Moving right removes only the left most characters of the ship.
        printf("%c[%d;%dH%c%c[%d;%dH%c%c[%d;%dH%c",
            ESC,p->oy,p->ox+3,255,ESC,p->oy+1,p->ox,255,ESC,p->oy+2,p->ox+3,255);
    }
}

//Function reads input from player and stores the input in variable "im"
void player_input(struct player *p) {

    int8_t j = 2;
    //Requests the keyboard input through the uart_get_char function, and store the requested input in a variable.
    j = uart_get_char();
    //Reset the current input direction to make sure that the player doesn't keep drifting in the previously picked direction.
    p->im = 0;

    //If a character that isn't 0 (no input) is input, cycle through the 6 different keyboard presses we care about.
    //These 6 different buttons then changes the input mode to a specific value, which other functions can understand.
    //We also make sure to clear the input storage after a requested letter has been received, to not create a buffer zone on the input.
    //The input modes are as following, through the numbers 1-6, Up, Down, Left, Right, Shoot, Boss Key.
    if (j != 0){
        switch(j) {
            case 'w':
                p->im = 1;
                uart_clear();
                break;
            case 's':
                p->im = 2;
                uart_clear();
                break;
            case 'a':
                p->im = 3;
                uart_clear();
                break;
            case 'd':
                p->im = 4;
                uart_clear();
                break;
            case ' ':
                p->im = 5;
                uart_clear();
                break;
            case 'b':
                p->im = 6;
                uart_clear();
                break;
        }
    }
}

//Function uses variable "im" to update player movement and shoot
void player_update(struct player *p,struct bullet *o,struct bullet *o2) {

    //Updates the players action, based on its current input mode.
    //im 1-4 represents the movement based updates on the window, which also defines the players movement limit box.
    //Both new position, as well as old positions are stored, as they are used for the visuals later on.
    //im 5 represents the spaceship deciding to shoot. Which also changes depending on current power-ups.
    if (p->im == 1 && p->y != 3) {
        p->oy = p->y;
        p->ox = p->x;
        p->y -= 1;
    }
    else if (p->im == 2 && p->y != 59) {
        p->oy = p->y;
        p->ox = p->x;
        p->y += 1;
    }
    else if (p->im == 3 && p->x != 26) {
        p->oy = p->y;
        p->ox = p->x;
        p->x -= 1;
    }
    else if (p->im == 4 && p->x != 105) {
        p->oy = p->y;
        p->ox = p->x;
        p->x += 1;
    }
    else if (p->im == 5) {
        if (o->shot == 0){
            o->shot=1;
            o->x=p->x + 15;
            o->y=p->y + 2;
        }
        else if (o2->shot == 0 && p->s2 == 1){
            o2->shot=1;
            o2->x=p->x + 15;
            o2->y=p->y + 2;
        }
    }
}

//Function that display the score
void scoredis(struct player *p) {

    //Updates the score display if the player gains points. To prevent constant printing.
    if (p->score > p->oscore) {
        p->oscore = p->score;
        printf("%c[%d;%dH%c[%d;%dmScore: %d",
            ESC,3,6,ESC,1,37,p->oscore);
    }
    //Sets the score display to zero, if no points has been gained, but also sets itself to not constantly print.
    else if (p->score == 0 && p->oscore == 0) {
        p->oscore +=1;
        printf("%c[%d;%dH%c[%d;%dmScore: 0",
            ESC,3,6,ESC,1,37);
    }
}

//Function displays changes in health
void hpcounter(struct player *p) {

    //If statement representing the different health stages of the player, for which it will print.
    //This includes both taking damage, as well as healing it back up through power-ups.
    //Old HP (oHP) determines what kind of health change it is, based on its relative value compared to HP.
    if (p->HP == 1 && p->oHP == 2) {
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
            ESC,15,12,ESC,1,37,219,219,255,219,219,
            ESC,16,11,219,ESC,2,30,219,219,ESC,1,37,219,ESC,2,30,219,219,ESC,1,37,219,
            ESC,17,11,219,ESC,2,30,219,219,219,219,219,ESC,1,37,219,
            ESC,18,12,219,ESC,2,30,219,219,219,ESC,1,37,219,
            ESC,19,13,219,ESC,2,30,219,ESC,1,37,219,
            ESC,20,14,219);
    }
    else if (p->HP == 2 && p->oHP == 3) {
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
            ESC,22,12,ESC,1,37,219,219,255,219,219,
            ESC,23,11,219,ESC,2,30,219,219,ESC,1,37,219,ESC,2,30,219,219,ESC,1,37,219,
            ESC,24,11,219,ESC,2,30,219,219,219,219,219,ESC,1,37,219,
            ESC,25,12,219,ESC,2,30,219,219,219,ESC,1,37,219,
            ESC,26,13,219,ESC,2,30,219,ESC,1,37,219,
            ESC,27,14,219);
    }
    else if (p->HP == 0 && p->oHP == 1) {
        printf("%c[%d;%dH%c[%d;%dmDEAD",
            ESC,8,6,ESC,1,37);
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
            ESC,8,12,ESC,1,37,219,219,255,219,219,
            ESC,9,11,219,ESC,2,30,219,219,ESC,1,37,219,ESC,2,30,219,219,ESC,1,37,219,
            ESC,10,11,219,ESC,2,30,219,219,219,219,219,ESC,1,37,219,
            ESC,11,12,219,ESC,2,30,219,219,219,ESC,1,37,219,
            ESC,12,13,219,ESC,2,30,219,ESC,1,37,219,
            ESC,13,14,219);
    }
    else if (p->HP == 2 && p->oHP == 1) {
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
            ESC,15,12,ESC,1,37,219,219,255,219,219,
            ESC,16,11,219,ESC,2,31,219,219,ESC,1,37,219,ESC,2,31,219,219,ESC,1,37,219,
            ESC,17,11,219,ESC,2,31,219,219,219,219,219,ESC,1,37,219,
            ESC,18,12,219,ESC,2,31,219,219,219,ESC,1,37,219,
            ESC,19,13,219,ESC,2,31,219,ESC,1,37,219,
            ESC,20,14,219);
    }
    else if (p->HP == 3 && p->oHP == 2) {
        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c%c%c[%d;%dm%c%c[%d;%dH%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c",
            ESC,22,12,ESC,1,37,219,219,255,219,219,
            ESC,23,11,219,ESC,2,31,219,219,ESC,1,37,219,ESC,2,31,219,219,ESC,1,37,219,
            ESC,24,11,219,ESC,2,31,219,219,219,219,219,ESC,1,37,219,
            ESC,25,12,219,ESC,2,31,219,219,219,ESC,1,37,219,
            ESC,26,13,219,ESC,2,31,219,ESC,1,37,219,
            ESC,27,14,219);
    }
}

//Function that places player in upper left corner when losing HP
void respawn_player(struct player *p){

    //If statement that checks for changes in players health, used in combination with taking damage, to move the player to the top left of the screen, effectively "respawning".
    //Also removes the previous player model, to not have duplicate players.
    if (p->oHP !=p->HP){
        printf("%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            ESC,p->oy,p->ox,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            ESC,p->oy+1,p->ox,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            ESC,p->oy+2,p->ox,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255);

        printf("%c[%d;%dH%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c%c%c%c%c[%d;%dm%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c[%d;%dH%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            ESC,p->y,p->x,ESC,22,37,255,255,255,220,220,ESC,22,36,220,219,219,219,220,ESC,22,37,220,220,255,255,255,
            ESC,p->y+1,p->x,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
            ESC,p->y+2,p->x,255,255,255,223,223,223,219,219,219,223,223,223,255,255,255);
    }
}

//Function reads input from joystick and shoots and detonates the rocket
void player_joystick(struct bullet *o3,struct bullet *o4,struct bullet *o5,struct player *p){

    uint8_t j;
    //Requests a value from which direction the joystick moved.
    j = readJoystick();

    //If the player got the rocket power-up, allow the player to shoot it, by moving the joystick down.
    if (j==2 && o3->shot==0 && o4->shot==0 && o5->shot==0 && p->s3==1){
        o3->shot=1;
        o3->x=p->x + 17;
        o3->y=p->y + 2;
    }
    //If the player has shot the rocket power-up, allow them to explode it, by moving the joystick up.
    else if (j==1 && o3->shot==1){
        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c%c[%d;%dm%c",
            ESC,o3->y,o3->x,ESC,22,31,255,ESC,1,37,255,255,ESC,1,30,255);

        printf("%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c%c[%d;%dH%c[%d;%dm%c%c[%d;%dm%c",
            ESC,o3->y,o3->x-3,ESC,22,31,255,ESC,1,31,255,ESC,1,33,255,
            ESC,o3->y-1,o3->x-2,ESC,22,31,255,ESC,1,31,255,
            ESC,o3->y+1,o3->x-2,ESC,22,31,255,ESC,1,31,255);

        o3->shot=0;
        p->s3=3;

        o4->shot=1;
        o4->x=o3->x;
        o4->y=o3->y;

        o5->shot=1;
        o5->x=o3->x;
        o5->y=o3->y;

        o3->x = p->x + 17;
        o3->y = p->y + 2;
    }
}
