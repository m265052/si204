#include <iostream>
using namespace std;
int main()
{
    char ori, par1, par2 , op, a, b, c;  //orientation, parenthesis, operand
    int n, pain, e, f, g;          //first int
    double d, tot;       //second double

    cin >> ori;

    if (ori == 'f')
    {
        cin >> par1 >> n >> par2 >> op >> d;
        if (op == '+')
            tot = n + d;
        else tot = n - d;
        cout << n << ' ' << op << ' ' << d << " = " << tot << endl;
    }
    else if (ori == 'r')
    {
        cin >> par1 >> a >> b >> c >> par2 >> op >> d;
        e = (a-48);
        f = (b-48)*10;
        g = (c-48)*100;
        pain = e + f + g;
        if (op == '+')
            tot = pain + d;
        else tot = pain - d;
        cout << pain << ' ' << op << ' ' << d << " = " << tot << endl;
    }
    else
    {
        cout << "error";
        return 1;
    }
    return 0;
}