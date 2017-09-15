#include "CashierRelease.hpp"

using namespace std;

CashierRelease::CashierRelease(double t, Cashier* ca, Client* cl, Bank* b): Event(t, b), _cashier(ca), _client(cl) {}

void CashierRelease::process() {
    // Delete client
    cout << "Cashier stops serving client" << endl;

    // If waiting list isn't empty, take 1st client waiting et have the cashier serve him
    // Else, cashier waits
}
