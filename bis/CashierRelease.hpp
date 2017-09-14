#ifndef __CASHIER_RELEASE_HPP
#define __CASHIER_RELEASE_HPP

#include "Event.hpp"
#include "Cashier.hpp"
#include "Client.hpp"

class CashierRelease: public Event {
protected:
    Cashier _cashier;
    Client _client;
public:
    explicit CashierRelease(double, Cashier, Client);
    void process();
};

#endif