#include "ClientArrival.hpp"

using namespace std;

ClientArrival::ClientArrival(double t): Event(t) {
    // _des = b;
}

void ClientArrival::process() {
    // Create client (using average time)
    cout << "Create client at time " << _time << endl;
    // Client *client = new Client(_time, _bank);
    
    // If a cashier is free, use the first to serve the client
    // Else, client joins the queue

    // Compute next arrival time = t
    // If t < estimated_time, add client arrival event to event list
}

// bool Event::operator<(const Event& e) const {
//     return (_time < e.time());
// }
