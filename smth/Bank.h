#pragma once
#include "Customer.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "Account.h"

#include <iostream>
#include <cstring>

using namespace std;

class Bank {
private:
	char* BankName;
	char* BankAdress;
	Customer* customers;
	int customers_count;
	NormalAccount* normal_accounts;
	int normal_count = 0;
	SavingsAccount* savings_accounts;
	int savings_count = 0;
	PrivilegeAccount* privilege_accounts;
	int privilege_count;
public:
	Bank() {
		this->customers = nullptr;
		this->normal_accounts = nullptr;
		this->savings_accounts = nullptr;
		this->privilege_accounts = nullptr;
		this->normal_count = 0;
		this->privilege_count = 0;
		this->savings_count = 0;
		this->customers_count = 0;
		BankAdress = nullptr;
		BankName = nullptr;
	}


	void addCustomer(char* name, char* email) {
		for (int i = 0; i < customers_count; i++)
		{
			if (strcmp(customers[i].getName(), name) == 0)
			{
				cout << "Customer is already registered!";
				return;
			}
		}
		customers_count++;
		Customer* place_holder = new Customer[customers_count];
		for (int i = 0; i < customers_count - 1; i++)
		{
			place_holder[i] = customers[i];
		}
		delete[] this->customers;

		place_holder[customers_count - 1].setEmail(email);
		place_holder[customers_count - 1].setName(name);

		this->customers = place_holder;

	}

	void addSavings_Account(int id) {
		for (int i = 0; i < customers_count; i++)
		{
			if (customers[i].getId() == id)
			{
				SavingsAccount newAcc;
				newAcc.setID(customers[i]);

				savings_count++;
				SavingsAccount* place_holder = new SavingsAccount[savings_count];
				for (int i = 0; i < savings_count - 1; i++)
				{
					place_holder[i] = savings_accounts[i];
				}
				delete[] this->savings_accounts;

				place_holder[savings_count - 1].setBalance(newAcc.getBalance());
				place_holder[savings_count - 1].setIban(newAcc.getIBAN());
				place_holder[savings_count - 1].setID(customers[i]);

				this->savings_accounts = place_holder;

				
			}
		}
	}
	//add userNames
	void addNormal_Account(int id) {
		for (int i = 0; i < customers_count; i++)
		{
			if (customers[i].getId() == id)
			{
				NormalAccount newAcc;
				newAcc.setID(customers[i]);

				normal_count++;
				NormalAccount* place_holder = new NormalAccount[normal_count];
				for (int i = 0; i < normal_count - 1; i++)
				{
					place_holder[i] = normal_accounts[i];
				}
				delete[] this->normal_accounts;

				place_holder[normal_count - 1].setBalance(newAcc.getBalance());
				place_holder[normal_count - 1].setIban(newAcc.getIBAN());
				place_holder[normal_count - 1].setID(customers[i]);

				this->normal_accounts = place_holder;


			}
		}
	}
	void addPrivilege_Account(int id) {
		for (int i = 0; i < customers_count; i++)
		{
			if (customers[i].getId() == id)
			{
				PrivilegeAccount newAcc;
				newAcc.setID(customers[i]);

				privilege_count++;
				PrivilegeAccount* place_holder = new PrivilegeAccount[privilege_count];
				for (int i = 0; i < privilege_count - 1; i++)
				{
					place_holder[i] = privilege_accounts[i];
				}
				delete[] this->privilege_accounts;

				place_holder[privilege_count - 1].setBalance(newAcc.getBalance());
				place_holder[privilege_count - 1].setIban(newAcc.getIBAN());
				place_holder[privilege_count - 1].setID(customers[i]);

				this->privilege_accounts = place_holder;


			}
		}
	}



