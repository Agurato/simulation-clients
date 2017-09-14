#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include "Event.hpp"

class ClientArrival: public Event {
public:
    explicit ClientArrival(double);
    void process() override;
    // bool operator<(const Event&) const;
};

#endif