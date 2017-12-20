/***************************************************************************************
 ** Program Filename: Circle9.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle9, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Circle9_hpp
#define Circle9_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"

class Circle9 : public Space {
private:
    bool foundSatan;
public:
    
    Circle9();
    void setCanGo();
    int demons();
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();
    
};

#endif /* Circle9_hpp */
