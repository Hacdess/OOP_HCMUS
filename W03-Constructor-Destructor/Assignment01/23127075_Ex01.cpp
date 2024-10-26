#include "Point2D.h"

int main() {
    // Default constructor
    Point2D A;
    cout << "A = " << A.toString() << "\n\n";

    // Parameterized constructor
    Point2D B(4, 5);
    cout << "B = " << B.toString() << "\n\n";

    // Copy constructor
    Point2D C(B);
    cout << "C = " << C.toString() << "\n\n";

    // Move constructor
    Point2D D = move(C);
    cout << "D = " << D.toString() << "\n";
    cout << "C = " << C.toString() << "\n\n";

    // String-extracting constructor
    string s = "15,-2";
    Point2D E(s);
    cout << "E = " << E.toString() << "\n\n";

    // Clone
    Point2D* F = E.clone();
    cout << "F = " << F->toString() << "\n\n";
    delete F;

    return 0;
}