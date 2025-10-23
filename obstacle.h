//Miguel Salvador | Program #1 | October 22, 2025
//This file declare the core hierarchy including the base: obstacle and Children: child,teen,adult

#pragma once

#include <iosfwd>
#include <cstdlib> //random
#include <cstring>
#include <string>
using namespace std;

class Obstacle {
    
    public:
    Obstacle();
    ~Obstacle();
    Obstacle(const Obstacle & a_obstacle);
    Obstacle( char* a_name, const string & a_message, int a_level);
    Obstacle& operator=(const Obstacle & a_obstacle);

    //Operator Overloading

    //diplay output cout function
    friend ostream & operator<<(ostream & O,const Obstacle & a_obstacle);
    //cin function
    friend istream & operator>>(ostream & I, const Obstacle & a_obstacle);
    //Compare function
    friend bool operator==(const Obstacle & op1, const Obstacle & op2);
    friend bool operator!=(const Obstacle & op1, const Obstacle & op2);
    friend bool operator<(const Obstacle & op1, const Obstacle & op2);
    friend bool operator>(const Obstacle & op1, const Obstacle & op2);
    friend bool operator<=(const Obstacle & op1, const Obstacle & op2);
    friend bool operator>=(const Obstacle & op1, const Obstacle & op2);

    private:
    char * name;
    string message;
    int level[3];


};


class Kid_obstacle {

    public:
    Kid_obstacle();
    ~Kid_obstacle();
    Kid_obstacle(char* a_name, const string & a_message, int a_level,
                char * a_motivation, int a_reward);
    Kid_obstacle(const Kid_obstacle & a_Kid_obstacle);
    Kid_obstacle& operator=(const Kid_obstacle & a_Kid_obstacle);
    
    //This  will start the maze by by giving motivation to the kid
    bool beginning();
    //This will give the kid candy and return an int which is how much you should move
    int  move(); 

    //operator overloading function
    //cout function
    friend ostream & operator<<(ostream & O, const Kid_obstacle & op1);
    //cin function
    friend istream & operator>>(istream & I, const Kid_obstacle & op1);

    //Compare function
    friend bool operator==(const Kid_obstacle & op1, const Kid_obstacle & op2);
    friend bool operator!=(const Kid_obstacle & op1, const Kid_obstacle & op2);
    friend bool operator<(const Kid_obstacle & op1, const Kid_obstacle & op2);
    friend bool operator>(const Kid_obstacle & op1, const Kid_obstacle & op2);
    friend bool operator<=(const Kid_obstacle & op1, const Kid_obstacle & op2);
    friend bool operator>=(const Kid_obstacle & op1, const Kid_obstacle & op2);

    private:
    char *motivation;
    int reward;


};

class Teen_obstacle {
    
    public:
    Teen_obstacle();
    Teen_obstacle(char* a_name, const string & a_message, int a_level,
                  int luck, int riddle_reward, int streak);

    ~Teen_obstacle();

    //This will start of the maze by scarying the teen 
    bool beginning();
    
    //this will ask the user a riddle and move based on that amount
    int move(); 

    //operator overloading function
    //cout << function
    friend ostream & operator<<(const Teen_obstacle & op1, const Teen_obstacle & op2);
    //cin >> function
    friend istream & operator>>(const Teen_obstacle & op1, const Teen_obstacle & op2);
    
    //Compare function
    friend bool operator==(const Teen_obstacle & op1, const Teen_obstacle & op2);
    friend bool operator!=(const Teen_obstacle & op1, const Teen_obstacle & op2);
    friend bool operator<(const Teen_obstacle & op1, const Teen_obstacle & op2);
    friend bool operator>(const Teen_obstacle & op1, const Teen_obstacle & op2);
    friend bool operator<=(const Teen_obstacle & op1, const Teen_obstacle & op2);
    friend bool operator>=(const Teen_obstacle & op1, const Teen_obstacle & op2);


    private:

    int luck;
    int riddle_reward;
    int streak;

};


class Adult_obstacle {

    public:
    Adult_obstacle();
    Adult_obstacle(char* a_name, const string & a_message, int a_level,
                   int a_age_req, int candy_price);
    ~Adult_obstacle();
    
    //This will start by verifying your age to see if old enough to participate
    bool beginning();
    
    //This will give the option to go safe and move normally or gamble and win big or lose big
    int  move();


    private:
    int age_req;//must be 18 to enter
    int candy_price;


};
