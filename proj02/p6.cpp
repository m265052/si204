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
    void score(int*, int*, int, int);
    
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

        int* card = cardvalue();
        //shuffle the deck here, if the user wants
        if (shuf == 'u')
            card = shuffle(card);

    //got rid of deck print here

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
        score(pHand, dHand, pNum, dNum);

        //create variable to track when both parties stand
        int stand = 0;
        bool pStand = false, dStand = false;

        while (stand < 2)
        {
            //check if dealer stood in previous round, then reset dStand
            if (dStand == false)
                stand = 0;
            dStand = false;

            //start with player's turn
            turn = "Play";
            cout << "Round " << round << ' ' << turn << "er's turn" << endl;
            cout << "hit or stand ? [h/s] ";
            cin >> c;
            if (c == 'h')
                deal(card, pHand, dHand, pNum, dNum, cCount, turn);
            else 
            {
                stand++;
                pStand = true;
            }
                

            //reinitialize stand here in case dealer stood first
            if (pStand == false)
                stand = 0;
            pStand = false;

            print(pHand, dHand, pNum, dNum);
            score(pHand, dHand, pNum, dNum);

            //end loop if stand = 2
            if (stand == 2)
                break;
            
            turn = "Deal";
            cout << "Round " << round << ' ' << turn << "er's turn" << endl;
            cout << "hit or stand ? [h/s] ";
            cin >> c;
            if (c == 'h')
                deal(card, pHand, dHand, pNum, dNum, cCount, turn);
            else 
            {
                stand++;
                dStand = true;
            }

           print(pHand, dHand, pNum, dNum);
           score(pHand, dHand, pNum, dNum);

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
        //source code for designs given:
        string clubs = "\u2663";
        string diamonds = "\u2666";
        string hearts = "\u2665";
        string spades = "\u2660";
        string suit;

        int sVal, fVal, cVal;        //suit, face, card value

        //find max length of decks
        int max;
        if (pNum < dNum)
            max = dNum;
        else if (pNum > dNum)
            max = pNum;
        //doesnt matter if theyre equal
        else max = pNum;

        cout << endl << " Player Dealer " << endl;

        for (int i=0; i < max; i++)
        {
            cVal = pHand[i];
            cout << "| ";

            sVal = cVal / 100;
            fVal = cVal % 100;

            //check if the full deck has been printed
            if (i < pNum)
            {
                //determine suit
                if (sVal == 1)
                    suit = clubs;
                else if (sVal == 2)
                    suit = diamonds;
                else if (sVal == 3)
                    suit = hearts;
                else if (sVal == 4)
                    suit = spades;

                //actually print suit, but first determine face
                if (fVal < 10)
                    cout << ' ' << fVal << suit;
                else if (fVal == 10)
                    cout << fVal << suit;
                else if (fVal == 11)
                    cout << " J" << suit;
                else if (fVal == 12)
                    cout << " Q" << suit;
                else if (fVal == 13)
                    cout << " K" << suit;
                else if (fVal == 14)
                    cout << " A" << suit;
            }
            else cout << "   ";
            cout << "  |  ";

            cVal = dHand[i];
            sVal = cVal / 100;
            fVal = cVal % 100;

            //check if full deck has been printed
            if (i < dNum)
            {
                if (sVal == 1)
                    suit = clubs;
                else if (sVal == 2)
                    suit = diamonds;
                else if (sVal == 3)
                    suit = hearts;
                else if (sVal == 4)
                    suit = spades;

                if (fVal < 10)
                    cout << ' ' << fVal << suit;
                else if (fVal == 10)
                    cout << fVal << suit;
                else if (fVal == 11)
                    cout << " J" << suit;
                else if (fVal == 12)
                    cout << " Q" << suit;
                else if (fVal == 13)
                    cout << " K" << suit;
                else if (fVal == 14)
                    cout << " A" << suit;
            }
            else cout << "   ";
            cout << "  |" << endl;
        }
    }

    void score(int* pHand, int* dHand, int pNum, int dNum)
    {
        int pTotal = 0, dTotal = 0;
        //counter
        int cVal;
        //track if there is an ace to decide if ace should equal 11
        bool aTp = false, aTd = false;         //ace tracker p/d

        for (int i=0; i < pNum; i++)
        {
            cVal = pHand[i] % 100;
            //turn face cards into 10 and ace into 1
            if (cVal == 11 || cVal == 12 || cVal == 13)
                cVal = 10;
            else if (cVal == 14)
            {
                cVal = 1;
                aTp = true;
            }
            pTotal = pTotal + cVal;
        }
        if (aTp == true && pTotal <= 11 )
            pTotal = pTotal + 10;

        for (int i=0; i < dNum; i++)
        {
            cVal = dHand[i] % 100;
            if (cVal == 11 || cVal == 12 || cVal == 13)
                cVal = 10;
            if (cVal == 14)
            {
                cVal = 1;
                aTd = true;
            }
            dTotal = dTotal + cVal;
        }
        if (aTd == true && dTotal <= 11 )
            dTotal = dTotal + 10;

        cout << "Player " << pTotal << ", Dealer " << dTotal << endl;
    }