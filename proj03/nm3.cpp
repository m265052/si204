#include <iostream>
using namespace std;
#include "nm3.h"

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

void makeBoard(int rows, int cols, Point** B, ifstream &fin, Board& bo, Ship** fleet)
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
      if (c == 'Z')
      {
        drawChar(' ', i, j);
        for( int k = 0; k < 5; k++){
          fleet[zs][k].where.row = i;
          fleet[zs][k].where.col = j;
          fleet[zs][k].whereOriginally.row = i;
          fleet[zs][k].whereOriginally.col = j;
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

void move(int rows, int cols, Board& bo, char kb, bool& brk, int& strack,
    int z, Ship** fleet)
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

    //collisions

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

void shiphunt(Ship** fleet, int z)
{
  //this function gives the initial directions
  for (int i=0; i < z; i++)
  {
    for (int j=0; j < 5; j++)
    {
      fleet[i][j].dir = rand()%4;
    }
  }
}
