    #pragma once
    #include <iostream>
    #include <fstream>
    #include <unistd.h>
    #include <cstdlib>
    using namespace std;
    #include "easycurses.h"
    #include "Pos.h"
    #include <cstdlib>

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

    struct Ship
    {
        Player singleShip;
        Pos where;
        Pos whereBefore;
        int dir;
        Pos whereOriginally;
    };

    struct Board
    {
        Pos xPos;
        Point** B;
        Player One;
    };
    
    int findPositions(int rows, int cols, Board& bo);
    void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo, Ship**);
    void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack,
              int z, Ship**);
    void deleteArrays(int rows, Point** B);
    void allStep(Ship** fleet, int z);
    void shiphunt(Ship** fleet, int z);