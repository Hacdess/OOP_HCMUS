#include "Fraction.h"

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

int Fraction::findGreatestCommonDivisor(const int &a, const int &b) {
    if (b == 0)
        return a;
    return findGreatestCommonDivisor(b, a % b);
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

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

Fraction::~Fraction() {
}

void Fraction::Input() {
    cout << "Input the fraction's numerator and denominator (separated by space): ";
    cin >> numerator >> denominator;
    
    while (denominator == 0) {
        cout << "Fraction's denominator mustn't be 0! Please input the denominator again: ";
        cin >> denominator;
    }

    reduce();
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
    if (fraction.denominator != 0) {
        if (fraction.numerator % fraction.denominator == 0)
            out << fraction.numerator / fraction.denominator;
        else
            out << fraction.numerator << '/' << fraction.denominator;

        return out;
    }
    else
        throw invalid_argument("Error: Invalid fraction because the denominator mustn't be 0!");
}

void Fraction::operator=(const Fraction &other) {
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction answer;
    answer.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
    answer.denominator = this->denominator * other.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction answer;
    answer.numerator = this->numerator * other.denominator - this->denominator * other.numerator;
    answer.denominator = this->denominator * other.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction answer;
    answer.numerator = this->numerator * other.numerator;
    answer.denominator = this->denominator * other.denominator;
    answer.reduce();
    return answer;
}

Fraction Fraction::operator/(const Fraction &other) const {
    if (other.numerator == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!");

    Fraction answer;
    answer.numerator = numerator * other.denominator;
    answer.denominator = denominator * other.numerator;

    if (answer.denominator < 0) {
        answer.numerator *= -1;
        answer.denominator *= -1;
    }

    answer.reduce();
    return answer;
}

bool Fraction::operator==(const Fraction &other) const {
    return this->numerator * other.denominator == this->denominator * other.numerator;
}

bool Fraction::operator!=(const Fraction &other) const {
    return this->numerator * other.denominator != this->denominator * other.numerator;
}

bool Fraction::operator>=(const Fraction &other) const {
    return this->numerator * other.denominator >= this->denominator * other.numerator;
}

bool Fraction::operator>(const Fraction &other) const {
    return this->numerator * other.denominator > this->denominator * other.numerator;
}

bool Fraction::operator<=(const Fraction &other) const {
    return this->numerator * other.denominator <= this->denominator * other.numerator;
}

bool Fraction::operator<(const Fraction &other) const {
    return this->numerator * other.denominator < this->denominator * other.numerator;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    this->numerator = this->numerator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    if (other.numerator == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!\n");

    this->numerator = numerator * other.denominator;
    this->denominator = denominator * other.numerator;

    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }

    this->reduce();
    return *this;
}

Fraction &Fraction::operator++() {
    this->numerator += this->denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    this->numerator += this->denominator;
    reduce(); 
    return temp; 
}

Fraction &Fraction::operator--() {
    this->numerator -= this->denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    this->numerator -= this->denominator;
    reduce(); 
    return temp; 
}

Fraction Fraction::operator+(int value) const {
    return Fraction(this->numerator + value * denominator, this->denominator);
}

Fraction Fraction::operator-(int value) const {
    return Fraction(numerator - value * denominator, denominator);
}

Fraction Fraction::operator*(int value) const {
    return Fraction(numerator * value, denominator);
}

Fraction Fraction::operator/(int value) const {
    if (value == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!\n");
    return Fraction(numerator, denominator * value);
}

Fraction operator+(int value, const Fraction &fraction) {
    return Fraction(value * fraction.denominator + fraction.numerator, fraction.denominator);
}

Fraction operator-(int value, const Fraction &fraction) {
    return Fraction(value * fraction.denominator - fraction.numerator, fraction.denominator);
}

Fraction operator*(int value, const Fraction &fraction) {
    return Fraction(value * fraction.numerator, fraction.denominator);
}

Fraction operator/(int value, const Fraction &fraction) {
    if (fraction.numerator == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!\n");
    return Fraction(value * fraction.denominator, fraction.numerator);
}

Fraction::operator float() const {
    if (denominator == 0)
        throw invalid_argument("Error: Can't divide by a fraction with a numerator of 0!\n");
    return static_cast<float>(numerator) / denominator;
}