#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "../Assignment01/Point2D.h"

class Triangle {
    private:
        Point2D A, B, C;
    public:
        Triangle();
        Triangle(Point2D A);
        Triangle(Point2D A, Point2D B, Point2D C);
        Triangle(const Triangle &other);
        Triangle(string s);
        ~Triangle();

        string toString();
        Triangle* clone();
};

#endif