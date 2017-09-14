#ifndef __CLIENT_HPP
#define __CLIENT_HPP

class Client{
protected:
    double _arrivalTime;
public:
    explicit Client (double);

    double arrivalTime();
};

#endif
