    #include <iostream>
    #include <unistd.h>
    #include <cstdlib>
    #include "easycurses.h"
    using namespace std;

    struct point
    {
        char name;
        int x;
        int y;
    };

    void clearPoints(point*, int);

    int main()
    {
        int n, x, y;
        char name, tr, c;
        //n is the number of points, tr is trash
        cin >> n;
        //declare point array to store inputs from the user
        point* P = new point[n];

        for(int i=0; i < n; i++)
        {
            cin >> name >> tr >> x >> tr >> y >> tr;
            P[i].name = name;
            P[i].x = x;
            P[i].y = y;
        }

        startCurses();

        do{
            
            //for loop to draw the points one by one
            for(int i=0; i < n; i++)
            {
                drawCharAndRefresh(P[i].name, P[i].x, P[i].y);
                usleep(800000);
            }

            clearPoints(P, n);

            // Loop forever until user enters 'q'
            c = inputChar();

        } while ( c!= 'q' );

        endCurses();

        delete  [] P;
        return 0;
    }

    void clearPoints(point* P, int n)
    {
        //create another point* so that the copy can be printed blank
        point* B = new point [n];
        //replace each part of the point with a blank space
        //drawChar() after each as well
        for(int i=0; i < n; i++)
        {
            B[i].name = ' ';
            B[i].x = P[i].x;
            B[i].y = P[i].y;
            drawChar(B[i].name, B[i].x, B[i].y);
        }
        //when this is done, refresh
        refreshWindow();
        usleep(800000);

        delete [] B;
    }