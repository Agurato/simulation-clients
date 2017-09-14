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
        _cashiers[i].averageServiceTime(averageServiceTimes[i]);
        cout << "Cashier " << i << ": " << _cashiers[i].averageServiceTime() << endl;
    }

    // Create first arrival event
    // Bank *b = new Bank(start, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    ClientArrival *ca = new ClientArrival(0.1);
    addEvent(ca);
}

Bank::~Bank() {
    delete [] _cashiers;
    delete [] _waitingLists;
}

void Bank::run() {
    for(_eventIterator = _events.begin() ; (_eventIterator != _events.end()) && (_time < _expectedTime) ; ++_eventIterator) {
        Event *e = *_eventIterator;
        _time = e->time();
        cout << _time << ":\t";
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

// TODO : implement
Cashier Bank::freeCashier() {
    // Check all cashiers and see if 1 is free
    return Cashier(2);
}

// TODO : implement
double Bank::realDuration() {
    return 0;
}
