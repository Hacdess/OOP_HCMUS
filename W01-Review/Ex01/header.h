#include <iostream>
using namespace std;

struct Fraction
{
    int Numerator;
    int Denominator;

    void format();
    void input();
    void output(); 
    Fraction addTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
    Fraction substractTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
    Fraction multiplyTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
    Fraction divideTwoFractions(const Fraction& fraction1, const Fraction& fraction2);
    Fraction reduce(); 
    short Compare(const Fraction& fraction1, const Fraction& fraction2);
    bool isPositive();
    bool isNegative();
    bool isZero();
};
