#include "Client.hpp"
#include <ctime>

namespace std;

Client::arrivalTime(){
        time_t result = time(nullptr);
        asctime(localtime(&result));

}
