    #include <iostream>
    using namespace std;
    #include "nm2.h"

    void findPositions(Point** B, int rows, int cols, Board& bo)
    {
        //location for storing the Zs (random arbitrary value), and a z counter
        bo.zPos = new Pos[10];
        int numZs = 0;
        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < cols+1; j++)
            {
                if (B[i][j].name == 'Y')
                {
                    cout << "Player start: (" << B[i][j].p.row << ',' <<
                        B[i][j].p.col << ')' << endl;
                }
                //must store locations of potentially multiple Zs
                else if (bo.B[i][j].name == 'Z')
                {
                    bo.zPos[numZs].row = bo.B[i][j].p.row;
                    bo.zPos[numZs].col = bo.B[i][j].p.col;
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
                cout << '(' << bo.zPos[i].row << ',' << bo.zPos[i].col << ") ";
            }
            cout << endl;
        }
    }

    void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo)
    {
        char c;
        //for loop to read in and output the board
        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < cols; j++)
            {
                //allocate the char itself to the name
                c = fin.get();
                if (c != '\n')
                {
                    B[i][j].name = c;
                    B[i][j].p.row = i;
                    B[i][j].p.col = j;
                }
                //now draw out the stuff
                if (c == 'Z')
                {
                    drawChar(' ', i, j);
                }
                else if (c == 'Y')      //***************player spawn
                {
                    drawChar('P', i, j);
                    bo.One.curr.row = i;
                    bo.One.curr.col = j;
                }
                else if (c == 'X')
                {
                    bo.xPos.row = i;
                    bo.xPos.col = j;
                    drawChar('X', i, j);
                }
                else 
                    drawChar(c, i, j);
            }
            //done to get each new line
            c = fin.get();
        }
    }

    void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack)
    {

        if (dist(bo.One.curr, bo.xPos) >= 1)
        {
            if (kb == 'r')
            {
                bo.One.move = false;
            }
            else if (kb == 'a')
            {
                bo.One.dir = 3;       //WEST
                bo.One.move = true;
            }
            else if (kb == 'd')
            {
                bo.One.dir = 1;       //EAST
                bo.One.move = true;
            }
            else if (kb == 's')
            {
                bo.One.dir = 2;       //SOUTH
                bo.One.move = true;
            }
            else if (kb == 'w')
            {
                bo.One.dir = 0;       //NORTH
                bo.One.move = true;
            }

            //step to new position based on above (step in Pos.cpp)
            //note previous position for later comparison
            bo.One.prev = bo.One.curr;

            if (bo.One.move == true)
            {
                bo.One.curr = step(bo.One.curr, bo.One.dir);
            //        cerr << "hello";
            }
            //check change in direction
            if (bo.B[bo.One.curr.row][bo.One.curr.col].name == '#')
            {
                //check for each of the 4 directions
                if (bo.One.dir == 0)       //NORTH, so go back SOUTH twice
                {
                    bo.One.curr = step(bo.One.curr, 2);
                    //step again if there is not a wall
                    //keep direction same if trapped in walls
                    if (bo.B[bo.One.curr.row+1][bo.One.curr.col].name != '#')
                    {
                        bo.One.curr = step(bo.One.curr, 2);
                        bo.One.dir = 2;
                    }
                }
                else if (bo.One.dir == 2)
                {
                    bo.One.curr = step(bo.One.curr, 0);
                    if (bo.B[bo.One.curr.row-1][bo.One.curr.col].name != '#')
                    {
                        bo.One.curr = step(bo.One.curr, 0);
                        bo.One.dir = 0;
                    }
                }
                else if (bo.One.dir == 1)
                {
                    bo.One.curr = step(bo.One.curr, 3);
                    if (bo.B[bo.One.curr.row][bo.One.curr.col-1].name != '#')
                    {
                        bo.One.curr = step(bo.One.curr, 3);
                        bo.One.dir = 3;
                    }
                }
                else if (bo.One.dir == 3)
                {
                    bo.One.curr = step(bo.One.curr, 1);
                    if (bo.B[bo.One.curr.row][bo.One.curr.col+1].name != '#')
                    {
                        bo.One.curr = step(bo.One.curr, 1);
                        bo.One.dir = 1;
                    }
                }
            }
            drawChar(' ', bo.One.prev.row, bo.One.prev.col);
            drawChar('P', bo.One.curr.row, bo.One.curr.col);

            if(bo.xPos.row == bo.One.curr.row
               && bo.xPos.col == bo.One.curr.col)
               brk = true;
               
            refreshWindow();
            strack++;

        }

    }

    void deleteArrays(int rows, Point** P)
    {
        for (int i=0; i < rows; i++)
            delete[] P[i];
        delete[] P;
    }
