#include <iostream>
using namespace std;

struct point
{
    double x, y;
};

point operator+(point p, point q);
point operator/(point p, double d);
istream& operator >>(istream& in, point &r);
ostream& operator <<(ostream& out, point r);

int main()
{
  point p, q;
  cin >> p >> q;

  cout << "midpoint: " << (p+q)/2.0 << endl;
  return 0;
}

point operator+(point p, point q)
{
    point r;
    r.x = p.x + q.x;
    r.y = p.y + q.y;
    return r;
}

point operator/(point p, double d)
{
    point r;
    r.x = p.x/d;
    r.y = p.y/d;
    return r;
}

istream& operator >>(istream& in, point &r)
{
    char c;
    return in >> c >> r.x >> c >> r.y >> c;
}

ostream& operator <<(ostream& out, point r)
{
    return out << '(' << r.x << ',' << r.y << ')';
}