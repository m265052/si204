    //function definitions
    #include <iostream>
    #include "point.h"
    using namespace std;    

    istream& operator >> (istream& is, point &p)
    {
        char c;
        return is >> c >> p.x >> c >> p.y >> c;
    }

    ostream& operator << (ostream& os, point p)
    {
        return os << '(' << p.x << ',' << p.y << ')';
    }
