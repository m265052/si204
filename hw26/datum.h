    #pragma once
    #include <iostream>
    #include "hhmmss.h"
    #include "point.h"
    #include "datum.h"
    using namespace std;

    //--- A DATA READING FROM THE EXPERIMENT ----//
    struct datum
    {
        point position;
        hhmmss time;
    };
    istream& operator >> (istream& is, datum& D);