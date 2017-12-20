/***************************************************************************************
 ** Program Filename: Hell.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Hell class function implementation file
 ** Input: as required by the functions
 ** Output: deppending on the functions
 ***************************************************************************************/

#include <iostream>
#include "Hell.hpp"
using std::cout;

/*****************************************************************************************
 ** Function: Constructor
 ** Description: Instantiates the circle spaces, sets them to their pointers to the proper 
 *               spaces and instantiates a player in the proper space to start the game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of a player inside of a linked list of space nodes 
 *                   simulating the 9 circles of Sante's inferno (skipping 2-5).
 ****************************************************************************************/
Hell::Hell() {
    
    // Instantiate all Space objects
    vestibule = new Vestibule();
    circle1 = new Circle1();
    circle6 = new Circle6();
    circle7 = new Circle7();
    circle8 = new Circle8();
    circle9 = new Circle9();
    
    // Instantiate Character and starting point
    this->player = new Player();
    this->player->setFirstSpace(vestibule);
    
    // Then set up Space pointers
    vestibule->modSpace(player, NULL, NULL, NULL, NULL, circle1);
                                //vestibule, vestibule, vestibule, vestibule, circle1);
    circle1->modSpace(player, NULL, NULL, NULL, NULL, circle6); //circle1, circle1, circle1, circle1, circle6);
    circle6->modSpace(player, NULL, NULL, NULL, NULL, circle7); //circle6, circle6, circle6, circle6, circle7);
    circle7->modSpace(player, NULL, NULL, NULL, NULL, circle8); //circle7, circle7, circle7, circle7, circle8);
    circle8->modSpace(player, NULL, NULL, NULL, NULL, circle9); //circle8, circle8, circle8, circle8, circle9);
    circle9->modSpace(player, NULL, NULL, NULL, NULL, NULL);    //circle9, circle9, circle9, circle9, NULL);
    
}

/*****************************************************************************************
 ** Function: getPlayer()
 ** Description: returns the pointer to the Player instance
 ** Parameters: none
 ** Pre-Conditions: a in instance of Hell has instantiated an instance of a PLayer
 ** Post-Conditions: returns the pointer to the player
 ****************************************************************************************/
Player* Hell::getPlayer() {
    return this->player;
}

