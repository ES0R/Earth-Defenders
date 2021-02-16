#include "utility.h"
#include "charset.h"
#include "player.h"
#include "lcdmenu.h"
#include <string.h>
#include "stm32f30x_flash.h"

//Prints the help menu. Consisting of the user controls of the player character. A short objective explanation of the game, as well as a short background story for the game.
void help(){

    printf("%c[%d;%dH%c[%d;%dmW to move up%c[%d;%dHA to move left%c[%d;%dHS to move down%c[%d;%dHD to move right%c[%d;%dHSpacebar to shoot%c[%d;%dHJoystick down to launch rocket%c[%d;%dHJoystick up to explode rocket%c[%d;%dHB for boss key%c[%d;%dHDestroy all space shuttles and space stations to invade earth%c[%d;%dHDestroying enemies gives points and progresses the level%c[%d;%dHAvoid enemy bullets or you will lose health, losing 3 kills you!%c[%d;%dHDifferent powerups can spawn throughout the game. Shoot them%c[%d;%dHto gain effects such as, regaining lost health and more bullets.%c[%d;%dHIt has recently come to notice, that the planet earth,%c[%d;%dHhas obtained technology, deemed to be too dangerous for our coexistence.%c[%d;%dHYour mission is to travel to earth and invade them,%c[%d;%dHin hopes of delaying their technological advances.%c[%d;%dHThe richest person on the planet is doing their best at protecting it though,%c[%d;%dHso be ready for a fight against whatever they retaliate with.",
        ESC,5,45,ESC,1,37,
        ESC,7,45,
        ESC,9,45,
        ESC,11,45,
        ESC,13,45,
        ESC,15,45,
        ESC,17,45,
        ESC,19,45,
        ESC,5,80,
        ESC,7,80,
        ESC,9,80,
        ESC,11,80,
        ESC,13,80,
        ESC,5,150,
        ESC,7,150,
        ESC,9,150,
        ESC,11,150,
        ESC,13,150,
        ESC,15,150);
}

//Displays the current top three high scores saved on the flash memory.
void get_high_score (){

    //We default our high score to be saved on the last page of the flash memory.
    uint32_t address = 0x0800F800;
    uint16_t score1;
    uint16_t score2;
    uint16_t score3;
    uint16_t time1;
    uint16_t time2;
    uint16_t time3;
    uint16_t name1;
    uint16_t name2;
    uint16_t name3;

    //We then assign each 16-bit value within the memory to represent a specific part of the high score display.
    //Namely, we are interested in storing a name consisting of two 8-bit char. A Score, and a time.
    //We request these values and use them as temporary constants for our display.
    score1 = *(uint16_t *)(address + 0 * 2);
    score2 = *(uint16_t *)(address + 1 * 2);
    score3 = *(uint16_t *)(address + 2 * 2);
    time1 = *(uint16_t *)(address + 3 * 2);
    time2 = *(uint16_t *)(address + 4 * 2);
    time3 = *(uint16_t *)(address + 5 * 2);
    name1 = *(uint16_t *)(address + 6 * 2);
    name2 = *(uint16_t *)(address + 7 * 2);
    name3 = *(uint16_t *)(address + 8 * 2);
    printf("%c[%d;%dHHigh score",ESC,48,6);
    //We print the three high scores, and split the name into each letter, by reading the last 8 bits of the 16 bit value, as the first letter, and the first 8 as the second letter.
    printf("%c[%d;%dH#1 %c%c %dp in %ds",ESC,50,2,name1>>8,name1,score1,time1);
    printf("%c[%d;%dH#2 %c%c %dp in %ds",ESC,51,2,name2>>8,name2,score2,time2);
    printf("%c[%d;%dH#3 %c%c %dp in %ds",ESC,52,2,name3>>8,name3,score3,time3);
}

