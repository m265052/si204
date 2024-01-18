    //Will Pitkin       265052
    //Lab02 p1          18Jan2024
    //converting binary to decimal

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main ()
    {
        char threes, twos, ones, zeros;
        
                //The idea with these variable names is that "threes" represents the furthest
                //left bit (2^3), followed by "twos," and so on.

        cout << "Enter a 4-bit binary number: ";

        cin >> threes;
        cin >> twos;
        cin >> ones;
        cin >> zeros;

        int decNot;
                
                //decNot = decimal notation. decNot will be used in math equation following
                //Convert the characters from ascii to decimal

        int threesi, twosi, onesi, zerosi;

                //the following conversions use the ascii values of the characters '0' and '1'.
                //those two values correspond to 48 and 49 in decimal respectively.
                //characters used in math expressions are converted to their decimal value,
                //so the following are actually subtracting '0' from '1' OR '0' which is the
                //same as subtracting 48 from 48 OR 49.

        threesi = threes - '0';
        twosi = twos - '0';
        onesi = ones - '0';
        zerosi = zeros - '0';

        decNot = (threesi * 8) + (twosi * 4) + (onesi * 2) + (zerosi * 1);
        
        cout << "In decimal " << threes << twos << ones << zeros << " = " << decNot << endl;

        return 0;
    }