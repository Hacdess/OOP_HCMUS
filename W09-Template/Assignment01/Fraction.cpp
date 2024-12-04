#include "Fraction.h"

void Fraction::simplify()
{
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den)
{
    if (den == 0)
        throw invalid_argument("Error: Denominator cannot be zero");
    simplify();
}

Fraction::Fraction(const Fraction &other) : numerator(other.numerator), denominator(other.denominator) {}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int num)
{
    numerator = num;
    simplify();
}

void Fraction::setDenominator(int den)
{
    if (den == 0)
        throw invalid_argument("Error: Denominator cannot be zero");
    denominator = den;
    simplify();
}

bool Fraction::operator==(const Fraction &other) const
{
    return numerator * other.denominator == denominator * other.numerator;
}

bool Fraction::operator!=(const Fraction &other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const
{
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction &other) const
{
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return !(*this > other);
}

bool Fraction::operator>=(const Fraction &other) const
{
    return !(*this < other);
}

Fraction Fraction::operator=(int value)
{
    return Fraction(value, 1);
}

string Fraction::toString() const
{
    if (numerator % denominator == 0)
        return to_string(numerator / denominator);
    return to_string(numerator) + '/' + to_string(denominator);
}

ostream &operator<<(ostream &os, const Fraction &fraction)
{
    if (fraction.numerator % fraction.denominator == 0)
        os << fraction.numerator / fraction.denominator;
    else
        os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

istream &operator>>(istream &is, Fraction &fraction)
{
    int num, den;
    char slash;
    is >> num >> slash >> den;
    if (slash != '/')
        throw invalid_argument("Invalid format. Use 'numerator/denominator'.");
    fraction = Fraction(num, den);
    return is;
}
