#ifndef __BANK_HPP
#define __BANK_HPP
#include "Cashier.hpp"

class Bank{
    protected:
        double _averageArrivalTime;
    public:
        double expedtedTime();
        int nbCasher();
        double averageArrivalTime();
        double realDuration();
        int nbClients();
        void aFreeCashier();
        Bank(double averageArrivalTime);
}

#endif
