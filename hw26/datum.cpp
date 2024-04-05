    //datum definitions
    #include <iostream>
    #include "datum.h"
    using namespace std;

    istream& operator >> (istream& is, datum& D)
    {
        char c;
        return is >> c >> D.time >> c >> D.position >> c; 
    }