#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <vector>


//const means this value NEVER changes
//ALL_CAPS naming for constants is industry standard
const std::string SAVE_FILE = "account.txt";


//-----Helper Functions-----------------------

void showMainMenu() {
    std::cout << "\n============================\n";
    std::cout << "     BANK ACCOUNT SYSTEM    \n";
    std::cout << "============================\n";
    std::cout << "1. View All Accounts\n";
    std::cout << "2. Create New Account\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Withdraw\n";
    std::cout << "5. View Account Info\n";
    std::cout << "6. Save & Exit\n";
    std::cout << "============================\n";
    std::cout << "Enter choice: ";
}

int getValidChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, Please enter a number: ";
    }
    return choice;

}   

void saveAllAccounts(std::vector<BankAccount>& accounts) {
    std::ofstream file(SAVE_FILE);
    if (!file.is_open()) {
        std::cout << "Error: Could not save data. \n";
        return;
    }
    file << accounts.size() << "\n"; //uploading the amount of accounts we hold
    

    for (BankAccount& acc : accounts) {
        acc.saveToFile(file);
    }

    file.close();
    std::cout << "All Accounts saved. \n";

}

bool loadAllAccounts(std::vector<BankAccount> accounts) {
    std::ifstream file(SAVE_FILE);
    if (!file.is_open()) return false;
    int count;
    file >> count; 
    file.ignore();

    for (int i = 0; i < count; i++) {
        BankAccount acc;
        if (acc.loadFromFile(file)) {
            accounts.push_back(acc);
        }
    }

    file.close();
    return true;

}

void listAllAccounts(std::vector<BankAccount>& accounts) {
    if (accounts.empty()) {
        std::cout << "No accounts found.\n";
        return;
    }
    std::cout << "\n=== ALL ACCOUNTS ===\n";
    for (int i = 0; i < accounts.size(); i++) {
        std::cout << i + 1 << "."
            << accounts[i].getName()
            << " ("
            << accounts[i].getAccountType()
            << ") - $"
            << accounts[i].getBalance()
            << "\n";
    }


}

int selectAccount(std::vector<BankAccount>& accounts) {
    listAllAccounts(accounts);
    if (accounts.empty()) return -1;

    std::cout << "Select Account Number: ";
    int choice = getValidChoice();
    if (choice < 1 || choice > accounts.size()) {
        std::cout << "Invalid Choice\n";
        return -1;
    }
    return choice - 1;
}



void createAccount(std::vector<BankAccount>& accounts) {
    std::string name, type;
    double balance; 

    std::cout << "\n=== Create New Account===\n";
    std::cin.ignore();

    std::cout << "Owner name: ";
    std::getline(std::cin, name);

    std::cout << "Account type: ";
    std::getline(std::cin, type);

    std::cout << "Starting Balance: $";
    std::cin >> balance; 

    accounts.emplace_back(name, balance, type); 

    std::cout << "Account created for " << name << "!\n";
}



//-------MAIN-------------------------------------

int main()
{

   
    std::vector<BankAccount> accounts;
 
    
    if (loadAllAccounts(accounts)) {
        std::cout << "Welcome Back! Loaded "
            << accounts.size()
            << " account(s).\n";
    }
    else {
        std::cout << "No Saved data found. Starting fresh\n";
    }

    //-----Program loop---------

    bool running = true;

    while (running) {

        showMainMenu();
        int choice = getValidChoice();

        switch (choice) {
        case 1: 
            listAllAccounts(accounts);
            break;
        case 2: 
            createAccount(accounts);
            break;
        case 3: {
            int idx = selectAccount(accounts);
            if (idx == -1) break;
            double amount; 
            std::cout << "Deposit amount : $";
            std::cin >> amount; 
            accounts[idx].deposit(amount);
            break;
        }
        case 4: {
            int idx = selectAccount(accounts);
            if (idx == -1) break;
            double amount;
            std::cout << "Withdraw amount: $";
            std::cin >> amount;
            accounts[idx].withdraw(amount);
            break;
        }
        case 5: {
            int idx = selectAccount(accounts);
            if (idx == -1) break;
            accounts[idx].displayInfo();
            break;
        }
        case 6: 
            saveAllAccounts(accounts);
            std::cout << "Goodbye!\n";
            running = false;
            break;

        default: 
            std::cout << "Please enter a valid number 1 - 6 \n";
            break;
        }

    
    }
    
    return 0;


}
