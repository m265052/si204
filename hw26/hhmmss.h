    #pragma once
    #include <iostream>
    using namespace std;

    //--- TIME IN HH:MM:SS ----------------------//
    struct hhmmss
    {
        int h,m,s;
    };
    istream& operator >> (istream& is, hhmmss& T);
    bool operator < (hhmmss a, hhmmss b);