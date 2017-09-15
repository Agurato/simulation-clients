#include "ClientArrival.hpp"

using namespace std;

ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {}

void ClientArrival::process() {
    // Create client (using average time)
    Client client(_time, _bank);

    Cashier* cashier = _bank->freeCashier();
    // If there isn't any free cashier, add client to the sortest queue
    if(cashier == 0) {
        WaitingList* wl = _bank->shortestQueue();
        wl->add(client);
        cout << "New client waits at line " << wl->number() << endl;
    }
    // Else, have the cashier serve the client
    else {
        cout << "New client served by " << cashier->number() << endl;
        cashier->serve(client); 
    }
    double nextTime = _bank->time()+Poisson::next(_bank->averageArrivalTime());
    if(nextTime < _bank->expectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, _bank);
        _bank->addEvent(ca);
    }
}
