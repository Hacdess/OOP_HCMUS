#include "Triangle.h"

void Point::input()
{
    cout << "Input point: ";
    cin >> x >> y;
}

void Point::output()
{
    cout << '(' << x << ", " << y << ')';
}

double Point::distance(const Point &point)
{
    return sqrt((x - point.x) * (x - point.x) + (y - point.y) * (y - point.y));
}

double Point::distanceToOx()
{
    return fabs(y);
}

double Point::distanceToOy()
{
    return fabs(x);
}

void Triangle::input()
{
    cout << "Input 3 points of the triangle:\n";
    A.input();
    B.input();
    C.input();
}

bool Triangle::isValidTriangle()
{
    double a = B.distance(C);
    double b = C.distance(A);
    double c = A.distance(B);

    return (a > 0) && (b > 0) && (c > 0) && (a + b > c) && (b + c > a) && (c + a > b);
}

void Triangle::output()
{
    if (!isValidTriangle())
    {
        cout << "Invalid triangle!\n";
        return;
    }

    cout << "Triangle: ";
    A.output();
    cout << " - ";
    B.output();
    cout << " - ";
    C.output();
}

string Triangle::type()
{
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
        fabs(c * c + a * a - b * b) < epsilon)

    {
        if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
            return "Right-Angled Isosceles Triangle";
        return "Right-Angled Triangle";
    }
    
    if (a * a + b * b < c * c ||
        b * b + c * c < a * a ||
        c * c + a * a < b * b) 
    {
        if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
            return "Obtuse-Angled Isosceles Triangle";
        return "Obtuse-Angled Triangle";
    }

    if (fabs(a - b) < epsilon || fabs(b - c) < epsilon || fabs(c - a) < epsilon)
        return "Isosceles Triangle";

    return "Scalene Triangle";
}

double Triangle::perimeter()
{
    if (!isValidTriangle())
    {
        cout << "Invalid Triangle!\n";
        return 0;
    }
    return B.distance(C) + C.distance(A) + A.distance(B);
}

// Shoelace theorem
double Triangle::area()
{
    if (!isValidTriangle())
    {
        cout << "Invalid Triangle!\n";
        return 0;
    }
    return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

Point Triangle::center()
{
    if (!isValidTriangle())
    {
        cout << "Invalid Triangle!\n";
        return {0,0};
    }
    return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
}