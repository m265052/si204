    //Will Pitkin       m265052
    //Lab07 pt1         29Feb24
    //swap-and-reverse game: organize a line of numbers from user 

    #include <iostream>
    using namespace std;

    int* read(int N);
    void print(int* A, int N);
    bool isInOrder(int* A, int N);

    //main given in lab intro, make the functions
    int main()
    {
        char c;
        int N;
        cin >> c >> c >> N;

        int* A = read(N);
        print(A,N);
        if (isInOrder(A,N))
            cout << "Is in order!" << endl;
        else
            cout << "Is not in order!" << endl;
        delete [] A;
        return 0;
    }

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