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
    cin.ignore();
    savingBankAccount.input();
    savingBankAccounts.push_back(savingBankAccount);
    cout << endl;
    savingBankAccount.print();
    cout << endl;

    int selection;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Deposite an amount of money\n";
        cout << "2. Withdraw an amount of money\n";
        cout << "3. Withdraw immediately\n";
        cout << "4. Check the current balance\n";
        cout << "5. Check the interest at this time\n";
        cout << "6. Exit\n";
        cout << "Your selection: ";
        cin >> selection;

        switch (selection) {
        case 1:
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
                cout << endl;
            }
            break;
        
        case 2:
            cout << "Input amount of money to withdraw: ";
            cin >> money;
            if (savingBankAccounts[0].withdraw(money)) {
                cout << "Withdrew successfully!\n";
                cout << "Current balance: " << savingBankAccounts[0].getBalance() << " VND\n\n";
            } else
                cout << "Failed to withdraw!\n\n";
            break;

        case 3:
            cout << "Withdrew " << savingBankAccounts[0].withdrawImmediately() << " VND\n\n";
            break;
        
        case 4:
            cout << "Current balance: " << savingBankAccounts[0].getBalance() << " VND\n\n";
            break;

        case 5:
            cout << "Current interest: " << savingBankAccounts[0].getInterest() << " VND\n\n";
            break;

        case 6:
            cout << "Closing program...";
            return 0;
            break;

        default:
            cout << "Invalid selection!\n\n";
            break;
        }


    }

    
}