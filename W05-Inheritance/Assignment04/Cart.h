#ifndef _STORE_H_
#define _STORE_H_

#include "Product.h"
#include "Promotion.h"

class Cart {
    private:
        // State = 1: on
        // State = 0: off
        bool state;
        vector<Product> products;
        vector<Promotion> promotions;
        int promotionIndex;
        int totalPrice;
    public:
        Cart();
        ~Cart();

        bool getProduct(string filename);
        void setState(bool state);
        bool getState();

        bool isDigit(char c);
        bool isNumber(string s);
        bool saveOrders(string filename);
        string getRequest();
        void solveRequest(string request);
        void run();
};

#endif