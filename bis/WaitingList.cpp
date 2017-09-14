#include "WaitingList.hpp"

WaitingList::WaitingList() = default;

WaitingList::~WaitingList() = default;

void WaitingList::add(Client c){
    _clientList.push_back(c);
}

Client WaitingList::removeFirst(){
    Client c = _clientList.front();
    _clientList.pop_front();
    return c;
}

bool WaitingList::isEmpty(){
    return _clientList.empty();
}

int WaitingList::size() {
    return _clientList.size();
}

int WaitingList::maxLength() {

}

int WaitingList::averageLength() {

}

double WaitingList::averageWaitingTime() {

}
