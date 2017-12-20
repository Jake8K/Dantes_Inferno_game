/***************************************************************************************
 ** Program Filename: main.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: main function file for a linked-list based game simulation of 
 *               Dante's Inferno with a modern political twist
 ** Input: user only
 ** Output: returns 0 if no errors
 ***************************************************************************************/
//
//  main.cpp
//  finalProject
//
//  Created by Jacob Karcz on 8/2/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Player.hpp"
#include "Items.hpp"
#include "Space.hpp"
#include "Vestibule.hpp" //preHell
#include "Circle1.hpp"   //Limbo
#include "Circle6.hpp"   //Dis
#include "Circle7.hpp"   //Plane of Fire
#include "Circle8.hpp"   //Malebolge
#include "Circle9.hpp"   //Frozen Pit of Hell
#include "Hell.hpp"      //Instantiates the game
using std::cout;
using std::cin;
using std::endl;


/*****************************************************************************************
 ** Function: main()
 ** Description: Main function to run Dante's Inferno game. It provides descriptions of 
 *               the player's current space and actions and prompts the users for the next
 *               action to take. Some functions within the space will have their own
 *               prompts for the user to take actions within the space.
 ** Parameters: None
 ** Pre-Conditions: Relevant class files included
 ** Post-Conditions: returns 0 if no errors encountered
 ****************************************************************************************/
int main() {
    double start,
           check,
           stop = 181836;
    
    srand(time(0));

    
    cout << "Trekking deep in the jungles of Indonesia, our protagonist comes across \n"
         << "a temple. There’s something different about it. Something that sets it \n"
         << "apart from the other beautiful Buddhist temples scattered in the area. The \n"
         << "temple, half consumed by vegetation—seemingly trying to tear it apart–is \n"
         << "carved and sculpted into a cliff deep in the jungle. The spires of the \n"
         << "temple's facade seem to stab through the cliff and tower over the canopy of \n"
         << "the forest. Our hero follows a nearby stream that leads him into the \n"
         << "temple. There is a stillness in the air, the young explorer can’t figure \n"
         << "out what it is, but there is something eerie about the chamber. You shine \n"
         << "your flashlight inside and the interiror is as expected: narrow hallways \n"
         << "made of stone. Guided by your compass, you venture into the labyrinth still \n"
         << "following the stream, though it has diminished to a trickle at best. \n"
         << "Finally you realize it, there is no life inside the chamber. The jungle \n"
         << "that seemed to be consuming every possible inch of real estate outside the \n"
         << "temple halted all growth at the entrance. you haven’t run into a cobweb or \n"
         << "heard a bat’s screech or fluttering wings. It’s unlikely that nothing has \n"
         << "made this temple its home given the safety it could provide. It’s just you, \n"
         << "your breath, your increasingly rapid heartbeat, and the slight buzz \n"
         << "emanating from your flashlight. The labyrinth opens up into a large oval \n"
         << "room. You follow the trickle of water as it leads you down the hall. The \n"
         << "hall narrows until you finally see an archway in the distance. You shine \n"
         << "the gentle yellow glow of your flashlight into the entryway but still, \n"
         << "all you can see is infinite darkness. You look up and see the \n"
         << "words \"Abandon all hope, ye who enter here\" scratched into the archway. \n"
         << "\"I found it, finally!\" He thinks to himself.\n" << endl;
    sleep(1);
    cout << "He takes a deep breath and steps through the archway into the abysmal \n"
         << "darkness. Now on the other side, the trickle of water runs red, and flows \n"
         << "into a river of blood. He’s just crossed through the last \n"
         << "remaining gateway to Hell." << endl;
    sleep(2);
    cout << "___________________________________________________________________________\n\n";
    cout << "To get through Hell, you must deal with demons and tortured souls. \n"
         << "You must find and collect various objects so you can traverse the \n"
         << "torturous terrain of Hell and bribe demons along the way to assist you \n"
         << "in your quest. Can you make a bargain with the devil and get out of Hell \n"
         << "before you're stuck in Hell for all eternity? Will you rescue your \n"
         << "girlfriend after her tragic suicide or will you become another \n"
         << "jester of a soul for Satan to toy with?\n";
    cout << "___________________________________________________________________________\n\n";
    
    sleep(1);
    
    Hell *inferno = new Hell();
    Player *player = inferno->getPlayer();
    
    player->getCurrentSpace()->lookAround();
    
    bool loop = false;
    start = clock();
    
    while (!loop) {
        cout << "\n\nWhat would you like to do?\n";
        cout << "  1. Look around\n  2. Move\n  3. Interact\n  4. Give Up\n\n";
//        cout << "secret menu:\n 4 calls demon\n 5 calls interact\n 6 gets you to a lower cicrle\n\n";
        cout << "Enter choice: ";

        
        std::cin.clear();
        int choice;
        while (!(std::cin >> choice) || (choice < 1 || choice > 4)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "\nEnter choice: ";
        }
        
        switch (choice) {
            case 1: //describe the place
                player->getCurrentSpace()->lookAround();
                break;
                
            case 2: //move the player, may encounter demons, people, or objects
                char d;
                std::cout << "\nWhich direction?\n";
                do {
                    std::cout << "Direction - (f)orward, (b)ack, (l)eft, (r)ight: ";
                    std::cin.ignore();
                    std::cin >> d;
                    cout << "\n\n";
                } while (d != 'f' && d != 'b' && d != 'l' && d != 'r');
                
                switch (d) {
                    case 'f':
                        inferno->circleFWD();
                        break;
                    case 'b':
                        inferno->circleBACK();
                        break;
                    case 'l':
                        inferno->circleLEFT();
                        break;
                    case 'r':
                        inferno->circleRIGHT();
                        break;
                    default:
                        break;
                }
                int function; //calls demon or interact to see what's in this space for you
                int descend;
                function = (rand() %10) +1;
                //if (function == 1 || function == 2 || function == 3 || function == 4) {
                //    player->getCurrentSpace()->interact(); //there might be an object here
                //}
                if (function % 2 == 0) {
                    descend = player->getCurrentSpace()->demons(); //good luck with the demons
                    if (descend == 3) {
                        inferno->descendCircle();
                        player->resetCounter();
                    }
                    if (descend == 5)
                        loop = true;
                }
                else if (function == 5 || function == 3 || function == 7 || function == 9)
                    loop = player->getCurrentSpace()->damnedSouls();
                else
                    cout << "... \n\n";
                break;
                
            case 3:
                cout << "\n\n";
                player->getCurrentSpace()->interact();
                break;
                
            case 4:
                loop = true;
                cout << "\n\nYou lazy coward, now you're damned to an eternity with the "
                     << "sullen in \nthe bottom of the river Styx.\n\n";
                break;
                
            case 5:
                player->getCurrentSpace()->demons();
                break;

            case 6:
                inferno->descendCircle();
                break;
                
            default:
                break;
        }
        check = clock();
        if (check - start >= stop) {
            loop = true;
            cout << "\n\n";
            cout << "What's happening? Your body just fell to the ground, I thought you \n"
                 << "fainted.... but there you are. You must have spent too much time \n"
                 << "down here. That must be what it looks like when it happens. \n\n"
                 << "You are never leaving Hell!\n You're stuck here until the \n"
                 << "end of time!\n";
            sleep(1);
            cout << "Uh-oh, there's a demon flying straight at you!\nI guess \n"
                 << "you belong to the damned. I have to run, good luck...\n\n";
        }
    }

    delete inferno;
    return 0;
}


