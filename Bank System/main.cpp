#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Event.h"
#include "SL_PriorityQueue.h"

using namespace std;

// Function to simulate the bank queue
void simulate()
{
    int totalCustomers = 0;         // Total number of customers processed
    double totalWaitingTime = 0.0; // Total waiting time for all customers

    string filename = "test.txt"; // Input file name containing customer arrival and transaction time data

    vector<int> departureTimes; // To store departure times for statistics

    ifstream dataFile;
    dataFile.open(filename.c_str());

    if (dataFile.fail())
    {
        cout << filename << " file cannot be opened!" << endl;
        cout << endl;
        return;
    }

    // Create priority queues for bank queue and event list
    PriorityQueueInterface<Event>* bankQueue = new SL_PriorityQueue<Event>();
    PriorityQueueInterface<Event>* eventListPQueue = new SL_PriorityQueue<Event>();

    bool tellerAvailable = true; // Flag to check if teller is available

    int arrivalTime, transactionTime;
    while (dataFile >> arrivalTime >> transactionTime)
    {
        // Create an arrival event for each customer and add it to the event list priority queue
        Event newArrivalEvent(arrivalTime, transactionTime);
        eventListPQueue->add(newArrivalEvent);
        totalCustomers++;
    }
    dataFile.close();

    cout << "Simulation Begins" << endl;

    // Simulation loop
    while (!eventListPQueue->isEmpty())
    {
        Event newEvent = eventListPQueue->peek(); // Get the next event from the event list priority queue
        unsigned int currentTime = newEvent.getArrivalTime();

        if (newEvent.getEventType() == 'A') // If the event is an arrival event
        {
            eventListPQueue->remove(); // Remove the arrival event from the event list

            Event customer = newEvent; // Get the arrival event as the current customer

            if (bankQueue->isEmpty() && tellerAvailable) // If the bank queue is empty and teller is available
            {
                // Process the arrival event immediately
                int departureTime = currentTime + newEvent.getTransactionTime();
                Event newDepartureEvent(departureTime, 0, 'D');
                eventListPQueue->add(newDepartureEvent); // Add the departure event to the event list
                tellerAvailable = false;                 // Teller is now busy
                departureTimes.push_back(departureTime);  // Store departure time for statistics
                int waitingTime = departureTime - customer.getArrivalTime();
                totalWaitingTime += waitingTime; // Update the total waiting time
            }
            else
            {
                // Otherwise, add the customer to the bank queue for later processing
                bankQueue->add(customer);
            }

            cout << "Processing an arrival event at time:\t" << customer.getArrivalTime() << endl;
        }
        else
        {
            // Process the departure event
            eventListPQueue->remove(); // Remove the departure event from the event list

            if (!bankQueue->isEmpty())
            {
                // If there are customers in the bank queue, process the next customer
                Event customer = bankQueue->peek();
                bankQueue->remove();
                int departureTime = currentTime + customer.getTransactionTime();
                Event newDepartureEvent(departureTime, 0, 'D');
                eventListPQueue->add(newDepartureEvent); // Add the next departure event to the event list
            }
            else
            {
                // If the bank queue is empty, teller is available
                tellerAvailable = true;
            }

            cout << "Processing a departure event at time:\t" << currentTime << endl;
        }
    }

    delete bankQueue;         // Delete the bank queue priority queue
    delete eventListPQueue;   // Delete the event list priority queue

    // Calculate the average waiting time.
    double averageWaitingTime = totalWaitingTime / totalCustomers;

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "Total number of customers processed: " << totalCustomers << endl;
    cout << "Average amount of time spent waiting: " << averageWaitingTime << endl;
}

int main()
{
    simulate(); // Start the simulation

    cout << endl;
    return 0;
}
