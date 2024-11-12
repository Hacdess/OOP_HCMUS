#include "BankAccount.h"

BankAccount::BankAccount() {
    balance = 0;
}

void BankAccount::input() {
    cout << "Enter account number: ";
    getline(cin, accountNumber);

    cout << "Enter owner's name: ";
    getline(cin, name);

    cout << "Enter owner's social ID: ";
    getline(cin, socialID);

    cout << "Input balance: ";
    cin >> balance;
}

void BankAccount::print() const {
    cout << "Account information:\n";
    cout << "Account number: " << accountNumber << endl;
    cout << "Owner's name: " << name << endl;
    cout << "Owner's social ID: " << socialID << endl;
    cout << "Balance: " << balance << " VND" << endl;
}

bool BankAccount::deposit(double money) {
    if (money > 0) {    
        balance += money;
        return true;
    }

    cout << "Invalid amount of money\n";
    return false;
}

bool BankAccount::withdraw(double money) {
    if (money <= 0) {
        cout << "Invalid amount of money\n";
        return false;
    }

    if (balance - money < 50000) {
        cout << "Your balance will be less than 50000 once being withdrawed!\n";
        return false;
    }

    balance -= money;
    return true;
}

double BankAccount::getBalance() {
    return balance;
}
