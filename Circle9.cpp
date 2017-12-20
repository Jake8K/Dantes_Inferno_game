/***************************************************************************************
 ** Program Filename: Circle9.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle9, function definition file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include <iostream>
#include "Circle9.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: constructor
 ** Description: instantiates the Circle9 Space and sets its spaceName and item member
 *               variables to the appropriate strings and its bool to false
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the Circle9 Space class
 ****************************************************************************************/
Circle9::Circle9 (){
    //this->item = "Gold";
    this->spaceName = "Treachery";
    this->foundSatan = false;
}

/*****************************************************************************************
 ** Function: setCanGo()
 ** Description: sets the instances canGo() function if the player has acquired the item
 *               found within the space
 ** Parameters: none
 ** Pre-Conditions: an instance of the class
 ** Post-Conditions: the bool is true if the player has the item in its item array
 ****************************************************************************************/
void Circle9::setCanGo() {
    if (this->player->hasItem(this->item))
        this->canGo = true;
}

/*****************************************************************************************
 ** Function: demons()
 ** Description: This is the grand finale of the game. If the player has not yet "found 
 *               satan" through the interact() function, it prints out a vague statement 
 *               and returns 1 to continue gamePlay, otherwise if the player has "found 
 *               satan" there's a long and drawn out dialogue (apologies!) that hopefully 
 *               is not too offensive to the reader (apologies!). At the end of Satan's 
 *               schpiel, the player makes a choice to do the devil's bidding in exchange 
 *               for what he was after or to reject the Devil's offer to keep his morals 
 *               (though, what's his getaway game here? He's in the pit of Hell with 
 *               Satan and no way out--unless he follows Dante and climbs "down" to
 *               Purgatory). Anyways, regardless of the player's choice they've "won" 
 *               the game. Though if they reject the devil superhuman Obama comes to \
 *               save him and Heaven gives the player everything he wanted.
 ** Parameters: none
 ** Pre-Conditions: an instance of Player and of Circle9 exist
 ** Post-Conditions: returns 5 to signal that the game is over 
 *                   (if the players foundSatan bool is true) otherwise it 
 *                   returns 1 to continue game-play
 ****************************************************************************************/
int Circle9::demons() {
    if (this->player->getDescent(10)) {
        cout << "Satan:\nAre you prepared to be judged in this place? Are you \n"
             << "without sin? \nEarth is but a different form of Hell, \n"
             << "people are its demons.\n";
        sleep(1);
        cout << "What makes your girl worthy of salvation? She’s nothing but a \n"
             << "weak, vile, slutty little whore. If you could read her, like I can, \n"
             << "you wouldn’t have bothered with this ludicrous quest.\n\n";
        sleep(1);
        cout <<  "For that matter, what makes you worthy of my grace and pitty? I \n"
             << "am justice, I am fairness, I am the alpha and the Omega. That old man \n"
             << "in the heavens is nothing but a disillusioned fool. I judge him not \n"
             << "though, dementia is bound to get anyone that old and foolish. Why \n"
             << "should I grant you the salvation you seek? Why not keep what is mine \n"
             << "and gain another, living, soul? When you were young, did you burn \n"
             << "ants? Did their plight matter?\n\n";
        sleep(2);
        cout << "Then why should yours!\n";
        sleep(1);
        cout << "I will enjoy having you around, my little pet. Thank you for coming.\n\n";
        sleep(2);
        cout << "I will grant you what you seek if you will give me your soul. Think \n"
             << "about it " << this->player->getName() << ". You would get everything \n"
             << "you wanted. It is, as you would say, a win win. I get my pet (as \n"
             << "I am bound to regardless of the outcome of this conversation) and \n"
             << "you get to save your precious whore and grow old with her..\n\n";
            sleep(1);
        cout << "Well, spend some more time with her in your world anyways, whatever "
             << "that’s worth to you.\n\n";
        sleep(3);
        cout << "Is that so? I admire your courage " << this->player->getName()
             << ". Do you kiss your mother with that mouth?\n\n";
        cout << "OK, I will make a deal with you. You can get everything you want, \n"
             << "your girl, your soul, your eternity.  BUT you must vote for Donald \n"
             << "Trump in the upcoming election. Tell your chums what you will. But \n"
             << "your vote belongs to my little orange minion. Help my little cinnamon \n"
             << "Hitler get elected and I will give you what you want. Once his \n"
             << "presidency comes into fruition, it won’t be long until I’m sodomizing \n"
             << "him in the Oval office, from whence we rule the world!\n\n";
        
        char choice;
        cout << "Will you take the devil up on his offer? Will you vote for the evil \n"
             << "oompa lumpa? (y/n)\n";
        std::cin >> choice;
        if (choice == 'y') {
            cout << "Devil:\nGood for you, my little pet.\n I wish you guys the best, \n"
                 << "long live the dictator of the US, emperor of the world, my little \n"
                 << "Donnie.\n\n";
            cout << "This was a bad idea. You made a deal with the devil, those \n"
                 << "never end well...\n\n";
            sleep(3);
            cout << "It's the future, you helped Trump get elected, it only took him \n"
                 << "2 weeks to destroy the global economy and plunge us into \n"
                 << "World War 3, the one where every trigger-happy dictator has \n"
                 << "nuclear weapons...\n\n";
            return 5;
        }
        if (choice == 'n') {
            cout << "Devil:\nYou virtuous fool. I shall make eternity a painful and \n"
                 << "meaningless torture for you!\n\n";
            sleep(3);
            cout << "Satan:\nWhat the Hell?!?!?!\n\n";
            cout << "Barack Obama just flew into the Pit of Hell through the \n"
                 << "gates to Purgatory?!?!\n\n";
            cout << "Obama:\n" << this->player->getName() << ", America, and in fact, \n"
                 << "the world at large, would like to thank you for not tipping the \n"
                 << "tables in our time of need. Believe it or not, your vote was the \n"
                 << "deciding vote. Thanks to the disillusioned Bernie Bros and the \n"
                 << "drunken money greedy hypocrite republicans, that tyrant actually \n"
                 << "had a shot at the presidency. You’ve saved the world and Zeus has \n"
                 << "sent me to grant your wishes and get you two back to Earth.\n\n";
            sleep(1);
            cout << "Oh yeah you’re confused. Well Zeus doesn’t care what you call him, \n"
                 << "and of course I’m superhuman! Have you seen the crap I’ve had to \n"
                 << "put up with for humanity? Now get back to it, why not enjoy the \n"
                 << "real pleasures of Indonesia with that girl now. We got you an all \n"
                 << "expense paid vacation, the drinks are on us.\n\n";
            return 5;
        }
        
    }
    
    else {
        cout << "Hell sucks...\n\n";
        return 1;
    }
    return 1;
}