//Function to request the user to write a name.
void write_name (struct player *p){

    uint8_t letter;

    //Requests the user to input two letters, as well as not allowing anything else to happen until the user has done it.
    printf("%c[%d;%dHYou got a new high score!%c[%d;%dHEnter your two initials:",ESC,43,87,ESC,45,87);
    while(p->name3 == 0) {
        //Input letters from the keyboard are stored.
        letter=uart_get_char();
        //If no first letter has been given, make next input key between a-w the first letter and display it to the user.
        if (letter >= 97 && letter <= 122 && p->name1 == 0) {
            p->name1 = letter;
            printf(" %c",p->name1);
        }
        //If no second letter has been given, make the next input between a-w the second letter and display it to the user.
        else if (letter >= 97 && letter <= 122 && p->name1 > 0 && p->name2 == 0) {
            p->name2 = letter;
            printf(" %c",p->name2);
        }
        //If both letters has been provided, combine them two a final name consisting of the two letters.
        //This would not be allowed with a 16 bit value shifting around, so was made by OR'ing a shifted value with a none shifted value.
        else if (p->name1 > 0 && p->name2 > 0 ) {
            p->name3 = p->name1 << 8;
            p->name3 |= p->name2;
        }
    }
    //Clearing the buffer, in case invalid input would fill up.
    uart_clear();
}

//Clears the LCD screen.
void clrlcd(){

    //Sets the displayed array variable to filled with nulls. Therefor removing any stored display.
    uint8_t arr[512];
    lcd_init();
    memset(arr,0x00,512);
    lcd_push_buffer(arr);
}

//Lets the joystick input set the menu into different stages. As well as allowing for interaction with the currently selected stage.
void menu_joystick (char j, struct LCD *l){

    //If the joystick input is up, cycle up through the three different menu stages.
    //This also allows the user input not to be blocked if at the top of the screen.
    if (j == 1) {
        if (l->option == 1) {
            l->option = 3;
        }
        else if(l->option == 2) {
            l->option = 1;
        }
        else if(l->option == 3) {
            l->option = 2;
        }
    }
    //If the joystick input is down, cycle down through the three different menu stages.
    //This also allows the user input not to be blocked if at the bottom of the screen.
    else if (j == 2) {
        if (l->option == 1) {
            l->option = 2;
        }
        else if(l->option == 2) {
            l->option = 3;
        }
        else if(l->option == 3) {
            l->option = 1;
        }
    }
    //If the joystick input is center, interact with the current displayed menu option.
    //Play (1) while set the game to a game running value, which will break the menu loop, and initiate the game loop.
    //Help (2) will call the help function to display all possible help to the user.
    //High score (3) will call the get_high_score(); function, and display to the user, the current top 3 high score list.
    else if (j == 16) {
        if (l->option == 1) {
            l->gr = 1;
        }
        else if(l->option == 2) {
            help();
        }
        else if(l->option == 3) {
            get_high_score();
        }
    }
}

//Function, to prevent the user from cycling too fast through the menu, which would be visually confusing.
uint8_t joystick_antispam (char k, struct LCD *l){

    //If input is the different from last input, allow the input to be sent. This means the user has not held onto the direction before.
    if (k != l->ooption) {
        l->ooption = k;
        return(k);
    }
    //When the joystick is moved, it sends a value. We therefor only allow that value to return once, and not again before the user has returned the joystick to rest position.
    else if (k == l->ooption) {
        l->ooption = k;
        return(0);
    }
    //If no joystick input is seen, make sure no joystick input is sent.
    return(0);
}

//Displays the three different menu options for the game.
void menu_disp (struct LCD *l){

    //Each different menu option for the game, is visually represented as selected by the "<" sign being in front of it.
    //We here also define which option state belongs to each visual representation of selected.
    //We get our requested visual on the display through the use of the LCD_write_string function.
    if (l->option == 1 && l->option != l->noption) {
        l->noption = l->option;
        lcd_write_string("EARTH DEFENDERS PLAY<           HELP            HIGH SCORE",0);
    }
    else if (l->option == 2 && l->option != l->noption) {
        l->noption = l->option;
        lcd_write_string("EARTH DEFENDERS PLAY            HELP<           HIGH SCORE",0);
    }
    else if (l->option == 3 && l->option != l->noption) {
        l->noption = l->option;
        lcd_write_string("EARTH DEFENDERS PLAY            HELP            HIGH SCORE<",0);
    }
}

