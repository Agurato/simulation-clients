#include "Bank.hpp"

using namespace std;

/* Constructor for Bank, with all simulation parameters */
Bank::Bank(double start, double expectedTime, int cashierNb, double averageArrivalTime, double* averageServiceTimes)
    : DES(start) {
    // Init attributes
    _expectedTime = expectedTime;
    _cashierNb = cashierNb;
    _averageArrivalTime = averageArrivalTime;

    // Create cashiers and waiting lines
    _cashiers = new Cashier[cashierNb];
    _waitingLists = new WaitingList[cashierNb];
    for(int i=0 ; i<cashierNb ; i++) {
        _waitingLists[i] = WaitingList(i, this);
        _cashiers[i] = Cashier(averageServiceTimes[i], i, this);
        cout << "Cashier " << i << ": " << _cashiers[i].averageServiceTime() << endl;
    }

    // Create first arrival event
    ClientArrival *ca = new ClientArrival(0.11111, this);
    addEvent(ca);
}

Bank::~Bank() {
    delete [] _cashiers;
    delete [] _waitingLists;
}

void Bank::run() {
    // For each event
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        // Change the current time of the simulation to the time of the event
        _time = e->time();
        cout << _time << ":  \t";
        // Process event
        e->process();
    }
}

/* Returns the average arrival time */
double Bank::averageArrivalTime() {
    return _averageArrivalTime;
}

/* Returns the expected time of the simulation */
double Bank::expectedTime() {
    return _expectedTime;
}

/* Returns the number of cashiers in the bank */
int Bank::cashierNb() {
    return _cashierNb;
}

/* Returns a pointer to the first cashier waiting to serve clients (from 0 to n)
If there isn't any free Cashier, returns 0
*/
Cashier* Bank::freeCashier() {
    // Iterate through the cashiers, if one is free, return it
    for(int i=0 ; i < _cashierNb ; i++) {
        if(_cashiers[i].isFree()) {
            return &(_cashiers[i]);
        }
    }

    return nullptr;
}

/* Returns the waiting lists */
WaitingList* Bank::waitingLists() {
    return _waitingLists;
}

/* Returns a pointer to the shortest waiting list (from 0 to n) */
WaitingList* Bank::shortestQueue() {
    int minIndex = 0;
    int min = _waitingLists[minIndex].size();
    // Iterate through the waiting lists
    for(int i=1 ; i < _cashierNb ; i++) {
        // If a waiting list is shorter
        if(_waitingLists[i].size() < min) {
            // Store the index for this one
            minIndex = i;
            min = _waitingLists[i].size();
        }
    }
    
    return &(_waitingLists[minIndex]);
}

void Bank::addServiceTime(double t) {
    _serviceTimes.push_back(t);
}

/* Returns the real duration of the simuation */
double Bank::realDuration() {
    return _time;
}

void Bank::displayStats() {
    cout << "=============\nResultats de la simulation:" << endl << endl;

    // Simulation stats
    cout << "La simulation avait un duree prevue de " << _expectedTime << ", mais a dure " << _time << endl << endl;

    // Cashier stats
    cout << _cashierNb << " caissiers servent les clients en moyenne sur une duree de : [ ";
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _cashiers[i].averageServiceTime() << " ";
    }
    cout << "] (pour chaque caissier)" << endl << endl;

    // Client stats
    cout << "Les clients arrivent en moyenne toutes les " << _averageArrivalTime << " unites de temps" << endl << endl;

    cout << "Les clients ont attendu en moyenne ";
    double sum = 0;
    for (vector<double>::iterator it = _serviceTimes.begin() ; it != _serviceTimes.end(); ++it) {
        sum += *it;
    }
    cout << (sum/_serviceTimes.size()) << " unites de temps" << endl << endl;

    // Queue stats
    cout << "Les files ont atteint une taille maximale de [ ";
    int max = _waitingLists[0].maxLength();
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _waitingLists[i].maxLength() << " ";
        if(_waitingLists[i].maxLength() > max) {
            max = _waitingLists[i].maxLength();
        }
    }
    cout << "] clients (pour chaque file)" << endl;
    cout << "Soit un maximum de " << max << " clients, toutes files confondues" << endl << endl;

    cout << "Les files ont eu une moyenne de [ ";
    sum = 0;
    for(int i=0 ; i<_cashierNb ; i++) {
        cout << _waitingLists[i].averageLength() << " ";
        sum += _waitingLists[i].averageLength();
    }
    cout << "] clients (pour chaque file)" << endl;
    cout << "Soit un moyenne de " << (sum/_cashierNb) << " clients, toutes files confondues" << endl << endl;
}
