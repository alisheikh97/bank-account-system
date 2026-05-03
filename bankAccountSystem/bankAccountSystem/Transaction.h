#pragma once
#include <string>

// A struct is like a class but everything is public by default
// Use struct when the thing is just pure data with no real behavior
// Transaction doesn't DO anything — it just holds a record
// This is standard practice — data containers = struct, things with behavior = class

struct Transaction {
	std::string type;
	double amount;
	double balanceAfter;
	std::string date;

	Transaction(std::string t, double a, double b, std::string d) : type(t), amount(a), balanceAfter(b), date(d) {}

};