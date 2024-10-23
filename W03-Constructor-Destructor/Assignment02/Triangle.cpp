#include "Triangle.h"

Triangle::Triangle() {
    A;
    B;
    C;
}

Triangle::Triangle(Point2D A) {
    this->A = A;
    B;
    C;
}

Triangle::~Triangle() {
    cout << "Triangle::Destructor" << endl;
}

string Triangle::toString() {
    return A.toString() + " - " + B.toString() + " - " + C.toString();
}
