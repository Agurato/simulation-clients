#ifndef __CLIENT_HPP
#define __CLIENT_HPP

#include "Bank.hpp"

class Bank;

class Client{
protected:
    double _arrivalTime;
    Bank* _bank;
public:
    explicit Client(double, Bank*);

    double arrivalTime();
};

#endif
