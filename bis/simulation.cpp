#include "simulation.hpp"

using namespace std;

int main() {
    double expectedTime = 500;
    int cashierNb = 3;
    double averageArrivalTime = 8;
    double* averageServiceTimes = new double[cashierNb];

    Poisson::init();

    genRandomDoubles(15, 15, &averageServiceTimes, cashierNb);

    Bank bank(0, expectedTime, cashierNb, averageArrivalTime, averageServiceTimes);
    bank.run();
}

void genRandomDoubles(double min, double max, double** arr, int arrSize) {
    uniform_real_distribution<double> unif(min, max);
    random_device rd;
    default_random_engine re(rd());
    for(int i=0 ; i<arrSize ; i++) {
        *(*arr+i) = unif(re);
    }
}

void displayEvents(set<Event*> events) {
    cout << events.size() << endl;
}
