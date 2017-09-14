#ifndef __CASHIER_HPP
#define __CASHIER_HPP

#include "Client.hpp"

class Cashier{
protected:
    double _averageServiceTime;
    int _clientNb;
public:
    explicit Cashier(double averageServiceTime);
    ~Cashier();

    double averageServiceTime();
    int clientNb();

    bool isFree();
    void serve(Client);
    void wait();

    double occupationRate();
};

#endif
