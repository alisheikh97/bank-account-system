#include <iostream>
#include "BankAccount.h"
#include <ctime>  //for getting current date and time


//this is where i house all my functions or "logic"

// "static" means it's private to this file — can't be called from outside
static std::string getCurrentDate() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	std::string year = std::to_string(1900 + ltm->tm_year);
	std::string month = std::to_string(1 + ltm->tm_mon);
	std::string day = std::to_string(ltm-> tm_mday);

	if (month.length() == 1) month = "0" + month;
	if (day.length() == 1) day = "0" + day;

	return year + "-" + month + "-" + day;
}

//default constructor
BankAccount::BankAccount() {
	ownerName = "temp";
	balance = 0.0;
	accountType = "temp";
}

BankAccount::BankAccount(std::string name, double startingBalance, std::string type) 
: ownerName(name), balance(startingBalance), accountType(type)
{
	history.emplace_back("Initial Deposit", startingBalance, startingBalance, getCurrentDate());
}

void BankAccount::deposit(double depositAmount) {
	if (depositAmount <= 0) {
		std::cout << "Deposit amount must be positive\n";
		return;
	}
	balance += depositAmount;

	history.emplace_back("Deposit", depositAmount, balance, getCurrentDate());

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

	history.emplace_back("Withdraw", withdrawAmount, balance, getCurrentDate());

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

void BankAccount::saveToFile(std::ofstream& file) {
	file << ownerName << "\n";
	file << accountType << "\n";
	file << balance << "\n";

	file << history.size() << "\n";
	for (const Transaction& t : history) {
		file << t.type << "\n";
		file << t.amount << "\n";
		file << t.balanceAfter << "\n";
		file << t.date << "\n";
	}
}

bool BankAccount::loadFromFile(std::ifstream& file) {
	if (!std::getline(file, ownerName)) return false;
	if (!std::getline(file, accountType)) return false;
	file >> balance;
	file.ignore();

	int txCount;
	file >> txCount;
	file.ignore();

	for (int i = 0; i < txCount; i++) {
		std::string type, date;
		double amount, balanceAfter;

		if (!std::getline(file, type)) break;
		file.ignore();
		file >> amount;
		file.ignore();
		file >> balanceAfter;
		file.ignore();
		if (!std::getline(file, date)) break;

		history.emplace_back(type, amount, balanceAfter, date);

	}
	return true;
}

void BankAccount::displayHistory() {
	std::cout << "\n=== Transaction History: " << ownerName << " ===\n";

	//if vector of history is empty give out error
	if (history.empty()) {
		std::cout << "No transaction yet. \n";
		return;
	}

	for (const Transaction& t : history) {
		std::cout << t.date
			<< "  | " << t.type
			<< "  | $" << t.amount
			<< "  | Balance: $" << t.balanceAfter
			<< "\n";
	}
	std::cout << "======================================\n";
}

bool BankAccount::deleteAccount() {
	
}