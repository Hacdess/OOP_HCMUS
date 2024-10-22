#ifndef _POINT2D_H_
#define _POINT2D_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Point2D {
    private:
        int x, y;
    public:
        Point2D();
        Point2D(int x);
        Point2D(int x, int y);
        Point2D(const Point2D &other);
        Point2D(string s);
        ~Point2D();

        string toString();
        Point2D* clone();
};

#endif