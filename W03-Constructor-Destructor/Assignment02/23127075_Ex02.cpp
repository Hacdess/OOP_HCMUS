#include "Triangle.h"

int main() {
    Triangle triangle1;
    cout << triangle1.toString() << "\n\n";

    int x, y;
    cout << "Input x, y: ";
    cin >> x >> y;
    Point2D A(x, y);
    cout << "Inputted point: " <<  A.toString() << "\n\n";

    Triangle triangle2(A);
    cout << triangle2.toString() << "\n\n";


    return 0;
}