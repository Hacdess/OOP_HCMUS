#include "Triangle.h"

int main() {
    // Triangle::Default constructor
    Triangle triangle1;
    cout << triangle1.toString() << "\n\n";

    // Triangle::Constructor with 1 argument
    Point2D point1(2, 3);
    Triangle triangle2(point1);
    cout << triangle2.toString() << "\n\n";

    // Triangle::Constructor with 3 arguments
    Point2D A(1,0), B(-1,0), C(0,1);
    Triangle triangle3(A, B, C);
    cout << triangle3.toString() << "\n\n";

    // Triangle::Copy constructor
    Triangle triangle4(triangle3);
    cout << triangle4.toString() << "\n\n";

    // Triangle::Constructor from string
    string s = "(2,3)-(4,3)-(3,4)";
    Triangle triangle5(s);
    cout << triangle5.toString() << "\n\n";

    // Triangle::clone
    Triangle* triangle6 = triangle5.clone();
    cout << triangle6->toString() << "\n\n";
    delete triangle6;

    return 0;
}