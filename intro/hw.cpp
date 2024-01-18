  #include <iostream>
  #include <cmath>

  using namespace std;

  int main()
  {
  
      //declare variables and create the space for the user to input values
      
    double x, y, z;
    double dc, solution;

    cout << "Enter length x: ";

    cin >> x;

    cout << "Enter length y (<" << x << "): ";

    cin >> y;
      
    cout << "Enter length z (<" << sqrt( x*x - y*y ) << "): ";

    cin >> z;

        //begin writing the math equations for the system to compute

    dc = sqrt( x*x - y*y ) - z ;

    solution = sqrt( abs(dc)*abs(dc) + y*y ) ;

        //write out the solution

    cout << "Length of BD is " << solution << endl;

  }


