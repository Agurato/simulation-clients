#include "simulation.hpp"

using namespace std;

int main() {
    set<Event*> events;
    ClientArrival *ca = new ClientArrival(2);
    events.insert(ca);
    displayEvents(events);
}

void displayEvents(set<Event*> events) {
    cout << events.size() << endl;
}