#include "WaitingList.hpp"
#iniclude "Client.cpp"
#include <iostream>
#include <deque>

namespace std;

deque<int> myints;


void WaitingList::maxLength(){
if (myints.size > WaitingList::maxLength){
        WaitingList::maxLength = myhints.size;
    }
return 0;
}


void WaitingList::isEmpty(){
    if (myints.size() == 0){
        return true;
    }else{
        return false;
    }
}



cout << "0. size: " << myints.size() << '\n';

for (int i=0; i<5; i++) myints.push_back(i);
cout << "1. size: " << myints.size() << '\n';

myints.insert (myints.begin(),5,100);
cout << "2. size: " << myints.size() << '\n';

myints.pop_back();
cout << "3. size: " << myints.size() << '\n';
