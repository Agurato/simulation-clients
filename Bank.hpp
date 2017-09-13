#ifndef __BANK_HPP
#define __BANK_HPP
#include "Cashier.hpp"

class Bank{
    protected:
        double _averageArrivalTime;
        double _expectedtime;
        int _nbCashier;
        double* averageServiceTimes;


    public:
        double expedtedTime();
        int nbCasher();
        double averageArrivalTime();
        double realDuration();
        int nbClients();
        void aFreeCashier();
        Bank(double, int, double*, double averageArrivalTime);
}

#endif
