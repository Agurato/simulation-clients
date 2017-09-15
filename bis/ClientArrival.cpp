#include "ClientArrival.hpp"

using namespace std;

ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {
    _bank = b;
}

void ClientArrival::process() {
    // Create client (using average time)
    cout << "Create client at time " << _time << endl;
//    cout << "Average arrival time " << _bank->cashierNb() << endl;
    Client *client = new Client(_time, _bank);

    Cashier* cashier = _bank->freeCashier();
    // If there isn't any free cashier, add client to the sortest queue
    if(cashier == 0) {
        WaitingList* wl = _bank->shortestQueue();
        wl->add(*client);
    }
    // Else, have the cashier serve the client
    else {
        cashier->serve(client);
        double nextTime = _bank->time()+Poisson::next(cashier->averageServiceTime());
        if(nextTime < _bank->expectedTime()) {
            ClientArrival *ca = new ClientArrival(nextTime, _bank);
            _bank->addEvent(ca);
        }
    }
}
