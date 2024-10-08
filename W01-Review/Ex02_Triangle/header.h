#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Point
{
    double x, y;

    void input();
    void output();
    double distanceToOx();
    double distanceToOy();
};

double distance(const Point& A, const Point& B);

struct Triangle
{
    Point A, B, C;

    void input();
    void output();
    bool isValidTriangle();
    string type();
    double perimeter();
    double area();
    Point center();
};
