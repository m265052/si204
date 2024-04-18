    //Will Pitkin       m265052
    //lab12 pt1         18APR24
    //read in and print in reverse

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
        int count = 0, val;

        //create while loop to read in all of the text
        while (fin >> tr >> word >> val >> tr)
        {
            L = add2front(word, val, L);
            count++;
        }

        cout << "count is " << count << endl;
        //print the list in reverse (read in to the front)
        printListRec(L);
        cout << endl;

        //delete list
        deletelist(L);

        return 0;
    }