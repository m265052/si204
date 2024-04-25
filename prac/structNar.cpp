#include <iostream>
#include <fstream>
using namespace std;

struct account
{
    int a;          //account number
    double b;       //balance
    string  n;      //name
};

int main()
{
    ifstream fin("BankAccts.txt");
    ifstream fin2("Transactions.txt");

    int num;
    string s;

    fin >> num >> s >> s >> s >> s;

    account* A = new account[num];
    char c;     //dollar sign

    for (int i=0; i < num; i++)
        fin >> A[i].a >> c >> A[i].b >> A[i].n;

    double tr;          //transaction
    int ch;              //check against account num

    while (fin2 >> s >> ch >> tr)
    {
        for (int i=0; i < num; i++)
        {
            if (A[i].a == ch)
            {
                A[i].b = A[i].b + tr;
            }
        }
    }

    for (int i=0; i < num; i++)
    {
        cout << A[i].a << '\t' << A[i].n << "\t$" << A[i].b << endl;
    }

    return 0;
}