#include "BankAccount.h"
#include <iostream>
#include <limits>


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






int main()
{

    //first i delcare for one account
    std::string name, type;
    double startingAmount;

    std::cout << "Welcome! Lets set up your Account!\n";
    std::cout << "Enter your name: \n";
    std::cin >> name;

    std::cout << "Please enter what type of account woud like to open?\n";
    std::cout << "Checking or Saving\n";
    std::cin >> type;

    std::cout << "Please enter your starting amount \n";
    std::cin >> startingAmount;

    BankAccount userAccount(name, startingAmount, type);

    std::cout << "Your account has been created! \n";

    bool running = true;

    while (running) {
        showMenu();
        int choice = getValidChoice();

        switch (choice) {
        case 1: 
            userAccount.displayInfo();
            break;
        case 2: {
            double depositAmount;
            std::cout << "Please enter amount you would like to deposit\n";
            std::cin >> depositAmount;
            userAccount.deposit(depositAmount);
            break;
        }
        case 3: {
            double withdrawAmount;
            std::cout << "Please enter amount you would like to withdraw: \n";
            std::cin >> withdrawAmount;
            userAccount.withdraw(withdrawAmount);
            break;

        }
        case 4: 
            std::cout << "Thank you for banking with us Goodbye! \n";
            running = false; 
            break;

        default: 
            std::cout << "Please enter a valid number 1 - 4 \n";
            break;
        }

    
    }
    return 0;


}
