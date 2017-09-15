#include "ClientArrival.hpp"

using namespace std;

/* Constructor with parameters:
- t     time of the event
- b     pointer to the bank
*/
ClientArrival::ClientArrival(double t, Bank* b): Event(t, b) {}

/* Process of the client arrival event */
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

    // Create next client arrival event if it doesn't exceed the expected time of the simulation
    double nextTime = _bank->time()+Poisson::next(_bank->averageArrivalTime());
    if(nextTime < _bank->expectedTime()) {
        ClientArrival *ca = new ClientArrival(nextTime, _bank);
        _bank->addEvent(ca);
    }
}
