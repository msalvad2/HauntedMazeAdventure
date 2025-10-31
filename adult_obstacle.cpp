//Miguel Salvador | Program #1 | October 22, 2025

#include "obstacle.h"


Adult_obstacle::Adult_obstacle() : Obstacle(), age_req(0), candy_price(0), jackpot(0)
{}


Adult_obstacle::Adult_obstacle(const string &  name, const list<int> &difficulties, int current_difficulty,
                   int age_req, int candy_price, int jackpot) : Obstacle(name,difficulties,current_difficulty),
                   age_req(age_req), candy_price(candy_price), jackpot(jackpot) {

    if(jackpot > 3)
        throw out_of_range("Jackpot cannot exceed 3!");


}
    
Adult_obstacle::~Adult_obstacle() {
    
    age_req = 0;
    candy_price = 0;
    jackpot = 0;
}
//operator overloading function
//cout << function
ostream & operator<<(ostream & O, const Adult_obstacle & op1) {
    
    //Call the bases operator <<
    O << static_cast<const Obstacle&>(op1);
    
    O << "Age Requirement: " << op1.age_req << endl;
    O << "Candy Price to Gamble: " << op1.candy_price << endl;
    O << "Jackpot: " << op1.jackpot << endl;

    
    return O;
}
//cin >> function
istream & operator>>(istream & I, Adult_obstacle & op1) {
    
    //call the base operator >>
    I >> static_cast<Obstacle&>(op1);

    //store variables in a temp first for safety
    int temp_age{0};
    int temp_price{0};
    int temp_jackpot{0};
    //This will read in from the buffer, for example the input
    // buffer may have (21 5 2) so age=21 price=5 jackpot = 2
    I >>temp_age >> temp_price >> temp_jackpot;
    I.ignore(100, '\n');

    if(temp_age <= 0)
        throw out_of_range("Please give your real age!");
    if(temp_jackpot > 3)
        throw out_of_range("Please set jackpot 3 or under!");
    
    op1.age_req = temp_age;
    op1.candy_price = temp_price;
    op1.jackpot = temp_jackpot;

    
    return I;
}


//This will start by verifying your age to see if old enough to participate
bool Adult_obstacle::beginning() {

    int player_age{0}; 

    cout << "Enter Age: ";
    cin >> player_age;
    cin.ignore(100, '\n');

    if(player_age < age_req) {
        cout << "Sorry! You must be at " <<age_req << " or older to enter!" << endl;
        return false;
    }

    cout << "Welcome to the Adult Obstacle Maze" << endl;
    cout << "You may or may not make it out alive" << endl;
    cout <<"___________________________________________________________________________" << endl;

    return true;

}
//This will give the option to go safe and move normally or gamble and win big or lose big
int  Adult_obstacle::move( mt19937 & random_generator) {
    
    char choice;
    int move{0};

    cout << "Welcome to my game!" << endl;
    cout << "My name is: " << name << endl;

    cout << "Would You like to gamble for a chance to move further ahead!(y/n): " << endl;
    cout << "Price to pay: " << candy_price << " candies! " << endl;

    cout << "Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    //This will commence the blackjack game
    if(toupper(choice) == 'Y') {

        //will set the min and max to 1 and 10
        uniform_int_distribution<int> blackjack(1,10);
        int user_sum{0};
        int obstacle_sum{0};

        int play{0};

        cout << "We will play blackjack! " << endl;
        cout << "Rules: " << endl;
        cout << "1).You will go first then I will" <<endl;
        cout << "2). Hit = another card | Stand = End turn " << endl;
        cout << "3). Availabe cards 1-10. No Ace or Face Cards! " << endl;
        cout << "4.) Goal is to get as close as 21 without going over! " << endl;

        cout << "GOOD LUCK! You're gonna need it ! MWUAAHAAHHAHAHHA! " << endl;
    
        //this will get the users score

        do {
            //this will store a random num from 1-10 
           int card = blackjack(random_generator);
           //add the users score
           user_sum += card;
           cout << "Your card is: " << card << " and total: " << user_sum << endl;
           cout << "1.) Hit | 2.Stand " << endl;
           cin >> play;
           cin.ignore(100, '\n');


        }while(play != 2 && user_sum < 21);
            
        while( obstacle_sum < 17) {
            
            int card2 = blackjack(random_generator);
            obstacle_sum += card2;

            cout << "I will hit! " << endl;
            cout << "Card I got: " << card2 << "| My total: " << obstacle_sum << endl;
        }
        cout << "I will Stand! " << endl;
       
        if(obstacle_sum > 21 && user_sum > 21) {
            cout << "WE BOTH WENT OVER 21! ";
            if(obstacle_sum < user_sum) {
                cout << "Loser am closer to 21 so I win! you move 1 osbtacle backwards! " << endl;
                move = -1;
            }
            else if(obstacle_sum > user_sum) {
                cout << "We both went over but you're closer to 21" << endl;
                cout << "Bummer here is your price: " << jackpot << endl;
                move = jackpot;
            }
            else {
                cout << "We Both Went over and tied" << endl;
                cout << "Since I'm feeling happy I'll let you move one forward " << endl;
                move = 1;

            }

        }
        else if(obstacle_sum > 21 || user_sum > 21) {
            //means I went over 21
            if(obstacle_sum > 21) {
                cout << "YOU win! Price: " << jackpot << endl;
                move = jackpot;

            }
            //means user went over 21
            else {
                cout << "YOU LOSE! You get to move one obstacle backwards! " << endl;
                move = -1;

            }



        }
        else {
            if(obstacle_sum > user_sum) {
                 cout << "Loser I win! you move 1 osbtacle backwards! " << endl;
                move = -1;
            }
            else if(obstacle_sum < user_sum) {
                cout << "You win!" << endl;
                cout << "Bummer here is your price: " << jackpot << endl;
                move = jackpot;
            }
            else {
                cout << "We Both tied!" << endl;
                cout << "Since I'm feeling happy I'll let you move one forward " << endl;
                move = 1;



        }
        }

        return move;

    }
    //otherwise will have 50/50 to move forward or backwards
    else {
        uniform_int_distribution<int> range_needed(0,1); //this will set the min and max
        //puting random_generator inside get us the random number! 
        int answer = range_needed(random_generator);

        if(answer == 1 ) {
            cout << "Move 1 obstacle forward! " << endl;
            move = 1;
        }
        else {
            cout << "Move 2 obstacle backwards! " << endl;
            move = -2;
        }
        

    }
   
   return move;
}
