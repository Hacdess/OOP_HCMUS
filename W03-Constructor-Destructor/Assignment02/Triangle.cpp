#include "Triangle.h"

Triangle::Triangle() {
    cout << "Triangle::Default constructor" << endl;
}

Triangle::Triangle(Point2D A, Point2D B, Point2D C) {
    cout << "Triangle::Parameterized constructor" << endl;

    this->A.setX(A.getX());
    this->A.setY(A.getY());

    this->B.setX(B.getX());
    this->B.setY(B.getY());

    this->C.setX(C.getX());
    this->C.setY(C.getY());
}

Triangle::Triangle(const Triangle &other) {
    cout << "Triangle::Copy constructor" << endl;

    this->A.setX(other.A.getX());
    this->A.setY(other.A.getY());

    this->B.setX(other.B.getX());
    this->B.setY(other.B.getY());

    this->C.setX(other.C.getX());
    this->C.setY(other.C.getY());
}

Triangle::Triangle(Triangle &&other) noexcept {
    cout << "Triangle::Move constructor" << endl;

    this->A.setX(other.A.getX());
    this->A.setY(other.A.getY());

    this->B.setX(other.B.getX());
    this->B.setY(other.B.getY());

    this->C.setX(other.C.getX());
    this->C.setY(other.C.getY());


    other.A.setX(0);
    other.A.setY(0);

    other.B.setX(0);
    other.B.setY(0);

    other.C.setX(0);
    other.C.setY(0);
}

Triangle::Triangle(string s) {
    cout << "Triangle::String-extracting constructor" << endl;
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
