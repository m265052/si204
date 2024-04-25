    #include <iostream>
    using namespace std;
    #include "ll.h"


    Node* add2back(int d, Node* L)
    {
        if (L == NULL)
        {
            return new Node{d, NULL};
        }
        else
        {
            // non-empty L case
            Node* last = L;
            while(last->next != NULL)
            last = last->next;

            // update last->next
            last->next = new Node{d, NULL};

            // The head of the list didn't change
            return L;
        }
    }

    //rec function to print
    void print(Node* L)
    {
        if (L == NULL)
            cout << endl;
        else 
        {
            cout << L->data << " ";
            print(L->next);
        }
    }

    void enter_after(int d, int x, Node* L)
    {
        //insert new node with given value
        Node* p = new Node;
        p->data = d;
        Node* temp = L;
        while (temp->data != x)
            temp = temp->next;

        //do value swaps to hold list together
        p->next = temp->next;
        temp->next = p;
        return;
    }

    //rec function that returns after deleting a node
    Node* remove(int d, Node* L)
    {
        if (L == NULL)
            return L;

        else if (L->data == d)
        {
            //create temp node to save values
            Node* temp = L->next;
            delete L;
            return temp;
        }
        
        L->next = remove(d, L->next);
        return L;
    }

    Node* deletefront(Node* L)
    {
        if (L == NULL)
            return NULL;

        Node* ret = L->next;   // store the 2nd node to return
        delete L;              // delete the front node
        return ret;
    }

    void deletelist(Node* L)
    {
        while (L != NULL)
            L = deletefront(L);
    }