/*****************************************************************************************
 ** Function: circleFWD()
 ** Description: moves the player forward 1 space by instantiating a new instance of the
 *               space class currently occupied
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
//moveFORWARD
void Hell::circleFWD() {
    string FWD = this->player->getCurrentSpace()->getSpaceType();
    
    //if FWD is not NULL, move to the last space inhabitted
//    if (this->player->getCurrentSpace()->getFWD() == this->player->getLastSpace())  {
//        this->player->setCurrentSpace(this->player->getLastSpace());
//    }
        
//    else {
        if (FWD == "Vestibule") {
        
            //if this is not the first space, delete the last space player was at
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
        
            //instantiate the space player is about to move to
            Space *vestibuleII = new Vestibule();
            vestibuleII->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, circle1);
        
            //put the player in the new space they just moved to
            this->player->setCurrentSpace(vestibuleII);
    
            //print circle description
            //this->player->getCurrentSpace()->lookAround(); //print circle description
        }
        if (FWD == "Limbo") {
        
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Limbo = new Circle1();
            Limbo->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, circle6);
        
            this->player->setCurrentSpace(Limbo);
        
            //this->player->getCurrentSpace()->lookAround();
        }
        if (FWD == "Heresy") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Heresy = new Circle6();
            Heresy->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, circle7);
            
            this->player->setCurrentSpace(Heresy);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (FWD == "Violence") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Violence = new Circle7();
            Violence->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, circle8);
            
            this->player->setCurrentSpace(Violence);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (FWD == "Fraud") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Fraud = new Circle8();
            Fraud->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, circle9);
            
            this->player->setCurrentSpace(Fraud);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (FWD == "Treachery") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Treachery = new Circle9();
            Treachery->modSpace(player, NULL, player->getCurrentSpace(), NULL, NULL, NULL);
            
            this->player->setCurrentSpace(Treachery);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
//        else if (FWD != "Limbo" && FWD != "Heresy" &&
//                 FWD != "Violence" && FWD != "Fraud" && FWD != "Treachery")
//            cout << "That way doesn't look safe... you should go in a different direction.\n";
//    }
}

/*****************************************************************************************
 ** Function: circleBACK()
 ** Description: moves the player back 1 space by instantiating a new instance of the
 *               space class currently occupied
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
//moveBACK
void Hell::circleBACK() {
    string back = this->player->getCurrentSpace()->getSpaceType();
    
    //if BACK is not NULL, move to the last space inhabitted
//    if (this->player->getCurrentSpace()->getBACK() == this->player->getLastSpace())  {
 //       this->player->setCurrentSpace(this->player->getLastSpace());
//    }
    
//    else {
        if (back == "Vestibule") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *vestibuleII = new Vestibule();
            vestibuleII->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, circle1);
            
            this->player->setCurrentSpace(vestibuleII);
            
            //this->player->getCurrentSpace()->lookAround(); //print circle description
        }
        if (back == "Limbo") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Limbo = new Circle1();
            Limbo->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, circle6);
            
            this->player->setCurrentSpace(Limbo);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        if (back == "Heresy") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Heresy = new Circle6();
            Heresy->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, circle7);
            
            this->player->setCurrentSpace(Heresy);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (back == "Violence") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Violence = new Circle7();
            Violence->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, circle8);
            
            this->player->setCurrentSpace(Violence);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (back == "Fraud") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Fraud = new Circle8();
            Fraud->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, circle9);
            
            this->player->setCurrentSpace(Fraud);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (back == "Treachery") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Treachery = new Circle9();
            Treachery->modSpace(player, player->getCurrentSpace(), NULL, NULL, NULL, NULL);
            
            this->player->setCurrentSpace(Treachery);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        else if (back != "Limbo" && back != "Heresy" &&
                 back != "Violence" && back != "Fraud" && back != "Treachery")
            cout << "That way doesn't look safe... you should go in a different direction.\n";
//    }
}

/*****************************************************************************************
 ** Function: circleLEFT()
 ** Description: moves the player left 1 space by instantiating a new instance of the
 *               space class currently occupied
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Hell::circleLEFT() {
    string left = this->player->getCurrentSpace()->getSpaceType();
    
    //if LEFT is not NULL, move to the last space inhabitted
//    if (this->player->getCurrentSpace()->getLEFT() == this->player->getLastSpace())  {
//        this->player->setCurrentSpace(this->player->getLastSpace());
//    }
    
//    else {
        if (left == "Vestibule") {
            
            //if this is not the first space, delete the last space player was at
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            //instantiate the space player is about to move to
            Space *vestibuleII = new Vestibule();
            vestibuleII->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), circle1);
            
            //put the player in the new space they just moved to
            this->player->setCurrentSpace(vestibuleII);
            
            //print circle description
            //this->player->getCurrentSpace()->lookAround(); //print circle description
        }
        if (left == "Limbo") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Limbo = new Circle1();
            Limbo->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), circle6);
            
            this->player->setCurrentSpace(Limbo);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        if (left == "Heresy") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Heresy = new Circle6();
            Heresy->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), circle7);
            
            this->player->setCurrentSpace(Heresy);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (left == "Violence") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Violence = new Circle7();
            Violence->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), circle8);
            
            this->player->setCurrentSpace(Violence);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (left == "Fraud") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Fraud = new Circle8();
            Fraud->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), circle9);
            
            this->player->setCurrentSpace(Fraud);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (left == "Treachery") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Treachery = new Circle9();
            Treachery->modSpace(player, NULL, NULL, NULL, player->getCurrentSpace(), NULL);
            
            this->player->setCurrentSpace(Treachery);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
//        else if (left != "Limbo" && left != "Heresy" &&
//                 left != "Violence" && left != "Fraud" && left != "Treachery")
//            cout << "That way doesn't look safe... you should go in a different direction.\n";
//    }
}

/*****************************************************************************************
 ** Function: circleRIGHT()
 ** Description: moves the player right 1 space by instantiating a new instance of the
 *               space class currently occupied
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player advanced to a new space in the desired direction
 ****************************************************************************************/
