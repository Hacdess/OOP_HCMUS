#include <iostream>
using namespace std;

long long findGreatestCommonDivisor(const long long& a, const long long& b);

struct Fraction
{
    int Numerator, Denominator;

    void input();
    void output(); 
    void reduce(); 
    Fraction add(const Fraction& fraction);
    Fraction subtract(const Fraction& fraction);
    Fraction multiply(const Fraction& fraction);
    Fraction divide(const Fraction& fraction);
    short compare(const Fraction& fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};