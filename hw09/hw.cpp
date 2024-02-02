  //Will Pitkin   m265052
  //hw09          01Feb24
  //place coookies in jar then eat them
  
  #include <iostream>
  using namespace std;

  int main ()
  {
    int cookies, eatenC, day, max, jarred;
    cout << "How many cookies? ";
    cin >> cookies;
    //set initial values at zero before cookies are placed in jar
    eatenC = 0;
    day = 0;
    max = 0;
    jarred = cookies;

    while (cookies > 0)
    {
      //state day and take input
      day = day + 1;
      cout << "Cookies eaten on day " << day << ": ";
      cin >> eatenC;

      //determine max
      if (eatenC > max)
        max = eatenC;

      //determine if there are enough cookies in the jar
      if (cookies - eatenC < 0)
      {
        cout << "Not enough cookies!" << endl;
        return 1;
      }
      //determine the total
      cookies = cookies - eatenC;
    }

    //final output
    cout << "You ate " << jarred  << " cookies over " << day << " days."
         << endl;
    cout << "On your piggiest day you ate " << max << " cookies." << endl;
    return 0;
  }

