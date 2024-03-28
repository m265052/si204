#include <iostream>
using namespace std;

void crash(int** A, int st, int av);
void map(int** A, int st, int av);

int main()
{
    int st, av, cr;
    string street, avenue;
    cin >> st >> street >> av >> avenue;
    
    int** A = new int*[st];
    for(int i=0; i < st; i++)
        A[i] = new int[av];

    for(int i=0; i < st; i++)
    {
        for(int j=0; j < av; j++)
        {
            cin >> cr;
            A[i][j] = cr;
        }
    }

    string cmd;
    while( cout << "> " && cin >> cmd && cmd != "quit" )
    {
        crash(A, st, av);
    }

    for(int i=0; i < st; i++)
        delete [] A[i];
    delete [] A;

    return 0;
}

void crash(int** A, int st, int av)
{
//    char num, h;
    char h;
    int s, a;
    string r;
    cin >> s >> h >> h >> r >> a >> r;
//    s = num - 48;
    int i = s-1;
    int j = a-1;

    A[i][j] = A[i][j] + 1;

    map(A, st, av);
}

void map(int** A, int st, int av)
{
    for(int i=0; i < st; i++)
    {
        for(int j=0; j < av; j++)
        {
            cout << A[i][j] << ' ';
            if(j == av-1)
                cout << endl;
        }
    }
}