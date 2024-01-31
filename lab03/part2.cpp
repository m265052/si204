    //Will Pitkin       m265052
    //Lab03 part2       28Jan24
    //Classifying triangles

    #include <iostream>
    #include <cmath>
    using namespace std;

    int main()
    {
    double side1, side2, side3, a, b, c;
    cout << "Enter side lengths: ";
    cin  >> side1 >> side2 >> side3;
        
    //determine the longest side and denote it as c

    if (side1 >= side2 && side1 >= side3) {
        c = side1;
        a = side2;
        b = side3;
    }
    else if (side2 >= side1 && side2 >= side3) {
        c = side2;
        a = side1;
        b = side3;
    }
    else if (side3 >= side1 && side3 >= side2) {
        c = side3;
        a = side1;
        b = side2;
    }
    else {
    cout << "Error! these lengths violate the traingle inequality!" << endl;
    return 1;
    } 

    //determine if the lengths constitute a traingle

    if (a + b <= c) {
    cout << "Error! these lengths violate the triangle inequality!" << endl;
    return 1;
    }

    //begin to classify triangles
    //starting with obstuse, acute, or right

    string angle;       //angle type to be determined
    if (a*a + b*b == c*c)
    angle = "right";
    if (a*a + b*b > c*c)
    angle = "acute";
    if (a*a + b*b < c*c)
    angle = "obtuse";

    //determine equilateral, isosceles, or scalene

    string type;
    if (a == b && a == c)
    type = "equilateral";
    if (a != b && a != c && b != c)
    type = "scalene";
    if ((a == b || a == c || b == c) && !(a == b && a == c))
    type = "isosceles";

    //output final determination

    cout << "This is a " << angle << " " << type << " triangle." << endl;
    return 0;
    }