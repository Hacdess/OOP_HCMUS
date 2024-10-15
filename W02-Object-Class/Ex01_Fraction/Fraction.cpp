#include "Fraction.h"

int findGreatestCommonDivisor(const int& a, const int& b) {
    if (b == 0)
        return a;
    return findGreatestCommonDivisor(b, a % b);
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::input() {
    cout << "Input the fraction's numerator and denominator (separated by space): ";
    cin >> numerator >> denominator;
    
    while (denominator == 0) {
        cout << "Fraction's denominator mustn't be 0! Please input the denominator again: ";
        cin >> denominator;
    }
}

void Fraction::output() {
    try {
        if (denominator != 0) {
            if (numerator % denominator == 0)
                cout << numerator / denominator;
            else
                cout << numerator << '/' << denominator;
        }
        else
            throw invalid_argument("Error: Invalid fraction because the denominator mustn't be 0!");

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Fraction::reduce() {
    int gcd = findGreatestCommonDivisor(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

Fraction Fraction::add(const Fraction& fraction) {
    Fraction answer;
    answer.numerator = numerator * fraction.denominator + denominator * fraction.numerator;
    answer.denominator = denominator * fraction.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::subtract(const Fraction& fraction) {
    Fraction answer;
    answer.numerator = numerator * fraction.denominator - denominator * fraction.numerator;
    answer.denominator = denominator * fraction.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::multiply(const Fraction& fraction) {
    Fraction answer;
    answer.numerator = numerator * fraction.numerator;
    answer.denominator = denominator * fraction.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::divide(const Fraction& fraction) {
    if (fraction.numerator == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!");

    Fraction answer;
    answer.numerator = numerator * fraction.denominator;
    answer.denominator = denominator * fraction.numerator;

    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    answer.reduce();
    return answer;
}

short Fraction::compare(const Fraction& fraction) {
    int delta = numerator * fraction.denominator - denominator * fraction.numerator;
    if (delta < 0) return -1;
    if (delta > 0) return 1;
    return delta;
}

bool Fraction::isPositive() {
    return (numerator * denominator > 0);
}

bool Fraction::isNegative() {
    return (numerator * denominator < 0);
}

bool Fraction::isZero() {
    return (denominator != 0 && numerator == 0);
}