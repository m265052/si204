    //Will Pitkin       m265052
    //hw05              25Jan24
    //determine if a year is a leap year

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main () 
    {
        int year;
        cout << "Enter year: ";
        cin  >> year;

            //write if statements to determine if year is a leap year
        
        if (year % 4 != 0)
        cout << "Is Not Leap Year" << endl;
        
        else if (year % 100 == 0 && year % 400 == 0 ||  //must be entirely divisible or not
                 year % 100 != 0 && year % 400 != 0)
        cout << "Is Leap Year" << endl;

        else cout << "Is Not Leap Year" << endl;

        return 0; 
    }