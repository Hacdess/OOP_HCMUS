#include "Triangle.h"

int main() {
    // Default constructor
    Triangle triangle1;
    cout << "Triangle 1: " << triangle1.toString() << "\n\n";

    // Triangle::Parameterized constructor
    Point2D A(1,0), B(-1,0), C(0,1);
    Triangle triangle2(A, B, C);
    cout << "Triangle 2: " << triangle2.toString() << "\n\n";

    // Triangle::Copy constructor
    Triangle triangle3(triangle2);
    cout << "Triangle 3: " << triangle3.toString() << "\n\n";

    // Move constructor
    Triangle triangle4 = move(triangle3);
    cout << "Triangle 4: " << triangle4.toString() << "\n";
    cout << "Triangle 3: " << triangle3.toString() << "\n\n";

    // String-extracting constructor
    string s = "(2,3)-(4,3)-(3,4)";
    Triangle triangle5(s);
    cout << "Triangle 5: " << triangle3.toString() << "\n\n";

    // Clone
    Triangle* triangle6 = triangle5.clone();
    cout << triangle6->toString() << "\n\n";
    delete triangle6;

    return 0;
}