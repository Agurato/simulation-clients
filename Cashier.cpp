#include <string>
#include "Cashier.hpp"

Cashier::Cashier(double averageTime){
    _averageServiceTime = averageTime;

}

double Cashier::averageServiceTime(){
    return _averageServiceTime;

}

int Cashier::nbClient(){
    return _nbClient;
}

void Cashier::occupationRate() {

}


void Cashier::serve(&Client){

}
