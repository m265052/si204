    //Will Pitkin       m265052
    //hw18              29Feb24
    #include <iostream>
    using namespace std;

    // ======================================
    // Function prototypes below
    // ======================================
    int readN();
    int* readData(int n);
    void show(int* A, int n);
    void swap(int* A, int n);

    // ======================================
    // main function
    // TOUCH NOTHING INSIDE THE FUNCTION!!
    // ======================================
    int main()
    {
        int n = readN();
        int* A = readData(n);

        string cmd;
        cout << "cmd: ";
        while( (cin >> cmd) && cmd != "quit" ) 
        {
            if( cmd == "show" )
            show(A, n);
            else if ( cmd == "swap" )
            swap(A, n);

            cout << "cmd: ";
        }

        delete[] A;

        return 0;
    }


    // ======================================
    // Function definitions below
    // ======================================
    int readN()
    {
        //super simple code that returns the integer of number of numbers
        char c;
        int n;
        cin >> c >> c >> n;
        return n;
    }

    int* readData(int n)
    {
        //just read in the numbers and store in array A
        int r;
        int* A = new int[n];
        for(int i=0; i < n; i++)
        {
            cin >> r;
            A[i] = r;
        }
        return A;
    }

    void show(int* A, int n)
    {
        for(int i=0; i < n; i++)
        {
            cout << '[' << i << "] ";
            //cout stars for the array
            for(int j=0; j < A[i]; j++)
                cout << '*';
            cout << endl;
        }
    }

    void swap(int* A, int n)
    {
        int t, i, j;      //temporary int then the two values
        cin >> i >> j;
        //reassign all the values
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }