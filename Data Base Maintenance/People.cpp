#include "People.h"
#include <iomanip>

// People class implementation
People::People() {}

People::People(const std::string& n, const Date& d) : name(n), birthday(d) {}

void People::setName(const std::string& n) {
    name = n;
}

void People::setBirthday(const Date& d) {
    birthday = d;
}

std::string People::getName() const {
    return name;
}

Date People::getBirthday() const {
    return birthday;
}

bool People::operator==(const People& other) const {
    return name == other.name;
}

bool People::operator<(const People& other) const {
    return name < other.name;
}

bool People::operator>(const People& other) const {
    return name > other.name;
}


std::istream& operator>>(std::istream& is, People& person) {
    // Read name
    is >> person.name;
    
    // Read birthday (month day year)
    int month, day, year;
    is >> month >> day >> year;
    Date birthday(month, day, year);
    person.setBirthday(birthday);

    return is;
}

std::ostream& operator<<(std::ostream& os, const People& person) {
    os << person.name << " " << person.birthday;
    return os;
}