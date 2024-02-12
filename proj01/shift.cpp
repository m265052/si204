    //Will Pitkin       m265052
    //Proj01 Pt4        11Feb24
    //this part will implement the green screen with a shifted image

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
        int rs, cs;                     //row shift, column shift
        cout << "Row shift: ";
        cin >> rs;
        cout << "Column shift: ";
        cin >> cs;
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
        string headerfg, headerbg;
        int widthfg, heightfg, maxValuefg, rfg, gfg, bfg; 
        int rbg, gbg, bbg, widthbg, heightbg, maxValuebg;

        //take in the descriptive values of the files
        fin >> headerfg >> widthfg >> heightfg >> maxValuefg;
        fin2 >> headerbg >> widthbg >> heightbg >> maxValuebg;

        //determine if the row/column shift is allowed
        if(heightfg + rs > heightbg || widthfg + cs > widthbg)
        {
            cout << "Error: The foreground goes past the background" << endl;
            return 1;
        }

        //fout the size of the background image
        fout << headerbg << endl << widthbg << ' ' 
             << heightbg << endl << maxValuebg << endl;

        //for loop to read the rows
        for(int i=0; i < heightbg; i++)
        {
            //nested for loop to analyze each row
            for(int j=0; j < widthbg; j++)
            {
                //still take in the background image
                fin2 >> rbg >> gbg >> bbg;
                //determine where the row shift starts and ends
                //output the green screen effect in that area
                //the following parameters make the following statement only
                //happen if the row is within the rowshift and column (j) within
                //the column shift
                if((i >= rs && i <= rs + heightfg) && (j >= cs && j < cs + widthfg))
                {
                    fin >> rfg >> gfg >> bfg;
                    if(rfg == 0 && gfg == 255 && bfg == 0)
                    fout << rbg << ' ' << gbg << ' ' << bbg << ' ';
                    else fout << rfg << ' ' << gfg << ' ' << bfg << ' ';
                }
                else fout << rbg << ' ' << gbg << ' ' << bbg << ' ';
            }
        }
        cout << "Image saved to " << nameo << endl;
        return 0;
    } 