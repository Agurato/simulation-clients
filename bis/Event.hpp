#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <set>

#include "DES.hpp"

using namespace std;

class DES;

class Event {
protected:
    DES* _des;
    double _time;
public:
    explicit Event(double);
    explicit Event(double, DES*);
    // Event(const Event&);
    // ~Event();

    virtual void process();
    double time() const;
    bool operator<(const Event&) const;
};

#endif
