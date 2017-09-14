#include "Cashier.hpp"

Cashier::Cashier() {
    _averageServiceTime = -1;
    _clientNb = 0;
    _currentClient = 0;
}

Cashier::Cashier(double averageTime){
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _currentClient = 0;
}

Cashier::~Cashier() = default;


double Cashier::averageServiceTime(){
    return _averageServiceTime;
}
void Cashier::averageServiceTime(double newTime) {
    _averageServiceTime = newTime;
}

int Cashier::clientNb(){
    return _clientNb;
}

bool Cashier::isFree() {
    return (_currentClient == 0);
}

void Cashier::serve(Client) {

}

void Cashier::wait() {

}

double Cashier::occupationRate() {
    return -1;
}
