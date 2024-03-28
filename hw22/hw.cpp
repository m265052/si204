    //Will Pitkin       m265052
    //hw22              19Mar24
    //2D arrays

    #include <iostream>
    using namespace std;

    int main()
    {
        cout << "What size? ";
        //n = rows, m = cols
        int n, m;
        char x;
        cin >> n >> x >> m;
        
        //create array to store the values in from the user
        int** A = new int*[n];
        for (int i=0; i < n; i++)
            A[i] = new int[m];

        int num;        //number from user

        //create for loop to read in from the user
        for (int i=0; i < n; i++)
        {
            for (int j=0; j < m; j++)
            {
                cin >> num;
                //the following will store num in the array
                A[i][j] = num;
            }
        }

        //now create loops to analyze the array values
        //create counters
        int tot =0, rows, cols;

        cout << "rows:";

        for (int i=0; i < n; i++)
        {
            for (int j=0; j < m; j++)
            {
                //total will be added for each row
                tot = tot + A[i][j];
            }
            //each row will be evaluated before moving to the next one
            if (tot % 3 == 0 && tot != 0)
            cout << ' ' << i;
            tot = 0;
        }
        cout << endl << "cols:";
        
        //now to evaluate the columns

        //this time it reads the wanted column value and adds each of the rows
        for (int j=0; j < m; j++)
        {
            for (int i=0; i < n; i++)
            {
                tot = tot + A[i][j];
            }
            if (tot % 3 == 0 && tot != 0)
                cout << ' ' << j;
            tot = 0;
        }
        cout << endl;
        
        //delete 2D array
        for (int i=0; i < n; i++)
            delete [] A[i];
        delete [] A;

        return 0;
    }