/*****************************************************************************************
 ** Function: damnedSouls()
 ** Description: a function that generates a random number and returns a true if the player
 *               is doomed to spend eternity in the pit of hell
 ** Parameters: none
 ** Pre-Conditions: an instance of the player class and an instance of Circle9
 ** Post-Conditions: returns true or false and prints a description of the future if true
 ****************************************************************************************/
bool Circle9::damnedSouls() {
    int doomed = (rand() %20) +1;
    
    if (doomed == 10) {
        cout << "Oh no! You lost your torch!\n\n";
        sleep(1);
        cout << "You're stuck in this frigid darkness for eternity.\n\n";
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
void Circle9::lookAround() {
    cout << "You're in the very pit of hell. The 9th Circle. The circle of Treachery. \n"
         << "Use your torch and find Satan. \n"
         << "It shouldn't be that hard, just look for an enormous chained up \n"
         << "3-headed demon gnawing on people like it's a teething puppy.\n\n";
}

/*****************************************************************************************
 ** Function: interact()
 ** Description: if the player has not yet "found" satan," there's a 50 percent chance that
 *               satan will be "close"  and the player will have "found" satan and had it's 
 *               foundSatan bool set to true.
 ** Parameters: none
 ** Pre-Conditions: a Player instance and a space instance
 ** Post-Conditions: if the player found satan, then the bool is set to true.
 ****************************************************************************************/
void Circle9::interact() {
    if (this->player->getDescent(10))
        cout << "It seems like Satan is chained up here, just work your way through \n"
             << "these enormous chains.\n\n";
    
    else {
        int satan = (rand() %10) +1;
        
        if (satan % 2 == 0) {
            cout << "Should be getting close!\n\n";
            this->canGo = true;
            this->player->setDescent(10);
        }
        else
            cout << "It's cold, dark, windy, and awful down here. This quest \n"
                 << "seems like a ridiculous idea...\n\n";
    }
    
    
}


/*****************************************************************************************
 ** Function: contQuest
 ** Description: sets the player's continue bool to true (note function unused)
 ** Parameters: none
 ** Pre-Conditions: a space instance and a player instance
 ** Post-Conditions: the player's continue bool is true, they can move to the next circle
 ****************************************************************************************/
void Circle9::contQuest() {
    return;
}