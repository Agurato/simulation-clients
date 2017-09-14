#include "Event.hpp"

Event::Event(double time) {
    _time = time;
    _des = 0;
}

Event::Event(double time, DES* des) {
    _time = time;
    _des = des;
}

// Event::Event(const Event& e) {
//     _time = e.time();
// }

// Event::~Event() = default;

void Event::process() {
}

double Event::time() const {
    return _time;
}

bool Event::operator<(const Event& e) const {
    return (_time < e.time());
}
