#include "Cashier.hpp"

Cashier::Cashier(double averageTime){
    _averageServiceTime = averageTime;
}

Cashier::~Cashier() = default;

double Cashier::averageServiceTime(){
    return _averageServiceTime;

}

int Cashier::clientNb(){
    return _clientNb;
}

bool Cashier::isFree() {

}

void Cashier::serve(Client) {

}

void Cashier::wait() {

}

double Cashier::occupationRate() {

}
