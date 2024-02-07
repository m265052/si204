    //Will Pitkin   m265052
    //Lab04Pt4      06Feb24
    //continuation: now all in Fahrenheit atuomatically, and make it produce the input file as an output
    //make graph and make it average days

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
        string s1, s2, date, maxD, minD, timeJunk;      //date and time are the precursers to getting a temperature
        int time = 0;             //convert the time into 24 hour clock and just output the hour later
        int i = 0;                      //must count the number to be able to take average
        double tempF, tempC, tempT, tempA, max, min;     //F = fahrenheit   C = celcius    T = total    A = avg
        tempT = 0;
        max = -100000000000000000;      //initialize max and min at unlikely values to be broken
        min = 100000000000000000;
        fin >> s1 >> s2;                //eliminate the first line
        while (fin >> date >> timeJunk) 
        {
            fin >> tempC;
            tempF = (9/5.0) * tempC + 32;
            i = i + 1;                  //designate another counted temp
            time++;                     //turn time into 24 hour

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
            //create if statement that tracks and separates the days
            if(time == 1)
            fout << date << "\t" << tempF << "\t";      //outputs the last value and next date
            else if(time == 24)
            {
            fout << tempF << endl;
            time = 0;
            }
            else fout << tempF << "\t";
            tempT = tempT + tempF;            
        }

        //compute the average
        tempA = tempT / i;

        //final output to user
        cout << "file: " << rep << endl << "ave: " << tempA << endl
             << "min: " << min << " on " << minD << endl
             << "max: " << max << " on " << maxD << endl
             << "output in: " << repo << endl;
        return 0;
    }