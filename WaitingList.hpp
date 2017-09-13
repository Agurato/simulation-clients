#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP
#include <deque>
#include "Client.hpp"
#include <iostream>


class WaitingList{
    protected:
        std::deque clientList;
    public:
        int maxLength();
        int averageLength();
        double averageWaitingTime();
        void add(Client);
        bool isEmpty();
        Client removeFirst();

};

#endif
