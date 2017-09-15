#include "CashierRelease.hpp"

using namespace std;

CashierRelease::CashierRelease(double t, Cashier* ca, int n, Client cl, Bank* b): Event(t, b), _cashier(ca), _client(cl) {
    _number = n;
}

void CashierRelease::process() {
    // Delete client
    cout << "Cashier " << _cashier->number() << " stops serving client" << endl;
    _cashier->wait();

    // If waiting list isn't empty, take 1st client waiting et have the cashier serve him
    if(_bank->waitingLists()[_number].size()>0) {
        Client c = _bank->waitingLists()[_number].removeFirst();
        _cashier->serve(c);
    }
    // Else, cashier waits
    else {
        _cashier->wait();
    }
}
