/***************************************************************************************
 ** Program Filename: player.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Player class declaration file
 ** Input: as required by functions
 ** Output: deppends on the function 
 ***************************************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <unistd.h>
class Space;
#include "Space.hpp"
//#include "Items.hpp"
using std::string;

class Player {
protected:
    string name; //player's name
    bool descend2C1; //player can descend to Cirlce 1
    bool descend2C6; //player can descend to Cirlce 6
    bool descend2C7; //player can descend to Cirlce 7
    bool descend2C8; //player can descend to Cirlce 8
    bool descend2C9; //player can descend to Cirlce 9
    bool darkOne; //player can meet satan
    bool killedMinotaur; //the player killed the minotaur in circle 7
    bool hasRope;
    bool hasSword;
    bool hasSoul;
    bool hasGold;
    int index;
    int circleCounter; //to keep track of player location in Circle subspaces (ie bolges)
    string itemArray[5]; //items player has collected
    Space* currentSpace;
    Space* lastSpace;
public:
    Player();
    void setName(string n);
    string getName();
    void setBools();
    void setDescent(int);   //if int == 1 (descend2C1) if int == 6 (descend2C6 ==true)....
    bool getDescent(int);
    bool hasItem(string item);
    void addItem(string item);
    void removeItem(string item);
    void setFirstSpace(Space *);
    void setCurrentSpace(Space *);
    Space* getCurrentSpace();
    Space* getLastSpace();
    void resetCounter();
    void incrementCounter();
    int getCounter();
    void moveFWD();
    void moveBACK();
    void moveLEFT();
    void moveRIGHT();
    void moveDOWN();
};

#endif /* Player_hpp */
