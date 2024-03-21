    //Will Pitkin       m265052
    //Lab09             21Mar24
    //Find avg rating from files with 2D array

    #include <iostream>
    #include <fstream>
    using namespace std;

    void avgMovieRat(double**, int);
    void avgUserRat(double**, int);
    
    int main()
    {
        //make 2D array to put the text into
        //movies (9724) will be the columns, users (610) will be the rows
        int u=610, m=9724;
        double** A = new double*[u];
        for (int i=0; i < u; i++)
            A[i] = new double[m];
        
        //prepare to place the content in the arrays
        ifstream fin("ratings.tsv");
        
        //remove header
        string s;
        fin >> s >> s >> s;

        //start by making all values 0
        for (int i=0; i < u; i++)
            for (int j=0; j < m; j++)
                A[i][j] = 0.0;
        
        int user=0, movie=0;
        double rating=0.0;
        //read in and replace non-zero files
        do{
        fin >> user >> movie >> rating;
        A[user][movie] = rating;
        } while (fin);

        int num;
        string query = "hehe";
        while (query != "quit")
        {
            cin >> query;

            if (query == "movie")
                {
                    cin >> num;
                    avgMovieRat(A, num);
                }
            else if (query == "user")
                {
                    cin >> num;
                    avgUserRat(A, num);
                }
            else query = "quit";
        }
        
        for (int i=0; i < u; i++)
            delete [] A[i];
        delete [] A;

        return 0;
    }

    void avgMovieRat(double** A, int num)
    {
        //need a counter to keep track of how many times the m has been rated
        int count = 0;
        double total = 0, avg = 0;
        //for loop to read the movie's rating
        for (int u=0; u < 610; u++)
        {
            if (A[u][num] != 0.0)
            {
                total = total + A[u][num];
                count++;
            }
        }
        avg = total / count;
        cout << avg << endl;
    }

    void avgUserRat(double** A, int num)
    {
        
        //do the counter and loop again same as function above
        int count=0;
        double total=0, avg=0;
        for (int m=0; m < 9724; m++)
        {
            if (A[num][m] != 0.0)
            {
                total = total + A[num][m];
                count++;
            }
        }
        avg = total / count;
        cout << avg << endl;
    }