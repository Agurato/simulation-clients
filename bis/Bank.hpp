#ifndef __BANK_HPP
#define __BANK_HPP

#include "Cashier.hpp"

class Bank{
protected:
    double _averageArrivalTime;
    double _expectedTime;
    int _cashierNb;
    double* _averageServiceTimes;

public:
    Bank(double, int, double*, double averageArrivalTime);
    ~Bank();

    double averageArrivalTime();
    double expectedTime();
    int cashierNb();
    Cashier freeCashier();

    double realDuration();
};

#endif
