#include "Bank.hpp"

using namespace std;

/* Constructor for Bank, with all simulation parameters */
Bank::Bank(double start, double expectedTime, int cashierNb, double averageArrivalTime, double* averageServiceTimes)
    : DES(start) {
    // Init attributes
    _expectedTime = expectedTime;
    _cashierNb = cashierNb;
    _averageArrivalTime = averageArrivalTime;

    // Create cashiers and waiting lines
    _cashiers = new Cashier[cashierNb];
    _waitingLists = new WaitingList[cashierNb];
    for(int i=0 ; i<cashierNb ; i++) {
        _waitingLists[i] = WaitingList(i);
        _cashiers[i] = Cashier(averageServiceTimes[i], i, this);
        cout << "Cashier " << i << ": " << _cashiers[i].averageServiceTime() << endl;
    }

    // Create first arrival event
    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

Bank::~Bank() {
    delete [] _cashiers;
    delete [] _waitingLists;
}

void Bank::run() {
    // For each event
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        // Change the current time of the simulation to the time of the event
        _time = e->time();
        cout << _time << ":  \t";
        // Process event
        e->process();
    }
}

/* Returns the average arrival time */
double Bank::averageArrivalTime() {
    return _averageArrivalTime;
}

/* Returns the expected time of the simulation */
double Bank::expectedTime() {
    return _expectedTime;
}

/* Returns the number of cashiers in the bank */
int Bank::cashierNb() {
    return _cashierNb;
}

/* Returns a pointer to the first cashier waiting to serve clients (from 0 to n)
If there isn't any free Cashier, returns 0
*/
Cashier* Bank::freeCashier() {
    // Iterate through the cashiers, if one is free, return it
    for(int i=0 ; i < _cashierNb ; i++) {
        if(_cashiers[i].isFree()) {
            return &(_cashiers[i]);
        }
    }

    return 0;
}

/* Returns the waiting lists */
WaitingList* Bank::waitingLists() {
    return _waitingLists;
}

/* Returns a pointer to the shortest waiting list (from 0 to n) */
WaitingList* Bank::shortestQueue() {
    int minIndex = 0;
    int min = _waitingLists[minIndex].size();
    // Iterate through the waiting lists
    for(int i=1 ; i < _cashierNb ; i++) {
        // If a waiting list is shorter
        if(_waitingLists[i].size() < min) {
            // Store the index for this one
            minIndex = i;
            min = _waitingLists[i].size();
        }
    }
    
    return &(_waitingLists[minIndex]);
}

/* Returns the real duration of the simuation */
double Bank::realDuration() {
    return _time;
}
