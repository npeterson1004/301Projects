#ifndef EVENT_H
#define EVENT_H

#include <iostream>

/// @class Event
/// @brief Represents an event in the simulation.
class Event
{
public:
    /// @brief Default constructor.
    Event();

    /// @brief Constructor with arrival and transaction time.
    /// @param arrTime The arrival time of the event.
    /// @param transTime The transaction time of the event.
    Event(int arrTime, int transTime);

    /// @brief Constructor with arrival, transaction time, and event type.
    /// @param arrTime The arrival time of the event.
    /// @param transTime The transaction time of the event.
    /// @param type The type of the event ('A' for arrival, 'D' for departure).
    Event(int arrTime, int transTime, char type);

    /// @brief Get the arrival time of the event.
    /// @return The arrival time.
    int getArrivalTime() const;

    /// @brief Get the transaction time of the event.
    /// @return The transaction time.
    int getTransactionTime() const;

    /// @brief Get the event type.
    /// @return The event type character ('A' for arrival, 'D' for departure).
    char getEventType() const;

    /// @brief Set the arrival time of the event.
    /// @param time The arrival time to set.
    void setArrivalTime(int time);

    /// @brief Set the transaction time of the event.
    /// @param type The transaction time to set.
    void setTransactionTime(int type);

    /// @brief Compare two events based on their arrival time (less than operator).
    /// @param other The other event to compare to.
    /// @return True if this event's arrival time is less than the other event's arrival time, false otherwise.
    bool operator<(const Event& other) const;

    /// @brief Compare two events based on their arrival time (greater than operator).
    /// @param other The other event to compare to.
    /// @return True if this event's arrival time is greater than the other event's arrival time, false otherwise.
    bool operator>(const Event& other) const;

    /// @brief Compare two events for equality.
    /// @param other The other event to compare to.
    /// @return True if both events have the same arrival and transaction time, false otherwise.
    bool operator==(const Event& other) const;

    /// @brief Compare two events for inequality.
    /// @param other The other event to compare to.
    /// @return True if the events have different arrival or transaction time, false otherwise.
    bool operator!=(const Event& other) const;

    /// @brief Overloaded input stream operator for reading Event objects.
    /// @param is The input stream.
    /// @param event The Event object to read into.
    /// @return The input stream after reading the event data.
    friend std::istream& operator>>(std::istream& is, Event& event);

private:
    int arrivalTime; ///< The arrival time of the event.
    int transactionTime; ///< The transaction time of the event.
    char eventType; ///< The type of the event ('A' for arrival, 'D' for departure).
};
#include "Event.cpp"
#endif // EVENT_H
