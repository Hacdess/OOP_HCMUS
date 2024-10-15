#include "Triangle.h"

int main()
{
    Point A;
    A.input();
    cout << "Inputted point: ";
    A.output();
    cout << endl;
    cout << "Distance to Ox: " << A.distanceToOx() << endl;
    cout << "Distance to Oy: " << A.distanceToOy() << "\n\n";

    Point B;
    B.input();
    cout << "Inputted point: ";
    B.output();
    cout << endl;
    cout << "Distance to Ox: " << B.distanceToOx() << endl;
    cout << "Distance to Oy: " << B.distanceToOy() << "\n\n";

    cout << "Distance from ";
    A.output();
    cout << " to ";
    B.output();
    cout << " is " << A.distance(B) << "\n\n";

    Triangle triangle;
    triangle.input();
    triangle.output();
    cout << endl;
    cout << "Is triangle: " << (triangle.isValidTriangle() ? "Yes" : "No") << endl;
    cout << "Type: " << triangle.type() << endl;
    cout << "Perimeter: " << triangle.perimeter() << endl;
    cout << "Area: " << triangle.area() << endl;
    cout << "Center G = ";
    triangle.center().output();

    return 0;
}