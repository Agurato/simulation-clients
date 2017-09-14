#include "Client.hpp"

Client::Client(double arrivalTime, Bank* bank){
    _arrivalTime = arrivalTime;
    _bank = bank;
}

double Client::arrivalTime() {
    return _arrivalTime;
}

