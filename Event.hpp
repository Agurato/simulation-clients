#ifndef __EVENT_HPP
#define __EVENT_HPP

class Event {
protected:
    double _time;
public:
    explicit Event(double);
    Event(const Event&);
    ~Event();
    virtual void process();
    double time() const;
    bool operator<(const Event&) const;
};

#endif