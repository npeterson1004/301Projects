#include "Event.h"

Event::Event()
{
    arrivalTime = 0;
    transactionTime = 0;
    eventType = ' ';
}

Event::Event(int arrTime, int transTime)
{
    arrivalTime = arrTime;
    transactionTime = transTime;
    eventType = 'A';
}

Event::Event(int arrTime, int transTime, char type)
{
    arrivalTime = arrTime;
    transactionTime = transTime;
    eventType = type;
}

int Event::getArrivalTime() const
{
    return arrivalTime;
}

int Event::getTransactionTime() const
{
    return transactionTime;
}

void Event::setArrivalTime(int time)
{
    arrivalTime = time;
}

void Event::setTransactionTime(int type)
{
    transactionTime = type;
}

bool Event::operator<(const Event& other) const
{
    return arrivalTime < other.arrivalTime;
}

std::istream& operator>>(std::istream& is, Event& event)
{
    int transactionTime, arrivalTime;
    is >> transactionTime >> arrivalTime;
    event.setTransactionTime(transactionTime);
    event.setArrivalTime(arrivalTime);
    return is;
}

bool Event::operator>(const Event& other) const
{
    return arrivalTime > other.arrivalTime;
}

bool Event::operator==(const Event& other) const
{
    return (arrivalTime == other.arrivalTime) && (transactionTime == other.transactionTime);
}

bool Event::operator!=(const Event& other) const
{
    return !(*this == other);
}

char Event::getEventType() const
{
    return eventType;
}
