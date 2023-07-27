#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "Date.h"

/**
 * @class People
 * @brief Represents a person with a name and birthday.
 *
 * The People class represents a person's information, including their name and birthday.
 * It is derived from the Date class to store the person's birthday.
 */
class People : public Date {
private:
    std::string name; ///< The name of the person.
    Date birthday;    ///< The birthday of the person.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes a People object with an empty name and default birthday (month, day, and year set to zero).
     */
    People();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes a People object with the provided name and birthday.
     *
     * @param n The name of the person.
     * @param d The birthday of the person.
     */
    People(const std::string& n, const Date& d);

    /**
     * @brief Set the name of the person.
     *
     * @param n The name to set.
     */
    void setName(const std::string& n);

    /**
     * @brief Set the birthday of the person.
     *
     * @param d The birthday to set.
     */
    void setBirthday(const Date& d);

    /**
     * @brief Get the name of the person.
     *
     * @return The name of the person.
     */
    std::string getName() const;

    /**
     * @brief Get the birthday of the person.
     *
     * @return The birthday of the person.
     */
    Date getBirthday() const;

    /**
     * @brief Overload of the equality operator.
     *
     * Checks if two People objects have the same name and birthday.
     *
     * @param other The other People object to compare.
     * @return True if both People objects are equal, False otherwise.
     */
    bool operator==(const People& other) const;

    /**
     * @brief Overload of the less than operator.
     *
     * Compares two People objects based on their names and birthdays.
     *
     * @param other The other People object to compare.
     * @return True if this People object is less than the other, False otherwise.
     */
    bool operator<(const People& other) const;

    /**
     * @brief Overload of the greater than operator.
     *
     * Compares two People objects based on their names and birthdays.
     *
     * @param other The other People object to compare.
     * @return True if this People object is greater than the other, False otherwise.
     */
    bool operator>(const People& other) const;

    /**
     * @brief Overload of the input stream operator.
     *
     * Allows reading a People object from an input stream.
     *
     * @param is The input stream.
     * @param person The People object to read.
     * @return The input stream after reading the People object.
     */
    friend std::istream& operator>>(std::istream& is, People& person);

    /**
     * @brief Overload of the output stream operator.
     *
     * Allows writing a People object to an output stream.
     *
     * @param os The output stream.
     * @param person The People object to write.
     * @return The output stream after writing the People object.
     */
    friend std::ostream& operator<<(std::ostream& os, const People& person);
};

#include "People.cpp"

#endif // PEOPLE_H
