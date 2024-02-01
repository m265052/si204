    //Will Pitkin   m265052
    //Lab04Pt2      01Feb24
    //avg computes, now make min and max and the days they happen

    #include <iostream>
    #include <fstream>
    using namespace std;
    
    int main()
    {
        //declare file input
        string rep;     //(report)
        cin >> rep;
        ifstream fin(rep);
        if (!fin)
        {
            cout << "Could not open file '" << rep << "'" << endl;
            return 1;
        }

        //begin reading the input file process
        string s1, s2, date, time, maxD, minD;      //date and time are the precursers to getting a temperature
        int i = 0;                      //must count the number to be able to take average
        double tempC, tempF, tempT, tempA, max, min;     // C = celcius    F = fahrenheit    T = total    A = avg
        tempT = 0;
        max = -100000000000000000;      //initialize max and min at unlikely values to be broken
        min = 100000000000000000;
        fin >> s1 >> s2;                //eliminate the first line
        while (fin >> date >> time) 
        {
            fin >> tempC;
            i = i + 1;                      //designate another counted temp
            tempF = (9/5.0) * tempC + 32;   //5.0 allows the fraction to compute as a double

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