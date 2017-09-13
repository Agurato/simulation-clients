#include "Event.hpp"

Event::Event(double time) {
    _time = time;
}

Event::Event(const Event& e) {
    _time = e.time();
}

double Event::time() const {
    return _time;
}

bool Event::operator<(const Event& e) const {
    return (_time < e.time());
}