#include "WaitingList.hpp"

using namespace std;

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

void WaitingList::averageLength() {

}

void WaitingList::averageWaitingTime() {

}

void WaitingList::maxLength() {

}
