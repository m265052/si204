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
    
    Node* deleteNode(Node* L, Node* p)
    {
        Node* te = L;
        //traverse list w/ new temp node
        while (te->next != p && te != p)
            te = te->next;

        if (te == p)
        {
            //did not work here*****************************
            p = p->next;
            return p;
        }
        //stop before p, then set t->next to the one after p
        te->next = p->next;
        delete p;
        return te;

    }

    //keep score from the words
    int tally(int score, Node* p)
    {
        int tot = score + p->data.n;
        return tot;
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