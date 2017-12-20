/***************************************************************************************
 ** Program Filename: Vestibule.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space derived class, Vestibule, class declaration file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#ifndef Vestibule_hpp
#define Vestibule_hpp

#include <stdio.h>
class Space;
#include "Space.hpp"
#include "Hell.hpp"

class Vestibule : public Space {
private:
    //string sword;
    
public:

    Vestibule ();
    void setCanGo();
    int demons();
    bool damnedSouls();
    void lookAround();
    void interact();
    void contQuest();

};




#endif /* Vestibule_hpp */
