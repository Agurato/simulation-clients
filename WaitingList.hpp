#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP

#include <iostream>
#include <deque>
#include "Client.hpp"

class WaitingList{
    protected:
        std::deque<Client> clientList;
    public:
        int maxLength();
        int averageLength();
        double averageWaitingTime();
        void add(Client);
        bool isEmpty();
        Client removeFirst();

};

#endif
