#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point {
    private:
        double x, y;

    public:
        Point();
        Point(const double& x, const double& y);

        double getX();
        double getY();

        void input();
        void output();
        double distance(const Point& point);
        double distanceToOx();
        double distanceToOy();
};

#endif