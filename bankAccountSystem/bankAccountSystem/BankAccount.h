#pragma once   //Tells the compiler to only this file once

#include <string>
#include <fstream> //Needed to save on a text file
#include <vector>
#include "Transaction.h"

class BankAccount {

	//variables inside private are hidden
private:
	//this string holds the name of the account owner
	std::string ownerName;
	//this double holds the balance of the account owner
	double balance;
	//this string holds the type of account "Savings" or "Cheq"
	std::string accountType;

	std::vector<Transaction>history;

public:
	//default constructor, logic will be written in logic file
	BankAccount();

	//this is a constructor - runs when object is created
	BankAccount(std::string name, double startingBalance, std::string type);
	//Methods
	//things account can do
	void deposit(double amount);
	//returns bool if sucess or false if not enough fund
	bool withdraw(double amount);
	void displayInfo();
	void displayHistory();

	void saveToFile(std::ofstream& file);
	bool loadFromFile(std::ifstream& file);



	//These are getters. These will be used to read private data safely
	std::string getName() { return ownerName; }
	std::string getAccountType() { return accountType; }
	double getBalance() { return balance; }



};


