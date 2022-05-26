#pragma once
#include "Account.h"
#include <iostream>
#include <stdexcept>
#include "Customer.h"

class SavingsAccount : public Account {
private:
	double investRate;
public:
	SavingsAccount() {
		this->investRate = 3.25;
	}
	SavingsAccount(char* username, char* password, int ID, char* iban, double amount, double investRate) : Account(username, password, ID, iban, amount), investRate(investRate) {

	}

	void displayInformation() const override
	{
		cout << "Name: " << getUserName() << endl;
		cout << "IBAN: " << getIBAN() << endl;
		cout << "Balance" << getBalance() << endl;
	}
	void withdrawMoney(double amount) override {
		return;
	}

	void depositMoney(double amount) override {
		setBalance(getBalance() + amount);
	}




};
