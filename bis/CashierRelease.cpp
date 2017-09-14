#include "CashierRelease.hpp"

CashierRelease::CashierRelease(double t, Cashier ca, Client cl): Event(t), _cashier(ca), _client(cl) {}

void CashierRelease::process() {
    // Delete client

    // If waiting list isn't empty, take 1st client waiting et have the cashier serve him
    // Else, cashier waits
}