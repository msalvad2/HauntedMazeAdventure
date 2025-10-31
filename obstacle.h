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
#include <array>
#include <random>

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

    protected:
    char * name;

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
    int  move(mt19937 & random_generator); 

    //operator overloading function
    //cout function
    friend ostream & operator<<(ostream & O, const Kid_obstacle & op1);
    //cin function
    friend istream & operator>>(istream & I, Kid_obstacle & op1);


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
    Teen_obstacle(const string & name, const list<int> & difficulties , int current_difficulty,
            const string & riddle, int scare_level, const array<string, 3>& choices, int answer);
    //Destructor;
    ~Teen_obstacle();

    //This will start of the maze by scarying the teen 
    bool beginning();
    
    //this will ask the user a riddle and move based on that amount
    int move( mt19937 & random_generator); 

    //operator overloading function
    //cout << function
    friend ostream & operator<<(ostream & O, const Teen_obstacle & op1);
    //cin >> function
    friend istream & operator>>(istream & I, Teen_obstacle & op1);
    

    private:
    
    //During every obstacle will give the teen a riddle
    //riddle displayed for user to anwser
    string riddle;
    //For every obstacle will give short message based on int
    int scare_level;
    //options available to choose from
    array <string, 3> choices;
    //Holds the index to the right ansswer
    int answer;

};


class Adult_obstacle :public Obstacle{

    public:
    Adult_obstacle();
    Adult_obstacle(const string &  name, const list<int> & difficulties, int current_difficulty,
                   int age_req, int candy_price, int jackpot);
    
    ~Adult_obstacle();
    
    //This will start by verifying your age to see if old enough to participate
    bool beginning();
    
    //This will give the option to go safe and move normally or gamble and win big or lose big
    int  move( mt19937 & random_generator);

    //operator overloading function
    //cout << function
    friend ostream & operator<<(ostream & O, const Adult_obstacle & op1);
    //cin >> function
    friend istream & operator>>(istream & I, Adult_obstacle & op1);

    private:
    //must be a certain age to enter maze
    int age_req;
    //price to gamble and win more steps
    int candy_price;
    //This is how many steps you get if you win
    int jackpot;    
};
