    //Will Pitkin       m265052
    //Proj3 pt1         15APR24
    //read in the board

    #include <iostream>
    #include <fstream>
    #include <unistd.h>
    #include <cstdlib>
    using namespace std;
    #include "easycurses.h"
    #include "Pos.h"

    struct Point{
        char name;
         Pos p;
    };
    
    void findPositions(Point** P, int rows, int cols);

    int main()
    {
        cout << "board file: ";
        string board;
        cin >> board;
        ifstream fin(board);
        
        //check if file exists
        if (!fin)
        {
            cout << "error, board not found" << endl;
            return 1;
        }

        //read in values
        int rows, cols, Zs;
        char tr, c;     //tr = trash
        fin >> rows >> tr >> cols >> Zs;
        fin.get();
        
        //create 2-D array of struct points
        Point** P = new Point* [rows];
        for (int i=0; i < rows; i++)
            P[i] = new Point[cols];

        //height and width of board to compare
        int height, width;

        //begin
        startCurses();

        //get window dimentions before beginning it
        getWindowDimensions(height, width); // declared in easycurses.h
        //compare this to rows and cols values
        if (height < rows || width < cols)
        {
            cout << "error, window too small" << endl;
            return 1;
        }

        //for loop to read in and output the board
        //cols+1 bc fin.get also pulls new line character
        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < cols; j++)
            {
                //allocate the char itself to the name
                c = fin.get();
                if (c != '\n')
                {
                    P[i][j].name = c;
                    P[i][j].p.row = i;
                    P[i][j].p.col = j;
                }
                //now draw out the stuff
                if (c == 'Z' || c == 'Y')
                {
                    drawChar(' ', i, j);
                }
                else 
                    drawChar(c, i, j);
            }
            //done to get each new line
            c = fin.get();
        }
        //refresh new board all at once
        refreshWindow();

        

        char cha;
        do {
            usleep(150000); // pause (sleep) for .15 seconds
            cha = inputChar();
        } while(cha != 'y'); //loop exits with a 'y'

        //close ncurses after do while loop
        endCurses();

        //after leaving the window, the player will see the positions outputted
        findPositions(P, rows, cols);


        for (int i=0; i < rows; i++)
            delete[] P[i];
        delete[] P;

    }

    void findPositions(Point** P, int rows, int cols)
    {
        //location for storing the Zs (random arbitrary value), and a z counter
        Pos* Zpos = new Pos[10];
        int numZs = 0;
        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < cols+1; j++)
            {
                if (P[i][j].name == 'Y')
                {
                    cout << "Player start: (" << P[i][j].p.row << ',' <<
                         P[i][j].p.col << ')' << endl;
                }
                //must store locations of potentially multiple Zs
                else if (P[i][j].name == 'Z')
                {
                    Zpos[numZs].row = P[i][j].p.row;
                    Zpos[numZs].col = P[i][j].p.col;
                    numZs++;
                }
            }
        }
        //output villian spawns
        if (numZs != 0)
        {
            cout << "Spawn spots: ";
            for (int i=0; i < numZs; i++)
            {
                cout << '(' << Zpos[i].row << ',' << Zpos[i].col << ") ";
            }
            cout << endl;
        }

        delete [] Zpos;
    }