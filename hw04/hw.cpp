    //Will Pitkin   265052
    //hw04: 3 letter word in all caps turned into lowercase

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main() 
    {
        char first, second, third;

        cout << "Input a 3-letter word in uppercase letters: ";

        cin >> first >> second >> third;

            //design the equations to transform the letters

        int fNum, sNum, tNum;

        fNum = first + 32;       //32 decimal values between U and l-case
        sNum = second + 32;
        tNum = third + 32;

        char uFirst, uSecond, uThird;

        uFirst = fNum;
        uSecond = sNum;
        uThird = tNum;

        cout << "Output: " << uFirst << uSecond << uThird << endl;

        return 0;
    }