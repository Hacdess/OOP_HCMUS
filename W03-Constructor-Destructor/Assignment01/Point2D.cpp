#include "Point2D.h"

Point2D::Point2D() {
    cout << "Point2D::Default constructor" << endl;
    x = y = 0;
}

Point2D::Point2D(int x, int y) {
    cout << "Point2D::Parameterized constructor" << endl;
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D &other) {
    cout << "Point2D::Copy constructor" << endl;
    x = other.x;
    y = other.y;
}

Point2D::Point2D(Point2D &&other) noexcept {
    cout << "Point2D::Move constructor" << endl;
    this->x = other.x;
    this->y = other.y;
    other.x = other.y = 0;
}

Point2D::Point2D(string s) {
    cout << "Point2D::String-extracting constructor" << endl;
    stringstream ss(s);
    ss >> x;
    char comma;
    ss >> comma;
    ss >> y;
}

Point2D::~Point2D() {
    cout << "Point2D::Destructor" << endl;
}

void Point2D::setX(int x) {
    this->x = x;
}

void Point2D::setY(int y) {
    this->y = y;
}

int Point2D::getX() const {
    return x;
}

int Point2D::getY() const {
    return y;
}

string Point2D::toString() {
    return '(' + to_string(x) + "," + to_string(y) + ')';
}

Point2D* Point2D::clone() {
    cout << "Cloning...\n";
    return new Point2D(*this);
}
