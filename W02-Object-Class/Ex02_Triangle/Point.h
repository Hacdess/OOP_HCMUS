#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double epsilon = 1e-9;

class Point {
    private:
        double x, y;

    public:
        Point();
        Point(const double& x, const double& y);

        double getX() const;
        double getY() const;

        void input();
        void output() const;
        double distance(const Point& point) const;
        double distanceToOx() const;
        double distanceToOy() const;
};

#endif