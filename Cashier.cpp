#include "Cashier.hpp"

Cashier::Cashier(double averageTime){
    _averageServiceTime = averageTime;

}

double Cashier::averageServiceTime(){
    return _averageServiceTime;

}
