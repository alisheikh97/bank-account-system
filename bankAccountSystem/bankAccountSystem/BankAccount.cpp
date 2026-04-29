#include <iostream>
#include "BankAccount.h"

//this is where i house all my functions or "logic"

BankAccount::BankAccount(std::string name, double startingBalance, std::string type) {
	ownerName = name;
	balance = startingBalance;
	accountType = type;
}

void BankAccount::deposit(double depositAmount) {
	if (depositAmount <= 0) {
		std::cout << "Deposit amount must be positive\n";
		return;
	}
	balance += depositAmount;
	std::cout << "Your amount $" << depositAmount << " has been deposited\n";

}

bool BankAccount::withdraw(double withdrawAmount) {
	if (withdrawAmount <= 0) {
		std::cout << "Withdraw amount must be postive";
		return false;
	}
	if (withdrawAmount >= balance) {
		std::cout << "Insufficient funds your bank balance is $" << balance;
		return false;
	}
	balance -= withdrawAmount;
	std::cout << "Withdrew $" << withdrawAmount << "\n";
	return true;
}

void BankAccount::displayInfo(){
	std::cout << "------------------------------------\n";
	std::cout << "Account Owner: " << ownerName  << "\n";
	std::cout << "Account type: " << accountType << "\n";
	std::cout << "Balance $: " <<    balance     << "\n";
	std::cout << "------------------------------------\n";
}