//A reset function for the stored memory. This function, while technically not always needed, is required, in case the user has insufficient values stored on the memory, for which we read and write to.
void reset_high_score(){

    //We default our high score to be saved on the last page of the flash memory.
    uint32_t address = 0x0800F800;

    //The process of changing the memory in the flash can be explained as following.
    //Unlocking the access to direct change of the memory.
    //Clearing the previous address of data.
    //Applying new values to be stored in the data.
    //Locking the data, to not allow additional data to overflow the storage later.
    FLASH_Unlock();
    FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
    FLASH_FLAG_WRPERR );

    FLASH_ErasePage(address);

    FLASH_ProgramHalfWord(address + 0 * 2, 0);
    FLASH_ProgramHalfWord(address + 1 * 2, 0);
    FLASH_ProgramHalfWord(address + 2 * 2, 0);
    FLASH_ProgramHalfWord(address + 3 * 2, 0);
    FLASH_ProgramHalfWord(address + 4 * 2, 0);
    FLASH_ProgramHalfWord(address + 5 * 2, 0);
    //The names, while also requiring a 16-bit value, consist of letters made of 8 bits. Therefor we shift the letters 8 bits to allow two letters to be stored together. Creating the initials.
    FLASH_ProgramHalfWord(address + 6 * 2, 24929); //24929 is 'aa' in binary 16 bit through above mentioned method.
    FLASH_ProgramHalfWord(address + 7 * 2, 24930); //24929 is 'ab' in binary 16 bit through above mentioned method.
    FLASH_ProgramHalfWord(address + 8 * 2, 24931); //24929 is 'ac' in binary 16 bit through above mentioned method.

    FLASH_Lock();
}

