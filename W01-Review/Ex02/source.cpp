#include "header.h"

long long findGreatestCommonDivisor(const long long& a, const long long& b)
{
    if (a == 0 || b == 0)
        return 0;

    if (a == b)
        return a;

    if (a > b)
        return findGreatestCommonDivisor(a - b, b);

    return findGreatestCommonDivisor(a, b - a);
}

void Fraction::format()
{
    if (Denominator == 0)
        cout << "Fraction's denominator mustn't be 0!";

    else if (Denominator < 0)
    {
        Numerator *= -1;
        Denominator *= -1;
    }
    
    int gcd = (Numerator < 0) ? findGreatestCommonDivisor(-Numerator, Denominator) : findGreatestCommonDivisor(Numerator, Denominator);
    
    if (gcd != 1)
    {
        Numerator /= gcd;
        Denominator /= gcd;
    }
}

void Fraction::input()
{
    cout << "Input the fraction's numerator and denominator: ";
    cin >> Numerator >> Denominator;
    
    while (Denominator == 0)
    {
        cout << "Fraction's denominator mustn't be 0! Please input it again: ";
        cin >> Denominator;
    }

    format();
}

void Fraction::output()
{
    if (Numerator % Denominator == 0)
        cout << Numerator;
    else
        cout << Numerator << '/' << Denominator;
}

Fraction Fraction::addTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    Fraction answer;
    answer.Numerator = fraction1.Numerator * fraction2.Denominator + fraction1.Denominator * fraction2.Denominator;
    answer.Denominator = fraction1.Denominator * fraction2.Denominator;
    answer.format();
    return answer;
}

Fraction Fraction::substractTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    Fraction answer;
    answer.Numerator = fraction1.Numerator * fraction2.Denominator - fraction1.Denominator * fraction2.Denominator;
    answer.Denominator = fraction1.Denominator * fraction2.Denominator;
    answer.format();
    return answer;
}

Fraction Fraction::multiplyTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    long long numerator = fraction1.Numerator * fraction2.Numerator;
    long long denominator = fraction1.Denominator * fraction2.Denominator;
    long long gcd = (numerator < 0) ? findGreatestCommonDivisor(-numerator, denominator) : findGreatestCommonDivisor(numerator, denominator);
    Fraction answer;
    answer.Numerator = numerator;
    answer.Denominator = denominator;
    return answer;
}

Fraction Fraction::divideTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    return Fraction();
}

Fraction Fraction::reduce()
{
    return Fraction();
}

short Fraction::Compare(const Fraction& fraction1, const Fraction& fraction2)
{
    int delta = fraction1.Numerator * fraction2.Denominator - fraction1.Denominator * fraction2.Numerator;
    if (delta < 0) return -1;
    if (delta > 0) return 1;
    return delta;
}

bool Fraction::isPositive()
{
    return (Numerator * Denominator > 0);
}

bool Fraction::isNegative()
{
    return (Numerator * Denominator < 0);
}

bool Fraction::isZero()
{
    return (Denominator != 0 && Numerator == 0);
}
