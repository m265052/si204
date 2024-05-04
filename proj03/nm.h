    #pragma once
    #include <iostream>
    #include <fstream>
    #include <unistd.h>
    #include <cstdlib>
    using namespace std;
    #include "easycurses.h"
    #include "Pos.h"
    #include <cstdlib>

    //original way of storing the board
    struct Point
    {
        char name;
         Pos p;
    };

    //this type of struct allows the player to move around, keeping track of
    //everything needed to move the player
    struct Player
    {
        int dir;
        bool move;
        Pos curr;       //current position
        Pos prev;       //previous position
    };

    //these next two kill the player, and they work similarly
    //hunters track the player, while ships wander aimlessly
    struct Ship
    {
        Player singleShip;
        Pos where;
        Pos whereBefore;
        int dir;
        Pos whereOriginally;
    };

    struct Hunt         //hunter
    {
        Pos where;
        Pos whereBefore;
        int dir;
        Pos whereOriginally;
    };

    //the vital things to know about the board are stored here
    //(for the most part)
    //of course, if that were totally true, this project would be much shorter
    struct Board
    {
        Pos xPos;
        Point** B;
        Player One;
    };
    //this uses the board read in to get data
    int findPositions(int rows, int cols, Board& bo);

    //this makes the board itself by reading it all in
    void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo,
                 Ship**, Hunt*);

    //this function is a nightmare, so bear with it:
    //it analyzes the player and all ships and hunters, and it allows for all
    //of their movements. it also includes the two final functions on this page
    void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack,
              int z, Ship**, Hunt*);

    //simply deletes the arrays to free memory at the end of the game
    void deleteArrays(int rows, Point** B);

    //manages the stepping of ships and hunters
    void allStep(Ship** fleet, int z);

    void hunterStepper(Hunt* packs, int z, Player);

    //shiphunt creates ships and hunters
    void shiphunt(Ship** fleet, Hunt* packs, int z);