#include "Point2D.h"

Point2D::Point2D() {
    x = y = 0;
}

Point2D::Point2D(int x) {
    this->x = this->y = x;
}

Point2D::Point2D(int x, int y) {
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D &other) {
    x = other.x;
    y = other.y;
}

Point2D::Point2D(string s) {
}
