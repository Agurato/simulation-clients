#ifndef __CASHIER_HPP
#define __CASHIER_HPP
public class Cashier{
    double averageServiceTime();
    int nbClient();
    double occupationRate();
    bool isFree();
    void serve(Client);
    void wait();
    void bank(): Bank*;
}

#endif
