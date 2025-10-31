//Miguel Salvador | Program #1 | October 22, 2025

#include "obstacle.h"

//default constructor
Teen_obstacle::Teen_obstacle(): Obstacle(), riddle(""), scare_level(0), choices{}, answer(0) {
    
}
//Argument constructor
Teen_obstacle::Teen_obstacle(const string & name, const list<int> & difficulties , 
                        int current_difficulty, const string & riddle, int scare_level,
                        const array<string, 3> & choices, int answer) :
                        Obstacle(name, difficulties, current_difficulty), riddle(riddle),
                        scare_level(scare_level), choices(choices), answer(answer) {
    
    //This will loop through the list choices and check to see if every element is not empty
    //if it is empty it will throw invaldi_argument
    for(string index: choices) {
        if(index.empty())
            throw invalid_argument("Cannot insert an empty string ");
    }

    //answer will be used to access index so it must be between 0-2
    if(answer < 0 || answer > 2)
        throw out_of_range("Answer must be between 0-2");

}
//Destructor;
Teen_obstacle::~Teen_obstacle() {
    scare_level = 0;
    riddle = "";
    choices = {};
    answer = 0;

}

//cout << function
ostream & operator<<(ostream & O, const Teen_obstacle & op1) {
    
    //call the bases operator<<

    O << static_cast< const Obstacle& >(op1);

    //display local variables
    O << "Riddle: " << op1.riddle << endl;

    O << "Scare Level: " << op1.scare_level << endl;
    
    O << "List: ";
    
    //Ranged based for loop to print every index
    for(string index: op1.choices) {
        O << index << ", ";
    }
    O << endl;

    O << "Answer: " << op1.answer << ".)" << op1.choices[op1.answer] << endl;

    return O;

}
//cin >> function
istream & operator>>(istream & I, Teen_obstacle & op1) {
    
    //Call the base istream
    I >> static_cast<Obstacle&>(op1);

    //istream I has the info that the user put in the input buffer
    //store it into temp variables then check for verification
    string temp_riddle;
    int scare_level;
    string choice1;
    string choice2;
    string choice3;
    int temp_answer;

    //This will read in the first line and ignore any initial white space 
    getline(I >> ws, temp_riddle);
    
    I >> scare_level;
    I.ignore(100, '\n');

    getline(I >> ws, choice1);
    getline(I >> ws, choice2);
    getline(I >> ws, choice3);
    
    I >> temp_answer;

    if(temp_riddle.empty() || choice1.empty() || choice2.empty() || choice3.empty())
        throw invalid_argument("String cannot be empty!");
    
    if(temp_answer < 0 || temp_answer > 2)
        throw out_of_range("Answer must be between 0-2");
    
    //copy data over
    op1.riddle = temp_riddle;
    op1.scare_level = scare_level;
    
    op1.choices[0] = choice1;    
    op1.choices[1] = choice2;    
    op1.choices[2] = choice3;    

    op1.answer = temp_answer;
    
    return I;
}


bool Teen_obstacle::beginning() {
    cout << "This is the Teens Obstacle Maze!" << endl;
    cout << "Turn back before you regret it!" << endl;
    cout << "Scary rating: " << scare_level << endl;

    cout << "I warned you now its TOO LATE! " << endl;

    cout <<"___________________________________________________________________________" << endl;
    return true;
}

int Teen_obstacle::move( mt19937 & random_generator) {
    //how much the user gets to move on ahead
    int move{0};

    char choice;

    cout << "Welcome to your nightmare!" << endl;
    
    cout << "My name is: " << name << endl;

    cout << "Would You like to play a game(y/n): " << endl;
    
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    if(toupper(choice) == 'Y') {
        //get size of array
        int size = choices.size();
        int response{0};

        cout << riddle << endl;

        for(int i =0; i < size; ++i) {
            cout << i << "). " << choices[i] << " ";
        }
        cout << endl << "Choice: ";
        cin >> response;
        cin.ignore(100, '\n');

        //answer holds the number to the correct index!
        if(response == answer) {
            cout << "Congrats! You get to move: 3 time forward"  << endl;
            move = 3;

        }
        else {
            cout << "ERRR!! WRONG!! Move 2 obstacle back!" << endl;
            move = -2;
        }
    }
    else {

        uniform_int_distribution<int> range_needed(0,1); //this will set the min and max
        //puting random_generator inside get us the random number! 
        int answer = range_needed(random_generator);

        if(answer == 1 ) {
            cout << "Move 1 obstacle forward! " << endl;
            move = 1;
        }
        else {
            cout << "Move 1 obstacle backwards! " << endl;
            move = -1;
        }
        
    }
    
    return move;
}




