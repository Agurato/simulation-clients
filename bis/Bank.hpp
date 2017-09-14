#ifndef __BANK_HPP
#define __BANK_HPP

#include <set>

#include "Cashier.hpp"
#include "ClientArrival.hpp"
#include "DES.hpp"
#include "WaitingList.hpp"

class Bank: public DES {
protected:
    double _averageArrivalTime;
    double _expectedTime;
    int _cashierNb;

    Cashier* _cashiers;
    WaitingList* _waitingLists;

    // std::set<Event*> _events;
    // std::set<Event*>::iterator _eventIterator;

public:
    Bank(double, double, int, double, double*);
    ~Bank() override;

    void run() override;

    double averageArrivalTime();
    double expectedTime();
    int cashierNb();

    Cashier* freeCashier();
    WaitingList* shortestQueue();

    double realDuration();
};

#endif
