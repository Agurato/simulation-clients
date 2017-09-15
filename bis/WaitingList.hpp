#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP

#include <iostream>
#include <deque>
#include "Client.hpp"

class Client;

class WaitingList{
protected:
    int _number;
    int _currClients;
    int _maxClients;
    std::deque<Client> _clientList;

public:
    WaitingList();
    explicit WaitingList(int);
    ~WaitingList();

    void add(Client);
    bool isEmpty();
    int size();
    Client removeFirst();
    int number();

    int maxLength();
    double averageLength();
    double averageWaitingTime();
};

#endif
