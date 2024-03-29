    //Will Pitkin       m265052
    //Proj02            18Mar24
    //Create hit and stand in rounds in BlackJack
    //shuffle deck

    #include <iostream>
    #include <cstdlib>
    using namespace std;

    int* cardvalue();
    int* shuffle(int*);
    void deal(int*, int*, int*, int&, int&, int&, string&);
    void print(int*, int*, int&, int&);
    
    int main()
    {
        //let the user shuffle the deck
        cout << "Shuffle: [n | u <seed>]: ";
        char shuf;
        int seed;
        cin >> shuf;
        if (shuf == 'u')
        {
            cin >> seed;
            srand(seed);
        }

        cout << '[';
        int* card = cardvalue();
        //shuffle the deck here, if the user wants
        if (shuf == 'u')
            card = shuffle(card);

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

        char c = 'a';
        string turn;
        int round = 1;

        //start the game by running the starting hands
        for (int i=0; i < 2; i++)
        {
            turn = "Play";
            deal(card, pHand, dHand, pNum, dNum, cCount, turn);
            turn = "Deal";
            deal(card, pHand, dHand, pNum, dNum, cCount, turn);
        }
        print(pHand, dHand, pNum, dNum);

        //only want 3 rounds
        while (round < 4)
        {
            //start with player's turn
            turn = "Play";
            cout << "Round " << round << ' ' << turn << "er's turn" << endl;
            cout << "hit or stand ? [h/s] ";
            cin >> c;
            if (c == 'h')
                deal(card, pHand, dHand, pNum, dNum, cCount, turn);

            print(pHand, dHand, pNum, dNum);

            turn = "Deal";
            cout << "Round " << round << ' ' << turn << "er's turn" << endl;
            cout << "hit or stand ? [h/s] ";
            cin >> c;
            if (c == 'h')
                deal(card, pHand, dHand, pNum, dNum, cCount, turn);

           print(pHand, dHand, pNum, dNum);

            round++;
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

    int* shuffle(int* card)
    {
        int j, temp;
        //do exactly as p4 tells, making j random and replacing each i with it
        for(int i=0; i < 52; i++)
        {
            j = rand() % 52;
            temp = card[j];
            card[j] = card[i];
            card[i] = temp;
        }
        return card;
    }

    void deal(int* card, int* pHand, int* dHand, int& pNum, int& dNum, 
              int& cCount, string& turn)
    {
        //these counters work everywhere bc of &
        if (turn == "Play")
            {
                //takes a card value and puts it in players hand
                pHand[pNum] = card[cCount];
                pNum++;
            }
        else if (turn == "Deal")
            {
                //now the same for the dealers hand
                dHand[dNum] = card[cCount];
                dNum++;
            }

        //anytime a card is dealt, "get rid of it" by inc card count.
        cCount++;
    }

    void print(int* pHand, int* dHand, int& pNum, int& dNum)
    {
        //check what the string read

            cout << endl << "Player: [";
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

            cout << "Dealer: [";
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
            cout << ']' << endl << endl;
    }