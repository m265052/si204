    //Will Pitkin       m265052
    //Lab07 pt2         29Feb24
    //swap-and-reverse game SWARE: now do part 1 but make it a game
    //instead of outputting whether it is in order or not,
    //keep outputting the new sequence and allow user to swap values
    //in order to organize the numbers in order
    //game counts 3 points for each swap

    #include <iostream>
    using namespace std;

    int* read(int N);
    void print(int* A, int N);
    bool isInOrder(int* A, int N);

    //p2 functions, still work in progress
    void swap(int* A, char col1, char col2);

    //main given in lab intro, make the functions
    int main()
    {
        cout << "Welcome to SWARE!" << endl << "board> ";
        char c;
        int N;
        cin >> c >> c >> N;

        int* A = read(N);
        print(A,N);

        //read in what user gives
        //also setup move tracker
        int move = 0;
        string s;
        char col1, col2;
        //add a while loop that allows swapping to occur
        while (!isInOrder(A,N))
        {
            cout << "> ";
            cin >> s;
            //make sure the string is "swap" before calling function
            if(s == "swap")
            {
                cin >> col1 >> col2;
                swap(A, col1, col2);
                move++;
                print(A,N);
            }
            else 
            {
                cout << "Unknown move '" << s << "'" << endl;
                cin >> s >> s;
            }
        }
        int points = 3 * move;
        cout << points << " points! (" << move << " moves)" << endl;
        delete [] A;
        return 0;
    }

    //this function is honestly unnecessary, but I will leave it here
    //in case the submit server looks for it
    int* read(int N)
    {
        int num;
        //get rid of colon following N
        char h;
        cin >> h;
        //prep the array
        int* A = new int[N];
        //loop to read the numbers input by user and place them in the array A
        for(int i=0; i < N; i++)
        {
            cin >> num;
            A[i] = num;
        }
        //return the array
        return A;
    }

    void print(int* A, int N)
    {
        char letter;
        //print the numbers from the array
        for(int k=0; k < N; k++)
            cout << ' ' << A[k];
        cout << endl;
        //print the line here
        for(int j=0; j < N; j++)
            cout << "--";
        cout << '-' << endl;
        //print the letters
        for(int i=0; i < N; i++)
        {
            letter = 'A' + i;
            cout << ' ' << letter;
        }
        cout << endl;
    }

    bool isInOrder(int* A, int N)
    {
        for(int i=0; i < N; i++)
        {
            //first make sure i stays within array bounds
            if(i < N-1)
            {
                //compare the first value to the second, etc.
                //make sure each value stays below the last
                if (A[i] > A[i+1])
                return false;
            }
        }
        return true;
    }

    //this function will make a new temp int to retain the values for swapping
    void swap(int* A, char col1, char col2)
    {
        //convert these to the array numbers
        int x, y;
        //'A' is 65 on the ASCII table, and arrays start at 0
        x = col1 - 65;
        y = col2 - 65;
        //now put the values from A into the "temporary" array B so the A
        //values can be reassigned
        int temp;
        temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }