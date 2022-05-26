#pragma once
#include "Account.h"
#include <iostream>
#include <stdexcept>
#include "Customer.h"

class NormalAccount : public Account {
public:
	NormalAccount() {

	}
	NormalAccount(char* username, char* password, int ID, char* iban, double amount) : Account(username, password, ID, iban, amount) {

	}
	void displayInformation() const override 
		{
			cout << "Name: " << getUserName() << endl;
			cout << "IBAN: " << getIBAN() << endl;
			cout << "Balance" << getBalance() << endl;
		}
	void withdrawMoney(double amount) override {
		if (amount <= 0) {
			throw invalid_argument("Amount can't be negative");
		}
		setBalance(getBalance() - amount);
		if (getBalance() < 0) {
			throw invalid_argument("Balance is negative");
		}
	}

	void depositMoney(double amount) override {
		setBalance(getBalance() + amount);
	}
	
};