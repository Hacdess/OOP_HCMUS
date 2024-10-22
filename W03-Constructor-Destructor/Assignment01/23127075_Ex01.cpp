#include "Point2D.h"

int main() {
    Point2D A;
    cout << "A = " << A.toString() << "\n\n";

    int x, y;

    cout << "Input x: ";
    cin >> x;
    Point2D B(x);
    cout << "B = " << B.toString() << "\n\n";

    cout << "Input x, y (separated by space): ";
    cin >> x >> y;
    Point2D C(x, y);
    cout << "C = " << C.toString() << "\n\n";

    Point2D D(C);
    cout << "D = " << D.toString() << "\n\n";

    string inputLine;
    cout << "Input x, y (separated by a comma): ";
    cin >> inputLine;
    Point2D E(inputLine);
    cout << "E = " << E.toString() << "\n\n";

    Point2D* F = E.clone();
    cout << "F = " << F->toString() << "\n\n";
    delete F;

    return 0;
}