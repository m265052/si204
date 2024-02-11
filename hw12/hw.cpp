    //Will Pitkin       m265052
    //hw12              08Feb24
    //create a box of stars
    #include <iostream>
    using namespace std;
    int main()
    {
        //declare variables and take input from user to form box
        int height, width, offset;
        cout << "Enter height (greater than 2): ";
        cin >> height;
        cout << "Enter width (greater than 2): ";
        cin >> width;
        cout << "Enter offset: ";
        cin >> offset;

        //begin constructing the box
        //start with the height since it determines each line
        for(int i=0; i < height; i++)
        {
            
            //spacing for the offset
            for(int spaceo=0; spaceo < offset; spaceo++)
            cout << ' ';
            //if statement to determine if first or last line
            if(i==0 || i == height-1)
            {
                for(int star=0; star < width; star++)
                cout << '*';
            }
            else
            {
                cout << '*';
                //spaceb is box inner spacings
                for(int spaceb=0; spaceb < width-2; spaceb++)
                cout << ' ';
                cout << '*';
            }
            cout << endl;
        }
        return 0;
    }