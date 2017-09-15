#include "Cashier.hpp"

using namespace std;

Cashier::Cashier(): _currentClient(Client(-1, 0)) {
    _number = -1;
    _averageServiceTime = -1;
    _clientNb = 0;
    _servingClient = false;
    _bank = 0;
}

Cashier::Cashier(double averageTime, int n, Bank* b): _currentClient(Client(-1, b)) {
    _number = n;
    _averageServiceTime = averageTime;
    _clientNb = 0;
    _servingClient = false;
    _bank = b;
}

Cashier::~Cashier() = default;

double Cashier::averageServiceTime(){
    return _averageServiceTime;
}

int Cashier::clientNb(){
    return _clientNb;
}

int Cashier::number() {
    return _number;
}

bool Cashier::isFree() {
    return !_servingClient;
}

void Cashier::serve(Client c) {
    _clientNb ++;
    _servingClient = true;
    _currentClient = c;
    double eventTime = _bank->time()+Poisson::next(_averageServiceTime);
    // Add event to stop serving the client
    _bank->addEvent(new CashierRelease(eventTime, this, _number, c, _bank));
}

void Cashier::wait() {
    _servingClient = false;
    _currentClient = Client(-1, 0);
}

double Cashier::occupationRate() {
    return -1;
}
