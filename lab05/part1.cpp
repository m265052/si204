    //Will Pitkin       m265052
    //lab05             08Feb24
    //play a simple game, don't land on an x moving down a line

    #include <iostream>
    #include <fstream>
    using namespace std;

    int main()
    {
        //declare file to use as a board
        string board;
        cin >> board;
        ifstream fin(board);


        //determine if file exists
        if(!fin)
        {
            cout << "File not found!" << endl;
            return 1;
        }

        //determine specs of the board
        string header, header2;
        int width;
        fin >> header >> header2 >> width;

        //ask user to move
        cout << "Enter position between 1 and " << width << ": ";
        int move;
        cin >> move;
        //determine if move is valid
        if(move > width)
        {
            cout << "Invalid position!" << endl;
            return 1;
        }
        //initialize the rows (steps)
        char pos, at;
        int step =1;
        //while loop that tracks having an input
        while(fin)
        {
            fin >> at;
            //j represents the values being read in
            for(int j=0; j < move; j++)
            {
                fin >> pos;
            }
            //j is only flagged if the last value it reads is an X
            if(pos == 'X')
            {
                cout << "You died on step " << step << endl;
                return 0;
            }
            //read in the rest of the spaces in the row after the move
            for(int k=0; k < width - move; k++)
            fin >> pos;
            //get rid of final @
            fin >> at;
            step++;

        }
        //get out of the loop after all characters have been read and win
        cout << "You survived!" << endl;
        return 0;
    }