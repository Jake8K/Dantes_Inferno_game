/***************************************************************************************
 ** Program Filename: Vestibule.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Vestibule, function definiton file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include <iostream>
#include "Vestibule.hpp"
using std::cout;
using std::cin;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Vestibule Space and sets its spaceName and item member
 *               variables to the appropriate strings
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Vestibule Space class
 ****************************************************************************************/
Vestibule::Vestibule (){
    this->item = "Sword";
    this->spaceName = "Vestibule";
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Vestibule::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
 ** Function: demons()
 ** Description: if the player has found the item in the Vestibule class, then Charon will
 *               ferry the player to the 1st circle of Hell.  Charon will also ask
 *               the player for a name to store as the player instance's name.
 *               if Charon appeared the function will return 3 so main can move the player
 *               to circle 1.
 ** Parameters: none
 ** Pre-Conditions: an instance of Player and of Vestibule exist
 ** Post-Conditions: returns 1 if the player has not found the item and 3 if the player 
 *                   found the item and is ready to move on to the next circle
 ****************************************************************************************/
int Vestibule::demons() { //the demon's that help or hinder the quest
    if (player->getDescent(1)) {
        string name;
        cout << "Charon:\n";
        cout << "A living mortal? You damned fool! I will grant you passage on my ferry, \n"
             << "so I may bear witness to the tortures your living flesh endures.\n";
        sleep(1);
        cout << "Through me the way to the City of Woe, through me the way to \n"
             << "everlasting pain.\nNow, I shall ferry you to the fire, the cold, the \n"
             << "everlasting darkness, and the absence of all that is hope.\n\n";
        sleep(1);
        cout << "What is your name, foolish mortal.\n";
        cin >> name;
        this->player->setName(name);
        cout << "Charon:\nWelcome to your worst nightmare, " << name << ".\n"
             << "You will never leave this deep, dark, frigid pit. Now get off my boat \n"
             << "before I make a snack of you!\n\n";
        sleep(2);
        return 3;
        
    }
    else {
        cout << "Charon doesn't seem to be coming yet, hopefully something useful \n"
             << "is lying around here somewhere.\n";
        return 1;
    }
}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               was killed or false if they are still alive
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Vestibule
 ** Post-Conditions: returns true or false (for vestibule it always returns false)
 ****************************************************************************************/
bool Vestibule::damnedSouls() { //this includes demons that eat you and soulds tht swarm
    //none here MAYBE have this return a bool, if true the dude looses
    return false;
}

/*****************************************************************************************
 ** Function: lookAround()
 ** Description: a void function that prints a description of the player's current Space
 ** Parameters: none
 ** Pre-Conditions: an instance of Player class and an instance of Vestibule
 ** Post-Conditions: prints the description of the Space
 ****************************************************************************************/
void Vestibule::lookAround() {
    cout << "According to Dante's Inferno and the map you drew up, you're at the \n"
         << "entrance to Hell. In front is the River Acharon, the River of Woes, \n"
         << "where hopefully Charon will take a silver dollar and ferry you to Limbo.\n";
}

/*****************************************************************************************
 ** Function: interact()
 ** Description: if the player has not yet acquired this space class's unique item, the
 *               function generates a random number, there's a 50 precent chance that the
 *               item wil appear here (deppending on that number). If the player finds the
 *               the item is added to the player's item array and the player's bool 
 *               to descend to the 1st circle is set to true.
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: if the item "appeared" it is added to the item array and the bool
 *                   to continue to the next space is set to true.
 ****************************************************************************************/
void Vestibule::interact() {
    if (this->player->hasItem(this->item))
        cout << "You should really get a move on, you don't want to miss Charon's arrival\n";
    else {
        int present = (rand() %10) +1;
    
        if (present % 2 == 0) {
            cout << "There's a sword leaning against the wall!\n"
                 << "You should definitely take that with you.\n";
            this->player->addItem(this->item);
            cout << "Got it!\n";
            player->setDescent(1);
        }
        else
            cout << "Might as well explore the area while Charon gets here.\n";
    }
    

}

/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Vestibule::contQuest() {
    player->setDescent(1);
}


