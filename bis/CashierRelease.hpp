#ifndef __CASHIER_RELEASE_HPP
#define __CASHIER_RELEASE_HPP

#include "Bank.hpp"
#include "Cashier.hpp"
#include "Client.hpp"
#include "Event.hpp"

class CashierRelease: public Event {
protected:
    Cashier _cashier;
    Client _client;
public:
    explicit CashierRelease(double, Cashier, Client, Bank*);
    void process();
};

#endif
