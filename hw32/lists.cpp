    #include <iostream>
    using namespace std;
    #include "node.h"

    //functions for lists

    // returns a pointer to the new list
    Node* add2front(int val, Node* oldlist)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->next = oldlist;
        return temp;				// return the new list!
    }
