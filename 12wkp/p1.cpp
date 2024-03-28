#include <iostream>
using namespace std;

int readN();
double* readnums(int, char*);
void reverse(double*, double*, char, char, int);
void min(double*, double*, char, char, int);

int main()
{

  //read N
  int n = readN();

  char cA, cB;
  //read the value of label and the first vector
  double* A = readnums(n, &cA);
  //read the value of second label and the second vector
  double* B = readnums(n, &cB);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "reverse" )
      reverse(A, B, cA, cB, n);
    else if ( cmd == "min" )
      min(A, B, cA, cB, n);
    else
      cout << "invalid command!" << endl;
  }

  delete [] A;
  delete [] B;

  return 0;
}
int readN()
{
  int n;
  cin >> n;
  return n;
}

double* readnums(int n, char *cA)
{
  double* D = new double[n];
  double d;
  char r;
  cin >> *cA >> r;
  for(int i=0; i < n; i++)
  {
    cin >> d;
    D[i] = d;
  }
  return D;
}

void reverse(double* A, double* B, char cA, char cB, int n)
{
  char c;
  cin >> c;
  if (c == cA)
  {
    cout << '[';
    for (int j=n-1; j >=0; j--)
    {
      if(j != 0)
        cout << A[j] << ' ';
      else cout << A[j];
    }
    cout << ']' << endl;
  }

  else if (c == cB)
  {
    cout << '[';
    for (int j=n-1; j >=0; j--)
    {
      if(j != 0)
        cout << B[j] << ' ';
      else cout << B[j];
    }
    cout << ']' << endl;
  }
  else cout << "no such vector!" << endl;
}

void min(double* A, double* B, char cA, char cB , int n)
{
  double min;
  char c;
  cin >> c;
  if (c == cA)
  {
    min = A[0];
    for (int i=1; i < n; i++)
    {
      if(A[i] < min)
        min = A[i];
    }
    cout << min << endl;
  }
  else if (c == cB)
  {
    min = B[0];
    for (int i=1; i < n; i++)
    {
      if(B[i] < min)
        min = B[i];
    }
    cout << min << endl;
  }
  else cout << "no such vector!" << endl;
}