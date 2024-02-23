#include <iostream>
using namespace std;

//==========================================
// Give the prototype of firstfactor below
int firstfactor(int x);

//==========================================
// main function
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next prime factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}


//==========================================
// Define firstfactor below
int firstfactor(int x)
{
  int test, div=2;
  //using the test to see if the divisor is a prime factor
  test = x%div;
  while(test !=0)
  {
    //if test == 0, then div is a prime factor, else, we will check the next integer
    div++;
    test =x%div; 
  }
  return div;
}



