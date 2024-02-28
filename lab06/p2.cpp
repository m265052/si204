    //Will Pitkin       m265052
    //Lab06 pt2         22Feb24
    //"craps" dice game
    //throw dice: house wins if roll is 2,3, or 12
    //            player wins if roll is 7 or 11
    //rolls continue until a winner

    #include <cstdlib>
    #include <iostream>
    using namespace std;

    //new prototype different than pt1
    //throwdice throws 2 dice, not 1
    int throwdice();

    int main()
    {
        cout << "Enter seed value: ";
        int seed;
        cin >> seed;
        srand(seed);

        //compare the rolled value to determine win

        int rollBig = throwdice();
        while(rollBig != 0 && rollBig != -1)          //going to need loop that repeats until winner
        {
            cout << " roll again" << endl;
            rollBig = throwdice();
        }

        if (rollBig == 0)
        {
            cout << " Player wins!" << endl;
            return 0;
        }
        else if (rollBig == -1)
        {
            cout << " House wins!" << endl;
            return 0;
        }
    }
    //define throwdice
    int throwdice()
    {
        int dice1 = rand()%8;
        while(dice1 == 0 || dice1 == 7)
        dice1 = rand()%8;
        int dice2 = rand()%8;
        while(dice2 == 0 || dice2 == 7)
        dice2 = rand()%8;

        //add the dice then compare
        int rollSum = dice1 + dice2;
        int returnVal;

        //cout the roll no matter the determination, which is made in main
        cout << "Player rolled " << dice1 << " + " << dice2 << " = " << rollSum;

        if(rollSum == 7 || rollSum == 11)
        returnVal = 0;
        else if(rollSum == 2 || rollSum == 3 || rollSum == 12)
        returnVal = -1;
        else returnVal = rollSum;

        return returnVal;
    }