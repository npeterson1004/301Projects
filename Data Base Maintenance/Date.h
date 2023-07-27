#ifndef Date_H
#define Date_H

#include <string>
#include <iostream>
#include <iomanip>

/**
 * @class Date
 * @brief Represents a date with month, day, and year.
 *
 * The Date class provides functionality to store and manipulate dates.
 * It includes methods to set and retrieve the month, day, and year.
 * The class also provides overloads for the input and output stream operators.
 */
class Date {
private:
    int month; ///< The month of the date.
    int day;   ///< The day of the date.
    int year;  ///< The year of the date.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the Date object with month, day, and year set to zero.
     */
    Date();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the Date object with the provided month, day, and year.
     *
     * @param m The month of the date.
     * @param d The day of the date.
     * @param y The year of the date.
     */
    Date(int m, int d, int y);

    /**
     * @brief Set the month of the date.
     *
     * @param m The month to set.
     */
    void setMonth(int m);

    /**
     * @brief Set the day of the date.
     *
     * @param d The day to set.
     */
    void setDay(int d);

    /**
     * @brief Set the year of the date.
     *
     * @param y The year to set.
     */
    void setYear(int y);

    /**
     * @brief Get the month of the date.
     *
     * @return The month of the date.
     */
    int getMonth() const;

    /**
     * @brief Get the day of the date.
     *
     * @return The day of the date.
     */
    int getDay() const;

    /**
     * @brief Get the year of the date.
     *
     * @return The year of the date.
     */
    int getYear() const;

    /**
     * @brief Overload of the input stream operator.
     *
     * Allows reading a Date object from an input stream.
     *
     * @param is The input stream.
     * @param date The Date object to read.
     * @return The input stream after reading the Date object.
     */
    friend std::istream& operator>>(std::istream& is, Date& date);

    /**
     * @brief Overload of the output stream operator.
     *
     * Allows writing a Date object to an output stream.
     *
     * @param os The output stream.
     * @param date The Date object to write.
     * @return The output stream after writing the Date object.
     */
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#include "Date.cpp"

#endif
