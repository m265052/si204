    //Will Pitkin       m265052
    //lab12 pt2         18APR24
    //let user move through list

    #include <iostream>
    #include <fstream>
    using namespace std;
    #include "node.h"

    //function prototypes listed in .h, defined in .cpp
    
    int main()
    {
        cout << "Input file is: ";
        string text;
        cin >> text;
        cout << endl;
        ifstream fin(text);

        //check if the text file exists
        if (!fin)
        {
            cout << "error, file DNE" << endl;
            return 1;
        }

        Node* L = NULL;
        //initialized w/ null bc only adding to front
        char tr;
        string word;
        int val;

        //create while loop to read in all of the text
        while (fin >> tr >> word >> val >> tr)
            L = add2front(word, val, L);

        //compute length at different points in the list
        // use this as basic function: int count = length(L);
        int count = 0, score = 0;
        //accept or reject char
        char d;

        //for loop to traverse the list
        for (Node* p = L; p != NULL; p = p->next)
        {
            cout << "The current node: "
            << '(' << p->data.w << ' ' << p->data.n << ')' << endl

            //the first run will not have any data in t
            << "Nodes before the current: ";

            //now set t to L and keep outputting until before p
            for (Node* t = L; t != p; t = t->next)
                cout << '(' << t->data.w << ' ' << t->data.n << ')';
            cout << endl;

            //now use compute length to get the count
            cout << "#nodes after the current: ";
            count = length(p->next);
            cout << count << endl;

            //ask user to accept or reject the pair
            cout << "[a]ccept or [r]eject: ";
            cin >> d;
            cout << endl;

            //function to count the score
            score = tally(score, p);
        }



        //***********************DO THIS AT THE END ***************************
        //print the list in reverse (read in to the front)
        cout << "List is: ";
        //for loop to go through and print the words
        for (Node* p = L; p != NULL; p = p->next)
            cout << p->data.w << ' ';

        cout << endl << "Score is: " << score << endl;



        //delete list
        deletelist(L);

        return 0;
    }