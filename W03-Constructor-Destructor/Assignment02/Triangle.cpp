#include "Triangle.h"

Triangle::Triangle() {
    cout << "Triangle::Default constructor" << endl;
    A;
    B;
    C;
}

Triangle::Triangle(Point2D A) {
    cout << "Triangle::Constructor with 1 argument" << endl;
    this->A = A;
    B;
    C;
}

Triangle::Triangle(Point2D A, Point2D B, Point2D C) {
    cout << "Triangle::Constructor with 3 arguments" << endl;
    this->A = A;
    this->B = B;
    this->C = C;
}

Triangle::Triangle(const Triangle &other) {
    cout << "Triangle::Copy constructor" << endl;
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
}

Triangle::Triangle(string s) {
    cout << "Triangle::Constructor from string" << endl;
    stringstream ss(s);
    int num;
    char c;

    ss >> c;
    ss >> num;
    A.setX(num);
    ss >> c;
    ss >> num;
    A.setY(num);
    ss >> c;

    ss >> c;

    ss >> c;
    ss >> num;
    B.setX(num);
    ss >> c;
    ss >> num;
    B.setY(num);
    ss >> c;

    ss >> c;

    ss >> c;
    ss >> num;
    C.setX(num);
    ss >> c;
    ss >> num;
    C.setY(num);
    ss >> c;
}

Triangle::~Triangle() {
    cout << "Triangle::Destructor" << endl;
}

string Triangle::toString() {
    return A.toString() + " - " + B.toString() + " - " + C.toString();
}

Triangle* Triangle::clone() {
    cout << "Cloning...\n";
    return new Triangle(*this);
}
