    //Will Pitkin       m265052
    //Proj3 pt2         15APR24
    //read in the board

    #include <iostream>
    using namespace std;
    #include "nm2.h"

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

        //create the board
        Board bo;
        
        //create 2-D array of struct points
        bo.B = new Point* [rows];
        for (int i=0; i < rows; i++)
            bo.B[i] = new Point[cols];


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
        makeBoard(rows, cols, bo.B, fin, bo);
        //refresh new board all at once
        refreshWindow();


        //make player move in loop
        bool brk = false;       //break out of loop
        int strack = 0;         //score tracker

        char kb;
        do {
            usleep(150000); // pause (sleep) for .15 seconds
            kb = inputChar();
            move(rows, cols, bo, kb, brk, strack);
        } while(kb != 'y' && brk == false); 
        //loop exits with a 'y' or when player reaches X

        int score = 500 - strack;

        //close ncurses after do while loop
        endCurses();

        //after leaving the window, the player will see the positions outputted
        findPositions(bo.B, rows, cols, bo);
        cout << "You won, high score = " << score << endl;

        deleteArrays(rows, bo.B);
        delete [] bo.zPos;
        return 0;
    }