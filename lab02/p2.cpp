    //Will Pitkin       265052
    //Lab02 p2          18Jan2024
    //converting decimal to binary

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main ()
    {
        //user enters number between 0 and 15 (so that it can be represented by 4 bits)

    cout << "Enter a number between 0 and 15: ";
     
    int num;

    cin >> num;
    
    int threes, twos, ones, zeros;
        
        //these numbers will the integers 1 or 0 that will be printed out side by side.
        //I subtracted all the previous most significant bits so each integer only yields a
        //1 or 0.

    threes = num / 8;
    twos = (num - threes *8) / 4;
    ones = (num - threes *8 - twos *4) / 2;
    zeros = (num - threes *8 - twos *4 - ones *2) / 1;

    cout << num << " in binary is " << threes << twos << ones << zeros << endl;

    return 0;
    }