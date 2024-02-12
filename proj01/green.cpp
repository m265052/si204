    //Will Pitkin       m265052
    //Proj01 Pt3        07Feb24
    //this part will make a rudimentary functional greenscreen

    #include <iostream>
    #include <fstream>
    using namespace std;

    int main()
    {
        //ask for the foreground file, then the background
        cout << "Foreground file: ";
        string namef, nameb, nameo;     //name: foreground, background, output
        cin >> namef;
        cout << "Background file: ";
        cin >> nameb;
        ifstream fin(namef);        //foreground fin
        ifstream fin2(nameb);       //background fin2
        //print to an output file
        cout << "Output file: ";
        cin >> nameo;
        ofstream fout(nameo);

        //ensure the files exist
        if(!fin || !fin2)
        {
            cout << "Error: Input file not found" << endl;
            return 1;
        }

        //prepare to read the files
        string header, header2;
        int width, height, maxValue, r, g, b, r2, g2, b2, width2, height2, maxValue2;

        //take in the descriptive values of the files and confirm they match
        fin >> header >> width >> height >> maxValue;
        fin2 >> header2 >> width2 >> height2 >> maxValue2;
        if( width != width2 || height != height2)
        {
            cout << "Error: Images have different sizes" << endl;
            return 1;
        }
        //put these back in place in new ppm
        else fout << header << endl << width << ' ' << height << endl << maxValue << endl;

        //for loop to read the rows
        for(int i=0; i < height; i++)
        {
            //nested for loop to analyze each row
            for(int j=0; j < width; j++)
            {
            //take in and read out the red, green, and blue values
            //check if greenscreen and if so, fout the background pixels
            fin >> r >> g >> b;
            fin2 >> r2 >> g2 >> b2;
            if(r == 0 && g == 255 && b == 0)
            fout << r2 << ' ' << g2 << ' ' << b2 << ' ';
            else fout << r << ' ' << g << ' ' << b << ' ';
            }
        }
        cout << "Image saved to " << nameo << endl;
        return 0;
    } 