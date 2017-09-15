#include "WaitingList.hpp"

/* Constructor with no params for the init of the array in Bank */
WaitingList::WaitingList() {
    _number = -1;
    _currClients = 0;
    _maxClients = 0;
}

/* Constructor with the index in the array of waiting lists in Bank */
WaitingList::WaitingList(int n): _number(n) {
    _currClients = 0;
    _maxClients = 0;
}

WaitingList::~WaitingList() = default;

/* Add Client to WaitingList */
void WaitingList::add(Client c){
    _currClients ++;
    if(_currClients > _maxClients) {
        _maxClients = _currClients;
    }
    _clientList.push_back(c);
}

/* Remove the first waiting Client of the queue and returns it */
Client WaitingList::removeFirst(){
    _currClients --;
    Client c = _clientList.front();
    _clientList.pop_front();
    return c;
}

/* Returns if the queue is empty */
bool WaitingList::isEmpty(){
    return _clientList.empty();
}

/* Returns the size of the queue */
int WaitingList::size() {
    return _clientList.size();
}

/* Returns the index of the queue in the Bank */
int WaitingList::number() {
    return _number;
}

// TODO: implement the stat functions
/* Returns the max length reached by the queue */
int WaitingList::maxLength() {
    return _maxClients;
}

/* Returns the number of client waiting in average in the queue */
double WaitingList::averageLength() {

}

/* Returns the average waiting time for clients in the queue */
double WaitingList::averageWaitingTime() {

}
