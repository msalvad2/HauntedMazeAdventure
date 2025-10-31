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
    strcpy(this->motivation, motivation.c_str());
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


//cout << function
ostream & operator<<(ostream & O, const Kid_obstacle & op1) {
   
   //static_cast<base&>(op1) lets the compiler treat is as const base&(parent class)
   //then it finds the operator << for it since said O<< before it
   O << static_cast< const Obstacle &>(op1); 

   //display local members
   O << "Motivation: " << op1.motivation << endl;
   O << "Reward: " << op1.reward << endl;
   O << "Bonus: " << op1.bonus << endl;

   return O;
}
//cin >> function
istream & operator>>(istream & I, Kid_obstacle & op1) {
    
    //call the bases operator >>
    I >> static_cast< Obstacle&>(op1);
    //Istream I holds the input the user typed store it in temp varibles for safety
    string temp_motivation;
    int temp_reward;
    int temp_bonus;
    //will read in the first line of the buffer, ws makes it so it ignores inital white space 
    getline(I >> ws, temp_motivation);
    
    //This reads in the the next two words in the buffer
    // (e.g 10 5 so temp_reward = 10 and temp_bonus = 5)
    I >> temp_reward >> temp_bonus;
    
    //ignores any left over, instead of cin use the istream variable name e.g I
    I.ignore(100, '\n');

    //time for exception handling to shine
    if(temp_motivation.empty())
        throw invalid_argument("Motivation cannot be empty");

    if(temp_bonus > 3 || temp_bonus < 1)
        throw out_of_range("Bonus must be between 1-3");
    
    //perform deep copy
    op1.motivation = new char[temp_motivation.size() + 1];
    strcpy(op1.motivation, temp_motivation.c_str());
    //perform shallow copies
    
    op1.reward = temp_reward;
    op1.bonus = temp_bonus;

    return I;
}

//This  will start the maze by by giving motivation to the kid
bool Kid_obstacle::beginning() {
    int choice;
    cout << "Welcome the Kids obstacle maze!" << endl;

    cout << motivation << endl;
    cout <<"To enter press 1" << endl;
    cin >> choice;
    cin.ignore(100, '\n');

    if(choice != 1)
        return false;

    return true;
}

//This will give the kid candy and return an int which is how much you should move
int  Kid_obstacle::move( mt19937 & random_generator) {
    
    //This will create the min and max of the random number generator
    int move = current_difficulty;
    char choice;

    cout << "Welcome to my place!" << endl;
    cout << "My name is: " << name << endl;
    cout << "You get : " << reward << " candies for being awesome!" << endl;
    
    cout << "Do you want to play a game? y/n" << endl;
    cout << "Answer: " << endl;
    cin >> choice;
    cin.ignore(100, '\n');
    
    if(toupper(choice) == 'Y') {
        int response{0};
        uniform_int_distribution<int> range_needed(1,3); //this will set the min and max
        //puting random_generator inside get us the random number! 
        int answer = range_needed(random_generator);

        cout << "I am thinking of a number from 1-3. If you get it right you win candy! " << endl;
        cout << "Awnser: ";
        cin >> response;
        cin.ignore(100, '\n');

        if(response > 3 || response < 1)
            throw out_of_range("Please enter a number between 1-3");


        if(response == answer)
            cout << "Congrats you won " << bonus << " candies!";
        else
            cout << "Sorry the number I was thinking was: " << answer << endl;
 
    }
    
    cout << " You get to move: " << move << endl;
    
    cout << "Good Luck on your journey! " << endl;
    cout <<"___________________________________________________________________________" << endl;
    return move;
}










