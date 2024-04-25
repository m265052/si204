#include <iostream>
#include <fstream>
using namespace std;

struct fruit
{
    string type;
    double price;
};

int main()
{
    cout << "Filename: ";
    string file;
    cin >> file;
    ifstream fin(file);

    if(!fin)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string s, f;
    int totn;
    double p;
    char c;
    fin >> totn >> s;
    fruit* F = new fruit [totn];
    
    for (int i=0; i < totn; i++)
    {
        fin >> F[i].type >> c >> F[i].price;
    }

    string input;
    string name;
    double amount;
    double tcost = 0.0;
    bool found = false;

    do
    {
        cout << "command: ";
        cin >> input;
        if(input == "checkout")
            exit;
        else if(input == "add")
        {
            cin >> amount >> s >> name;
            found = false;
            for (int i=0; i < totn; i++)
            {
                if (name == F[i].type)
                {
                    tcost = tcost + F[i].price * amount;
                    found = true;
                }
            }
            if (found == false)
                cout << "Error! " << name << " not found!" << endl;
        }

        else if (input == "price")
        {
            cin >> name;
            found = false;
            for (int i=0; i < totn; i++)
            {
                if (name == F[i].type)
                {
                    cout << name << " are $" << F[i].price << " per pound" << endl;
                    found = true;
                }
            }
            if (found == false)
                cout << "Error! " << name << " not found!" << endl;
        }
    } while (input != "checkout");

    cout << "total is $" << tcost << endl;

    delete [] F;
    return 0;
}