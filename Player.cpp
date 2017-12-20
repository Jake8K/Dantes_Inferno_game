/***************************************************************************************
 ** Program Filename: player.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Player class function implementation file
 ** Input: as required by functions
 ** Output: as required by functions
 ***************************************************************************************/

#include <iostream>
#include "Player.hpp"
using std::cout;
using std::cin;

/*****************************************************************************************
 ** Function: Constructor
 ** Description: sets all bools to false and counters to 0
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: a player object instance
 ****************************************************************************************/
Player::Player() {
    name = "";
    hasRope = false;
    hasSword = false;
    hasSoul = false;
    hasGold = false;
    descend2C1 = false;
    descend2C6 = false;
    descend2C7 = false;
    descend2C8 = false;
    descend2C9 = false;
    darkOne = false;
    killedMinotaur = false;
    index = 0;
    circleCounter = 0;
    //for (int i = 0; i < 5; i++)
    //    itemArray[i] = "nothing";

}

/*****************************************************************************************
 ** Function: setName()
 ** Description: sets the name of the character to the string passed
 ** Parameters: a string for the name
 ** Pre-Conditions: a character instance
 ** Post-Conditions: the character now has a name
 ****************************************************************************************/
void Player::setName(string n) {
    this->name = n;
}

/*****************************************************************************************
 ** Function: getName()
 ** Description: a function that returns the name of the player
 ** Parameters: none
 ** Pre-Conditions: a player instance with a name
 ** Post-Conditions: returns the name of the player
 ****************************************************************************************/
string Player::getName() {
    return this->name;
}

/*****************************************************************************************
 ** Function: setBools()
 ** Description: the function sets the player's bool variables to true if the player 
 *               has acquired the items passed to the hasItem(string) function
 ** Parameters: None
 ** Pre-Conditions: a player instance
 ** Post-Conditions: the player's bools are updated
 ****************************************************************************************/
void Player::setBools() {
    if (hasItem("rope"))
        hasRope = true;
    
    if (hasItem("sword"))
        hasSword = true;
    
    if (hasItem("soul"))
        hasSoul = true;
    
    if (hasItem("gold"))
        hasGold = true;
    
}

/*****************************************************************************************
 ** Function: setDescent(int)
 ** Description: sets the player instances descend bools, the int passed designates 
 *               the bool to be set to true
 ** Parameters: an int representing the circle of inferno to be accessed next
 ** Pre-Conditions: a player instance exists
 ** Post-Conditions: the descend circles bool is set to true deppending on the int passed
 ****************************************************************************************/
void Player::setDescent(int x) {
    if (x == 1)
        this->descend2C1 = true;
    if (x == 6)
        this->descend2C6 = true;
    if (x == 7)
        this->descend2C7 = true;
    if (x == 8)
        this->descend2C8 = true;
    if (x == 9)
        this->descend2C9 = true;
    if (x == 10)
        this->darkOne = true;
    if (x == 18)
        this->killedMinotaur = true;
}

/*****************************************************************************************
 ** Function: getDescent(int)
 ** Description: returns the boolean value of the bool variable indicated by the int passed
 *               as an arguement.
 ** Parameters: an int representing the player's ability to access the circle in question
 ** Pre-Conditions: a player instance
 ** Post-Conditions: returns the bool requested (else returns false)
 ****************************************************************************************/
bool Player::getDescent(int z) {
    if (z == 1)
        return this->descend2C1;
    if (z == 6)
        return this->descend2C6;
    if (z == 7)
        return this->descend2C7;
    if (z == 8)
        return this->descend2C8;
    if (z == 9)
        return this->descend2C9;
    if (z == 10)
        return this->darkOne;
    if (z == 18)
        return this->killedMinotaur;
    else
        return false;
}

