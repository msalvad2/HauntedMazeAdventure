//Miguel Salvador | Program #1 | October 22, 2025
#include "obstacle.h"

//Base
//Default constructor
Obstacle::Obstacle(): name(nullptr), difficulties{1,2,3}, current_difficulty(1)
{}
//The destructor
Obstacle::~Obstacle() {
    
    delete[] name;
    difficulties = {};
    current_difficulty = 0;



}
//This is the coppy constructor
Obstacle::Obstacle(const Obstacle & a_obstacle) :
name(nullptr), difficulties(a_obstacle.difficulties), current_difficulty(a_obstacle.current_difficulty) {
   

    name = new char[strlen(a_obstacle.name) + 1];
    strcpy(name,a_obstacle.name);
   

}
//This is the argument constructor
Obstacle::Obstacle( const string &  a_name, const list<int> & the_difficulties, int a_difficulty) :
name(nullptr), difficulties(the_difficulties), current_difficulty(a_difficulty){
    
    if(a_name.empty())
        throw invalid_argument("Name can't be a empty! ");
    if(the_difficulties.empty())
        throw invalid_argument("List difficulty cannot be empty!");


    for(int num: the_difficulties) {
        if(num >3 || num < 1)
            throw out_of_range("List has out of range values! Must be between 1-3 ");

    }
    if(a_difficulty > 3 || a_difficulty < 1)
        throw out_of_range("The difficulty mode is out of range! Must be between 1-3 ");


    name = new char[a_name.size() + 1];
    strcpy(name,a_name.c_str());
    
    difficulties = the_difficulties;
    current_difficulty = a_difficulty;

}
//Assignment operator
Obstacle& Obstacle::operator=(const Obstacle & a_obstacle) {

    //check for self assignment
    if(this == &a_obstacle)
        return *this;
    //Copy everything into a temp pointer incase you get bad_alloc (run out of memory) before you delete
    //Because if you delete first and get bad_alloc you will have lost your daata
    char *temp_name = nullptr;
    if(a_obstacle.name) {
        temp_name = new char[strlen(a_obstacle.name) + 1];
        strcpy(temp_name, a_obstacle.name);
    }
    //delete data after allocation success
    if(name)
        delete[] name;
    //set data = to temp
    name = temp_name;

    difficulties = a_obstacle.difficulties;
    current_difficulty = a_obstacle.current_difficulty;

    return *this;

}

ostream & operator<<(ostream & O,const Obstacle & a_obstacle) {
    
        O << "Name: " << a_obstacle.name << endl;

        O << "Difficulties: ";

        for(int number: a_obstacle.difficulties) {
            O << number << ", ";
            }
        O << endl;

        O << "Current Difficulty: " << a_obstacle.current_difficulty << endl;

        return O;
}
//this will cin into the objects data members
istream & operator>>(istream & I, Obstacle & op1) {
   //The I function now contains the data the user provided in main.cpp
   //Now our goal is to set the locals data to that
   //istream I will have Name Difficulties Current_difficulties
    
    //Create temps to first what the input buffer has before setting it to the objects member
    //incase bad input was given
    string name;
    int diff1  = 0;
    int diff2 = 0;
    int diff3 = 0;
    int curr = 0;
    
    //This will set the temp variables equal to the input buffer
    // example input buffer containds:
    //using get line will read an entire line instead of just a word until it encounters a space
    getline(I >> ws, name); //the I >> ws ignores any white space until next non-whitespace char
    //1 2 3 2 // first 3 numbers = difficulty list Last num = current difficulty
    I >> diff1 >> diff2 >> diff3 >> curr;
    //name = bob diff1 = 1 diff2 = 2 diff3 = 3 curr = 2
    I.ignore(100, '\n');    

    if(name == "")
        throw invalid_argument("Can't Pass empty string  name" );

    if(diff1 > 3 || diff1< 1)
        throw invalid_argument("List has to contain data between 1-3");
    if(diff2 > 3 || diff2< 1)
        throw invalid_argument("List has to contain data between 1-3");
    if(diff3 > 3 || diff3< 1)
        throw invalid_argument("List has to contain data between 1-3");
    if(curr > 3 || curr< 1)
        throw invalid_argument("Current Difficulty has to contain data between 1-3");
    
    //first allocate with a temp pointer before deleting so that you don't risk losing memory
    //incase you get bad_alloc
    char *temp_name = new char[name.size() + 1];
    strcpy(temp_name, name.c_str());
    
    //Then you can delete the data after successfulling dynamic allocation
    delete [] op1.name;

    //Now set the variable equal to the temp pointer
    op1.name = temp_name;


    //This doesn't work because it's a list of ints so loop
    //I >> op1.difficulties;
    
    //First clear the current list of op1
    op1.difficulties.clear();
    //Set the elements
    op1.difficulties.push_back(diff1);
    op1.difficulties.push_back(diff2);
    op1.difficulties.push_back(diff3);
    
    //sets the current objects difficulty to the curr which is a temp variable
    op1.current_difficulty = curr;
    
    return I;
}
//This operator will strictlly check if there are matching names
bool operator==(const Obstacle & op1, const Obstacle & op2) {
    
    //if(!op1.name || !op2.name) {
        //throw logic_error("Cannot compare Nullptrs");
    //}
    if(strcmp(op1.name, op2.name) == 0)
        return true;
    return false;
}
//This operator will return true if they don't match
bool operator!=(const Obstacle & op1, const Obstacle & op2) {
   //if??(!op1.name || !op2.name)
       //throw logic_error("Cannot compare Nullptrs");

   if(strcmp(op1.name, op2.name) != 0)
       return true;
    return false;
}
//This operator compares a string name to an object.name return true if match
bool operator==(const string & name, const Obstacle & op1) {
    //if(name == "" || !op1.name)
        //throw logic_error("Can't compare empty string or nullptr name" );

    if(strcmp(name.c_str(), op1.name) == 0)
        return true;

    return false;
}
bool operator==(const Obstacle & op1, const string & name) {
    //if(name == "" || !op1.name)
        //throw logic_error("Can't compare empty string or nullptr name" );

    if(strcmp(name.c_str(), op1.name) == 0)
        return true;

    return false;
}
bool operator!=(const Obstacle & op1, const string & name) {
    //if(!op1.name || name == "")
     //   throw logic_error("Can compare empty string or nullptr name");
    if(strcmp(op1.name, name.c_str()) != 0)
        return true;
    return false;
}
bool operator!=(const string & name, const Obstacle & op1) {
    //`if(!op1.name || name == "")
      //  throw logic_error("Can compare empty string or nullptr name");
    if(strcmp(op1.name, name.c_str()) != 0)
        return true;
    return false;

}

