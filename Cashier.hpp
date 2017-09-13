#ifndef __CASHIER_HPP
#define __CASHIER_HPP
class Cashier{
    protected:
        double _averageServiceTime;
    public:
        double averageServiceTime();
        int nbClient();
        double occupationRate();
        bool isFree();
        void serve(Client);
        void wait();
        void bank(): Bank*;
        Cashier(double averageServiceTime);
}

#endif
