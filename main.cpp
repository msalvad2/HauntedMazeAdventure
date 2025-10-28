//Miguel Salvador | Program #1 | October 8, 2025
#include "obstacle.h"
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
    cout << "hello!" << endl;  

    Obstacle a( "apple", {1,2,3}, 2);
    Obstacle b( "bike", {1,2,3}, 3);
    Obstacle c( "apple", {1,2,3}, 2);
    Obstacle d( "dog", {1,2,3}, 2);

    
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
