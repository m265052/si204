/**************************************************
p3.cpp

DO NOT TOUCH THIS FILE AT ALL
**************************************************/

#include <iostream>
#include <fstream>
#include "list.h"
using namespace std;

int main()
{
  Node* L = NULL;

  // read the characters into list L
  cout << "Filename: ";
  string fname;
  cin >> fname;
  ifstream fin(fname);

  Character x;
  char c;
  while( fin >> x.label >> c >> x.row >> c >> x.col >> c )
    L = add2back(x, L);

  // handle the commands
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "print" )
    {
      print(L);
    }
    else if ( cmd == "left-of" )
    {
      int col;
      cin >> col;
      nodesLeftOf(L, col);
    }
    else if ( cmd == "rm-third" )
    {
      removeThird(L); 
    }
  }

  // delete the list 
  deletelist(L);
  return 0;
}
