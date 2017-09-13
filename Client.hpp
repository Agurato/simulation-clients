#ifndef __CLIENT_HPP
#define __CLIENT_HPP



class Client{
    protected:
        double _arrivalTime;
    public:
        double arrivalTime();
        explicit Client (double);
};

#endif
