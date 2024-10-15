#include "Triangle.h"

void Triangle::input() {
    cout << "Input 3 points of the triangle:\n";
    A.input();
    B.input();
    C.input();
}

bool Triangle::isValidTriangle() {
    double a = B.distance(C);
    double b = C.distance(A);
    double c = A.distance(B);

    return (a > 0) && (b > 0) && (c > 0) && (a + b > c) && (b + c > a) && (c + a > b);
}

void Triangle::output() {
    try {
        if (isValidTriangle()) {
            cout << "Triangle: ";
            A.output();
            cout << " - ";
            B.output();
            cout << " - ";
            C.output();
        }
        else
            throw invalid_argument("Error: Invalid triangle!");
    }
    catch(const invalid_argument& e) {
        cout << e.what() << '\n';
    }
}

string Triangle::type() {
    if (!isValidTriangle())
        return "Invalid Triangle";

    const double epsilon = 1e-9;

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

double Triangle::perimeter() {
    if (!isValidTriangle()) {
        throw invalid_argument("Error: Invalid Triangle!");
        return 0;
    }
    return B.distance(C) + C.distance(A) + A.distance(B);
}

// Shoelace theorem
double Triangle::area() {
    if (!isValidTriangle()) {
        throw invalid_argument ("Error: Invalid Triangle!");
        return 0;
    }
    return 0.5 * fabs(A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()));
}

Point Triangle::center() {
    if (!isValidTriangle())
        throw invalid_argument("Error: Invalid Triangle!");
    return {(A.getX() + B.getX() + C.getX()) / 3, (A.getY() + B.getY() + C.getY()) / 3};
}