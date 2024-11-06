#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    int getYear();

    bool isLeapYear() const;
    bool isValidInput();
    void Input();

    void operator=(const Date& other);
    void format();

    Date Tomorrow();
    Date Yesterday();

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;
    
    Date operator+(int value) const;
    Date operator-(int value) const;

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    friend ostream& operator<<(ostream& os, const Date& date);
    friend istream& operator>>(istream& is, Date& date);

    operator int() const;
    operator long() const;

    Date& operator+=(const int& day);
    Date& operator-=(const int& day);
};

#endif