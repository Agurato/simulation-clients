#include "Cashier.hpp"

using namespace std;

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

void Cashier::serve(Client* c) {
    _currentClient = c;
    cout << "Start serving client arrived at " << c->arrivalTime() << endl;
    // Add event to stop serving the client
}

void Cashier::wait() {

}

double Cashier::occupationRate() {
    return -1;
}
