//This file will contain the doubly link list


//This is parametric polymorphism
//it says that the  following functions will use the identifier TYPE
//instead of the explicit name of a data type
#pragma once

#include <iostream>
#include <string>
#include <iosfwd> //ostream


using namespace std;


template <typename TYPE>

class Node{
    
    public:
    //default constructor
    Node();
    //argument constructor
    Node(const TYPE& data);
    //copy constructor
    Node(const Node& src);

    //functions that work with the next node
    void set_next(Node<TYPE>*& next_node);
    Node<TYPE>*& get_next();

    //functions that work with the prev node
    void set_prev(Node<TYPE>*& prev_node);
    Node<TYPE>*& get_prev();
    
    //this will return the modifiable reference
    TYPE& get_data();
    //this will read only
    //
    //const TYPE& get_data() const;

    private:
    
    TYPE data;
    Node<TYPE>* next;
    Node<TYPE>* prev;

};



template <typename TYPE>

class DLL {
    
    public:
    //Default constructor
    DLL();
    //Destructor
    ~DLL();
    //copy constructor
    DLL(const DLL & src);
    //assignment operator
    DLL& operator=(const DLL & src);
    
    //will insert an obj
    bool insert(const TYPE& obj);
    //will remove by comparing a string name to the lists objects
    bool remove(TYPE& removed, const string & name);
    //will retrieve by comparing a string name to the list objects
    bool retrieve(TYPE& retrieved, const string & name) const;
    //display entire list
    bool display() const;
    //remove entire list
    bool remove_all();

    //The user game functions
    int play_maze(mt19937 & random_generator);

    private:
    //recursive call to insert 
    bool insert(Node<TYPE>*& head, const TYPE& obj);
    //recursive call to remove
    bool remove(Node<TYPE>*& head, TYPE& removed, const string & name);
    //recursive call to retrieve
    bool retrieve( Node<TYPE>* head, TYPE& retrieved, const string & name) const;
    //Recursive call to display entire list
    bool display(Node<TYPE>* head) const;
    //remove entire list
    bool remove_all(Node<TYPE>*& head);
    //function to copy entire list
    bool copy_all(Node<TYPE>*& dest, Node<TYPE>* src);
    //The recursive function to play the game
    int play_recursively(Node<TYPE>* head, mt19937 & random_generator);
    Node<TYPE>* traverse_list(Node<TYPE>* start, int steps);

    Node<TYPE>* head;
    Node<TYPE>* tail;


};
//this makes the compiler see the template implementations
#include "list.tpp"



