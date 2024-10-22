#include "Point2D.h"

Point2D::Point2D() {
    x = y = 0;
    cout << "Point2D::Default constructor" << endl;
}

Point2D::Point2D(int x) {
    this->x = x;
    this->y = 0;
    cout << "Point2D::Constructor with 1 argument" << endl;
}

Point2D::Point2D(int x, int y) {
    this->x = x;
    this->y = y;
    cout << "Point2D::Constructor with 2 arguments" << endl;
}

Point2D::Point2D(const Point2D &other) {
    x = other.x;
    y = other.y;
    cout << "Point2D::Copy constructor" << endl;
}

Point2D::Point2D(string s) {
    stringstream ss(s);
    ss >> x;
    char comma;
    ss >> comma;
    ss >> y;
    cout << "Point2D::Constructor from string" << endl;
}

Point2D::~Point2D() {
    cout << "Point2D::Destructor" << endl;
}

string Point2D::toString() {
    return '(' + to_string(x) + "," + to_string(y) + ')';
}

Point2D* Point2D::clone() {
    return new Point2D(*this);
}
