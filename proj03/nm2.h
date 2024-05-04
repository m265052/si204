    #pragma once
    #include <iostream>
    #include <fstream>
    #include <unistd.h>
    #include <cstdlib>
    using namespace std;
    #include "easycurses.h"
    #include "Pos.h"

    struct Point
    {
        char name;
         Pos p;
    };

    struct Player
    {
        int dir;
        bool move;
        Pos curr;       //current position
        Pos prev;       //previous position
    };

    struct Board
    {
        Pos* zPos;
        Pos xPos;
        Point** B;
        Player One;
    };
    
    void findPositions(Point** B, int rows, int cols, Board& bo);
    void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo);
    void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack);
    void deleteArrays(int rows, Point** B);
    int av(int a, int b);