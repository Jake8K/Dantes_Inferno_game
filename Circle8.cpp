/***************************************************************************************
 ** Program Filename: Circle8.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle8, function definition file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include <iostream>
#include "Circle8.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Circle8 Space and sets its spaceName and item member
 *               variables to the appropriate strings and its counter to 0
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Circle8 Space class
 ****************************************************************************************/
Circle8::Circle8 (){
    this->item = "Torch";
    this->spaceName = "Fraud";
    this->gift2Giant = false;
    this->BolgeCounter = 0;
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Circle8::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
 ** Function: demons()
 ** Description: If the player is allowed to descend to the next circle, Antaeous appears to
 *               the player and helps him along his path to the next circle and returns 3.
 *               if the player hs not yet found the torch and been allowed to continue
 *               to the next circle with it's descend bool the function prints a statement
 *               describing each of the 10 "Bolges" of the Malebolge deppending on a 
 *               random number between 1 and 10 and returns 1.
 ** Parameters: none
 ** Pre-Conditions: an instance of Player and of Circle8 exist
 ** Post-Conditions: returns 1 if the player has not found the torch and 3 if the player
 *                   found the item and is ready to move on to the next circle
 ****************************************************************************************/
int Circle8::demons() {
    if (!this->player->getDescent(9)) {
        int fallenAngel = (rand() %10) +1;
        if (fallenAngel == 1)
            cout << "Pimps and seducers are whipped by demons while marching.\n\n.";
        else if (fallenAngel == 2)
            cout << "Flatterers are immersed in human excrement.\n\n.";
        else if (fallenAngel == 3)
            cout << "Simoniacs are placed in holes head first while their legs \n"
                 << "are exposed and burned.\n\n.";
        else if (fallenAngel == 4)
            cout << "Diviners are contorted until their heads are backwards \n"
                 << "and they cry until they go blind.\n\n.";
        else if (fallenAngel == 5)
            cout << "Corrupt politicians are immersed in pools of boiling pitch.\n\n.";
        else if (fallenAngel == 6)
            cout << "Hypocrites are forced to wear cloaks of lead.\n\n.";
        else if (fallenAngel == 7)
            cout << "Thieves are chased and bitten by reptiles. Poor reptiles...\n\n.";
        else if (fallenAngel == 8)
            cout << "False counselors are wrapped in their own individual \n"
                 << "flaming columns.\n\n.";
        else if (fallenAngel == 9)
            cout << "Schismatics are constantly split from chin to groin \n"
                 << "by sword wielding demons.\n\n.";
        else if (fallenAngel == 10)
            cout << "Falsifiers scratch their itching skin, "
                 << "but gain no comfort,\n only wounds.\n\n.";
        return 1;
    }
    if (this->player->getDescent(9)) {
        cout << "The giant over there is Antaeous .\n He might help.\n\n";
        sleep(1);
        cout << "Antaeous:\nIt is true I helped Dante descend to the lowest pit of \n"
             << "Hell. He and Virgil had a divine decree.  I maybe have done bad \n"
             << "things in life, but I want to be good. I wish there was a way for \n"
             << "me to leave this torment behind. I will help you, but only because \n"
             << "I believe in your quest. I hope you can save that poor girl from this \n"
             << "endless suffering. Be warned mortal, your only hope is to parley with \n"
             << "the Fallen One. He is a trickster, always looking to further his \n"
             << "agenda... even while shackled to the deepest, darkest, \n"
             << "coldest pit in existence.\n\n";
        sleep(1);
        cout << "Climb onto my hand, and I shall lower you to the pit of Hell.\n\n";
        return 3;
        
    }
    else {
        cout << "This is the worst circle of Hell yet... I wonder how much worst \n"
             << "the pit will be\n\n";
        return 1;
    }
}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               was killed or false if they are still alive
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Circle8
 ** Post-Conditions: returns true or false and prints a description of the death if true
 ****************************************************************************************/
bool Circle8::damnedSouls() {
    int fallenAngel = (rand() %20) +1;
    
    if (fallenAngel == 10) {
        cout << "Oh no! A demon torturing people in the Malebolge spotted you!\n\n";
        sleep(1);
        cout << "A demon caught and ate you. You never had a chance.\n\n";
        sleep(1);
        cout << "Hell doesn't have postcards for a reason..\n\n";
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
void Circle8::lookAround() {
    cout << "THis is the Malebolge. The Eight Circle of Hell. This is where those \n"
         << "that committed evil against society suffer unspeakable horrors. Lets \n"
         << "just try and rush through here as quickly as possible. The giants \n"
         << "guarding the pit of Hell lie ahead.\n\n";
}

/*****************************************************************************************
 ** Function: interact()
 ** Description: if the player has not yet acquired this space class's unique item, the
 *               function generates a random number, there's a 50 precent chance that the
 *               item wil appear here (deppending on that number). If the player finds the
 *               the item is added to the player's item array and the player's bool
 *               to descend to the final circle is set to true.
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: if the item "appeared" it is added to the item array and the bool
 *                   to continue to the next space is set to true.
 ****************************************************************************************/
void Circle8::interact() {
    if (this->player->hasItem(this->item))
        cout << "I think that torch will come in handy in the pit of Hell\n\n";
    
    else {
        int present = (rand() %10) +1;
        
        if (present % 2 == 0) {
            cout << "You found a torch. One of the demons must have dropped it.\n";
            sleep(1);
            cout << "Lets turn it off and take it, you can light it when you need it.\n\n";
            this->player->addItem(this->item);
            this->canGo = true;
            this->player->setDescent(9);
        }
        else
            cout << "A cold refreshing soda would be nice.\n";
    }
    
    
}


/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true (note function unused)
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Circle8::contQuest() {
    return;
}
