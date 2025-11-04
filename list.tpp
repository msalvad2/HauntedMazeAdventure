
template <typename TYPE>

//default constructor
Node<TYPE>::Node() : data{}, next(nullptr), prev(nullptr) 
{}

template <typename TYPE>
//argument constructor
Node<TYPE>::Node(const TYPE& data) : data(data), next(nullptr), prev(nullptr) 
{}

template <typename TYPE>
//copy constructor
Node<TYPE>::Node(const Node<TYPE>& src) : data(src.data), next(nullptr), prev(nullptr)
{}

//this will set the current node->next = the node you pass in as an argument
template <typename TYPE>
void Node<TYPE>::set_next(Node<TYPE>*& src) {

    next = src;
}
//This will return the current nodes next 
template <typename TYPE>
Node<TYPE>*& Node<TYPE>::get_next() {
    return next;
}

//functions that work with the prev node
template <typename TYPE>
void Node<TYPE>::set_prev(Node<TYPE>*& prev_node) {
    prev = prev_node;
}
//This will return the current nodes prev
template <typename TYPE>
Node<TYPE>*& Node<TYPE>::get_prev() {
    return prev;
}

template <typename TYPE>
//this will return the modifiable reference
TYPE& Node<TYPE>::get_data() {
    return data;
}
//this starts the Doubly Link list//////////////////////////////////////////////////////////

template <typename TYPE>
//Default constructor
DLL<TYPE>::DLL() : head(nullptr), tail(nullptr) 
{}

//Destructor
template <typename TYPE>
DLL<TYPE>::~DLL() {

    remove_all(head);
    head = nullptr;
    tail = nullptr;
}


//copy constructor
template <typename TYPE>
DLL<TYPE>::DLL(const DLL & src) {

    copy_all(this->head, src.head);

}
//will copy from an old list to a new list dynamically
template <typename TYPE>
bool DLL<TYPE>::copy_all(Node<TYPE>*& dest, Node<TYPE>* src) {

    //list is empty 
    if(!src) {
        dest = nullptr;
        return true;

    }
    //will stop when you get to the last node
    if(!src->get_next()) {
        
        Node<TYPE> * hold = nullptr;
        dest = new Node<TYPE>(*src);
        dest->set_next(hold);
        dest->set_prev(hold);

        this->tail = dest;

        return true;

    }
    Node<TYPE>* hold = nullptr;
    dest = new Node<TYPE>(*src);//sets the dests data = src data
    dest->set_prev(hold);

    //dest->set_prev(src->get_prev());//sets dest->prev = src->prev

    //dest->set_next(src->get_next());

    copy_all(dest->get_next(), src->get_next());
    /* 
    //this will link the prev nodes
    if(dest->get_next()) {
    Node<TYPE>* ahead_node = dest->get_next();
    ahead_node->set_prev(dest);

    }
     */

    //better way to do the code above in one line!

    dest->get_next()->set_prev(dest);//this does the same as the commented if statement above
    return true; 
}


//assignment operator
template <typename TYPE>
DLL<TYPE>& DLL<TYPE>:: operator=(const DLL & src) {

    //checks to see if both memoriesa are the same
    //if so returns the address of the current node;
    if(this == &src) {
        return *this;
    }
    //deallocate old memroy
    remove_all(head);

    //copy all information over
    copy_all(head, src.head);

    //return a reference to the pointer
    return *this;


}
//This will recursive delete all the nodes as it unwinds the stack
template <typename TYPE>
bool DLL<TYPE>::remove_all(Node<TYPE>*& head) {
    if(!head) {
        this->tail = nullptr;

        return true;
    }

    remove_all(head->get_next());

    delete head;
    head = nullptr;

    return true;
}


