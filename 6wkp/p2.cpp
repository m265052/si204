#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    cout << "Enter a filename: ";
    string data;
    cin >> data;
    ifstream fin(data);

    if (!fin)
    {
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    int r1=0, r2=0, r3=0, r4=0;      //range10, 20.....
    while (fin)
    {
        int n;
        fin >> n;
        if (n <= 19 && n >= 10)
        r1++;
        else if (n <= 29 && n >= 20)
        r2++;
        else if (n <= 39 && n >= 30)
        r3++;
        else if (n <= 49 && n >= 40)
        r4++;
        else cout << "123";
    }

    cout << "[10,19]: ";
    for (int star=0; star < r1; star++){
    cout << '*';
    }
    cout << endl << "[20,29]: ";
    for (int star2=0; star2 < r2; star2++){
    cout << '*';
    }
    cout << endl << "[30,39]: ";
    for (int star3=0; star3 < r3; star3++){
    cout << '*';
    }
    cout << endl << "[40,49]: ";
    for (int star4=0; star4 < r4; star4++){
    cout << '*';
    }
    cout << endl;

    return 0;
}