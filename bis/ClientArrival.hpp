#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include <iostream>

#include "Bank.hpp"
#include "Client.hpp"
#include "Event.hpp"

//class Bank;
//class Event;

class ClientArrival: public Event {
public:
    explicit ClientArrival(double, Bank*);
    void process() override;
};

#endif
