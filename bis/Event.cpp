#include "Event.hpp"

#include <iostream>

Event::Event(double time, Bank* bank) {
    _time = time;
    _bank = bank;
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

//bool Event::operator<(const Event& e) const {
//    std::cout << (_time < e.time()) << std::endl;
//    return (_time < e.time());
//}


