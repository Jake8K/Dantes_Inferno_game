/***************************************************************************************
 ** Program Filename: Circle1.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle1, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Circle1_hpp
#define Circle1_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"

class Circle1 : public Space {
private:
    bool Minos;
    
public:
    
    Circle1();
    void setCanGo();
    int demons();
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();
    
};

#endif /* Circle1_hpp */