template <typename TYPE>
//will insert an obj
bool DLL<TYPE>::insert(const TYPE& obj) {
    //list is empty
    if(!head) {
        //creates new node and copies data from obj
        head = new Node<TYPE>(obj);
        tail = head;
        return true;
    }

    return insert(head, obj);
}
template <typename TYPE>
//recursive call to insert 
bool DLL<TYPE>::insert(Node<TYPE>*& head, const TYPE& obj) {

    //will stop and insert at end if the obj should be placed at the end
    //since list is entered in sorted order
    if(!head->get_next()) {
        head->get_next() = new Node<TYPE>(obj);    
        head->get_next()->set_prev(head);
        Node<TYPE>* hold = nullptr;
        head->get_next()->set_next(hold);
        this->tail = head->get_next();
        return true;
    }
    /*This WOULD INSERT IN SORTED ORDER BUT IT IS BAD FOR OUR MAZE SINCE WE WANT ADD RANDOM
    //This will insert in sorted order 
    if( head->get_next()->get_data() > obj) {
    //easier to create a new node
    //instead of what I did for the base case above
    Node<TYPE>* newNode = new Node<TYPE>(*obj);
    newNode->set_next(head->get_next());//links newNodes->next
    newNode->get_next()->set_pre(newNode);//links the next nodes prev with newNode
    newNode->set_prev(head);//links newNodes prev to head
    head->set_next(neNode);//links head->next = newNode

    return true;
    }
     */

    return insert(head->get_next(), obj);

}
template <typename TYPE>
//will remove by comparing a string name to the lists objects
bool DLL<TYPE>::remove(TYPE& removed, const string & name) {
    if(!head){
        cout <<"List is empty cannot remove" << endl;
        return false;//empty list
    }

    return remove(head, removed, name);
}
template <typename TYPE>
//recursive call to remove
bool DLL<TYPE>::remove(Node<TYPE>*& head, TYPE& removed, const string & name) {

    if(!head) {
        cout << "No match for: " << name << endl;
        return false;
    }
    if(head->get_data() == name) {
        //copy the contents of the data in the node into the empty object passed in
        removed = head->get_data();
        //holds the nodes next
        Node<TYPE>* next = head->get_next(); 
        //holds the nodes prev
        Node<TYPE>* prev = head->get_prev();
        delete head;
        head = next;
        //check to see that hold wasn't set to nullptr when you set it to head->next
        if(head) {
            head->set_prev(prev); 
        }

        //means list became empty
        if(!head)
            this->tail = nullptr;

        return true;
    }
    remove(head->get_next(), removed, name);

    if(!head->get_next())
        this->tail = head;

    return true;
}

template <typename TYPE>
//will retrieve by comparing a string name to the list objects
bool DLL<TYPE>::retrieve(TYPE& retrieved, const string & name) const {

    if(!head) {
        cout << "List is empty cannot retrieve!" << endl;
        return false;
    }

    return retrieve(head, retrieved, name);
}
template <typename TYPE>
//recursive call to retrieve
bool DLL<TYPE>::retrieve( Node<TYPE>* head, TYPE& retrieved, const string & name) const {

    if(!head) {
        cout << "NO MATCH" << endl;
        return false;
    }

    if(head->get_data() == name) {
        retrieved = head->get_data();
        cout <<"SUCCESSFULLy FOUND MATCH! " << endl;
        return true;
    }

    return retrieve(head->get_next(), retrieved, name);
}

template <typename TYPE>
//display entire list
bool DLL<TYPE>::display() const {

    if(!head) {
        cout << "List is empty" << endl;
        return false;
    }

    return display(head);
}

template <typename TYPE>
//Recursive call to display entire list
bool DLL<TYPE>::display(Node<TYPE>* head) const {
    //end of list
    if(!head)
        return false;
    cout << head->get_data();

    return display(head->get_next());
}


//FUNCTIONS TO PLAY THE GAME 


    mt19937 random_generator;
template <typename TYPE>
//This is the wrapper function
int DLL<TYPE>::play_maze(mt19937 & random_generator) {

    if(!head) {
        cout << "List is empty " << endl;
        return -1;
    }
    if(!head->get_data().beginning())//display the intro for the maze
        return -1;

    return play_recursively(head,random_generator);
}
template <typename TYPE>
int DLL<TYPE>::play_recursively(Node<TYPE>* head, mt19937 & random_generator) {

    if(!head) {
        cout << "Congrats you reached the end of the maze! " << endl;
        return 1;
    }
    //This will trigger the current obstacle game and return the number of moves you get 
    int steps = head->get_data().move(random_generator);

    Node<TYPE>* next = traverse_list(head, steps);

    return play_recursively(next,random_generator);//This will call itself but take in the new position you are at after traversing

}
//This function will receive the steps to move and traveres either forward or backwards depending on moves
//Then it returns where the node is pointing
template <typename TYPE>
Node<TYPE>* DLL<TYPE>::traverse_list(Node<TYPE>* start, int steps) {
    if(!start) return nullptr;
    //means we don't need to traverse list 
    //Also base case for when traversing
    if(steps == 0) {
        return start;
    }
    
    else if(steps > 0) {
        //means we reached the end of the list
       if(!start->get_next()) 
           return nullptr;
           //makes you keep traversing the list right
        return traverse_list(start->get_next(), steps - 1);
    }
    else {
        //means we are the first item in list so we cannot go any further left
        if(!start->get_prev()) {
            cout <<"Wait you're at the first obstacle you can't go back any further so you deal with me again! " << endl;
            return start;
        }
            //makes you keep traversing the list left
        return traverse_list(start->get_prev(), steps + 1);

    }
    return start;
}
