/***************************************************************************************
 ** Program Filename: Space.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space abstract base class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
class Player;
#include "Player.hpp"
using std::string;

class Space {
protected:
    Space *forward;
    Space *back;
    Space *left;
    Space *right;
    Space *down;
    string item;
    bool canGo;
    string spaceName;
    Player *player;

public:
    //constructors and destructor
    Space();
    Space(Player *p, string spaceName, string i, Space *f = NULL, Space *b = NULL,
           Space *l = NULL, Space *r = NULL, Space *d = NULL, bool cG = false);
    ~Space();
    
    //member functions
    void modSpace (Player *p, Space *f, Space *b, Space *l, Space *r, Space *dn);
    Space* getFWD();
    Space* getBACK();
    Space* getLEFT();
    Space* getRIGHT();
    Space* getDOWN();
    bool getCanGo();
    string getSpaceType();
    
    //pure virtual functions
    virtual int demons() = 0;
    virtual bool damnedSouls() = 0;
    virtual void lookAround() = 0;
    virtual void interact() = 0;
    virtual void contQuest() = 0;
};

#endif /* Space_hpp */
