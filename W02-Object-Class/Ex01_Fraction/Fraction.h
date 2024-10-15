#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

int findGreatestCommonDivisor(const int& a, const int& b);

class Fraction {
    private:
        int numerator, denominator;
    
    public:
        int getDenominator();

        void input();
        void output(); 
        void reduce(); 
        Fraction add(const Fraction& fraction);
        Fraction subtract(const Fraction& fraction);
        Fraction multiply(const Fraction& fraction);
        Fraction divide(const Fraction& fraction);
        short compare(const Fraction& fraction);
        bool isPositive();
        bool isNegative();
        bool isZero();
};

#endif