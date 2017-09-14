#include "DES.hpp"

DES::DES(double start) {
    _time = start;
}

void DES::run() {

}

void DES::addEvent(const Event& e) {
    _eventSet.insert(e);
}

double DES::time() {
    return _time;
}