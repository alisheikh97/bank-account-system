#include "BankAccount.h"
#include <iostream>

int main()
{
	BankAccount ali("Ali", 1000.0, "Checking");
	BankAccount rimsha("Rimsha", 5000.0, "Savings");
	
	ali.displayInfo();
	rimsha.displayInfo();

	ali.deposit(1000.0);

	ali.withdraw(173.0);

	ali.displayInfo();


}
