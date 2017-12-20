/***************************************************************************************
 ** Program Filename: Circle6.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle6, function definition file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include <iostream>
#include "Circle6.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Circle6 Space and sets its spaceName and item member
 *               variables to the appropriate strings and its bool to false
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Circle7 Space class
 ****************************************************************************************/
Circle6::Circle6 (){
    //this->item = "wayDown";
    this->spaceName = "Heresy";
    this->climbDown = false;
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Circle6::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
** Function: demons()
** Description: If the player is allowed to descend to the next circle, the function
*               prints out a brief statement about climbing down and  and returns 3.
*               if the player has not yet found the way down and been allowed to continue
*               to the next circle with it's descend bool the function prints a descriptive
*               statement and returns 1.
** Parameters: none
** Pre-Conditions: an instance of Player and of Circle6 exist
** Post-Conditions: returns 1 if the player has not found the item and 3 if the player
*                   found the item and is ready to move on to the next circle
****************************************************************************************/
int Circle6::demons() {
    if (this->player->getDescent(7)) {
        cout << "Finally, that was a tough climb down!\n\n";
        return 3;
    }

    else {
        cout << "This seems like a pretty bad place to spend eternity, just because \n"
             << "they didn't take the word of an outdated guide to life...\n\n";
        return 1;
    }

}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               was killed or false if they are still alive
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Circle6
 ** Post-Conditions: returns true or false and prints a description of the death if true
 ****************************************************************************************/
bool Circle6::damnedSouls() {
    int fallenAngel = (rand() %20) +1;
    
    if (fallenAngel == 10) {
        cout << "Oh no, one of the fallen angels patrolling the city spotted you!\n\n";
        sleep(1);
        cout << "The demon caught you, grilled you, and ate you. He hid your essence \n"
             << "in one of the coffins. Unfortunately, this quest did not end as you \n"
             << "had hoped.\n\n";
        return true;
    }
    return false;
}

/*****************************************************************************************
 ** Function: lookAround()
 ** Description: a void function that prints a description of the player's current Space
 ** Parameters: none
 ** Pre-Conditions: an instance of Player class and an instance of Vestibule
 ** Post-Conditions: prints the description of the Space
 ****************************************************************************************/
void Circle6::lookAround() {
    cout << "According to Dante's Inferno, the only way he got through the gates to \n"
         << "the City of Dis was because an angel flew down to let him in, I guess you \n"
         << "caught a lucky break with Minos.\n\nThis is the 6th circle, where heretics \n"
         << "lie in burning stone coffins. The next circle should be just "
         << "outside \nthe hall.\n\n";

}

/*****************************************************************************************
 ** Function: interact()
 ** Description: if the player has not yet had its descent bool set to true for the 7th 
 *               circle, the function generates a random number, there's a 50 precent 
 *               chance that the player will find a way down (and set the bool to true,
 *               deppending on that number).
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: if the item "appeared" it is added to the item array and the bool
 *                   to continue to the next space is set to true.
 ****************************************************************************************/
void Circle6::interact() {

    if (!this->player->getDescent(7)) {
        int wayDown = (rand() %10) +1;
        
        if (wayDown % 2 == 0) {
            cout << "There's a door over there! It looks like it can lead you "
                 << "down \nto the next circle!\n\n";
            this->canGo = true;
            this->player->setDescent(7);
        }
        else
            cout << "There has to be a way out of this hall and down to the Seventh "
                 << "Circle somewhere, \nDante's Inferno doesn't seem to offer any clues.\n\n";
    }
        
    if (this->player->getDescent(7)) {
        cout << "It shouldn't be much further, the path looks promising.\n\n";
    }
    
        
    
    
}


/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true (note function unused)
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Circle6::contQuest() {
    return;
}


