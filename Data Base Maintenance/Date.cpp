#include "Date.h"

// Date class implementation
Date::Date() : month(0), day(0), year(0) {}

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.month >> date.day >> date.year;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.month << " " << date.day << " " << date.year;
    return os;
}