#include "Point.h"

Point::Point() {
    x = y = 0;
}

Point::Point(const double &x, const double &y) {
    this->x = x;
    this->y = y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::input() {
    cout << "Input point: ";
    cin >> x >> y;
}

void Point::output() const {
    cout << '(' << x << ", " << y << ')';
}

double Point::distance(const Point &point) const {
    return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

double Point::distanceToOx() const {
    return fabs(y);
}

double Point::distanceToOy() const {
    return fabs(x);
}