	//add from privileged
	void transfer(const char* FromIBAN, const char* ToIBAN, double amount) {

		for (int i = 0; i < normal_count; i++) {
			if (strcmp(FromIBAN, normal_accounts[i].getIBAN()) == 0) {
				for (int j = 0; j < normal_count; j++) {
					if (strcmp(ToIBAN, normal_accounts[j].getIBAN()) == 0) {
						normal_accounts[j].depositMoney(amount);
						normal_accounts[i].withdrawMoney(amount);
					}
				}
				for (int j = 0; j < savings_count; j++) {
					if (strcmp(ToIBAN, savings_accounts[j].getIBAN()) == 0) {
						savings_accounts[j].depositMoney(amount);
						normal_accounts[i].withdrawMoney(amount);
					}
				}
				for (int j = 0; j < privilege_count; j++) {
					if (strcmp(ToIBAN, privilege_accounts[j].getIBAN()) == 0) {
						privilege_accounts[j].depositMoney(amount);
						normal_accounts[i].withdrawMoney(amount);
					}
				}
			}
		}


	}




	void listCustomers() {
		for (int i = 0; i < customers_count; i++) {
			cout << customers[i].getName() << endl;
		}
	}
	void listAccounts() {
		cout << "Normal accounts:" << endl;
		for (int i = 0; i < normal_count; i++) {
			cout << normal_accounts[i].getUserName() << endl;
		}
		cout << "Savings Accounts: " << endl;
		for (int i = 0; i < savings_count; i++) {
			cout << savings_accounts[i].getUserName() << endl;
		}
		cout << "Privilege Accounts: " << endl;
		for (int i = 0; i < privilege_count; i++) {
			cout << privilege_accounts[i].getUserName() << endl;
		}

	}
	void listCustomerAccounts(int id) {
		for (int i = 0; i < customers_count; i++) {
			if (customers[i].getId() == id) {
				for (int j = 0; j < normal_count; j++) {
					if (normal_accounts[j].getID() == id) {
						cout << "Normal account: " << normal_accounts[j].getIBAN()<<endl;
					}
				}
				for (int j = 0; j < savings_count; j++) {
					if (savings_accounts[j].getID() == id) {
						cout << "Savings account: " << savings_accounts[j].getIBAN() << endl;
					}
				}
				for (int j = 0; j < privilege_count; j++) {
					if (privilege_accounts[j].getID() == id) {
						cout << "Privilege account: " << privilege_accounts[j].getIBAN() << endl;
					}
				}
			}
		}
	}





	Bank(const Bank& other) {
		copyFrom(other);
	}

	Bank& operator=(const Bank& other) {
		if (this != &other)
		{
			free();
			copyFrom(other);
		}

		return *this;
	}
	~Bank()
	{
		free();
	}
	void free() {
		delete[] customers;
		delete[] normal_accounts;
		delete[] savings_accounts;
		delete[] privilege_accounts;
		delete[] BankName;
		delete[] BankAdress;

	}
	void copyFrom(const Bank& other) {

		customers = new Customer[other.customers_count];
		for (int i = 0; i < other.customers_count; i++) {
			this->customers[i] = other.customers[i];
		}
		savings_accounts = new SavingsAccount[other.savings_count];
		for (int i = 0; i < other.savings_count; i++) {
			this->savings_accounts[i] = other.savings_accounts[i];
		}
		normal_accounts = new NormalAccount[other.normal_count];
		for (int i = 0; i < other.normal_count; i++) {
			this->normal_accounts[i] = other.normal_accounts[i];
		}
		privilege_accounts = new PrivilegeAccount[other.privilege_count];
		for (int i = 0; i < other.privilege_count; i++) {
			this->privilege_accounts[i] = other.privilege_accounts[i];
		}
		int len = strlen(other.BankName);
		BankName = new char[len + 1];
		strcpy(this->BankName, other.BankName);

		int lenght = strlen(other.BankAdress);
		BankAdress = new char[lenght + 1];
		strcpy(this->BankAdress, other.BankAdress);

		this->customers_count = other.customers_count;
		this->savings_count = other.savings_count;
		this->normal_count = other.normal_count;
		this->privilege_count = other.privilege_count;
	}



};
