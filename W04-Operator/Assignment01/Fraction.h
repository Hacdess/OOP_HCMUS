#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator, denominator;
    
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        ~Fraction();

        int findGreatestCommonDivisor(const int& a, const int& b);
        void reduce();
        void Input();
        void Output() const;
        
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
        Fraction& operator--();

};

#endif