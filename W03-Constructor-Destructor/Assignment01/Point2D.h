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
        // Default constructor
        Point2D();

        // Parameterized constructor
        Point2D(int x, int y);

        // Copy constructor
        Point2D(const Point2D &other);

        // Move constructor
        Point2D(Point2D &&other) noexcept;

        // String-extracting constructor
        Point2D(string s);

        // Destructor
        ~Point2D();

        void setX(int x);
        void setY(int y);

        string toString();
        Point2D* clone();
};

#endif