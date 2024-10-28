#include "Store.h"

Store::Store() {
    state = 1;
    totalQuantity = 0;
    totalPrice = 0;
}

Store::~Store() {
    cout << "Closing Program...\n";
    products.clear();
    quantities.clear();
    unitPrice.clear();
}

bool Store::getPRoduct(string filename) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Can't open file!\n";
        state = 0;
        return 0;
    }

    string getString;
    int getNum;
    fin >> getString;
    fin.ignore();

    int count = 0;
    while (getline(fin, getString, ',')) {
        products.push_back(getString);

        fin >> getNum;
        quantities.push_back(getNum);
        fin.ignore();
        
        fin >> getNum;
        unitPrice.push_back(getNum);
        fin.ignore();
    }

    int len = products.size();
    for (int i = 0; i < len; ++i)
        totalPrice += (unitPrice[i] * quantities[i]);

    fin.close();
    return 1;
}

void Store::setState(bool state) {
    this->state = state;
}

bool Store::getState() {
    return state;
}

void Store::run() {
    int len = products.size();
    string inputLine;

    cout << "\n===================================== TKIN SHOP =====================================\n";
    cout << left << setw(55) << "Products"
                 << setw(20) << "Quantity" << right
                 << setw(10) << "Price\n";
    cout << "---------------------------------------------------------------------------------------\n";

    for (int i = 0; i < len; ++i)
        cout << left << setw(55) << products[i] 
                     << setw(20) << quantities[i]  << right 
                     << setw(10) << ((unitPrice[i] == 0) ? "Free" : (to_string(unitPrice[i])) + " VND") << endl;
    cout << "\n-------------------------------------------------------------------------------------\n";
    
    cout << "Total Prices: " << totalPrice << " VND" << endl;
    cout << "---------------------------------------------------------------------------------------\n";
    
    cout << "Please select an option:\n";
    cout << "1. Add / decline the quantity of a product: <product>,<key '+' / '-'>\tEx: Keyboard,+\n";
    cout << "2. Remove a product: <product>,<key 'x'>\tEx: Keyboard,x\n";
    cout << "3. Purchase: key 'p'\n";
    cout << "4. Exit: key 'e'\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Your selection: ";
    getline(cin, inputLine, '\n');

    if (inputLine == "e") {
        state = 0;
        cout << "Exiting...\n";
        cout << "\n=====================================================================================\n";
    }
    else if (inputLine == "p") {
        if (products.size() < 1)
            cout << "There is nothing to purchase. Please select key 'e' to exit.\n";
        else {
            cout << "\nPurchased successfully!\n";
            cout << "\n=====================================================================================\n";
            state = 0;
        }
    }
    else {
        stringstream ss(inputLine);
        string product;
        char action;
        getline(ss, product, ',');
        ss >> action;

        int len = products.size();
        bool notFound = 1;
        for (int i = 0; i < len; ++i)
            if (products[i] == product) {
                notFound = 0;
                switch (action) {
                    case '+':
                        quantities[i]++;
                        totalPrice += unitPrice[i];
                        break;
                    case '-':
                        quantities[i]--;
                        totalPrice -= unitPrice[i];

                        if (quantities[i] < 1) {
                            products.erase(products.begin() + i);
                            quantities.erase(quantities.begin() + i);
                            unitPrice.erase(unitPrice.begin() + i);
                            --i;
                        }

                        break;
                    case 'x':
                        totalPrice -= (unitPrice[i] *  quantities[i]);
                        products.erase(products.begin() + i);
                        quantities.erase(quantities.begin() + i);
                        unitPrice.erase(unitPrice.begin() + i);
                        --i;
                        break;
                    default:
                        cout << "Invalid selection!\n";
                        break;
                }
                break;
            }

        if (notFound)
            cout << "Can't find the product in the shopping cart!\n";
    }
}