void Hell::circleRIGHT() {
    string right = this->player->getCurrentSpace()->getSpaceType();
    
    //if FWD is not NULL, move to the last space inhabitted
//    if (this->player->getCurrentSpace()->getRIGHT() == this->player->getLastSpace())  {
//        this->player->setCurrentSpace(this->player->getLastSpace());
//    }
    
//    else {
        
        if (right == "Vestibule") {
            
            //if this is not the first space, delete the last space player was at
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            //instantiate the space player is about to move to
            Space *vestibuleII = new Vestibule();
            vestibuleII->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, circle1);
            
            //put the player in the new space they just moved to
            this->player->setCurrentSpace(vestibuleII);
            
            //print circle description
            //this->player->getCurrentSpace()->lookAround(); //print circle description
        }
        if (right == "Limbo") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Limbo = new Circle1();
            Limbo->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, circle6);
            
            this->player->setCurrentSpace(Limbo);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        if (right == "Heresy") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Heresy = new Circle6();
            Heresy->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, circle7);
            
            this->player->setCurrentSpace(Heresy);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (right == "Violence") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Violence = new Circle7();
            Violence->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, circle8);
            
            this->player->setCurrentSpace(Violence);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (right == "Fraud") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Fraud = new Circle8();
            Fraud->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, circle9);
            
            this->player->setCurrentSpace(Fraud);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
        if (right == "Treachery") {
            
            if ((this->player->getLastSpace()) != (this->player->getCurrentSpace()))
                delete this->player->getLastSpace();
            
            Space *Treachery = new Circle9();
            Treachery->modSpace(player, NULL, NULL, player->getCurrentSpace(), NULL, NULL);
            
            this->player->setCurrentSpace(Treachery);
            
            //this->player->getCurrentSpace()->lookAround();
        }
        
//        else if (right != "Limbo" && right != "Heresy" &&
//                 right != "Violence" && right != "Fraud" && right != "Treachery")
//            cout << "That way doesn't look safe... you should go in a different direction.\n";
//    }
}

/*****************************************************************************************
 ** Function: descendCircle()
 ** Description: moves the player down to the next circle space. The function first 
 *               deallocates the memory of the currentSpace and lastSpace player 
 *               member variables and then sets the player's Space pointers to the next 
 *               circle in the structure
 ** Parameters: none
 ** Pre-Conditions: a player instance and a space instance
 ** Post-Conditions: the player descends to the next circle in the linked list
 ****************************************************************************************/
void Hell::descendCircle() {
    string down = this->player->getCurrentSpace()->getDOWN()->getSpaceType();
    
    if (down == "Limbo") {
        
        //The descent to the pit of Hell is a one way path
        if (this->player->getCurrentSpace() == this->player->getLastSpace())
            delete this->player->getCurrentSpace();
        else if (this->player->getCurrentSpace() != this->player->getLastSpace()) {
            delete this->player->getLastSpace();
            delete this->player->getCurrentSpace();
        }
        
        sleep(3.5);
        //set the player's current and last space pointers to the new circle
        this->player->setFirstSpace(circle1); //sets currentSpace and lastSpace pointers to pointer passed
        this->player->getCurrentSpace()->lookAround(); //describe the place
    }
    if (down == "Heresy") {
        
        if (this->player->getCurrentSpace() == this->player->getLastSpace())
            delete this->player->getCurrentSpace();
        else if (this->player->getCurrentSpace() != this->player->getLastSpace()) {
            delete this->player->getLastSpace();
            delete this->player->getCurrentSpace();
        }
        
        sleep(3.5);
        this->player->setFirstSpace(circle6);
        this->player->getCurrentSpace()->lookAround(); //describe the place
        
    }
    
    if (down == "Violence") {
        
        if (this->player->getCurrentSpace() == this->player->getLastSpace())
            delete this->player->getCurrentSpace();
        else if (this->player->getCurrentSpace() != this->player->getLastSpace()) {
            delete this->player->getLastSpace();
            delete this->player->getCurrentSpace();
        }
        
        sleep(3.5);
        this->player->setFirstSpace(circle7);
        this->player->getCurrentSpace()->lookAround(); //describe the place
    }
    
    if (down == "Fraud") {
        
        if (this->player->getCurrentSpace() == this->player->getLastSpace())
            delete this->player->getCurrentSpace();
        else if (this->player->getCurrentSpace() != this->player->getLastSpace()) {
            delete this->player->getLastSpace();
            delete this->player->getCurrentSpace();
        }
        
        sleep(3.5);
        this->player->setFirstSpace(circle8);
        this->player->getCurrentSpace()->lookAround(); //describe the place
    }
    
    if (down == "Treachery") {
        
        if (this->player->getCurrentSpace() == this->player->getLastSpace())
            delete this->player->getCurrentSpace();
        else if (this->player->getCurrentSpace() != this->player->getLastSpace()) {
            delete this->player->getLastSpace();
            delete this->player->getCurrentSpace();
        }
        
        sleep(3.5);
        this->player->setFirstSpace(circle9);
        this->player->getCurrentSpace()->lookAround(); //describe the place
    }
    
//    else if (down != "Heresy" && down != "Violence" && down != "Fraud" && down != "Treachery")
//        cout << "You can't get down there through here.\n";
}

//    Space(Player *p, string spaceName, string i, Space *f = NULL, Space *b = NULL,
//          Space *l = NULL, Space *r = NULL, Space *d = NULL, bool cG = false);

//I can mount flip as an external drive