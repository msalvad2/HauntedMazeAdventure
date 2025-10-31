//Miguel Salvador | Program #1 | October 8, 2025
#include "obstacle.h"
#include "list.h"
#include <iostream>

int main() {
/*    
    try {
    Obstacle obstacle1("", {1,2,4}, -1);
    Obstacle obstacle2("Alien", {1,2,3}, 3);
    obstacle2 = obstacle2;
    
    cout << obstacle2 << endl;
    }catch(const invalid_argument & e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    catch(const out_of_range & e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
 */
    //This is a class inside the random library that lets us create a random generator
    random_device random_seed;
    mt19937 random_generator;
    
    //I will seed it with 123 so that it produces the same random sequences
    random_generator.seed(random_seed());

    cout << "hello!" << endl;  
    Teen_obstacle e( "apple", {1,2,3}, 2 ,"one! ", 2, {"zero","one", "two"}, 1);
    
    //e.beginning();
    //e.move(random_generator);

    Adult_obstacle f( "apple", {1,2,3}, 2 ,2, 100, 1);
    f.beginning();
    f.move(random_generator);


    Obstacle a( "apple", {1,2,3}, 2);
    Obstacle b( "bike", {1,2,3}, 3);
    Adult_obstacle c( "apple", {1,2,3}, 2 ,2, 100, 1);
    Adult_obstacle d( "candy", {1,2,3}, 2 , 2, 300, 2);
    Adult_obstacle z;    
    
    
/*
try{    
    Obstacle a;
    cout << "Name: Diff1 Diff2 Diff3 curr: " << endl;
    cin >> a;
    cout << a;
}catch (const invalid_argument & e) {
    cerr << e.what() << endl;
}
catch(const out_of_range & e) {
    cerr << e.what() << endl;
}
*/
    return 0;
}
