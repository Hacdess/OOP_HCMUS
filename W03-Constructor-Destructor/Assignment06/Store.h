#ifndef _STORE_H_
#define _STORE_H_

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Store {
    private:
        // State = 1: on
        // State = 0: off
        bool state;

        vector<string> products;
        vector<int> quantities;
        vector<int> unitPrice;
        int totalQuantity;
        int totalPrice;
    public:
        Store();
        ~Store();

        bool getPRoduct(string filename);
        void setState(bool state);
        bool getState();

        void run();
};

#endif