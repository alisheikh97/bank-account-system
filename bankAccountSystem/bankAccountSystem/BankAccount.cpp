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


void BankAccount::saveToFile(std::string fileName) {
	//ofstream = output file stream
	//This Creates a file if it does not exist
	//Or Overwrites the exisiting one
	std::ofstream file(fileName);

	//if file does not open then we give this error
	if (!file.is_open()) {
		std::cout << "Error: Could not saved account data. \n";
		return;
	}

	file << ownerName << "\n";
	file << accountType << "\n";
	file << balance << "\n";
	
	//always close when done to release the file
	file.close();
	std::cout << "Account saved sucessfully \n";

}

bool BankAccount::loadFromFile(std::string fileName) {
	//ifsteam = input file stream
	std::ifstream file(fileName);

	if (!file.is_open()) {
		return false;
	}

	//getline reads a full line including spaces
	std::getline(file, ownerName);
	std::getline(file, accountType);
	// Each >> reads value from the file 
	// but stops at when there would be a space
	file >> balance;


	file.close();
	return true;

}