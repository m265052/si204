    //Will Pitkin       265052
    //hw03              18Jan2024
    //this code will subtract feet and inches

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main() 
    {
        cout << "Enter two lengths in feet and inches (larger first!)" << endl;

        int feetNum, inchNum, feetDen, inchDen;     //(numerator and denominator)
        char apos1, apos2, apos3, apos4, apos5, apos6;    //apostrophes user inputs
    
        cin  >> feetNum;            //user inputs values
        cin  >> apos1;

        cin  >> inchNum;
        cin  >> apos2 >> apos3;
        //cout << endl;
        //cout << '\'' << endl;       //neccessary to write quotation mark

        cin  >> feetDen;
        cin  >> apos4;

        cin  >> inchDen;
        cin  >> apos5 >> apos6;
        //cout << endl;

            //convert the numerator and denominator to inches
        
        int convNum, convDen;

        convNum = feetNum *12 + inchNum;
        convDen = feetDen *12 + inchDen;

            //perform subraction and convert back to feet and inches

        int diff, diffFeet, diffInch;       //(difference, difference converted)

        diff = convNum - convDen;

        diffFeet = diff / 12;
        diffInch = diff % 12;

            //display result
        
        cout << "Difference is " << diffFeet << "' " << diffInch << "''" << endl;

        return 0;
    }