#pragma once
#include "Account.h"
#include <iostream>
#include <stdexcept>
#include "Customer.h"

class SavingsAccount : virtual public Account {
private:
	double interestRate;
public:
	SavingsAccount() {
		this->interestRate = 3.25;
	}
	SavingsAccount(char* username, char* password, int ID, char* iban, double amount, double interestRate) : Account(username, password, ID, iban, amount), interestRate(interestRate) {

	}

	const double getIneterstRate() const {
		return interestRate;
	}

	void setInvestRate(double investRate) {
		this->interestRate = investRate;
	}

	void displayInformation() const override
	{
		Account::displayInformation();
		cout << "Invest rate: " << getIneterstRate();
	}
	void withdrawMoney(double amount) override {
		return;
	}

	void depositMoney(double amount) override {
		setBalance(getBalance() + amount);
	}

	void CopyFrom(SavingsAccount& other) {
		Account::copyFrom(other);
		this->interestRate = other.interestRate;
	}

	SavingsAccount(SavingsAccount& other) {
		CopyFrom(other);
	}

	SavingsAccount& operator=(const SavingsAccount& other) {
		if (this != &other) {
			Account::free();
			copyFrom(other);
		}
		return *this;

	}



};
