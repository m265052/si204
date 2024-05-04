#include <iostream>
using namespace std;
#include "nm.h"

int findPositions(int rows, int cols, Board& bo)
{
  //location for storing the Zs (random arbitrary value), and a z counter
  int numZs = 0;
  for (int i=0; i < rows; i++)
  {
    for (int j=0; j < cols+1; j++)
    {
      if (bo.B[i][j].name == 'Y')
      {
        bo.B[i][j].p.row = i;
        bo.B[i][j].p.col = j;
      }
      //must store locations of potentially multiple Zs
      else if (bo.B[i][j].name == 'Z')
      {
        numZs++;
      }
    }
  }
  return numZs;
}

void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo, Ship** 
              fleet, Hunt* packs)
{
  char c;
  //for loop to read in and output the board
  int zs = 0;
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
      //for this first case, initialize the ships and hunters
      if (c == 'Z')
      {
        drawChar(' ', i, j);
        for( int k = 0; k < 5; k++){
          fleet[zs][k].where.row = i;
          fleet[zs][k].where.col = j;
          fleet[zs][k].whereOriginally.row = i;
          fleet[zs][k].whereOriginally.col = j;
          packs[zs].where.row = i;
          packs[zs].where.col = j;
          packs[zs].whereOriginally.row = i;
          packs[zs].whereOriginally.col = j;
        }
        //bo.zPos[zs].gen.row = i;
        //bo.zPos[zs].gen.col = j;
        zs++;

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

//*****************DISCLAIMER: THIS IS AN UGLY FUNCTION************************

void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack,
    int z, Ship** fleet, Hunt* packs)
{
  //determine player direction
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
    //determine hunter and ship directions


    //step to new position based on above (step in Pos.cpp)
    //note previous position for later comparison
    bo.One.prev = bo.One.curr;

    //step in function so that it can be applied to ships and hunters  
    allStep(fleet, z);
    hunterStepper(packs, z, bo.One);


    //*************************************************************************
    //                          WALL BOUNCING
    //*************************************************************************
    //let's get ambitious here after the code already works...
    //I will attempt to make and implement a working fuction for the wall
    //bouncing for the player, hunters, and ships

    //UPDATE: UNFORTUNATELY, SINCE I DECIDED TO MAKE A DIFFERENT STRUCT FOR
    //THE SHIPS AND HUNTERS AND PLAYER, THERE IS NO CONVENIENT WAY TO CREATE A
    //FUNCTION FOR ALL OF THESE, AND I WILL LEAVE THE HORID WRECK THEY HAVE 
    //BROUGHT UPON THIS FUNCTION HERE

    if (bo.One.move == true)
    {
      bo.One.curr = step(bo.One.curr, bo.One.dir);
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
    //now do wall bounces for ships and hunters

    //I UNDERSTAND NOW THAT THESE GIANT MESSES THAT ARE THE GIANT WALL 
    //INTERACTIONS COULD HAVE BEEN A SINGLE FUNCTION
    for(int i = 0; i < z; i++){
      for(int j = 0; j < 5; j++){

        //check change in direction
        if (bo.B[fleet[i][j].where.row][fleet[i][j].where.col].name == '#')
        {
          //check for each of the 4 directions
          if (fleet[i][j].dir == 0)       //NORTH, so go back SOUTH twice
          {
            fleet[i][j].where = step(fleet[i][j].where, 2);
            //step again if there is not a wall
            //keep direction same if trapped in walls
            if (bo.B[fleet[i][j].where.row+1][fleet[i][j].where.col].name != '#')
            {
              fleet[i][j].where = step(fleet[i][j].where, 2);
              fleet[i][j].dir = 2;
            }
          }
          else if (fleet[i][j].dir == 2)
          {
            fleet[i][j].where = step(fleet[i][j].where, 0);
            if (bo.B[fleet[i][j].where.row-1][fleet[i][j].where.col].name != '#')
            {
              fleet[i][j].where = step(fleet[i][j].where, 0);
              fleet[i][j].dir = 0;
            }
          }
          else if (fleet[i][j].dir == 1)
          {
            fleet[i][j].where = step(fleet[i][j].where, 3);
            if (bo.B[fleet[i][j].where.row][fleet[i][j].where.col-1].name != '#')
            {
              fleet[i][j].where = step(fleet[i][j].where, 3);
              fleet[i][j].dir = 3;
            }
          }
          else if (fleet[i][j].dir == 3)
          {
            fleet[i][j].where = step(fleet[i][j].where, 1);
            if (bo.B[fleet[i][j].where.row][fleet[i][j].where.col+1].name != '#')
            {
              fleet[i][j].where = step(fleet[i][j].where, 1);
              fleet[i][j].dir = 1;
            }
          }
        }
      }
    }

    //THIS MESS IMPLEMENTS WALL INTERACTIONS FOR HUNTERS
    //THESE SECTIONS DEFINITELY COULD HAVE BEEN A SINGLE FUNCTION
    for(int i = 0; i < z; i++)
    {
      //check change in direction
      if (bo.B[packs[i].where.row][packs[i].where.col].name == '#')
      {
        //check for each of the 4 directions
        if (packs[i].dir == 0)       //NORTH, so go back SOUTH twice
        {
          packs[i].where = step(packs[i].where, 2);
          //step again if there is not a wall
          //keep direction same if trapped in walls
          if (bo.B[packs[i].where.row+1][packs[i].where.col].name != '#')
          {
            packs[i].where = step(packs[i].where, 2);
            packs[i].dir = 2;
          }
        }
        else if (packs[i].dir == 2)
        {
          packs[i].where = step(packs[i].where, 0);
          if (bo.B[packs[i].where.row-1][packs[i].where.col].name != '#')
          {
            packs[i].where = step(packs[i].where, 0);
            packs[i].dir = 0;
          }
        }
        else if (packs[i].dir == 1)
        {
          packs[i].where = step(packs[i].where, 3);
          if (bo.B[packs[i].where.row][packs[i].where.col-1].name != '#')
          {
            packs[i].where = step(packs[i].where, 3);
            packs[i].dir = 3;
          }
        }
        else if (packs[i].dir == 3)
        {
          packs[i].where = step(packs[i].where, 1);
          if (bo.B[packs[i].where.row][packs[i].where.col+1].name != '#')
          {
            packs[i].where = step(packs[i].where, 1);
            packs[i].dir = 1;
          }
        }
      }
    }

    //*****************************COLLISIONS**********************************

    //collision for the stars (hunters work the same)
    for(int i = 0; i < z; i++)
    {
      for(int j = 0; j < 5; j++)
      {
        if( (fleet[i][j].where.col == bo.One.curr.col && 
           fleet[i][j].where.row == bo.One.curr.row ) ||
           (fleet[i][j].where.col == bo.One.prev.col &&
           fleet[i][j].where.row == bo.One.prev.row &&
           fleet[i][j].whereBefore.col == bo.One.curr.col &&
           fleet[i][j].whereBefore.row == bo.One.curr.row)
         )
        {
          brk = true;
          return;
        }        
      }
    }

    for(int i = 0; i < z; i++)
    {
      if( (packs[i].where.col == bo.One.curr.col && 
          packs[i].where.row == bo.One.curr.row ) ||
          (packs[i].where.col == bo.One.prev.col &&
          packs[i].where.row == bo.One.prev.row &&
          packs[i].whereBefore.col == bo.One.curr.col &&
          packs[i].whereBefore.row == bo.One.curr.row)
        )
      {
        brk = true;
        return;
      }
    }

    //*****************************DRAW****************************************
    //erase old, draw new
    drawChar(' ', bo.One.prev.row, bo.One.prev.col);
    drawChar('P', bo.One.curr.row, bo.One.curr.col);
    for (int i=0; i < z; i++)
    {
      for (int j=0; j < 5; j++)
      {
        drawChar(' ', fleet[i][j].whereBefore.row,
            fleet[i][j].whereBefore.col);
        drawChar('*', fleet[i][j].where.row,
            fleet[i][j].where.col);
      }
    }

    for (int i=0; i < z; i++)
    {
      drawChar(' ', packs[i].whereBefore.row,
          packs[i].whereBefore.col);
      drawChar('K', packs[i].where.row,
          packs[i].where.col);
    }

    if(bo.xPos.row == bo.One.curr.row
        && bo.xPos.col == bo.One.curr.col)
      brk = true;

    refreshWindow();
    strack++;
  }
}
//*********************FINALLY, THE END OF MOVE!!!!!!**************************

void deleteArrays(int rows, Point** P)
{
  for (int i=0; i < rows; i++)
    delete[] P[i];
  delete[] P;
}

void allStep(Ship** fleet, int z)
{
  int t, a;       //turn and angle

  //stepping is done randomly for each ship
  for (int i=0; i < z; i++)
  {
    for (int j=0; j < 5; j++)
    {
      if (rand()%10 == 1)
      {
        a = 90 - 180*(rand()%2);      //will be 90 or -90
        fleet[i][j].dir = turn(fleet[i][j].dir, a);
      }
      fleet[i][j].whereBefore = fleet[i][j].where;
      fleet[i][j].where = step(fleet[i][j].where, 
          fleet[i][j].dir);
    }
  }
}

void hunterStepper(Hunt* packs, int z, Player One)
{
  //the stepping for hunters will work similarly:
  //instead of a random 1 in ten chance of turning, hunters have a 50% chance
  //of turning towards the player using an assortment of rules

  int cdir, rdir;

  int chance;
  
  int t, a;       //turn and angle
  for (int i=0; i < z; i++)
  {
    //declare ints for distances apart between rows and cols
    //the hunter targets the player based on these
    int dc = One.curr.col - packs[i].where.col;
    int dr = One.curr.row - packs[i].where.row;
    //conditional statements for the distances
    if (dc < 0)
      cdir = 3;     //WEST
    else cdir = 1;  //EAST

    if (dr < 0)
      rdir = 0;     //NORTH
    else rdir = 2;  //SOUTH

    //50% chance for either direction
    chance = rand()%2;
    if (chance == 0)
      packs[i].dir = rdir;
    else if (chance == 1)
      packs[i].dir = cdir;

    packs[i].whereBefore = packs[i].where;
    packs[i].where = step(packs[i].where, packs[i].dir);
  }
}

void shiphunt(Ship** fleet, Hunt* packs, int z)
{
  //this function gives the initial directions
  for (int i=0; i < z; i++)
  {
    for (int j=0; j < 5; j++)
    {
      fleet[i][j].dir = rand()%4;
    }
  }

  //hunter also has a random direction
  for (int i=0; i < z; i++)
  {
    packs[i].dir = rand()%4;
  }
}
