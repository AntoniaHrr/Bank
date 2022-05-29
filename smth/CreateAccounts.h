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
	int id;
	Account** accounts;
	int count;
public:

	CreateAccounts() {
		this->id = 0;
		this->accounts = nullptr;
		this->count = 0;
	}
	//setters
	
	void setId(int id) {
		this->id = id;
	}

	char* getIBAN(int i) const {
		return accounts[i]->getIBAN();
	}
	//getters

	const int getID() const {
		return id;
	}

	Account* getAccount(char* iban) {
		for (int i = 0; i < count; i++)
		{
			if (strcmp(accounts[i]->getIBAN(), iban) == 0) {
				return accounts[i];
			}
		}
		return nullptr;
	}

	bool acc_exist(char* IBAN) {
		for (int i = 0; i < count; i++)
		{
			if (strcmp(accounts[i]->getIBAN(), IBAN) == 0) {
				return true;
			}
		}
		return false;
	}


	void Witdraw(double amount, char* Iban) {
		for (int i = 0; i < count; i++) {
			if (strcmp(accounts[i]->getIBAN(), Iban) == 0) {
				accounts[i]->withdrawMoney(amount);
			}
			break;
		}
	}
	void Deposit(double amount, char* Iban) {
		for (int i = 0; i < count; i++) {
			if (strcmp(accounts[i]->getIBAN(), Iban) == 0) {
				accounts[i]->depositMoney(amount);
			}
			break;
		}
	}

	void CreateSavings_Account(int id, double amount,const char* username, char* password,char* IBAN, double interestRate) {

				SavingsAccount newAcc;
				newAcc.setBalance(amount);
				newAcc.setIban(IBAN);
				newAcc.setID(id);
				newAcc.setUserName(username);
				newAcc.setPassword(password);
				newAcc.setInvestRate(interestRate);

				count++;
				Account** place_holder = new Account*[count];
				for (int i = 0; i < count - 1; i++)
				{
					if (dynamic_cast<SavingsAccount*>(accounts[i])) {
						place_holder[i] = new SavingsAccount(*dynamic_cast<SavingsAccount*>(accounts[i]));
					}
				}
				delete[] this->accounts;

				place_holder[count - 1] = new SavingsAccount(newAcc);
				this->accounts = place_holder;
	}
	void CreateNormal_Account(int id, double amount, char* IBAN, const char* username, const char* password) {

		NormalAccount newAcc;
		newAcc.setBalance(amount);
		newAcc.setIban(IBAN);
		newAcc.setID(id);
		newAcc.setUserName(username);
		newAcc.setPassword(password);

		count++;
		Account** place_holder = new Account * [count];
		for (int i = 0; i < count - 1; i++)
		{
			if (dynamic_cast<NormalAccount*>(accounts[i])) {
				place_holder[i] = new NormalAccount(*dynamic_cast<NormalAccount*>(accounts[i]));
			}
		}
		delete[] this->accounts;

		place_holder[count - 1] = new NormalAccount(newAcc);
		this->accounts = place_holder;
	}
	void CreatePrivilege_Account(int id, double amount, char* IBAN, double overdraft, const char* username, const char* password) {

		PrivilegeAccount newAcc;
		newAcc.setBalance(amount);
		newAcc.setIban(IBAN);
		newAcc.setID(id);
		newAcc.setUserName(username);
		newAcc.setPassword(password);
		newAcc.setOverdraft(overdraft);

		count++;
		Account** place_holder = new Account * [count];
		for (int i = 0; i < count - 1; i++)
		{
			if (dynamic_cast<PrivilegeAccount*>(accounts[i])) {
				place_holder[i] = new PrivilegeAccount(*dynamic_cast<PrivilegeAccount*>(accounts[i]));
			}
		}
		delete[] this->accounts;

		place_holder[count - 1] = new PrivilegeAccount(newAcc);
		this->accounts = place_holder;
	}

	void Delete_Account(char* IBAN) {
		int index = 0;
		for (int i = 0; i < count; i++) {
			if (acc_exist(IBAN)) {
				index = i;
				break;
			}
		}
		count--;
		Account** place_holder = new Account * [count];
		for (int i = 0; i < count - 1; i++) {
			if (i < index) {
				if (dynamic_cast<SavingsAccount*>(accounts[i])) {
					place_holder[i] = new SavingsAccount(*dynamic_cast<SavingsAccount*>(accounts[i]));
				}
				else if (dynamic_cast<NormalAccount*>(accounts[i])) {
					place_holder[i] = new NormalAccount(*dynamic_cast<NormalAccount*>(accounts[i]));
				}
				else if (dynamic_cast<PrivilegeAccount*>(accounts[i])) {
					place_holder[i] = new PrivilegeAccount(*dynamic_cast<PrivilegeAccount*>(accounts[i]));
				}
			}
			else {
				if (dynamic_cast<SavingsAccount*>(accounts[i])) {
					place_holder[i] = new SavingsAccount(*dynamic_cast<SavingsAccount*>(accounts[i++]));
				}
				else if (dynamic_cast<NormalAccount*>(accounts[i])) {
					place_holder[i] = new NormalAccount(*dynamic_cast<NormalAccount*>(accounts[i++]));
				}
				else if (dynamic_cast<PrivilegeAccount*>(accounts[i])) {
					place_holder[i] = new PrivilegeAccount(*dynamic_cast<PrivilegeAccount*>(accounts[i++]));
				}
			}
		}

		delete[] this->accounts;
		this->accounts = place_holder;
	}

	void Print_Accounts() {
		for (int i = 0; i < count; i++) {
			cout << "Account: " << accounts[i]->getIBAN() << endl;
		}

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
		for (size_t i = 0; i < count; i++)
		{
			delete accounts[i];
		}
		delete[] accounts;
	}

	CreateAccounts(const CreateAccounts& other) {
		copyFrom(other);
	}

	void copyFrom(const CreateAccounts& other) {

		this->id = other.id;
		this->count = other.count;


		this->accounts = new Account*[other.count];
		for (int i = 0; i < count - 1; i++)
		{
			if (dynamic_cast<SavingsAccount*>(other.accounts[i])) {
				accounts[i] = new SavingsAccount(*dynamic_cast<SavingsAccount*>(other.accounts[i]));
			}
			else if (dynamic_cast<NormalAccount*>(other.accounts[i])) {
				accounts[i] = new NormalAccount(*dynamic_cast<NormalAccount*>(other.accounts[i]));
			}
			else if (dynamic_cast<PrivilegeAccount*>(other.accounts[i])) {
				accounts[i] = new PrivilegeAccount(*dynamic_cast<PrivilegeAccount*>(other.accounts[i]));
			}
		}
	}



};