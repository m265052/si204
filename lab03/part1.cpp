    //Will Pitkin   m265052
    //lab03         25Jan24
    //part1: bounding box and triangle in gnuplot

    #include <iostream>
    using namespace std;

    int main() 
    {
        double x1, y1, x2, y2, x3, y3;                  //input coordinates
        char p1, c1, p2, p3, c2, p4, p5, c3, p6;        //skip over the parenthesis and commas

        cin >> p1 >> x1 >> c1 >> y1 >> p2 
            >> p3 >> x2 >> c2 >> y2 >> p4
            >> p5 >> x3 >> c3 >> y3 >> p6;

            //must determine the greatest and least x and y values to obtain corners of box
        double xGreatest, xLeast, yGreatest, yLeast;

            //comparison to determine the greatest x value
        if (x1 >= x2 && x1 >= x3)
            xGreatest = x1;
        else if (x2 >= x1 && x2 >= x3)
            xGreatest = x2;
        else xGreatest = x3;

            //comparison to determine the least x value
        if (x1 <= x2 && x1 <= x3)
            xLeast = x1;
        else if (x2 <= x1 && x2 <= x3)
            xLeast = x2;
        else xLeast = x3;

            //comparison to determine the greatest y value
        if (y1 >= y2 && y1 >= y3)
            yGreatest = y1;
        else if (y2 >= y1 && y2 >= y3)
            yGreatest = y2;
        else yGreatest = y3;

            //comparison to determine the least y value
        if (y1 <= y2 && y1 <= y3)
            yLeast = y1;
        else if (y2 <= y1 && y2 <= y3)
            yLeast = y2;
        else yLeast = y3;

            //output the coordinates for the box

        cout << xLeast << " " << yLeast << endl
             << xLeast << " " << yGreatest << endl
             << xGreatest << " " << yGreatest << endl
             << xGreatest << " " << yLeast << endl << endl;

            //output the traingle coordinates

        cout << x1 << " " << y1 << endl
             << x2 << " " << y2 << endl
             << x3 << " " << y3 << endl;
        
        return 0;
    }