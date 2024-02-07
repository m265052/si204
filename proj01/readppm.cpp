    //Will Pitkin       m265052
    //Proj01 Pt1        05Feb24
    //this part will output the contents of rgb values organized for a ppm

    #include <iostream>
    #include <fstream>
    using namespace std;

    int main()
    {
        //simple: ask for file
        cout << "Input file: ";
        string name;
        cin >> name;
        fstream fin(name);

        //ensure the file exists
        if(!fin)
        {
            cout << "file does not exist" << endl;
            return 1;
        }

        //prepare to read the file
        string header;
        int width, height, maxValue, r, g, b;

        //take in the descriptive values of the file
        fin >> header >> width >> height >> maxValue;
        cout << header << endl;
        cout << "width = " << width << ", height = " << height << endl;
        cout << "max value = " << maxValue << endl;

        //for loop to read the rows
        for(int i=0; i < height; i++)
        {
            cout << "*** row " << i << " ***" << endl;
            //nested for loop to analyze each row
            for(int j=0; j < width; j++)
            {
            cout << "row " << i << ", col " << j << ": ";
            //take in and read out the red, green, and blue values
            fin >> r >> g >> b;
            cout << "r" << r << " g" << g << " b" << b << endl;
            }
        }
        return 0;
    }