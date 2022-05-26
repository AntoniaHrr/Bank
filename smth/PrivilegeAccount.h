#pragma once
#include "Account.h"
#include <iostream>
#include <stdexcept>
#include "Customer.h"


class PrivilegeAccount : public Account {
private:
	double overdraft;
public:
	PrivilegeAccount() {
		this->overdraft = 0;

	}
	PrivilegeAccount(char* username, char* password, int ID, char* iban, double amount, double overdraft) : Account(username, password, ID, iban, amount), overdraft(overdraft) {

	}

	void setOverdraft(double overdraft) {
		this->overdraft = overdraft;
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
		if (getBalance()+overdraft < amount)
		{
			throw invalid_argument("Amount is bigger than allowed");
		}
		setBalance(getBalance() - amount);
	}

	void depositMoney(double amount) override {
		setBalance(getBalance() + amount);
	}

	void copyFrom(PrivilegeAccount& other) {
		Account::copyFrom(other);
		this->overdraft = other.overdraft;
	}





};