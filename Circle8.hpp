/***************************************************************************************
 ** Program Filename: Circle8.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle8, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Circle8_hpp
#define Circle8_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"

class Circle8 : public Space {
private:
    bool gift2Giant;
    int BolgeCounter;
    
public:
    
    Circle8();
    void setCanGo();
    int demons();
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();
    
};

#endif /* Circle8_hpp */
