#include "Cart.h"

Cart::Cart() {
    state = 1;
    totalPrice = 0;
}

Cart::~Cart() {
    cout << "Closing Program...\n";
    products.clear();
}

bool Cart::getProduct(string filename) {
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
    Product product;

    while (getline(fin, getString, ',')) {
        product.setName(getString);

        fin >> getNum;
        product.setQuantity(getNum);
        fin.ignore();
        
        fin >> getNum;
        product.setUnitPrice(getNum);
        fin.ignore();

        products.push_back(product);
    }

    fin.close();
    return 1;
}

void Cart::setState(bool state) {
    this->state = state;
}

bool Cart::getState() {
    return state;
}

bool Cart::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Cart::isNumber(string s) {
    int len = s.length();

    for (int i = 0; i < len; ++i)
        if (!isDigit(s[i]))
            return 0;

    return 1;
}

string Cart::getRequest() {
    int len = products.size();
    string inputLine;

    cout << "\n========================================= SHOPEE CART =========================================\n";
    cout << left << setw(10) << "Selected"
                 << setw(55) << "Products"
                 << setw(20) << "Quantity" << right
                 << setw(10) << "Price\n";
    cout << "-----------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < len; ++i)
        cout << left << setw(10) << (products[i].getSelected() ? 'x' : ' ') 
                     << setw(55) << products[i].getName()
                     << setw(20) << products[i].getQuantity()  << right 
                     << setw(10) << ((products[i].getUnitPrice() == 0) ? "Free" : to_string(products[i].getUnitPrice()) + " VND") << endl;
    cout << "\n-----------------------------------------------------------------------------------------------\n";

    cout << "Total Prices: " << totalPrice << " VND" << endl;
    cout << "-----------------------------------------------------------------------------------------------\n";
    
    cout << "Please select an option:\n";
    cout << "1. Increase / decrease the quantity of a product: <product>|<key '+' / '-'>\tEx: Keyboard|+\n";
    cout << "2. Remove a product: <product>|<key 'x'>\tEx: Keyboard|x\n";
    cout << "3. Change the number of a product: <product>|<number>\tEx: Keyboard|6\n";
    cout << "4. Select / unselect a product: <product>|<key 's'>\tEx: Keyboard|s\n";
    cout << "5. Purchase: key 'p'\n";
    cout << "6. Exit: key 'e'\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    cout << "Your selection: ";
    getline(cin, inputLine, '\n');

    return inputLine;
}

void Cart::solveRequest(string request) {
    int len = products.size();
    
    if (request == "e") {
        state = 0;
        cout << "Exiting...\n";
        cout << "\n===============================================================================================\n";
    }
    else if (request == "p") {
        bool isEmpty = 1;

        for (int i = 0; i < len; ++i)
            if (products[i].getSelected())
                isEmpty = 0;
 
        if (products.size() < 1)
            cout << "There is nothing to purchase. Please select key 'e' to exit.\n";
        else if (isEmpty)
            cout << "There is nothing to purchase. Please select products to purchase or key 'e' to exit.\n";
        else {
            cout << "\nPurchased successfully!\n";
            cout << "\n===============================================================================================\n";
            state = 0;
        }
    }
    else {
        stringstream ss(request);
        string product;
        string action;

        getline(ss, product, '|');
        ss >> action;

        bool notFound = 1;
        for (int i = 0; i < len; ++i)
            if (products[i].getName() == product) {
                notFound = 0;

                if (action == "+") {
                    products[i].increase();
                    totalPrice += products[i].getUnitPrice();
                }

                else if (action == "-") {
                    products[i].decrease();
                    totalPrice -= products[i].getUnitPrice();

                    if (products[i].getQuantity() < 1) {
                        products.erase(products.begin() + i);
                        --i;
                    }
                }

                else if (action == "x") {
                    totalPrice -= (products[i].getUnitPrice() * products[i].getQuantity());
                    products.erase(products.begin() + i);
                    --i;
                }

                else if (action == "s")
                    products[i].setSelected(1 - products[i].getSelected());

                else if (isNumber(action)) {
                    int quantity = stoi(action);
                    if (quantity < 0)
                        cout << "Invalid selection!\n";
                    else if (quantity == 0) {
                        products.erase(products.begin() + i);
                        --i;
                    }
                    else
                        products[i].setQuantity(quantity);
                }

                else
                    cout << "Invalid selection!\n";

                break;
            }

        if (notFound)
            cout << "Can't find the product in the shopping cart!\n";
    }

    totalPrice = 0;
    for (int i = 0; i < len; ++i)
        if (products[i].getSelected())
            totalPrice += (products[i].getUnitPrice() * products[i].getQuantity());
}

void Cart::run() {
    string request = getRequest();
    solveRequest(request);
}
