#include "header.h"

void Point::input()
{
    cout << "Input point: ";
    cin >> x >> y;
}

void Point::output()
{
    cout << '(' << x << ',' << y << ')';
}

double Point::distanceToOx()
{
    return y;
}

double Point::distanceToOy()
{
    return x;
}

double distance(const Point& A, const Point& B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void Triangle::input()
{
    cout << "Input 3 points of triangle:\n";
    A.input();
    B.input();
    C.input();
}

void Triangle::output()
{
    cout << "Triangle: ";
    A.output();
    cout << " - ";
    B.output();
    cout << " - ";
    C.output();
}

bool Triangle::isValidTriangle()
{
    double a = distance(B, C);
    double b = distance(C, A);
    double c = distance(A, B);

    return (a + b > c) && (b + c > a) && (c + a > b);
}

string Triangle::type()
{
    if (!isValidTriangle())
        return "Not Triangle";

    double a = distance(B, C);
    double b = distance(C, A);
    double c = distance(A, B);

    if (a == b && b == c)
        return "Equilateral Triangle";

    if (a * a + b * b == c * c ||
        b * b + c * c == a * a ||
        c * c + a * a == b * b)
    {
        if (a == b || b == c || c == a)
            return "Right Isosceles Triangle";
        return "Right-Angled Triangle";
    }

    if (a == b || b == c || c == a)
        return "Isosceles Triangle";
    
    if (a * a + b * b < c * c ||
        b * b + c * c < a * a ||
        c * c + a * a < b * b)
        return "Obtuse-Angled Triangle";

    return "Scalene Triangle";
}

double Triangle::perimeter()
{
    return distance(B, C) + distance(C, A) + distance(A, B);
}

double Triangle::area()
{
    return 0.5 * abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

Point Triangle::center()
{
    return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
}