/*****************************************************************************************
 ** Function: hasItem(string)
 ** Description: a function that returns true if the player has acquired the item in
 *               in question, or false if the item is not in the array.
 ** Parameters: a string of the item in question
 ** Pre-Conditions: a player instance
 ** Post-Conditions: returns true if player has the item in the array or false if not
 ****************************************************************************************/
bool Player::hasItem(string itm) {
    for (int i = 0; i < 5; i++) {
        if (itemArray[i] == itm) {
            return true;
        }
    }
    return false;
}

/*****************************************************************************************
 ** Function: addItem(string)
 ** Description: function that adds a string (item), passed as a parameter. If the item is 
 *               already in the array, it prints a message saying so, if the array is full
 *               it tells the character so he can get rid of an item, and if there's room
 *               and it's a novel item it stores the string in the array
 ** Parameters: a string with the name of the item
 ** Pre-Conditions: a player instance
 ** Post-Conditions: the item passed is in the array if it's a novel item and there is 
 *                   room in the array.
 ****************************************************************************************/
void Player::addItem(string itm) {
    
  //  if arrayfull, get rid of something??? Add removeItem(itm) func…
    bool addedItm = false;
    for (int i = 0; i < 5; i++)
        if (itemArray[i] == itm) {
            //cout << "You already have that item... weird... think it regenerated?\n";
            return;
        }
    //for (int i = 0; i < 5; i++) {
    //    if (itemArray[i] != "nothing") {
    //        if (!addedItm) {
    //            itemArray[i] = itm;
    //            addedItm = true;
    //            cout << "item added\n";
    //        }
    //    }
    
        if (!addedItm && index == 4) {
            cout << "You don't have any more room in your backpack.\n";
            return;
        }
        else {
            itemArray[index] = itm;
            index++;
        }
            
    
    //}
    
}

/*****************************************************************************************
 ** Function: removeItem(string)
 ** Description: a function to remove an item from the array
 ** Parameters: a string with the name of the item
 ** Pre-Conditions: a player instance and the item in question to be in the array
 ** Post-Conditions: the item is removed, if it was in the array.
 ****************************************************************************************/
void Player::removeItem(string itm) {
    for (int i = 0; i < 5; i++)
        if (itemArray[i] == itm) {
            itemArray[i] = "";
            index--;
        }
}

/*****************************************************************************************
 ** Function: setFirstSpace(Space *)
 ** Description: sets the player's currentSpace and lastSpace pointers to the the same 
 *               space. Used when instantiating a new game or descending a circle.
 ** Parameters: a Space pointer, for the space the player will occupy
 ** Pre-Conditions: a player instance and a Space instance both exist
 ** Post-Conditions: the player objects space pointers now point to the space passed
 ****************************************************************************************/
void Player::setFirstSpace(Space *spot) {
    this->currentSpace = spot;
    this->lastSpace = spot;
    
}

/*****************************************************************************************
 ** Function: setCurrentSpace(Space *)
 ** Description: Sets the currentSpace pointer to the space passed as a parameter and 
 *               lastSpace pointer to the Space currentSpace points to when the function 
 *               is called
 ** Parameters: a Space pointer
 ** Pre-Conditions: a player instance and a Space instance both exist
 ** Post-Conditions: The lastSpace and currentSpace pointers are updated according 
 *                   to the pointer passed
 ****************************************************************************************/
void Player::setCurrentSpace(Space *spot) {
    this->lastSpace = this->currentSpace;
    this->currentSpace = spot;
}

/*****************************************************************************************
 ** Function: getCurrentSpace()
 ** Description: returns the player instance's currentSpace pointer
 ** Parameters: none
 ** Pre-Conditions: a player instance and a Space instance both exist
 ** Post-Conditions: returns the currentSpace pointer
 ****************************************************************************************/
Space* Player::getCurrentSpace(){
    return this->currentSpace;
}

/*****************************************************************************************
 ** Function: getLastSpace()
 ** Description: returns the player instances lastSpace pointer
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance exist
 ** Post-Conditions: returns the player instances lastSpace pointer
 ****************************************************************************************/
