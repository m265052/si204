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

            char startingAt, pos, endingAt, another;
            fin >> startingAt;
        //

        while(startingAt == '@')
        {
        int step =1;

            for(int j=0; j < move; j++)
            {
                fin >> pos;
            }
            if(pos == 'X')
            {
                cout << "You died on step " << step << endl;
                return 0;
            }
            fin >> endingAt >> another;
            step++;

        }
    }