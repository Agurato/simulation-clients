#include "Bank.hpp"

Bank::Bank(double expectedTime, int cashierNb, double* averageServiceTimes ,double averageArrivalTime){
    _expectedTime = expectedTime;
    _cashierNb = cashierNb;
    _averageServiceTimes = new double[cashierNb];
    for (int i=0; i < cashierNb; i++){
        _averageServiceTimes[i] = averageServiceTimes[i];
    }
    _averageArrivalTime = averageArrivalTime;
}

Bank::~Bank() {
    delete [] _averageServiceTimes;
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
}

// TODO : implement
double Bank::realDuration() {
    return 0;
}
