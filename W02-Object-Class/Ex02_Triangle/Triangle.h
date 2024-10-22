#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point.h"

class Triangle {
    private:
        Point A, B, C;

    public:
        void input();
        bool isValidTriangle() const;
        void output() const;
        string type() const;
        double perimeter() const;
        double area() const;
        Point center() const;
};

#endif