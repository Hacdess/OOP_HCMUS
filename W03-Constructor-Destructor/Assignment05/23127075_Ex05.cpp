#include "Theater.h"

int main() {
    Theater theater;

    string filename;
    cout << "Please input the name of the file that consists of the data of prices: ";
    cin >> filename;
    
    if (!theater.getPrices(filename))
        theater.setState(STATE::EXIT);

    while (theater.getState() != EXIT) {
        switch (theater.getState()) {
            case MENU:
                theater.showMenu();
                break;
            case PURCHASING:
                theater.purchase();
                break;
            case SALES:
                theater.viewSales();
                break;
            case CHECK:
                theater.check();
                break;
            default:
                break;
        }
    }

    return 0;
}