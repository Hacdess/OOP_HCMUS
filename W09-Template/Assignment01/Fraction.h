#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <numeric> // std::gcd
#include <stdexcept>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    void simplify();

public:
    // Constructors
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction &other);

    // Getter và Setter
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int den);

    // Compare
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;

    // Others
    Fraction operator=(int value);
    string toString() const;

    // Input & output
    friend ostream &operator<<(ostream &os, const Fraction &fraction);
    friend istream &operator>>(istream &is, Fraction &fraction);
};

#endif
