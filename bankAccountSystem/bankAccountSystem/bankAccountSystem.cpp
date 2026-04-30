#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <fstream>


void showMenu() {
    std::cout << "\n============================\n";
    std::cout << "     BANK ACCOUNT SYSTEM    \n";
    std::cout << "============================\n";
    std::cout << "1. View Account Info\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n";
    std::cout << "============================\n";
    std::cout << "Enter your choice: ";

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


bool fileExists(std::string fileName) {
    std::ifstream file(fileName);
    return file.is_open();
}


int main()
{

    const std::string SAVE_FILE = "account.txt";
    //const means this value NEVER changes
    //ALL_CAPS naming for constants is industry standard
    
   
    BankAccount* account = nullptr;

    if (fileExists(SAVE_FILE)) {
        account = new BankAccount("temp", 0.0, "temp");
        account->loadFromFile(SAVE_FILE);

        std::cout << "Welcome Back, " << account->getName() << "!\n";

    }
    else {

        std::string name, type;
        double startingAmount;

        std::cout << "Welcome! Lets set up your Account!\n";
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Please enter what type of account woud like to open?\n";
        std::cout << "Checking or Saving\n";
        std::getline(std::cin, type);

        std::cout << "Please enter your starting amount \n";
        std::cin >> startingAmount;

        account = new BankAccount(name, startingAmount, type);

        std::cout << "Your account has been created! \n";
    }

    //-----Program loop---------

    bool running = true;

    while (running) {
        showMenu();
        int choice = getValidChoice();

        switch (choice) {
        case 1: 
            account->displayInfo();
            break;
        case 2: {
            double depositAmount;
            std::cout << "Please enter amount you would like to deposit\n";
            std::cin >> depositAmount;
            account->deposit(depositAmount);
            break;
        }
        case 3: {
            double withdrawAmount;
            std::cout << "Please enter amount you would like to withdraw: \n";
            std::cin >> withdrawAmount;
            account->withdraw(withdrawAmount);
            break;

        }
        case 4: 
            account->saveToFile(SAVE_FILE);
            std::cout << "Thank you for banking with us Goodbye! \n";
            running = false; 
            break;

        default: 
            std::cout << "Please enter a valid number 1 - 4 \n";
            break;
        }

    
    }
    delete account;
    return 0;


}
