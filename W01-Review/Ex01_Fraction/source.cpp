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

void Fraction::input()
{
    cout << "Input the fraction's numerator and denominator: ";
    cin >> Numerator >> Denominator;
    
    while (Denominator == 0)
    {
        cout << "Fraction's denominator mustn't be 0! Please input it again: ";
        cin >> Denominator;
    }
}

void Fraction::output()
{
    if (Denominator == 0)
        cout << "Invalid fraction: Denominator mustn't be 0!\n";
    else if (Numerator % Denominator == 0)
        cout << Numerator / Denominator;
    else
        cout << Numerator << '/' << Denominator;
}

void Fraction::reduce()
{
    if (Denominator < 0)
    {
        Numerator *= -1;
        Denominator *= -1;
    }

    long long gcd = (Numerator < 0) ? findGreatestCommonDivisor(-Numerator, Denominator) : findGreatestCommonDivisor(Numerator, Denominator);
    if (gcd > 1)
    {
        Numerator /= gcd;
        Denominator /= gcd;
    }
}

short Fraction::compare(const Fraction& fraction)
{
    int delta = Numerator * fraction.Denominator - Denominator * fraction.Numerator;
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

Fraction addTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    Fraction answer;
    answer.Numerator = fraction1.Numerator * fraction2.Denominator + fraction1.Denominator * fraction2.Numerator;
    answer.Denominator = fraction1.Denominator * fraction2.Denominator;
    answer.reduce();
    return answer;
}

Fraction substractTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    Fraction answer;
    answer.Numerator = fraction1.Numerator * fraction2.Denominator - fraction1.Denominator * fraction2.Numerator;
    answer.Denominator = fraction1.Denominator * fraction2.Denominator;
    answer.reduce();
    return answer;
}

Fraction multiplyTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    long long numerator = fraction1.Numerator * fraction2.Numerator;
    long long denominator = fraction1.Denominator * fraction2.Denominator;
    long long gcd = (numerator < 0) ? findGreatestCommonDivisor(-numerator, denominator) : findGreatestCommonDivisor(numerator, denominator);
    
    if (gcd > 1)
    {
        numerator /= gcd;
        denominator /= gcd;
    }

    Fraction answer;
    answer.Numerator = numerator;
    answer.Denominator = denominator;

    return answer;
}

Fraction divideTwoFractions(const Fraction &fraction1, const Fraction &fraction2)
{
    if (fraction2.Numerator == 0)
    {
        cout << "Can't divided by 0!\n";
        return {0, 0};
    }

    long long numerator = fraction1.Numerator * fraction2.Denominator;
    long long denominator = fraction1.Denominator * fraction2.Numerator;

    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }

    long long gcd = (numerator < 0) ? findGreatestCommonDivisor(-numerator, denominator) : findGreatestCommonDivisor(numerator, denominator);

    if (gcd > 1)
    {
        numerator /= gcd;
        denominator /= gcd;
    }

    Fraction answer;
    answer.Numerator = numerator;
    answer.Denominator = denominator;

    return answer;
}