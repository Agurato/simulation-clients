#include "Bank.hpp"

Bank::Bank(double expectedTime, int nbCashier, double* averageServiceTimes ,double averageArrivalTime){
    _expectedTime = expectedTime;
    _nbCashier = nbCashier;
    _averageServiceTimes = new double[nbCashier];
    for (int i=0; i < nbCashier; i++){
        _averageServiceTimes[i] = averageServiceTimes[i];
    }
    _averageArrivalTime = averageArrivalTime;

}

int Bank::cashierNb() {
    return _nbCashier;
}

double Bank::expectedTime() {
    return _expectedTime;
}
