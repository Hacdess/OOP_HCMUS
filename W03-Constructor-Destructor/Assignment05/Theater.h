#ifndef _THEATER_H_
#define _THEATER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

enum STATE {MENU, PURCHASING, SALES, EXIT};

class Theater {
    private:
        STATE state;

        // 2D array for seats and prices
        char seats[15][30];
        float prices[15][30];

        // Sales: number of sold tickets and total revenue
        int numSoldTickets;
        float totalRevenue;

    public:
        Theater();
        ~Theater();

        bool getPrices(string filename);
        void setState(STATE state);
        STATE getState();

        void showSeats();
        void showPrices();

        void showMenu();
        bool isValid(int row, int col);
        void purchase();
        void viewSales();
};

#endif