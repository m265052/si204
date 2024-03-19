    //Will Pitkin       m265052
    //Proj02            04Mar24
    //Create a deck of cards

    #include <iostream>
    using namespace std;

    int* cardvalue();
    //part 2 functions
    void deal(string, int*, int*, int*, int&, int&, int&);
    void print(string, int*, int*, int&, int&);
    
    int main()
    {
        cout << '[';
        int* card = cardvalue();

        for(int i=0; i < 52; i++)
        {
            if (i==51)
            cout << card[i] << ']';
            else cout << card[i] << ' ';
        }
        cout << endl;
        //create two variables that keep track of what card d and p are on
        int pNum = 0, dNum = 0, cCount=0;
        
        //create the two hands (both are arrays)
        int* pHand = new int[52];
        int* dHand = new int[52];

        //allow for more commands until player decides to quit
        //initialize s so the code will enter straight into loop
        string s = "word";
        while (s != "quit")
        {
            cout << "> ";
            cin >> s;
            if (s == "deal-p" || s == "deal-d")
                deal(s, card, pHand, dHand, pNum, dNum, cCount);

            else if (s == "print-p" || "print-d")
                print(s, pHand, dHand, pNum, dNum);

        }

        delete [] card;
        delete [] dHand;
        delete [] pHand;
        return 0;
    }

    int* cardvalue()
    {
        //establish card deck of 52 cards
        int n = 52;
        int* card = new int[n];

        //for loop to create the clubs (102-114)
        for(int i=0; i < 13; i++)
            card[i] = 102 + i;

        //for loop to create the diamonds (202-214)
        for(int i=13; i < 26; i++)
            card[i] = 202 - 13 + i;
        
        //loop to create the hearts (302-314)
        for(int i=26; i < 39; i++)
            card[i] = 302 - 26 + i;
        
        //loop to create the spades (402-414)
        for(int i=39; i < 52; i++)
            card[i] = 402 -39 + i;
        
        return card;
    }

    void deal(string s, int* card, int* pHand, int* dHand, int& pNum, int& dNum, int& cCount)
    {
        //these counters work everywhere bc of &
        if (s == "deal-p")
            {
                //takes a card value and puts it in players hand
                pHand[pNum] = card[cCount];
                pNum++;
            }
        else if (s == "deal-d")
            {
                //now the same for the dealers hand
                dHand[dNum] = card[cCount];
                dNum++;
            }

        //anytime a card is dealt, "get rid of it" by inc card count.
        cCount++;
    }

    void print(string s, int* pHand, int* dHand, int& pNum, int& dNum)
    {
        //check what the string read
        if (s == "print-p")
        {    
            cout << '[';
            //check if the player has a hand dealt to them
            if (pNum > 0)
            {
                for (int i=0; i < pNum; i++)
                {
                    if (i == pNum-1)
                        cout << pHand[i];
                    else cout << pHand[i] << ' ';
                }
            }
            cout << ']' << endl;
        }

        if (s == "print-d")
        {    
            cout << '[';
            //check if the dealer has a hand dealt to them
            if (dNum > 0)
            {
                for (int i=0; i < dNum; i++)
                {
                    if (i == dNum-1)
                        cout << dHand[i];
                    else cout << dHand[i] << ' ';
                }
            }
            cout << ']' << endl;
        }
    }