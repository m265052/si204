    //Will Pitkin           m265052
    //hw17                  27Feb24
    //read in sentences and reverse using arrays

    #include <iostream>
    using namespace std;

    int main()
    {
        cout << "Number of words: ";
        int count;
        cin >> count;
        
        //create my first array, how exciting
        string * ar = new string[count];

        cout << "Sentence: ";
        
        string word;
        //for loop to read in each word
        for(int i=0; i<count; i++)
        {
            cin >> word;
            //now store each word in one array block
            ar[i] = word;
            //output each word and check if it is last
            cout << word;
            if (i != count -1)
            cout << ' ';
            else cout << '?';
        }
        
        //this specific for loop design is necessary bc arrays count from 0
        //to i-1, but the count from user is one digit higher
        for (int i = count -1; i >= 0; i--)
        {
            //this will output the words in reverse order
            cout << ' ' << ar[i]; 
        }
        cout << '!' << endl;
        delete [] ar;
        return 0;
    }