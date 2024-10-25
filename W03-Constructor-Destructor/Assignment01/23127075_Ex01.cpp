#include "Point2D.h"

int main() {
    // Point2D::Default constructor
    Point2D A;
    cout << "A = " << A.toString() << "\n\n";

    // Point2D::Constructor with 1 argument
    Point2D B(3);
    cout << "B = " << B.toString() << "\n\n";

    // Point2D::Constructor with 2 arguments
    Point2D C(4, 5);
    cout << "C = " << C.toString() << "\n\n";

    // Point2D::Copy constructor
    Point2D D(C);
    cout << "D = " << D.toString() << "\n\n";
    
    // Point2D::Constructor from string
    string s = "15,-2";
    Point2D E(s);
    cout << "E = " << E.toString() << "\n\n";

    // Point2D::clone
    Point2D* F = E.clone();
    cout << "F = " << F->toString() << "\n\n";
    delete F;

    return 0;
}