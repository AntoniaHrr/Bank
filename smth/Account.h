#include <iostream>
#include <stdexcept>
#include <cstring>
#include <ctime> 
#pragma warning(disable : 4996)
#include "Customer.h"

using namespace std;

class Account {
	char* iban;
	char* username;
	char* password;
	int ID;
	double amount;
	tm* dateOfCreation;
public:
	Account() {
		this->iban = nullptr;
		this->ID = 0;
		this->amount = 0;
		this->password = nullptr;
		this->username = nullptr;
		dateOfCreation = nullptr;
	}

	Account(char* username, char* password, int ID, char* iban, double amount) {
		this->amount = amount;
		time_t t = time(0);   // get time now
		this->dateOfCreation = localtime(&t);

		int len = strlen(username);
		this->username = new char[len + 1];
		strcpy(this->username, username);

		int leng = strlen(iban);
		this->iban = new char[leng + 1];
		strcpy(this->iban, iban);

		int lenght = strlen(password);
		this->password = new char[lenght + 1];
		strcpy(this->password, password);

		this->ID = ID;
	}

	//getters

	double getBalance() const {
		return amount;
	}

	char* getUserName() const {
		return username;
	}

	char* getIBAN() const {
		return iban;
	}

	int getID() const {
		return ID;
	}
	//setters

	void setIban(char* iban) {

		delete[] this->iban;

		int lenght = strlen(iban);
		this->iban = new char[lenght + 1];
		strcpy(this -> iban, iban);
	}
	void setBalance(double amount) {
		this->amount = amount;
	}
	void setID(int id) {
		this->ID = id;
	};
	void setUserName(const char* username) {
		delete[] this->username;
		int len = strlen(username);
		this->username = new char[len + 1];
		strcpy(this->username, username);
	}
	void setPassword(const char* password) {
		delete[] this->password;
		int len = strlen(password);
		this->password = new char[len + 1];
		strcpy(this->password, password);
	}

	//Constructors

	Account(const Account& other) {
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
		int lenght = strlen(other.iban);
		this->iban = new char[lenght + 1];
		strcpy(this->iban, other.iban);

		int len = strlen(other.username);
		this->username = new char[len + 1];
		strcpy(this->username, other.username);

		int leng = strlen(other.password);
		this->password = new char[leng + 1];
		strcpy(this->password, other.password);

		this->ID = other.ID;

		this->amount = other.amount;
		this->dateOfCreation = other.dateOfCreation;
	}

	void free() {
		delete[] iban;
		delete[] username;
		delete[] password;
	} 

	virtual void withdrawMoney(double amount) = 0;
	
	virtual void depositMoney(double amount) = 0;

	virtual void displayInformation() const = 0; //virtual

	int getTime() const throw() {
		return dateOfCreation->tm_year+1900;
	}

	~Account() {
		free();
	}

};