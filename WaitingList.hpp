#ifndef __WAITINGLIST_HPP
#define __WAITINGLIST_HPP
#include <deque>
#iniclude "Client.cpp"
#include <iostream>


class WaitingList{
    protected:
        deque clientList;
    public:
        int maxLength();
        int averageLength();
        double averageWaitingTime();
        void add(Client);
        bool isEmpty();
        Client removeFirst();

};

#endif
