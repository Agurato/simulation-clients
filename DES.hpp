#ifndef __DES_HPP
#define __DES_HPP

#include <iostream>
#include <set>
#include "Event.hpp"

using namespace std;

class DES {
protected:
    double _time;
    set<Event> _eventSet;
public:
    explicit DES(double);
    void run();
    void addEvent(const Event&);
    double time();
};

#endif