    //Will Pitkin   m265052
    //Lab04Pt3      01Feb24
    //continuation: now all in Fahrenheit atuomatically, and make it produce the input file as an output

    #include <iostream>
    #include <fstream>
    using namespace std;
    
    int main()
    {
        //declare file input
        string rep, repo;     //(report)
        cin >> rep >> repo;
        ifstream fin(rep);
        ofstream fout(repo);
        if (!fin)
        {
            cout << "Could not open file '" << rep << "'" << endl;
            return 1;
        }

        //begin reading the input file process
        string s1, s2, date, time, maxD, minD;      //date and time are the precursers to getting a temperature
        int i = 0;                      //must count the number to be able to take average
        double tempF, tempT, tempA, max, min;     //F = fahrenheit    T = total    A = avg
        tempT = 0;
        max = -100000000000000000;      //initialize max and min at unlikely values to be broken
        min = 100000000000000000;
        fin >> s1 >> s2;                //eliminate the first line
        fout << "day" << "\t" << s1 << "\t" << s2;      // "\t" inserts a tab 
        while (fin >> date >> time) 
        {
            fin >> tempF;
            i = i + 1;                  //designate another counted temp

            //compute max and min to be stored 
            if (tempF > max)
            {
                max = tempF;
                maxD = date;
            }
            if (tempF < min)
            {
                min = tempF;
                minD = date;
            }
            fout << date << " " << time << "\t" << tempF;

            tempT = tempT + tempF;            
        }

        //compute the average
        tempA = tempT / i;

        //final output to user
        cout << "file: " << rep << endl << "ave: " << tempA << endl
             << "min: " << min << " on " << minD << endl
             << "max: " << max << " on " << maxD << endl;
        return 0;
    }