//Function to check if the players final score, is better than the previous top scores.
void check_if_high_score (struct player *p){

    //We default our high score to be saved on the last page of the flash memory.
    uint32_t address = 0x0800F800;
    uint16_t score1;
    uint16_t score2;
    uint16_t score3;
    uint16_t time1;
    uint16_t time2;
    uint16_t time3;
    uint16_t name1;
    uint16_t name2;

    //We request the currently stored high scores.
    score1 = *(uint16_t *)(address + 0 * 2);
    score2 = *(uint16_t *)(address + 1 * 2);
    score3 = *(uint16_t *)(address + 2 * 2);
    time1 = *(uint16_t *)(address + 3 * 2);
    time2 = *(uint16_t *)(address + 4 * 2);
    time3 = *(uint16_t *)(address + 5 * 2);
    name1 = *(uint16_t *)(address + 6 * 2);
    name2 = *(uint16_t *)(address + 7 * 2);

    //We then start comparing the players current runs score to the previously stored high scores.
    //If the player is found to have obtained a score or time, allowing them a position on the high score list, then it will input the player in their deserved score.

    //The process of changing the memory in the flash can be explained as following.
    //Unlocking the access to direct change of the memory.
    //Clearing the previous address of data.
    //Applying new values to be stored in the data.
    //Locking the data, to not allow additional data to overflow the storage later.

    //If higher score than first place.
    if (p->score > score1) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);

        //Give the player the first place position values, and push the previous two highest one tier down.
        FLASH_ProgramHalfWord(address + 0 * 2, p->score);
        FLASH_ProgramHalfWord(address + 1 * 2, score1);
        FLASH_ProgramHalfWord(address + 2 * 2, score2);
        FLASH_ProgramHalfWord(address + 3 * 2, p->time);
        FLASH_ProgramHalfWord(address + 4 * 2, time1);
        FLASH_ProgramHalfWord(address + 5 * 2, time2);
        FLASH_ProgramHalfWord(address + 6 * 2, p->name3);
        FLASH_ProgramHalfWord(address + 7 * 2, name1);
        FLASH_ProgramHalfWord(address + 8 * 2, name2);

        FLASH_Lock();

    }
    //If Same score as first place, but done faster.
    else if (p->score == score1 && p->time < time1) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);


        //Give the player the first place position values, and push the previous two highest one tier down.
        FLASH_ProgramHalfWord(address + 0 * 2, p->score);
        FLASH_ProgramHalfWord(address + 1 * 2, score1);
        FLASH_ProgramHalfWord(address + 2 * 2, score2);
        FLASH_ProgramHalfWord(address + 3 * 2, p->time);
        FLASH_ProgramHalfWord(address + 4 * 2, time1);
        FLASH_ProgramHalfWord(address + 5 * 2, time2);
        FLASH_ProgramHalfWord(address + 6 * 2, p->name3);
        FLASH_ProgramHalfWord(address + 7 * 2, name1);
        FLASH_ProgramHalfWord(address + 8 * 2, name2);

        FLASH_Lock();
    }
    //If higher score than second place, but not higher or equal to first.
    else if (p->score > score2) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);

        //Give the player the second place position values, and push the previous second highest one tier down.
        FLASH_ProgramHalfWord(address + 0 * 2, score1);
        FLASH_ProgramHalfWord(address + 1 * 2, p->score);
        FLASH_ProgramHalfWord(address + 2 * 2, score2);
        FLASH_ProgramHalfWord(address + 3 * 2, time1);
        FLASH_ProgramHalfWord(address + 4 * 2, p->time);
        FLASH_ProgramHalfWord(address + 5 * 2, time2);
        FLASH_ProgramHalfWord(address + 6 * 2, name1);
        FLASH_ProgramHalfWord(address + 7 * 2, p->name3);
        FLASH_ProgramHalfWord(address + 8 * 2, name2);

        FLASH_Lock();
    }
    //If high score is equal to second place, but done faster.
    else if (p->score == score2 && p->time < time2) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);

        //Give the player the second place position values, and push the previous second highest one tier down.
        FLASH_ProgramHalfWord(address + 0 * 2, score1);
        FLASH_ProgramHalfWord(address + 1 * 2, p->score);
        FLASH_ProgramHalfWord(address + 2 * 2, score2);
        FLASH_ProgramHalfWord(address + 3 * 2, time1);
        FLASH_ProgramHalfWord(address + 4 * 2, p->time);
        FLASH_ProgramHalfWord(address + 5 * 2, time2);
        FLASH_ProgramHalfWord(address + 6 * 2, name1);
        FLASH_ProgramHalfWord(address + 7 * 2, p->name3);
        FLASH_ProgramHalfWord(address + 8 * 2, name2);

        FLASH_Lock();
    }
    //If high score is higher than third place, but lower than second place.
    else if (p->score > score3) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);

        //Give the player the third place position values.
        FLASH_ProgramHalfWord(address + 0 * 2, score1);
        FLASH_ProgramHalfWord(address + 1 * 2, score2);
        FLASH_ProgramHalfWord(address + 2 * 2, p->score);
        FLASH_ProgramHalfWord(address + 3 * 2, time1);
        FLASH_ProgramHalfWord(address + 4 * 2, time2);
        FLASH_ProgramHalfWord(address + 5 * 2, p->time);
        FLASH_ProgramHalfWord(address + 6 * 2, name1);
        FLASH_ProgramHalfWord(address + 7 * 2, name2);
        FLASH_ProgramHalfWord(address + 8 * 2, p->name3);

        FLASH_Lock();
    }
    //If high score is equal to third place, but done faster.
    else if (p->score == score3 && p->time < time3) {

        //Call the write_name function, so the users initials can be put into the flash.
        write_name(p);

        FLASH_Unlock();
        FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR |
        FLASH_FLAG_WRPERR );
        FLASH_ErasePage(address);

        //Give the player the third place position values.
        FLASH_ProgramHalfWord(address + 0 * 2, score1);
        FLASH_ProgramHalfWord(address + 1 * 2, score2);
        FLASH_ProgramHalfWord(address + 2 * 2, p->score);
        FLASH_ProgramHalfWord(address + 3 * 2, time1);
        FLASH_ProgramHalfWord(address + 4 * 2, time2);
        FLASH_ProgramHalfWord(address + 5 * 2, p->time);
        FLASH_ProgramHalfWord(address + 6 * 2, name1);
        FLASH_ProgramHalfWord(address + 7 * 2, name2);
        FLASH_ProgramHalfWord(address + 8 * 2, p->name3);

        FLASH_Lock();
    }
}

