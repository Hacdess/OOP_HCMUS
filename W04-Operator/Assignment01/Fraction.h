#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator, denominator;
    
    public:
        Fraction();
        int findGreatestCommonDivisor(const int& a, const int& b);
        void reduce();
        Fraction(int numerator, int denominator);
        ~Fraction();

        void Input();
        friend ostream& operator<<(ostream& out, const Fraction& fraction);

        void operator=(const Fraction& other);
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;

        Fraction& operator+=(const Fraction& other);
        Fraction& operator-=(const Fraction& other);
        Fraction& operator*=(const Fraction& other);
        Fraction& operator/=(const Fraction& other);

        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        Fraction operator+(int value) const;
        Fraction operator-(int value) const;
        Fraction operator*(int value) const;
        Fraction operator/(int value) const;

        friend Fraction operator+(int value, const Fraction &fraction);
        friend Fraction operator-(int value, const Fraction &fraction);
        friend Fraction operator*(int value, const Fraction &fraction);
        friend Fraction operator/(int value, const Fraction &fraction);

        operator float() const;
};

#endif