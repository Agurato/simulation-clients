#include "DES.hpp"

DES::DES(double start) {
    _time = start;
}

DES::~DES() {
    _events.clear();
}

void DES::run() {
}

void DES::addEvent(Event* e) {
    _events.insert(e);
}

double DES::time() {
    return _time;
}
