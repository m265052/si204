    //Will Pitkin       m265052
    //Proj02            04Mar24
    //Create a deck of cards

    #include <iostream>
    using namespace std;

    int* cardvalue();
    //part 2 functions (incomplete prototypes)
    void print();
    void deal();
    
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


        delete [] card;
    }

    int* cardvalue()
    {
        //establish card deck of 52 cards
        int n = 52;
        int* card = new int(n);

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