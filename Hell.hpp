/***************************************************************************************
 ** Program Filename: Hell.hpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Hell class declaration file. This class controls the gameplay.
 ** Input: as required by the functions
 ** Output: deppending on the functions
 ***************************************************************************************/

#ifndef Hell_hpp
#define Hell_hpp

#include <stdio.h>
#include "Player.hpp"
#include "Space.hpp"
#include "Items.hpp"
#include "Vestibule.hpp" //preHell
#include "Circle1.hpp"   //Limbo
#include "Circle6.hpp"   //Dis
#include "Circle7.hpp"   //Plane of Fire
#include "Circle8.hpp"   //Malebolge
#include "Circle9.hpp"   //Frozen Pit of Hell

class Hell {
private:
    Player *player;
    Space *vestibule;
//    Space *vestibuleII;
    Space *circle1;
//    Space *Limbo;
    Space *circle6;
//    Space *Heresy;
    Space *circle7;
//    Space *Violence;
    Space *circle8;
//    Space *Fraud;
    Space *circle9;
//    Space *Treachery;

public:
    Hell();
    void circleFWD();
    void circleBACK();
    void circleLEFT();
    void circleRIGHT();
    void descendCircle();
    Player* getPlayer();

};
#endif /* Hell_hpp */
