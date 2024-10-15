#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point.h"

struct Triangle {
    private:
        Point A, B, C;

    public:
        void input();
        bool isValidTriangle();
        void output();
        string type();
        double perimeter();
        double area();
        Point center();
};

#endif