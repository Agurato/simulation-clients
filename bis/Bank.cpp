#include "Bank.hpp"

using namespace std;

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
    // Bank *b = new Bank(start, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

Bank::~Bank() {
    delete [] _cashiers;
    delete [] _waitingLists;
}

void Bank::run() {
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        _time = e->time();
        cout << _time << ":  \t";
        e->process();
    }
}

double Bank::averageArrivalTime() {
    return _averageArrivalTime;
}

double Bank::expectedTime() {
    return _expectedTime;
}

int Bank::cashierNb() {
    return _cashierNb;
}

Cashier* Bank::freeCashier() {
    for(int i=0 ; i < _cashierNb ; i++) {
        if(_cashiers[i].isFree()) {
            return &(_cashiers[i]);
        }
    }

    return 0;
}

WaitingList* Bank::waitingLists() {
    return _waitingLists;
}

WaitingList* Bank::shortestQueue() {
    int minIndex = 0;
    int min = _waitingLists[minIndex].size();
    for(int i=1 ; i < _cashierNb ; i++) {
        if(_waitingLists[i].size() < min) {
            minIndex = i;
            min = _waitingLists[i].size();
        }
    }
    return &(_waitingLists[minIndex]);
}

double Bank::realDuration() {
    return _time;
}
