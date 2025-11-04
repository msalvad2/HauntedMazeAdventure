//Miguel Salvador | Program #1 | October 8, 2025
#include "obstacle.h"
#include "list.h"
#include <iostream>


//This function will check if the number the user provided is valid
int num_check(int low, int high, int & num) {
    while(num > high || num < low) {
        cout <<"Please choose a number between " << low << " - " << high << endl;
        cout << "Choice: ";
        cin >> num;
        cin.ignore(100, '\n');
    }
    return num;
}

int main() {
    //This is a class inside the random library that lets us create a random generator
    random_device random_seed;
    mt19937 random_generator;
    uniform_int_distribution<int> range_needed(0,2); //this will set the min and max

    int size = 5;

    int choice{0};    
    cout <<"Which would you like to enter: " << endl;
    cout <<"1). Kid's Maze| 2. Teen's Maze| 3. Adult's Maze" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    num_check(1, 3, choice);

    cout << "///////////////////////////////////////////////////////////////" << endl;

    //Work with the artist
    if(choice == 1) {
        try{
            DLL<Kid_obstacle> Kid_list;
            DLL<Kid_obstacle> Kid_list2;
            //This is where we will create the obstacles. Each list will have 3 unique obstacles
            //Kid list//as difficulty increases the prizes go down
            Kid_obstacle Kid_easy( "Buzz Light Year", {1,2,3}, 1 ,"You Can Do It! - Buzz Light year` ", 5 , 3);
            Kid_obstacle Kid_medium( "Spiderman", {1,2,3}, 2 ,"With Great power come great responsibility  - Spiderman ", 4 , 2);
            Kid_obstacle Kid_hard( "Zombie", {1,2,3}, 1 ,"RAAAWWRRR - zombie ", 2 , 1);
    vector <Kid_obstacle>  options_kid;
    options_kid.push_back(Kid_easy);
    options_kid.push_back(Kid_medium);
    options_kid.push_back(Kid_hard);
            
            for(int i = 0; i < size; ++i) {
                int num = range_needed(random_generator);
                Kid_list.insert(options_kid[num]); 
            }
            for(int i = 0; i < size; ++i) {
                int num = range_needed(random_generator);
                Kid_list2.insert(options_kid[num]); 
            }
        
    Kid_list.display();
    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    Kid_list2 = Kid_list;
    Kid_list2.display();

            Kid_list.play_maze(random_generator);
        } catch(const out_of_range & e) {
            cerr << e.what() << endl;
        }
        catch(const invalid_argument & e) {
            cerr << e.what() << endl;
        }
        catch(const logic_error & e) {
            cerr << e.what() << endl;
        }
}

        /////////////////////////////////////////////////////////////////////////////////
        //Work with Merch
        else if(choice == 2) {
            try{
    //Template we created now lets us reuse it with different data types
    DLL<Teen_obstacle> Teen_list;
    //crete the 3 unique obstacles for teen
    Teen_obstacle Teen_easy( "Chucky ", {1,2,3}, 1 ,"I don't have eyes but once I did see!", 1 , { "Skull", "Leg", "Arm"},0 );
    Teen_obstacle Teen_medium( "Slenderman", {1,2,3}, 2 ," I protect, I stand tall my purpose is to strike fear in all ", 2 , {"Slenderman", "Scarecrow", "Zombie"}, 1);
    Teen_obstacle Teen_hard( "Leatherface", {1,2,3}, 1 ,"I have a head and no body. My smile light up the night. What am I? ", 3 ,{"Mirror", "Santa claus","Jack O lantern"}, 2);
    vector <Teen_obstacle>  options_teen;
    options_teen.push_back(Teen_easy);
    options_teen.push_back(Teen_medium);
    options_teen.push_back(Teen_hard);

            for(int i = 0; i < size; ++i) {
                int num = range_needed(random_generator);
                Teen_list.insert(options_teen[num]); 
            }
                Teen_list.play_maze(random_generator);
            } catch(const out_of_range & e) {
                cerr << e.what() << endl;
            }
            catch(const invalid_argument & e) {
                cerr << e.what() << endl;
            }
            catch(const logic_error & e) {
                cerr << e.what() << endl;
            }

        }//elseif main
         /////////////////////////////////////////////////////////////////////////////////////
         //Work with the Food
        else {
            try{
    //Template we created now lets us reuse it with different data types
    DLL<Adult_obstacle> Adult_list;
    //create the 3 unique obstacles for adults
    Adult_obstacle Adult_easy( "Freddy Kruger", {1,2,3},1, 18 , 2 , 3);
    Adult_obstacle Adult_medium( "The Boogeyman", {1,2,3},2, 18 , 5 , 2);
    Adult_obstacle Adult_hard( "Pennywise", {1,2,3},3, 18, 7 , 1);
    //createa a vector and the obstacles to it
    vector <Adult_obstacle>  options_adult;
    options_adult.push_back(Adult_easy);
    options_adult.push_back(Adult_medium);
    options_adult.push_back(Adult_hard);

            for(int i = 0; i < size; ++i) {
                int num = range_needed(random_generator);
                Adult_list.insert(options_adult[num]); 
            }
                Adult_list.play_maze(random_generator);
            } catch(const out_of_range & e) {
                cerr << e.what() << endl;
            }
            catch(const invalid_argument & e) {
                cerr << e.what() << endl;
            }
            catch(const logic_error & e) {
                cerr << e.what() << endl;
            }
        }//main else





        return 0;
    }