Space* Player::getLastSpace(){
    return this->lastSpace;
}

/*****************************************************************************************
 ** Function: resetCounter()
 ** Description: a function to reset the player instance's circleCounter counter back to 0
 ** Parameters: none
 ** Pre-Conditions: a player instance
 ** Post-Conditions: the player instances counter is reset
 ****************************************************************************************/
void Player::resetCounter() {
    this->circleCounter = 0;
}

/*****************************************************************************************
 ** Function: incrementCounter()
 ** Description: a function that increments the player instances circleCounter by 1
 ** Parameters: none
 ** Pre-Conditions: a player instance
 ** Post-Conditions: the player instances circleCounter is incremented by 1
 ****************************************************************************************/
void Player::incrementCounter() {
    this->circleCounter += 1;
}

/*****************************************************************************************
 ** Function: getCounter()
 ** Description: a function that returns the player instances circleCounter count
 ** Parameters: none
 ** Pre-Conditions: a player instance
 ** Post-Conditions: returns the count of circleCounter
 ****************************************************************************************/
int Player::getCounter() {
    return this->circleCounter;
}

/*****************************************************************************************
 ** Function: moveFWD()
 ** Description: moves the player forward 1 space if it isn't null and calls the 
 *               Space class's lookAround() function to describe the place
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Player::moveFWD(){
    if(currentSpace->getFWD() != NULL) {
        this->lastSpace = currentSpace;
        this->currentSpace = currentSpace->getFWD();
        currentSpace->getFWD()->lookAround();
    }
    else
        cout << "That way doesn't look safe... you should go in a different direction.\n";
    
}

/*****************************************************************************************
 ** Function: moveBACK()
 ** Description: moves the player back 1 space if it isn't null and calls the
 *               Space class's lookAround() function to describe the place
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Player::moveBACK(){
    if(currentSpace->getBACK() != NULL) {
        this->lastSpace = currentSpace;
        this->currentSpace = currentSpace->getBACK();
        currentSpace->getBACK()->lookAround();
    }
    else
        cout << "That way doesn't look safe... you should go in a different direction.\n";
}

/*****************************************************************************************
 ** Function: moveLEFT()
 ** Description: moves the player left 1 space if it isn't null and calls the
 *               Space class's lookAround() function to describe the place
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Player::moveLEFT(){
    if(currentSpace->getLEFT() != NULL) {
        this->lastSpace = currentSpace;
        this->currentSpace = currentSpace->getLEFT();
        currentSpace->getLEFT()->lookAround();
    }
    else
        cout << "That way doesn't look safe... you should go in a different direction.\n";
    
}

/*****************************************************************************************
 ** Function: moveRIGHT()
 ** Description: moves the player right 1 space if it isn't null and calls the
 *               Space class's lookAround() function to describe the place
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Player::moveRIGHT(){
    if(currentSpace->getRIGHT() != NULL) {
        this->lastSpace = currentSpace;
        this->currentSpace = currentSpace->getRIGHT();
        currentSpace->getRIGHT()->lookAround();
    }
    else
        cout << "That way doesn't look safe... you should go in a different direction.\n";
}

/*****************************************************************************************
 ** Function: moveDOWN()
 ** Description: moves the player down to a lower circle if it isn't null and calls the
 *               Space class's lookAround() function to describe the place
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Player::moveDOWN(){
    if(currentSpace->getDOWN() != NULL) {
        if (currentSpace->getCanGo()) { //add something here to invoke demons();
            this->lastSpace = currentSpace;
            this->currentSpace = currentSpace->getDOWN();
            currentSpace->getDOWN()->lookAround();
        }
    }
    else
        cout << "you can’t get down there. "
             << "Maybe there's a tool or a demon that can help you descend.\n";
        
   // Character will only move down for circles where he cannot move back up. May need rethinking
}

