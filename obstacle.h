//Miguel Salvador | Program #1 | October 22, 2025
//This file declare the core hierarchy including the base: obstacle and Children: child,teen,adult

#pragma once

#include <iosfwd>
#include <cstdlib> //random
#include <cstring>
#include <cctype>
#include <string>
#include <list>
#include <ostream>
#include <iostream>
#include <stdexcept>

using namespace std;

class Obstacle {
    
    public:
    Obstacle();
    ~Obstacle();
    Obstacle(const Obstacle & a_obstacle);
    Obstacle( const string &  a_name, const list<int> & the_difficulties, int a_difficulty);
    Obstacle& operator=(const Obstacle & a_obstacle);

    //Operator Overloading

    //diplay output cout function
    friend ostream & operator<<(ostream & O,const Obstacle & a_obstacle);
    //cin function
    friend istream & operator>>(istream & I, Obstacle & a_obstacle);
    //Compare function
    friend bool operator==(const Obstacle & op1, const Obstacle & op2);
    friend bool operator!=(const Obstacle & op1, const Obstacle & op2);

    friend bool operator==(const string & name, const Obstacle & op1);
    friend bool operator==(const Obstacle & op1, const string & name);

    friend bool operator!=(const Obstacle & op1, const string & name);
    friend bool operator!=(const string & name,const Obstacle & op1);


    friend bool operator<(const Obstacle & op1, const Obstacle & op2);
    friend bool operator<(const Obstacle & op1, const string & name);
    friend bool operator<(const string & name, const Obstacle & op1);

    friend bool operator>(const Obstacle & op1, const Obstacle & op2);
    friend bool operator>(const Obstacle & op1, const string & name); 
    friend bool operator>(const string & name, const Obstacle & op1 ); 

    friend bool operator<=(const Obstacle & op1, const Obstacle & op2);
    friend bool operator<=(const Obstacle & op1, const string & name);
    friend bool operator<=(const string & name, const Obstacle & op1);

    friend bool operator>=(const Obstacle & op1, const Obstacle & op2);
    friend bool operator>=(const Obstacle & op1, const string & name);
    friend bool operator>=(const string & name, const Obstacle & op2);

    Obstacle& operator+=(int num);  
    Obstacle& operator-=(int num);

    friend Obstacle operator+( const Obstacle & op1, int num);
    friend Obstacle operator+( int num, const Obstacle & op1);
    friend Obstacle operator-(const Obstacle & op1, int num);
    friend Obstacle operator-( int num, const Obstacle & op1);

    private:
    char * name;

    protected:
    list <int> difficulties;
    int current_difficulty;


};


class Kid_obstacle : public Obstacle{

    public:
    Kid_obstacle();
    ~Kid_obstacle();
    Kid_obstacle(const string &  name, const list<int> & difficulties, int current_difficulty,
                const string &  motivation, int reward, int bonus);
    Kid_obstacle(const Kid_obstacle & Kid_obst);
    Kid_obstacle& operator=(const Kid_obstacle & kid_obst);
    
    //This  will start the maze by by giving motivation to the kid
    bool beginning();
    //This will give the kid candy and return an int which is how much you should move
    int  move(); 

    //operator overloading function
    //cout function
    friend ostream & operator<<(ostream & O, const Kid_obstacle & op1);
    //cin function
    friend istream & operator>>(istream & I, const Kid_obstacle & op1);


    private:
    //Will motivated the kid
    char *motivation;
    //Candies given to kids
    int reward;
    //int bonus based on difficulty, will let kid move forward a certain #
    int bonus;

};

class Teen_obstacle : public Obstacle{
    
    public:
    //default constructor
    Teen_obstacle();
    //Argument constructor
    Teen_obstacle(const string & a_name, const string & a_message, int a_level,
                  int luck, int riddle_reward, int streak);
    //Destructor;
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
    

    private:
    
    //For every obstacle will give short message based on int
    int scare_level;
    //During every obstacle will give the teen a riddle
    //riddle will be a simple math question
    string riddle;
    //If teen gets riddle right then user gets reward
    int riddle_reward;

};


class Adult_obstacle :public Obstacle{

    public:
    Adult_obstacle();
    Adult_obstacle(const string &  a_name, const string & a_message, int a_level,
                   int a_age_req, int candy_price);
    ~Adult_obstacle();
    
    //This will start by verifying your age to see if old enough to participate
    bool beginning();
    
    //This will give the option to go safe and move normally or gamble and win big or lose big
    int  move();


    private:
    //must be a certain age to enter maze
    int age_req;
    //price to gamble and win more steps
    int candy_price;
    //This is how many steps you get if you win
    int jackpot;    
};
