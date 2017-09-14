#include "WaitingList.hpp"

WaitingList::WaitingList() = default;

WaitingList::~WaitingList() = default;

void WaitingList::add(Client c){
    clientList.push_back(c);
}

Client WaitingList::removeFirst(){
    Client c = clientList.front();
    clientList.pop_front();
    return c;
}

bool WaitingList::isEmpty(){
    return clientList.empty();
}

int WaitingList::maxLength() {

}

int WaitingList::averageLength() {

}

double WaitingList::averageWaitingTime() {

}
