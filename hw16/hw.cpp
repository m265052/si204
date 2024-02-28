    //Will Pitkin       m265052
    //hw16              25Feb24
    //use functions to compare fractions in lowest terms

    #include <iostream>
    using namespace std;

    //declare prototypes
    void gcd(int nume, int deno);

    int main()
    {
        int numer, denom;
        char c;
        //while statement just needs to call the void function
        while (c != ';')
        {
            cin >> numer >> c >> denom >> c;
            gcd(numer, denom);
        }
        return 0;
    }

    //void function does the majority of the work
    void gcd(int nume, int deno)
    {
        int r, a, b;      //remainder
        a=nume;
        b=deno;
        //loop runs through gcd process:
        //if the gcd is 1, it is in lowest terms
        while (a % b > 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        if (b == 1)
            cout << nume << '/' << deno << " is in lowest terms!" << endl;
        else return;
    }