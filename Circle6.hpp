/***************************************************************************************
 ** Program Filename: Circle6.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Circle6, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Circle6_hpp
#define Circle6_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"

class Circle6 : public Space {
private:
    bool climbDown;
    
public:
    Circle6();
    void setCanGo();
    int demons(); //kill minotaur with sword
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();
    
};


#endif /* Circle6_hpp */
