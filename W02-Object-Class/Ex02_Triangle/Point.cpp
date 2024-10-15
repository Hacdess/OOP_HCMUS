#include "Point.h"

Point::Point() {
    x = y = 0;
}

Point::Point(const double &x, const double &y) {
    this->x = x;
    this->y = y;
}

double Point::getX()
{
    return x;
}

double Point::getY() {
    return y;
}

void Point::input() {
    cout << "Input point: ";
    cin >> x >> y;
}

void Point::output() {
    cout << '(' << x << ", " << y << ')';
}

double Point::distance(const Point &point) {
    return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

double Point::distanceToOx() {
    return fabs(y);
}

double Point::distanceToOy() {
    return fabs(x);
}