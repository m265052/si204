    //Will Pitkin       m265052
    //Lab11 pt2         11APR24
    //fractals, cantor set working
    #include <iostream>
    using namespace std;
    
    void repeat(string, int);
    void cantor_row(int length);

    int main()
    {
        cout << "size: ";
        int length;
        cin >> length;

        //string to fill the empty spaces
        string s = "_";

        cout << "Width-" << length << " Cantor set: " << endl;

        //cantor sets are in lengths of 3
        //therefore, call it with 1/3 of the length 3 times
        cantor_row(length);

        cout << endl;

        return 0;
    }

    void repeat(string s, int count)
    {
        if (count==0)
            return;
        else 
        {
        cout << s;
        return repeat(s, count-1);
        }
    }

    void cantor_row(int length)
    {
        if (length == 1)
            cout << 'X';
        else
        {
            cantor_row(length/3);
            repeat("_", length/3);
            cantor_row(length/3);
        }
    }