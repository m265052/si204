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
        // read your characters as in part 2
        // draw them with drawChar() calls
        for(int i=0; i < n; i++)
        {
            drawChar(P[i].name, P[i].x, P[i].y);
            usleep(800000);
        }
        // call refreshWindow() (only once) to show what you drew on the screen
        // sleep for 80,000 micro-seconds (i.e., 0.08 sec).

        for(int frame=0; frame < 20; frame++)
        {
        // Move all characters one step:
        //   1. erase them in the old positions with drawChar() calls
        //   2. compute the new positions for characters (based on the direction 
        //      of each character)
        //   3. draw them in the new positions with drawChar() calls
        // Call refreshWindow() (only once) to show what you drew on the screen

        usleep(80000); // sleep for 80,000 micro-seconds (i.e., 0.08 sec).
                        // This corresponds to flipping to the next "frame" in 
                        //  an animation.
                        // The program is drawing about 12.5 (= 1/0.08) frames 
                        //  per second.
        }

        // exit the program right away; you don't need to take any user input
                

        endCurses();

        delete [] P;
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