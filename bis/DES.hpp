#ifndef __DES_HPP
#define __DES_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        return (lhs->time() < rhs->time());
    }
};

class DES {
protected:
    double _time;

    set<Event*, EventComp> _events;
    set<Event*, EventComp>::iterator _eventIterator;
public:
    explicit DES(double);
    virtual ~DES();

    virtual void run();
    void addEvent(Event*);
    double time();
};

#endif
