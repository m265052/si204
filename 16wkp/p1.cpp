/************************************************
p1.cpp

DO NOT DELETE ANY CODE BELOW. 
Only add code as necessary.
*************************************************/

#include <iostream>
using namespace std;

struct position
{
  int row, col;
};

struct movement
{
  char dir;
  int length;
};

istream& operator >> (istream& is, position& p);
istream& operator >> (istream& is2, movement& v);
ostream& operator << (ostream& os, position p);
position operator + (position p, movement v);

int main()
{
  position p; 
  cout << "position? ";
  cin >> p;

  cout << "how many moves? ";
  int n; 
  cin >> n;

  for(int i=0; i<n; i++)
  {
    movement v;
    cin >> v;
    p = p + v;
    cout << p << endl;
  }

  return 0;
}

istream& operator >> (istream& is, position& p)
{
    char c;
    return is >> c >> p.row >> c >> p.col >> c;
}

istream& operator >> (istream& is2, movement& v)
{
    return is2 >> v.dir >> v.length;
}

ostream& operator << (ostream& os, position p)
{
    return os << '(' << p.row << ',' << p.col << ')';
}

position operator + (position p, movement v)
{
    position q;
    if (v.dir == 'N')
    {
        q.row = p.row - v.length; 
        q.col = p.col;
    }
    else if (v.dir == 'S')
    {
        q.row = p.row + v.length;
        q.col = p.col;
    }
    else if (v.dir == 'E')
    {
        q.col = p.col + v.length;
        q.row = p.row;
    }
    else if (v.dir == 'W')
    {
        q.col = p.col - v.length;
        q.row = p.row;
    }
    return q;
}
