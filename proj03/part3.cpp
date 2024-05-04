    //Will Pitkin       m265052
    //Proj3 pt3         01MAY24

    #include <iostream>
    #include <cstdlib>
    using namespace std;
    #include "nm3.h"

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
        char tr;     //tr = trash
        fin >> rows >> tr >> cols >> Zs;
        fin.get();

        //"random" directions
        int seed = 1;
        srand(seed);

        //create the board
        Board bo;
        
        //create 2-D array of struct points
        bo.B = new Point* [rows];
        for (int i=0; i < rows; i++)
            bo.B[i] = new Point[cols];
        
        Ship** fleet = new Ship*[Zs];
        for( int i = 0; i < Zs; i++)
        {
            fleet[i] = new Ship[5]; // creates a fleet of ships
        }
        

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

        //call function to make board
        makeBoard(rows, cols, bo.B, fin, bo, fleet);
        //refresh new board all at once
        refreshWindow();

        //find positions then make board
        int numZs = findPositions(rows, cols, bo);

        //assign ships and hunters
        shiphunt(fleet, numZs);

        //make player move in loop
        bool brk = false;       //break out of loop
        int strack = 0;         //score tracker

        char kb;
        do {
            usleep(150000); // pause (sleep) for .15 seconds
            kb = inputChar();
            move(rows, cols, bo, kb, brk, strack, numZs, fleet);
        } while(kb != 'y' && brk == false); 
        //loop exits with a 'y' or when player reaches X

        int score = 500 - strack;

        //close ncurses after do while loop
        endCurses();

        //after leaving the window, the player will see the positions outputted
        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < cols+1; j++)
            {
                if (bo.B[i][j].name == 'Y')
                {
                    cout << "Player start: (" << bo.B[i][j].p.row << ',' <<
                        bo.B[i][j].p.col << ')' << endl;
                }
            }
        }
        //output villian spawns
        if (numZs != 0)
        {
            cout << "Spawn spots: ";
            for (int i=0; i < numZs; i++)
            {
                cout << '(' << fleet[i][0].whereOriginally.row << ',' 
                << fleet[i][0].whereOriginally.col << ") ";
            }
            cout << endl;
        }


        cout << "You won, high score = " << score << endl;

        deleteArrays(rows, bo.B);

        for (int i=0; i < numZs; i++)
        {
            delete [] fleet[i];
        }
        delete [] fleet;
        return 0;
    }