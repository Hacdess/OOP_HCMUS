#include "Fraction.h"

int findGreatestCommonDivisor(const int& a, const int& b)
{
    if (b == 0)
        return a;
    return findGreatestCommonDivisor(b, a % b);
}

void Fraction::input()
{
    cout << "Input the fraction's numerator and denominator (separated by space): ";
    cin >> Numerator >> Denominator;
    
    while (Denominator == 0)
    {
        cout << "Fraction's denominator mustn't be 0! Please input the denominator again: ";
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
    int gcd = findGreatestCommonDivisor(Numerator, Denominator);
    Numerator /= gcd;
    Denominator /= gcd;

    if (Denominator < 0)
    {
        Numerator *= -1;
        Denominator *= -1;
    }
}

Fraction Fraction::add(const Fraction& fraction)
{
    Fraction answer;
    answer.Numerator = Numerator * fraction.Denominator + Denominator * fraction.Numerator;
    answer.Denominator = Denominator * fraction.Denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::subtract(const Fraction& fraction)
{
    Fraction answer;
    answer.Numerator = Numerator * fraction.Denominator - Denominator * fraction.Numerator;
    answer.Denominator = Denominator * fraction.Denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::multiply(const Fraction& fraction)
{
    Fraction answer;
    answer.Numerator = Numerator * fraction.Numerator;
    answer.Denominator = Denominator * fraction.Denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::divide(const Fraction& fraction)
{
    if (fraction.Numerator == 0)
    {
        cout << "Can't be divided by 0!\n";
        return {0, 0};
    }

    Fraction answer;
    answer.Numerator = Numerator * fraction.Denominator;
    answer.Denominator = Denominator * fraction.Numerator;

    if (answer.Denominator < 0)
    {
        answer.Numerator *= -1;
        answer.Denominator *= -1;
    }

    answer.reduce();
    return answer;
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