bool operator<(const Obstacle & op1, const Obstacle & op2) {
    if(strcmp(op1.name, op2.name) < 0)
        return true;

    return false;
}

bool operator>(const Obstacle & op1, const Obstacle & op2) {
    
    return strcmp(op1.name, op2.name) > 0;
}
//This function will see if op <= op2 and if so will return true
bool operator<=(const Obstacle & op1, const Obstacle & op2) {
        
    return strcmp(op1.name, op2.name) <= 0;
}
//this operator will see if op1 >= op2 if so will return true
bool operator>=(const Obstacle & op1, const Obstacle & op2) {
    
    return strcmp(op1.name, op2.name) >= 0;
}
//This operator will check to see if op1.name is less than name if so returns true
bool operator<(const Obstacle & op1, const string & name) {

    return strcmp(op1.name, name.c_str()) < 0;
}
//This operator returns true if name < op1 in that order
bool operator<(const string & name, const Obstacle & op1) {
    
    return strcmp(name.c_str(), op1.name) < 0;
}
//This is a secondary comparison so you can call the primary inside
//This functin compares op1 > name 
bool operator>(const Obstacle & op1, const string & name) {

   return strcmp(op1.name, name.c_str()) > 0;
}
bool operator>(const string & name, const Obstacle & op1 ) {
    
    return strcmp(name.c_str(), op1.name) > 0;
}
bool operator<=(const Obstacle & op1, const string & name) {
    
    return strcmp(op1.name, name.c_str()) <= 0;
}
bool operator<=(const string & name, const Obstacle & op1) {
    
    return strcmp(name.c_str(), op1.name) <=0;
}
bool operator>=(const Obstacle & op1, const string & name) {
    
    return strcmp(op1.name, name.c_str()) >= 0;

}
bool operator>=(const string & name, const Obstacle & op2) {
    
    return strcmp(name.c_str(), op2.name) >= 0;
}
//This function will allow user to say object += num
//will add one to the difficulty level
Obstacle& Obstacle::operator+=(int num) {
    //difficulty can at most be 3 
    if(current_difficulty >=3)
        throw logic_error("The difficulty is max cannot increase it");
    if(num != 1)
        throw out_of_range("You can only increase the level by one");
    
    //current_difficulty = current_difficulty + 1;
    current_difficulty += num;

    return *this;
}
//This operator will modify itself to make it less difficult level by one
Obstacle& Obstacle::operator-=(int num) {
    
    if(current_difficulty <= 1)
        throw logic_error("Difficulty is at Mininum cannot decrease it");
    if(num != 1)
        throw out_of_range("Cannot decrease difficulty by more than one");

    current_difficulty -= num;
    return *this;
}
//This will return a modified temp version and you will catch it in main with a
//new version
Obstacle operator+( const Obstacle & op1, int num) {

    if(op1.current_difficulty >= 3)
        throw logic_error("Difficulty is max cannot increase it");

    if(num != 1)
        throw out_of_range("Cannot increase difficulty by more than 1 at once");

    //This calls the copy constructor
    Obstacle result = op1;
    result.current_difficulty +=num;
    
    return result;
}
//This does the same as the previous operator +
//They both are essentially just recreating the same obstacle but making it a bit hard by
//increasing the level
Obstacle operator+( int num, const Obstacle & op1) {
    
    //This will call the other +operator so we don't have to rewrite code
    return op1 + num;
}
Obstacle operator-(const Obstacle & op1, int num) {
    
    if(op1.current_difficulty <= 1)
        throw logic_error("Difficulty is at Mininum cannot decrease it");
    if(num != 1)
        throw out_of_range("Cannot decrease difficulty by more than one");

    Obstacle result = op1;
    result.current_difficulty -= num;

    return result;
}
Obstacle operator-( int num, const Obstacle & op1) {
    
    return op1 - num;
}















































