#include <iostream>
#include <stdexcept>
#include <cstring>
#include <ctime> 
#pragma warning(disable : 4996)
#include "Customer.h"

using namespace std;

class Account : public Customer {
	char* iban;
	double amount;
	tm* dateOfCreation;
public:
	Account() {
		this->iban = nullptr;
		this->amount = 0;
		dateOfCreation = nullptr;

	}

	Account(char* username, char* email, int id, char* iban, double amount) : Customer(username, email, id), iban(iban) {
		this->amount = amount;
		time_t t = time(0);   // get time now
	    this->dateOfCreation = localtime(&t);
	}

	double getBalance() const {
		return amount;
	}

	char* getIBAN() const {
		return iban;
	}

	void setIban(char* iban) {

		delete[] this->iban;

		int lenght = strlen(iban);
		this->iban = new char[lenght + 1];
		strcpy(this -> iban, iban);
	}
	void setBalance(double amount) {
		this->amount = amount;
	}

	Account(const Account& other) {
		Customer::Customer(other);
		copyFrom(other);
	}

	Account& operator=(const Account& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	void copyFrom(const Account& other) {
		Customer::copyFrom(other);
		int lenght = strlen(other.iban);
		this->iban = new char[lenght + 1];
		strcpy(this->iban, other.iban);
		this->amount = other.amount;
		this->dateOfCreation = other.dateOfCreation;
	}

	void free() {
		//Customer::free();
		delete[] iban;
	}

	void withdrawMoney(double amount) {
		if (amount <= 0) {
			throw invalid_argument("Amount can't be negative");
		}
		setBalance(getBalance() - amount);
		if (getBalance() < 0) {
			throw invalid_argument("Balance is negative");
		}
	}
	void depositMoney(double amount) {
		setBalance(getBalance() + amount);
	}
	void displayInformation() {
		cout << "Name: " << getUsername()<<endl;
		cout << "IBAN: " << getIBAN() << endl;
		cout << "Balance" << getBalance() << endl;
	}

	int getTime() const throw() {
		return dateOfCreation->tm_year+1900;
	}

	~Account() {
		free();
	}

};