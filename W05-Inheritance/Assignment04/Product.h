#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Product {
    private:
        string name;
        int quantity;
        int unitPrice;
        bool selected;
    public:
        Product();
        Product(string name, int quantity, int unitPrice);
        ~Product();

        void setName(string name);
        void setQuantity(int quantity);
        void setUnitPrice(int unitPrice);
        void setSelected(bool selected);

        string getName();
        int getQuantity();
        int getUnitPrice(); 
        bool getSelected();

        void increase();
        void decrease();
};

#endif