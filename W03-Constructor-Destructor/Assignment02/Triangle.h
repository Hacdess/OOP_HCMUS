#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "../Assignment01/Point2D.h"

class Triangle {
    private:
        Point2D A, B, C;
    public:
        // Default constructor
        Triangle();

        // Parameterized constructor
        Triangle(Point2D A, Point2D B, Point2D C);

        // Copy constructor
        Triangle(const Triangle &other);

        // Move constructor
        Triangle(Triangle &&other) noexcept;

        // String-extracting constructor
        Triangle(string s);

        // Destructor
        ~Triangle();

        string toString();
        Triangle* clone();
};

#endif