//
//Miguel Salvador | Program #1 | October 22, 2025

#include "obstacle.h"

//Default constructor
Kid_obstacle::Kid_obstacle() : Obstacle(), motivation(nullptr), reward(0),bonus(0) 
{}
//Destructor
Kid_obstacle::~Kid_obstacle() {
    
    delete [] motivation;
    motivation = nullptr;
    reward = 0;
    bonus = 0;
}
//Argument Constructor
Kid_obstacle::Kid_obstacle(const string &  name, const list<int> & difficulties, int current_difficulty,
            const string & motivation, int reward, int bonus) :
            Obstacle(name, difficulties, current_difficulty),
            motivation(nullptr), reward(reward), bonus(bonus) {
            //in the initilization list the outside is the local member and the inside variable
            //is the argument passed in (e.g   local(argument) = reward(reward)
            //which is why we can name them the same

    if(motivation.empty())
        throw invalid_argument("Cannot pass in empty string as argument");

    this->motivation = new char[motivation.size() + 1];
    strcmp(this->motivation, motivation.c_str());
}

//
Kid_obstacle::Kid_obstacle(const Kid_obstacle & Kid_obst) : 
Obstacle(Kid_obst),motivation(nullptr), reward(Kid_obst.reward), bonus(Kid_obst.bonus) {
    
    if(!Kid_obst.motivation)
        throw invalid_argument("Motivation cannot be nullptr");

    motivation = new char[strlen(Kid_obst.motivation) + 1];
    strcpy(motivation, Kid_obst.motivation);
}
//
Kid_obstacle& Kid_obstacle:: operator=(const Kid_obstacle & kid_obst) {
    
   //checks to see if both memory addresses are the same
   //if so then returns this
    if(this == &kid_obst)
        return *this;
    
    //calls the bases assignment operator
    Obstacle::operator=(kid_obst);

    //creates dynamic memory with a temp pointer incase of bad_alloc
    
    char* temp_motivation = nullptr;

    if(kid_obst.motivation) {
        temp_motivation = new char[strlen(kid_obst.motivation) + 1];
        strcpy(temp_motivation, kid_obst.motivation);
    }
    //after successfuly allocating memory you can delete the old memory

    delete [] motivation;

    //copy data from old object to the new object
    motivation = temp_motivation;
    reward = kid_obst.reward;
    bonus = kid_obst.bonus;
    
    //return *this since passed by reference
    return *this;
}
