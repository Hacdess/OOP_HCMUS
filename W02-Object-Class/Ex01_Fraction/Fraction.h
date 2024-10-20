#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

int findGreatestCommonDivisor(const int& a, const int& b);

class Fraction {
    private:
        int numerator, denominator;
    
    public:
        void input();
        void output() const;
        void reduce(); 
        Fraction add(const Fraction& fraction) const;
        Fraction subtract(const Fraction& fraction) const;
        Fraction multiply(const Fraction& fraction) const;
        Fraction divide(const Fraction& fraction) const;
        short compare(const Fraction& fraction) const;
        bool isPositive() const;
        bool isNegative() const;
        bool isZero() const;
};

#endif