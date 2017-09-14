#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include "Client.hpp"

class Client;

class Cashier{
protected:
    double _averageServiceTime;
    Client* _currentClient;
    int _clientNb;
public:
    Cashier();
    explicit Cashier(double averageServiceTime);
    ~Cashier();

    double averageServiceTime();
    void averageServiceTime(double);
    int clientNb();

    bool isFree();
    void serve(Client);
    void wait();

    double occupationRate();
};

#endif
