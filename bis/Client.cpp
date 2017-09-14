#include "Client.hpp"

Client::Client(double arrivalTime){
    _arrivalTime = arrivalTime;
}

double Client::arrivalTime() {
    return _arrivalTime;
}

