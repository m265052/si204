    //Will Pitkin       m265052
    //hw08              30Jan24
    //sort student grades

    #include <iostream>
    #include <fstream>
    #include <cmath>
    using namespace std;

    int main()
    {
        //setup for file 
        cout << "Filename: ";
        string fname;
        cin >> fname;
        ifstream fin(fname);
        
        //checking for file existence

        if(!fin)
        {
            cout << "File does not exist.";
            return 1;
        }

        //read file contents
        //ignore s1-4, name will be used in while loop

        string s1, s2, s3, s4, name, nameBest;
        int hw, quiz, exam;
        double grade, gradeBest;

        fin >> s1 >> s2 >> s3 >> s4;
        
        //best student setup
        gradeBest = 0;

        while (fin >> name)
        {
            fin >> hw >> quiz >> exam;
            grade = 0.2*hw + 0.2*quiz + 0.6*exam;
            cout << name << "   " << grade << endl;
            if(grade > gradeBest) {
            gradeBest = grade; 
            nameBest = name;
            }
        }
        //conclusion: best student output
        cout << "The best student is " << nameBest << "." << endl;
        return 0;
    }