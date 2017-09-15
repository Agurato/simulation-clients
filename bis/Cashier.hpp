#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include <iostream>

#include "Bank.hpp"
#include "CashierRelease.hpp"
#include "Client.hpp"

class Bank;

class Cashier{
protected:
    double _averageServiceTime;
    Client* _currentClient;
    int _clientNb;

    Bank* _bank;
public:
    Cashier();
    explicit Cashier(double, Bank*);
    ~Cashier();

    double averageServiceTime();
    int clientNb();

    bool isFree();
    void serve(Client*);
    void wait();

    double occupationRate();
};

#endif
