/***************************************************************************************
 ** Program Filename: Circle1.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle1, function definition file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/
#include <iostream>
#include "Circle1.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Circle1 Space and sets its spaceName and item member
 *               variables to the appropriate strings and its bool to false
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Circle1 Space class
 ****************************************************************************************/
Circle1::Circle1 (){
    this->item = "Gold";
    this->spaceName = "Limbo";
    this->Minos = false;
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Circle1::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
 ** Function: demons()
 ** Description: If the player is allowed to descend to the next circle, Minos appears to 
 *               the player and helps him along his path to the next circle and returns 3.
 *               If the player has already met Minos, Minos yells at the player to move on.
 *               if the player hs not yet found the item and been allowed to continue 
 *               to the next circle with it's descend bool the function prints a vague
 *               statement and returns 1.
 ** Parameters: none
 ** Pre-Conditions: an instance of Player and of Circle1 exist
 ** Post-Conditions: returns 1 if the player has not found the item and 3 if the player
 *                   found the item and is ready to move on to the next circle
 ****************************************************************************************/
int Circle1::demons() {
    if (player->getDescent(6) && !Minos) { 
        cout << "Minos is just up ahead...\n\n";
        sleep(2);
        cout << "Minos:\n";
        cout << "Well hello, " << this->player->getName() << ", it's a pleasure to make "
             << "your acquaintance. I've been expecting your arrival.\n";
        sleep(2);
        cout << "I sympathize with your plight, if you can find my lucky coin somewhere "
             << "on this mountain, I will grant you passage. Otherwise, I will feed you "
             << "to the Minotaur.\n\n";
        sleep(2);
        cout << "Minos:\n";
        cout << "Oh, you found my coin?.\nI am glad to see it again. It reminds me "
             << "of when I was the king of Crete. I am feeling charitable, I can help "
             << "you get as far as the Wall of the city of Dis, in the 6th circle.\n\n";
        this->Minos = true;
        return 3;
    }
    if (player->getDescent(6) && Minos) {
        cout << "Minos:\n";
        cout << "Do not linger here mortal, I offered you passage to Dis. If you do not "
             << "take it you will suffer the wrath of Hades until the end of time.\n\n";
        return 3;
    }
    else {
        cout << "Limbo doesn't seem so awful, I wish there was time to meet some of "
             << "the great minds that reside here. Anyways, Minos judges the damned "
             << "from up there on that hill somewhere. That is the only way to get to "
             << "the second circle of Hell.\n\n";
        return 1;
    }
}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               was killed or false if they are still alive for most circles.
 *               Here it just prints a description of Limbo (since nothing kills here).
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Circle1
 ** Post-Conditions: returns true or false (for Limbo it always returns false)
 ****************************************************************************************/
bool Circle1::damnedSouls() {
    cout << "That's amazing, in that hall over there are the people that made history, "
         << "for better or worse, the world wouldn't be what it is without them... "
         << "God's a pretty messed up guy...\n\n";
    return false;
}

/*****************************************************************************************
 ** Function: lookAround()
 ** Description: a void function that prints a description of the player's current Space
 ** Parameters: none
 ** Pre-Conditions: an instance of Player class and an instance of Vestibule
 ** Post-Conditions: prints the description of the Space
 ****************************************************************************************/
void Circle1::lookAround() {
    cout << "According to Dante's Inferno and your trusty map, this is Limbo. "
         << "The first circle of Hell. Everyone that was anyone in the dawn of "
         << "civilization is here. There's a hall somewhere that houses all the virtuous "
         << "\"Pagans.\" Up there on that hill somewhere King Minos judges the poor "
         << "souls destined for Hell. You must find him and appeal to any semblance "
         << "of humanity that he has left so he can ease your journey into the next "
         << "circle.\n\n";
}

/*****************************************************************************************
 ** Function: interact()
 ** Description: if the player has not yet acquired this space class's unique item, the
 *               function generates a random number, there's a 50 precent chance that the
 *               item wil appear here (deppending on that number). If the player finds the
 *               the item is added to the player's item array and the player's bool
 *               to descend to the 6th circle is set to true.
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: if the item "appeared" it is added to the item array and the bool
 *                   to continue to the next space is set to true.
 ****************************************************************************************/
void Circle1::interact() {
    if (this->player->hasItem(this->item))
        cout << "Judging by the screams and moans, it seems like we're getting "
             << "close to Minos.\n\n";
    else {
        int present = (rand() %10) +1;
        
        if (present % 2 == 0) {
            cout << "There's a gold coin lying on the dirt!\n\n";
            sleep(1);
            cout << "It looks ancient, it'll make a weird souvenir if you make it out.\n\n";
            this->player->addItem(this->item);
            this->canGo = true;
            this->player->setDescent(6);
        }
        else
            cout << "This has to be the worst hike ever.\n\n";
    }

    
}

/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true (note function unused)
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Circle1::contQuest() {
    return;
}


