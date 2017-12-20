/***************************************************************************************
 ** Program Filename: Circle7.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle7, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Circle7_hpp
#define Circle7_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"

class Circle7 : public Space {
private:
    bool killMinotaur;
    int circleCounter;
    char input;
    
public:
    
    Circle7();
    void setCanGo();
    int demons();
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();
    
};


#endif /* Circle7_hpp */
