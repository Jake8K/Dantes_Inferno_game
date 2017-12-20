/***************************************************************************************
 ** Program Filename: Space.cpp
 ** Author: Jacob Karcz
 ** Date: 8/2/2016
 ** Description: Space abstract base class function defintion file
 ** Input: as required by the functions
 ** Output: deppending on the function
 ***************************************************************************************/

#include "Space.hpp"

/*****************************************************************************************
 ** Function: default constructor
 ** Description: creates an instance of space and sets all of its pointers to null
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: an instance of the abstract base class Space
 ****************************************************************************************/
Space::Space() {
    this->forward = NULL;
    this->back = NULL;
    this->left = NULL;
    this->right = NULL;
    this->down = NULL;
    this->canGo = false;
}

/*****************************************************************************************
 ** Function: constructor
 ** Description: a constructor that creates a space accoridng to the parameters passed
 ** Parameters: a pointer to player, a string with the name of the space, pointers to 
 *              the 5 class pointers (forward, back, left, right, and down; if no 
 *              pointers are specified they default to NULL), and a bool that defaults 
 *              to false if not passed.
 ** Pre-Conditions: None
 ** Post-Conditions: a Space instance with the variables initialized according to the
 *                   variables passed (or not passed)
 ****************************************************************************************/
Space::Space (Player *p, string sN, string itm, Space *f,
              Space *b, Space *l, Space *r, Space *d, bool cG) {
        this->forward = f;
        this->back = b;
        this->left = l;
        this->right = r;
        this->down = d;
        this->item = itm;
        this->canGo = cG;
        this->spaceName = sN;
        this->player = p;
}

/*****************************************************************************************
 ** Function: Destructor
 ** Description: Space class destructor
 ** Parameters: none
 ** Pre-Conditions: a space class instance
 ** Post-Conditions: the instance is gone
 ****************************************************************************************/
Space::~Space() {
    
}

/*****************************************************************************************
 ** Function: modSpace(Player *p, Space *f, Space *b, Space *l, Space *r, Space *dn)
 ** Description: a function to modify a Space instance's pointers once it has been instantiated.
 ** Parameters: a pointer to a player instance, 
 *              and pointers to Spaces (forward, back, left, right, and down)
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: the space instance's pointers have been modified acording too the 
 *                   parameters passed
 ****************************************************************************************/
void Space::modSpace (Player *p, Space *f, Space *b, Space *l, Space *r, Space *dn) {
    this->player = p;
    this->forward = f;
    this->back = b;
    this->left = l;
    this->right = r;
    this->down = dn;
}

/*****************************************************************************************
 ** Function: getFWD()
 ** Description: if not null, returns the pointer to the Space 
 *               instance pointed to by the forward pointer
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances forward pointer
 ****************************************************************************************/
Space* Space::getFWD(){
    if (this->forward != NULL)
        return this->forward;
    else
        return NULL;
}

/*****************************************************************************************
 ** Function: getBACK()
 ** Description: if not null, returns the pointer to the Space
 *               instance pointed to by the back pointer
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances back pointer
 ****************************************************************************************/
Space* Space::getBACK() {
    if (this->back != NULL)
        return this->back;
    else
        return NULL;
}

/*****************************************************************************************
 ** Function: getLEFT()
 ** Description: if not null, returns the pointer to the Space
 *               instance pointed to by the left pointer
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances left pointer
 ****************************************************************************************/
Space* Space::getLEFT() {
    if (this->left != NULL)
        return this->left;
    else
        return NULL;
}

/*****************************************************************************************
 ** Function: getRIGHT()
 ** Description: if not null, returns the pointer to the Space
 *               instance pointed to by the right pointer
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances right pointer
 ****************************************************************************************/
Space* Space::getRIGHT() {
    if (this->right != NULL)
        return this->right;
    else
        return NULL;
}

/*****************************************************************************************
 ** Function: getDOWN()
 ** Description: if not null, returns the pointer to the Space
 *               instance pointed to by the down pointer
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances down pointer
 ****************************************************************************************/
Space* Space::getDOWN() {
    if (this->down != NULL)
        return this->down;
    else
        return NULL;
}

/*****************************************************************************************
 ** Function: getCanGo()
 ** Description: returns the Space instances canGo bool
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances canGo bool value
 ****************************************************************************************/
bool Space::getCanGo() {
    return this->canGo;
}

/*****************************************************************************************
 ** Function: getSpaceType()
 ** Description: returns the Space instances name (class type) as a string
 ** Parameters: none
 ** Pre-Conditions: a Space instance
 ** Post-Conditions: returns the instances spaceName (string)
 ****************************************************************************************/
string Space::getSpaceType() {
    return this->spaceName;
}





