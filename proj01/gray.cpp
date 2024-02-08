    //Will Pitkin       m265052
    //Proj01 Pt2        05Feb24
    //this part will output the contents of rgb values organized for a ppm and make them grayscale

    #include <iostream>
    #include <fstream>
    using namespace std;

    int main()
    {
        //simple: ask for file
        cout << "Input file: ";
        string name, nameo;
        cin >> name;
        ifstream fin(name);
        //also  printing to an output file
        cout << "Output file: ";
        cin >> nameo;
        ofstream fout(nameo);

        //ensure the file exists
        if(!fin)
        {
            cout << "Error: Input file not found" << endl;
            return 1;
        }

        //prepare to read the file
        string header;
        int width, height, maxValue, r, g, b, gray;

        //take in the descriptive values of the file
        fin >> header >> width >> height >> maxValue;
        //put these back in place in new ppm
        fout << header << endl << width << " " << height << endl << maxValue << endl;

        //for loop to read the rows
        for(int i=0; i < height; i++)
        {
            //nested for loop to analyze each row
            for(int j=0; j < width; j++)
            {
            //take in and read out the red, green, and blue values
            fin >> r >> g >> b;
            gray = (r + b + g) / 3.0;
            fout << gray << " " << gray << " " << gray << " ";
            }
        }
        cout << "Image saved to " << nameo << endl;
        return 0;
    }