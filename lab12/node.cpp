    #include <iostream>
    using namespace std;
    #include "node.h"

    Node* add2front(string word, int val, Node* L)
    {
        Node* temp = new Node;
        temp->data.w = word;
        temp->data.n = val;
        temp->next = L;
        return temp;				// return the new list!
    }

    //use recursion to print
    void printListRec(Node* L)
    {
        if (L == NULL)
            return;
        else
        {
            cout << '(' << L->data.w << ' ' << L->data.n << ") ";
            return printListRec(L->next);
        }
    }

    int length(Node* L)
    {
        int count = 0;
        for(Node* curr = L; curr != NULL; curr = curr->next)
            count++;

        return count;
    }
    
    //the next two functions delete (called at end)****************************
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