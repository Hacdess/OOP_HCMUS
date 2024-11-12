#include "SavingBankAccount.h"
#include <vector>

int main() {
    cout << "\n========== Bank account ==========\n";
    BankAccount bankAccount;
    bankAccount.input();
    cout << endl;
    bankAccount.print();
    cout << endl;
    
    double money;
    cout << "Input amount of money to deposit: ";
    cin >> money;
    if (bankAccount.deposit(money)) {
        cout << "Deposited successfully!\n";
        cout << "Current balance: " << bankAccount.getBalance() << "\n\n";
    } else
        cout << "Failed to deposit!\n\n";

    cout << "Input amount of money to withdraw: ";
    cin >> money;
    if (bankAccount.withdraw(money)) {
        cout << "Withdrew successfully!\n";
        cout << "Current balance: " << bankAccount.getBalance() << "\n\n";
    } else
        cout << "Failed to withdraw!\n\n";

    cout << "\n========== Saving bank account ==========\n";
    vector <SavingBankAccount> savingBankAccounts;
    SavingBankAccount savingBankAccount;
    savingBankAccount.input();
    savingBankAccounts.push_back(savingBankAccount);
    cout << endl;
    savingBankAccount.print();
    cout << endl;

    cout << "Input amount of money to deposit: ";
    cin >> money;
    if (savingBankAccounts[0].deposit(money)) {
        cout << "Deposited successfully!\n";
        cout << "Current balance: " << savingBankAccounts[0].getBalance() << "\n\n";
    } else {
        cout << "Failed to deposit!\n\n";
        cout << "Please created a new saving account to store new amount of money!\n\n";
        savingBankAccount.createNew(savingBankAccounts[0], money);
        cout << endl;
        savingBankAccounts.push_back(savingBankAccount);
        cout << "New account:\n";
        savingBankAccounts[1].print();
    }
    
}