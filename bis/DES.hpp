#ifndef __DES_HPP
#define __DES_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

class DES {
protected:
    double _time;

    set<Event*> _events;
    set<Event*>::iterator _eventIterator;
public:
    explicit DES(double);
    virtual ~DES();

    virtual void run();
    void addEvent(Event*);
    double time();
};

#endif
