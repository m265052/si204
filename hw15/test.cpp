#include <iostream>
using namespace std;

int f(int, int);
int main()
{
    int x =2, y=3;
    x = f(x,y);
    cout << "main: x=" << x << ", y=" << y << endl;
    y = f(y,x);
    cout << "main: x= " << x << ", y=" << y << endl;
}
int f(int x, int y)
{
    x++;
    y+=2;
    cout << "f: x=" << x << ", y=" << y << endl;
    return x+y;
}