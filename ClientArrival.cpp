#include "ClientArrival.hpp"

ClientArrival::ClientArrival(double t): Event(t) {}

void ClientArrival::process() {
    // Create client (using average time)
    
    // If a cashier is free, use the first to serve the client
    // Else, client joins the queue

    // Compute next arrival time = t
    // If t < estimated_time, add client arrival event to event list
}

bool Event::operator<(const Event& e) const {
    return (_time < e.time());
}