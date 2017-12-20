/***************************************************************************************
 ** Program Filename: Circle7.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle7, function definition file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include <iostream>
#include "Circle7.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Circle7 Space and sets its spaceName and item member
 *               variables to the appropriate strings, its bool to false, and input to 
 *               NULL for when the player fights the Minotaur
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Circle7 Space class
 ****************************************************************************************/
Circle7::Circle7 (){
    this->item = "Rope";
    this->spaceName = "Violence";
    this->killMinotaur = false;
    this->input = ' ';
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Circle7::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
 ** Function: demons()
 ** Description: first if the player has just arrived at this class, they must first fight
 *               the minotaur by hitting the right key. Once they kill the minotaur, the
 *               player's kill minotaur bool is set to true and Nessus takes the player
 *               past the Phlagathon.
 *               Once the Minotaur has been slain,the function returns a description of
 *               "section of the circle" currently occupied by the player deppending on the
 *               player's circleCounter value. at the 3rd "space" of the circle, the player
 *               finds the rope they need to descend to the next circle.
 *               Once the player has made it through at least 13 steps in this circle of
 *               Hell, the player is allowed to continue to the next circle.
 ** Parameters: none
 ** Pre-Conditions: an instance of Player and of Circle7 exist
 ** Post-Conditions: returns 1 if the player has not found the item and 3 if the player
 *                   has made it through the desert with the rope (found in the 
 *                   woods of suicides) and is ready to move on to the next circle
 ****************************************************************************************/
int Circle7::demons() {
    
    if (!this->player->getDescent(18)) { //fight the minotaur first
        cout << "Oh no! The Minotaur is right there, and it seems like he spotted you.\n\n";
        sleep(2);
        cout << "Minotaur:\n Ah some fun! \nI haven't tasted living flesh since my \n"
             << "days in the labyrinth of Crete. I always did enjoy toying with \n"
             << "my meals...\n";
        cout << "[enter any character to continue]\n\n";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        cout << "It's a good thing you found that sword earlier! Good luck.\n\n";
        cout << "[enter any character to fight for your life]\n\n";
        
        while (!killMinotaur) {
            std::cin >> input;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            int killedIt = (rand() %10) +1;
            if (killedIt == 5) {
                cout << "You got him! You've won the battle "
                     << "against the tyranical Minotaur!";
                killMinotaur = true;
            }
            else {
                cout << "He's rearing up for another charge, get your sword ready!\n\n";
            }
                
        }
        sleep(1);
        cout << "Fantastic, there's something charging at you from a distance...\n";
        sleep(3);
        cout << "Oh no, the sword is stuck in the carcass of the minotaur!\n";
        sleep(2);
        cout << "It looks like a centaur, but she doesn't seem angry...\n\n";
        cout << "Centaur:\nI am Nessus. Thank you for vanquishing that dreadful beast. \n"
             << "His incessant attempts to mount me amounted to an exhausting, \n"
             << "unnecessary,  unending, and unyielding eternal labor.\n\n";
        cout << "Nessus:\nWhat purpose have you? What brings you to the \n"
             << "infernal depths of the Earth?\n\n";
        sleep(2);
        cout << "Nessus:\nThat is quite the gesture " << this->player->getName()
             << ". I shall help you along your journey as a token of my gratitude. \n"
             << "Climb onto my back, I will take you past the Phlagathon. I can't \n"
             << "take you any further though.\n";
        sleep(2);
        cout << "The wrathful sinners are forced to swim in that river of boiling blood. \n"
             << "What a terrible fate.\n\n";
        cout << "Nessus:\n Farewell friend, good luck on your quest. This is the edge \n"
             << "of the Wodds of Suicides, past it is the Plains of Fire. I've heard \n"
             << "stories of the horrors beyond, but have been fortunate not to bear \n"
             << "witness.\nI hope we never meet again.\n\n";
        this->player->setDescent(18);
        return 1;
    }
    
    else {
        circleCounter = this->player->getCounter(); // 0 - 5 is suicide, >5 is the desert
        this->player->incrementCounter();
        
        
        //if you're in the suicide woods, you can't get down yet
        if(circleCounter < 5) {
            cout << "This is the Woods of Suicides, where the poor unhappy people \n"
                 << "that took their lives to escape their hell above were transformed \n"
                 << "into thorny trees that are constantly ripped appart by Harpies. \n"
                 << "Your girlfriend is one of these trees.\n\n";
            if (circleCounter == 3)
                cout << "There's a noose on that tree. That's really morbid. You \n"
                     << "should take that rope though, it's a lot of rope, it can \n"
                     << "come in handy.\n\n";
            this->player->addItem(this->item);
            return 1;
        }
        
        if(circleCounter > 5 && circleCounter < 12) {
            cout << "The Plains of Fire seem to go on forever...\n\n";
            return 1;
        }
        if (circleCounter >= 13) {
            cout << "Finally, there's the edge of this miserable desert. I guess \n"
                 << "Dante had Geryon help him down, but I don't see any monstruous \n"
                 << "giants lurking about...\nIt's a good thing we found that rope. \n\n"
                 << "Lets climb down to the Malebolge. I wish it was safe to blindfold \n"
                 << "yourself, because this is where hell is especially horrifying.\n\n";
            this->player->setDescent(8);
            return 3;
            
        }

        else {
            return 1;
        }
    }
}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               was killed or false if they are still alive
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Circle7
 ** Post-Conditions: returns true or false and prints a description of the death if true
 ****************************************************************************************/
bool Circle7::damnedSouls() {
    int fallenAngel = (rand() %20) +1;

    if (!this->player->getDescent(18)) {
        cout << "This is getting pretty hairy\n\n";
        return false;
    }
    if(circleCounter < 5 && fallenAngel == 10) {
        cout << "The Harpies found you and made a meal out of you. You are now a \n"
             << "carcass hanging from a thorny tree in the Woods of Suicides. In a \n"
             << "way, you're going to spend eternity with your lover...\n\n";
        return true;
    }
    if(circleCounter > 5 && fallenAngel == 10) {
        cout << "The dead of the Plain of Fire swarmed you. Apparently your carcass \n"
             << "affords them some protection from their eternal torment of burning \n"
             << "sand and rain of fire\n\n";
        return true;
    }
    
    else
        return false;

}

/*****************************************************************************************
 ** Function: lookAround()
 ** Description: a void function that prints a description of the player's current Space
 ** Parameters: none
 ** Pre-Conditions: an instance of Player class and an instance of Vestibule
 ** Post-Conditions: prints the description of the Space
 ****************************************************************************************/
void Circle7::lookAround() {
    circleCounter = this->player->getCounter();
    
    if (!this->player->getDescent(18))
        cout << "You made it down to the 7th circle. Ahead lies the Phlagathon, the \n"
             << "river of fire and boiling blood. I don't know how you're going to make \n"
             << "it past it. The wrathful are punished with an eternity in this river.\n\n";
    
    if(circleCounter < 5 && this->player->getDescent(18))
        cout << "This is the Woods of Suicides, where the poor unhappy people that \n"
             << "took their lives to escape their hell above were transformed into \n"
             << "thorny trees that are constantly ripped appart by Harpies. Your \n"
             << "girlfriend is one of these trees.\n\n";
    if(circleCounter > 5 && this->player->getDescent(18))
        cout << "You're in the Burning Plain, the big desert of Hell. Turns out the \n"
             << "sodomite thing isn't true. Wonder why Dante was a homophobe?\n"
             << "It's a pretty terrible place. I wonder why the scorching sand and \n"
             << "rain of fire isn't affecting you\n\n";
}

/*****************************************************************************************
 ** Function: interact()
 ** Description: first if the player has just arrived at this class, they must first fight
 *               the minotaur by hitting the right key. Once they kill the minotaur, the
 *               player's kill minotaur bool is set to true and Nessus takes the player 
 *               past the Phlagathon.
 *               Once the Minotaur has been slain,the function returns a description of 
 *               "section of the circle" currently occupied by the player deppending on the
 *               player's circleCounter value. at the 3rd "space" of the circle, the player
 *               finds the rope they need to descend to the next circle.
 *
 *               for the most part, this is a copy of the demon() function, but it doesn't
 *               return a continue bool. This way, something still happens when the 
 *               function is called, since this space is all about fighting the minotaur 
 *               and getting through the woods of suicides and the desert of fire.
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: the rope item is added to the item array and the bool
 *                   to continue to the next space is set to true.
 ****************************************************************************************/
void Circle7::interact() {
    
    if (!this->player->getDescent(18)) { //must fight the minotaur first
        cout << "The Phlagathon looks fairly foreboding. This is going to be one \n"
             << "hell of an obstacle...\n\n";
    }
    else {
        circleCounter = this->player->getCounter(); // 0 - 5 is suicide, >5 is the desert
        this->player->incrementCounter();
        
        
        //if you're in the suicide woods, you can't get down yet
        if(circleCounter < 5) {
            cout << "This is the Woods of Suicides, where the poor unhappy people that took their lives to escape their hell above were transformed into thorny trees that are constantly ripped appart by Harpies. Your girlfriend is one of these trees.\n\n";
            if (circleCounter == 3) {
                cout << "There's a noose on that tree. That's really morbid. You "
                << "should take that rope though, it's a lot of rope, it can "
                << "come in handy.\n\n";
                this->player->addItem(this->item);
            }
        }
        
        if(circleCounter > 5 && circleCounter < 12) {
            cout << "The Plains of Fire seem to go on forever...\n\n";
        }
    }
}


/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true (note function unused)
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Circle7::contQuest() {
    return;
}
