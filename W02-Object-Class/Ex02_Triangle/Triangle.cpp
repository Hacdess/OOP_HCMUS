#include "Triangle.h"

void Triangle::input() {
    cout << "Input 3 points of the triangle:\n";
    A.input();
    B.input();
    C.input();
}

bool Triangle::isValidTriangle() const {
    double a = B.distance(C);
    double b = C.distance(A);
    double c = A.distance(B);

    return (a > -epsilon) && (b > -epsilon) && (c > -epsilon) && (a + b > c + epsilon) && (b + c > a + epsilon) && (c + a > b + epsilon);
}

void Triangle::output() const {
    if (isValidTriangle()) {
        cout << "Triangle: ";
        A.output();
        cout << " - ";
        B.output();
        cout << " - ";
        C.output();
    }
    else
        cout << "Error: Invalid triangle!\n";
}

string Triangle::type() const {
    if (!isValidTriangle())
        return "Invalid Triangle";

    double a = B.distance(C);
    double b = C.distance(A);
    double c = A.distance(B);

    if (fabs(a - b) < epsilon && fabs(b - c) < epsilon)
        return "Equilateral Triangle";

    if (fabs(a * a + b * b - c * c) < epsilon || 
        fabs(b * b + c * c - a * a) < epsilon || 
        fabs(c * c + a * a - b * b) < epsilon) {
        if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
            return "Right-Angled Isosceles Triangle";
        return "Right-Angled Triangle";
    }
    
    if (a * a + b * b < c * c ||
        b * b + c * c < a * a ||
        c * c + a * a < b * b) {
        if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
            return "Obtuse-Angled Isosceles Triangle";
        return "Obtuse-Angled Triangle";
    }

    if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
        return "Isosceles Triangle";

    return "Scalene Triangle";
}

double Triangle::perimeter() const {
    return B.distance(C) + C.distance(A) + A.distance(B);
}

// Shoelace theorem
double Triangle::area() const {
    return 0.5 * fabs(A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()));
}

Point Triangle::center() const {
    return {(A.getX() + B.getX() + C.getX()) / 3, (A.getY() + B.getY() + C.getY()) / 3};
}