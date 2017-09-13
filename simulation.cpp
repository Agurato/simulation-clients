#include "simulation.hpp"

using namespace std;

int main() {
    set<Event> events;
    ClientArrival ca(2);
    events.insert(ca);
}