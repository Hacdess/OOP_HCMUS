#include "Theater.h"

Theater::Theater() {
    state = MENU;

    for (int i = 0; i < 15; ++i)
        for (int j  = 0; j < 30; ++j) {
            seats[i][j] = '#';
            prices[i][j] = 0;
        }

    numSoldTickets = 0;
    totalRevenue = 0;
}

Theater::~Theater() {
    cout << "Closing program...\n";
}

bool Theater::getPrices(string filename) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Can't open file!\n";
        return 0;
    }

    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 30; ++j)
            fin >> prices[i][j];

    fin.close();
    return 1;
}

void Theater::setState(STATE state) {
    this->state = state;
}

STATE Theater::getState() {
    return state;
}

void Theater::showSeats() {
    cout << "\t\tSeats\n";
    cout << "\t123456789012345678901234567890\n";
    for (int i = 0; i < 15; ++i) {
        cout << "Row " << i + 1 << '\t';
        for (int j = 0; j < 30; ++j)
            cout << seats[i][j];
        cout << endl;
    }
}

void Theater::showMenu() {
    cout << "\n========= MENU =========\n";
    cout << "Please select an action:\n";
    cout << "1. Buying tickets.\n";
    cout << "2. View ticket sales.\n";
    cout << "3. Check sold, available seats in each row and available seats in the entire auditorium.\n";
    cout << "4. Exit.\n";
    cout << "Your selection: ";
    int select;
    cin >> select;
    
    while (select != 1 && select != 2 && select != 3 && select != 4) {
        cout << "\nSelction must be 1, 2 or 3! Please input again:\n";
        cout << "1. Buying tickets.\n";
        cout << "2. View ticket sales.\n";
        cout << "3. Check sold, available seats in each row and available seats in the entire auditorium.\n";
        cout << "4. Exit.\n";
         cout << "Your selection: ";
        cin >> select;
    }

    switch (select) {
        case 1:
            state = PURCHASING;
            break;
        case 2:
            state = SALES;
            break;
        case 3:
            state = CHECK;
            break;
        case 4:
            state = EXIT;
            break;
        default:
            break;
    }
}

bool Theater::isValid(int row, int col) {
    return row >-1 && row < 15 && col > -1 && col < 30 && seats[row][col] == '#';
}

void Theater::purchase() {
    int selectRow, selectCol, numTickets = 0;
    float total = 0;

    while (state == PURCHASING) {
        showSeats();
        cout << "\nQuantity: " << numTickets << '\t' << "Total: " << total << " dollars" << endl;
        cout << "\nChoose a seat by inputting the seat index or get back to menu by inputting \"0 0\"?\nYour selection: ";
        cin >> selectRow >> selectCol;

        if (selectRow == 0 && selectCol == 0)
            state = MENU;
        else {
            while (!isValid(selectRow - 1, selectCol - 1)) {
                cout << "Seat (" << selectRow << ',' << selectCol << ") is not valid! Please choose another one: ";
                cin >> selectRow >> selectCol;
            }

            numTickets ++;
            total += prices[--selectRow][--selectCol];
            seats[selectRow][selectCol] = '*';
        }
    }

    numSoldTickets += numTickets;
    totalRevenue += total;
}

void Theater::viewSales() {
    char c;

    cout << "\n========== Sales ==========\n";
    cout << "Number of sold tickets: " << numSoldTickets << endl;
    cout << "Total revenue: " << totalRevenue << endl;
    
    do {
        cout << "Press 'e' to get back to menu: ";
        cin >> c;
    } while (c != 'e');
        
    state = MENU;
}

void Theater::checkAvailable() {
    char c;
    cout << "\n========== SEAT STATUS ==========\n";
    short count = 0;

    for (int i = 0; i < 15; ++i) {
        count  = 0;
        cout << "Row " << i + 1 << ":\t Number of sold seats: ";
        for (int j = 0; j < 30; ++j)
            if (seats[i][j] == '*')
                count ++;
        cout << count << "\tNumber of available seats:" << 30 - count << endl;
    }

    cout << "Number of available seats in the entire auditorium: " << 450 - numSoldTickets << endl;

    do {
        cout << "Press 'e' to get back to menu: ";
        cin >> c;
    } while (c != 'e');

    state = MENU;
}
