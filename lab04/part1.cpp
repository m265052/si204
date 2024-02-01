    //Will Pitkin   m265052
    //Lab04Pt1      01Feb24
    //crunch data from weather (temp) report files into single avg values

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
        string s1, s2, date, time;      //date and time are the precursers to getting a temperature
        int i = 0;                      //must count the number to be able to take average
        double tempC, tempF, tempT, tempA;     // C = celcius    F = fahrenheit    T = total    A = avg
        tempT = 0;
        fin >> s1 >> s2;                //eliminate the first line
        while (fin >> date >> time) 
        {
            fin >> tempC;
            i = i + 1;                  //designate another counted temp
            tempF = (9/5.0) * tempC + 32;
            tempT = tempT + tempF;            
        }

        //compute the average
        tempA = tempT / i;

        //final output to user
        cout << "file: " << rep << endl << "ave: " << tempA << endl;
        return 0;
    }