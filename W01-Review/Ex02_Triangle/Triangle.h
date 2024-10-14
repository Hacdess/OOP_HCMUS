#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Point
{
    double x, y;

    void input();
    void output();
    double distance(const Point& point);
    double distanceToOx();
    double distanceToOy();
};



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
