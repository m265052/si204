    //Will Pitkin       m265052
    //Lab11 pt3         11APR24
    //fractals, cantor set full
    #include <iostream>
    using namespace std;
    
    void repeat(string, int);
    void cantor_row(int, int);
    int calculateLevels(int, int);

    int main()
    {
        cout << "size: ";
        int width;
        cin >> width;

        //string to fill the empty spaces
        string s = "_";

        cout << "Width-" << width << " Cantor set: " << endl;

        //fuctions to define the levels
        int levels = 0;
        levels = calculateLevels(width, levels);

        //for loop that the level corresponds to what row the cantor immitates
        //from part 2. the loop is repeated width number of times
        //implement with a nested for loop of widths within levels (rows, cols)
        //i goes up to equal bc that is how the math works with powers
        for (int i=0; i <= levels; i++)
        {
            cantor_row(i, width);
            //end line after each level
            cout << endl;
        }
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

    void cantor_row(int i, int width)
    {
        if (i == 0)
            repeat("X",width);
        else
        {
        //cantor sets are in lengths of 3
        //level has already been scaled in calculating from the width
            cantor_row(i-1, width/3);
            repeat("_", width/3);
            cantor_row(i-1, width/3);
        }
    }

    int calculateLevels(int width, int levels)
    {
        if (width == 1)
            return levels;
        else
        {
            levels++;
            return calculateLevels(width/3, levels);
        }
    }