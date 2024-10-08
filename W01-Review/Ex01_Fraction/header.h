#include <iostream>
using namespace std;

long long findGreatestCommonDivisor(const long long& a, const long long& b);

struct Fraction
{
    int Numerator, Denominator;

    void input();
    void output(); 
    void reduce(); 

    short compare(const Fraction& fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};

Fraction addTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction substractTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction multiplyTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
Fraction divideTwoFractions(const Fraction& fraction1, const Fraction& fraction2);