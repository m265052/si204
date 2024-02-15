#include <iostream>
using namespace std;
int main ()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;

    for (int row=0; row < n; row++)
    {
        if (row == 0 || row == n-1)
        {
            cout << '@';
            for (int per=0; per < n-2; per++)
            cout << '.';
            cout << '@' << endl;
        }
        for (int per=0; per < row; per++)
        cout << '.';
        cout << '@';
        for (int per=0; per < row; per++)
        cout << '.';
        cout << '@';
        for (int per=0; per < row; per++)
        cout << '.';
        cout << endl;
    }
}