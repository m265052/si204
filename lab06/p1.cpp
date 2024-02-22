    //Will Pitkin       m265052
    //Lab06 pt1         22Feb24
    //rolls random die a few times

    #include <cstdlib>
    #include <iostream>
    using namespace std;

    //declare prototype:
    //parenthesis stays empty bc there is no variable to call in it
    //the function rolldie runs internally when the program runs
    //having a parameter
    //stating prototype here allows us to make it at end bc compiler will know
    //that it exists
    int rolldie();

    int main()
    {
        //seed rand() by asking for input from user
        int seed; 
        cout << "Enter seed value: ";
        cin >> seed;
        srand(seed);

        //create the dice rolls
        for(int i = 0; i < 5; i++)
        {
            int roll1, roll2, rollSum;
            //even though both rolls call rolldie, it will do it each time
            roll1 = rolldie();
            roll2 = rolldie();
            rollSum = roll1 + roll2;
            cout << "Player rolled " << roll1 << " + " << roll2
                 << " = " << rollSum << endl;
        }

        return 0;
    }
    //define rolldie() to be called into
    int rolldie()
    {
        //call from the function rand
        //even though this is at the end after int main, this still can be
        //recalled in int main
        int num = rand()%8;
        while (num == 0 || num == 7)
        num = rand()%8;
        return num;
    }