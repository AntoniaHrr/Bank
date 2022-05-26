#pragma once
#include "Customer.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "Account.h"
#include <iostream>
#include <cstring>

using namespace std;

class CreateAccounts {
private:
	char* username;
	char* password;
	int id;
	NormalAccount* normal_accounts;
	int normal_count;
	SavingsAccount* savings_accounts;
	int savings_count;
	PrivilegeAccount* privilege_accounts;
	int privilege_count;
public:

	CreateAccounts() {
		this->username = nullptr;
		this->password = nullptr;
		this->id = 0;
		this->normal_accounts = nullptr;
		this->privilege_accounts = nullptr;
		this->savings_accounts = nullptr;
		this->normal_count = 0;
		this->privilege_count = 0;
		this->savings_count = 0;
	}
	void setUsername(const char* username) {
		if (this->username != nullptr)
		{
			delete[] this->username;
		}
		int length = strlen(username);
		this->username = new char[length + 1]; //+ 1 for '\0'
		strcpy(this->username, username);
	}
	void setPassword(const char* password) {
		if (this->password != nullptr)
		{
			delete[] this->password;
		}
		int length = strlen(password);
		this->password = new char[length + 1]; //+ 1 for '\0'
		strcpy(this->password, password);
	}
	void setId(Customer customer) {
		id = customer.getId();
	}

	void addSavings_Account(Customer customer, double amount, char* IBAN, double interestRate) {

				SavingsAccount newAcc;
				newAcc.setBalance(amount);
				newAcc.setIban(IBAN);
				newAcc.setID(customer);
				newAcc.setUserName(this->username);
				newAcc.setPassword(this->password);
				newAcc.setInvestRate(interestRate);

				savings_count++;
				SavingsAccount* place_holder = new SavingsAccount[savings_count];
				for (int i = 0; i < savings_count - 1; i++)
				{
					place_holder[i] = savings_accounts[i];
				}
				delete[] this->savings_accounts;

				place_holder[savings_count - 1] = newAcc;
				this->savings_accounts = place_holder;
	}
	//add userNames
	void addNormal_Account(Customer customer, double amount, char* IBAN) {

		NormalAccount newAcc;
		newAcc.setBalance(amount);
		newAcc.setIban(IBAN);
		newAcc.setID(customer);
		newAcc.setUserName(this->username);
		newAcc.setPassword(this->password);

		normal_count++;
		NormalAccount* place_holder = new NormalAccount[normal_count];
		for (int i = 0; i < normal_count - 1; i++)
		{
			place_holder[i] = normal_accounts[i];
		}
		delete[] this->normal_accounts;

		place_holder[normal_count - 1] = newAcc;
		this->normal_accounts = place_holder;
	}
	void addPrivilege_Account(Customer customer, double amount, char* IBAN) {

		PrivilegeAccount newAcc;
		newAcc.setBalance(amount);
		newAcc.setIban(IBAN);
		newAcc.setID(customer);
		newAcc.setUserName(this->username);
		newAcc.setPassword(this->password);

		privilege_count++;
		PrivilegeAccount* place_holder = new PrivilegeAccount[privilege_count];
		for (int i = 0; i < privilege_count - 1; i++)
		{
			place_holder[i] = privilege_accounts[i];
		}
		delete[] this->privilege_accounts;

		place_holder[privilege_count - 1] = newAcc;
		this->privilege_accounts = place_holder;
	}


	CreateAccounts& operator=(const CreateAccounts& other) {
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
	~CreateAccounts()
	{
		free();
	}
	void free() {
		delete[] username;
		delete[] password;
		delete[] savings_accounts;
		delete[] normal_accounts;
		delete[] privilege_accounts;
	}

	CreateAccounts(const CreateAccounts& other) {
		copyFrom(other);
	}

	void copyFrom(const CreateAccounts& other) {

		int len = strlen(other.username);
		this->username = new char[len + 1];
		strcpy(this->username, other.username);

		int lenght = strlen(other.password);
		this->password = new char[lenght + 1];
		strcpy(this->password, other.password);

		this->id = other.id;
		this->normal_count = other.normal_count;
		this->privilege_count = other.privilege_count;
		this->savings_count = other.savings_count;


		this->normal_accounts = new NormalAccount[other.normal_count];
		for (int i = 0; i < other.normal_count; i++) {
			normal_accounts[i] = other.normal_accounts[i];
		}

		this->savings_accounts = new SavingsAccount[other.savings_count];
		for (int i = 0; i < other.savings_count; i++) {
			savings_accounts[i] = other.savings_accounts[i];
		}

		this->privilege_accounts = new PrivilegeAccount[other.privilege_count];
		for (int i = 0; i < other.privilege_count; i++) {
			privilege_accounts[i] = other.privilege_accounts[i];
		}
	}



};