#include "Date.h"

Date::Date() {
    day = month = year = 0;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getYear() {
    return year;
}

bool Date::isLeapYear() const {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

bool Date::isValidInput() {
    if (year < 1 || month < 1 || day < 1) {
        cout << "All input must be positive!\n";
        return false;
    }

    if (month > 12) {
        cout << "Month must be less than or equal to 12\n";
        return false;
    }

    int maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear())
        maxDay[1] = 29;

    if (day > maxDay[month - 1]) {
        if (month == 2 && maxDay[1] == 29)
            cout << year << " is a leap year\n";
        cout << "Day of month " << month << " of " << (maxDay[1] == 29 ? "leap" : "") << " year " << year << " must be less than or equal to " << maxDay[month - 1] << endl;
        return false;
    }

    return true;
}

void Date::Input() {
    cout << "Please input the day, month, year of the date (separated by space): ";
    cin >> day >> month >> year;

    while (!isValidInput()) {
        cout << "Please input the day, month, year of the date (separated by space) again: ";
        cin >> day >> month >> year;
    }   
}

void Date::operator=(const Date &other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

void Date::format() {
    int maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear())
        maxDay[1] = 29;

    while (day > maxDay[month - 1]) {
        day -= maxDay[month - 1];
        month++;
        
        if (month > 12) {
            month = 1;
            ++year;
            maxDay[1] = (isLeapYear()) ? 29 : 28;
        }
    }

    while (day < 1) {
        --month;

        if (month < 1) {
            month = 12;
            --year;
            maxDay[1] = (isLeapYear()) ? 29 : 28;
        }

        day += maxDay[month - 1];
    }
}

Date Date::Tomorrow() {
    Date tomorrow = *this;
    ++tomorrow.day;
    tomorrow.format();
    return tomorrow;
}

Date Date::Yesterday() {
    Date yesterday = *this;
    --yesterday.day;
    yesterday.format();
    return yesterday;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year; 
}

bool Date::operator!=(const Date &other) const {
    return day != other.day || month != other.month || year != other.year; 
}

bool Date::operator>(const Date &other) const {
    if (year != other.year)
        return year > other.year;
    if (month != other.month)
        return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date &other) const {
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator>=(const Date &other) const {
    return !(*this < other);
}

bool Date::operator<=(const Date &other) const {
    return !(*this > other);
}

Date Date::operator+(int value) const {
    Date date = *this;
    date.day += value;
    date.format();
    return date;
}

Date Date::operator-(int value) const {
    Date date = *this;
    date.day -= value;
    date.format();
    return date;
}

Date &Date::operator++() {
    ++this->day;
    format();
    return *this;
}

Date Date::operator++(int) {
    Date date = *this;
    ++this->day;
    format();
    return date;
}

Date &Date::operator--() {
    --this->day;
    format();
    return *this;
}

Date Date::operator--(int) {
    Date date = *this;
    --this->day;
    format();
    return date;
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

istream &operator>>(istream &is, Date &date) {
    cout << "Please input the day, month, year of the date (separated by space): ";
    int day, month, year;

    is >> day >> month >> year;
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    while (!date.isValidInput()) {
        cout << "Please input the day, month, year of the date (separated by space) again: ";
    is >> day >> month >> year;
        date.setDay(day);
        date.setMonth(month);
        date.setYear(year);
    }

    return is;
}

Date::operator int() const {
    int maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = day;

    if (isLeapYear())
        maxDay[1] = 29;

    for (int i = 0; i < month - 1; ++i) {
        days += maxDay[i];
    }

    return days - 1;
}

Date::operator long() const {
    int maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long days = 0;

    for (int y = 1; y < year; ++y) {
        days += (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 366 : 365;
    }

    if (isLeapYear())
        maxDay[1] = 29;

    for (int i = 0; i < month - 1; ++i) {
        days += maxDay[i];
    }

    days += day;

    return days - 1;
}

Date &Date::operator+=(const int &day) {
    this->day += day;
    format();
    return *this;
}

Date &Date::operator-=(const int &day) {
    this->day -= day;
    format();
    return *this;
}