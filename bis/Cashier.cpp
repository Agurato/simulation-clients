#include "Cashier.hpp"

using namespace std;

Cashier::Cashier() {
    _averageServiceTime = -1;
    _clientNb = 0;
    _currentClient = 0;
    _bank = 0;
}

Cashier::Cashier(double averageTime, Bank* b){
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _currentClient = 0;
    _bank = b;
}

Cashier::~Cashier() = default;


double Cashier::averageServiceTime(){
    return _averageServiceTime;
}

int Cashier::clientNb(){
    return _clientNb;
}

bool Cashier::isFree() {
    return (_currentClient == 0);
}

void Cashier::serve(Client* c) {
    _clientNb ++;
    _currentClient = c;
    double eventTime = c->arrivalTime()+Poisson::next(_averageServiceTime);
    // Add event to stop serving the client
    _bank->addEvent(new CashierRelease(eventTime, this, c, _bank));
}

void Cashier::wait() {

}

double Cashier::occupationRate() {
    return -1;
}
