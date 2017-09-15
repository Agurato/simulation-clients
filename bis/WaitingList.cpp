#include "WaitingList.hpp"

WaitingList::WaitingList() {
    _number = -1;
}

WaitingList::WaitingList(int n): _number(n) {}

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

int WaitingList::number() {
    return _number;
}

int WaitingList::maxLength() {

}

int WaitingList::averageLength() {

}

double WaitingList::averageWaitingTime() {

}
