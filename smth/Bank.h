#pragma once
#include "Customer.h"
#include "CreateAccounts.h"
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
	CreateAccounts* accounts;
	int accounts_count;
public:
	Bank() {
		this->customers = nullptr;
		this->accounts = nullptr;
		this->accounts_count = 0;
		this->customers_count = 0;
		BankAdress = nullptr;
		BankName = nullptr;
	}

	bool CustomerExist(int id) {
			for (int i = 0; i < customers_count; i++)
		{
			if (customers[i].getId()==id) //check by name?
			{
				return true;
			}
		}

			return false;
	}

	void addCustomer(char* name, char* email, int id) {

		if (CustomerExist(id) == true) {
			cout << "Customer is already registered!"<<endl;
			return;
		};
		
		Customer newCustomer;
		newCustomer.setEmail(email);
		newCustomer.setName(name);
		newCustomer.setId(id);

		customers_count++;
		Customer* place_holder = new Customer[customers_count];
		for (int i = 0; i < customers_count - 1; i++)
		{
			place_holder[i] = customers[i];
		}
		delete[] this->customers;

		place_holder[customers_count - 1] = newCustomer;

		this->customers = place_holder;
		

		CreateAccounts newAccount;
		newAccount.setId(id);

		accounts_count++;
		CreateAccounts* place_holder_accounts = new CreateAccounts[customers_count];
		for (int i = 0; i < accounts_count - 1; i++)
		{
			place_holder_accounts[i] = accounts[i];
		}
		delete[] this->accounts;

		place_holder_accounts[accounts_count - 1] = newAccount;

		this->accounts = place_holder_accounts;
	}
	void DeleteCustomer(int id) {
		int index;
		for (int i = 0; i < customers_count; i++) {
			if (customers[i].getId() == id) {
				index = i;
				break;
			}
		}

		accounts_count--;
		CreateAccounts* place_holder = new CreateAccounts[accounts_count];
		for (int i = 0; i < accounts_count; i++) {
			if (i < index) {
				place_holder[i] = accounts[i];
			}
			else {
				place_holder[i] = accounts[i++];
			}
		}

		delete[] this->accounts;
		this->accounts = place_holder;

		customers_count--;
		Customer* place_holder_customers = new Customer[customers_count];
		for (int i = 0; i < customers_count; i++) {
			if (i < index) {
				place_holder_customers[i] = customers[i];
			}
			else {
				place_holder_customers[i] = customers[i++];
			}
		}

		delete[] this->customers;
		this->customers = place_holder_customers;


	}
	void DeleteAccount(char* IBAN) {
		for (int i = 0; i < accounts_count; i++) {
			if (accounts[i].acc_exist(IBAN)) {
				accounts[i].Delete_Account(IBAN);
			}
		}
	}

	void addSavings_Account(int Id, double amount, char* IBAN,char* username, char* password ,double ineterstRate) {
		for (int i = 0; i < accounts_count; i++)
		{
				if (accounts[i].acc_exist(IBAN)) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreateSavings_Account(Id,amount,IBAN, username, password,ineterstRate);
		}
		cout << "Added new account!";
	}
	void addNormal_Account(int Id, double amount, char* IBAN, const char* username, const char* password) {
		for (int i = 0; i < accounts_count; i++)
		{
				if (accounts[i].acc_exist(IBAN) == false) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreateNormal_Account(Id, amount, IBAN, username, password);
			
		}
	}
	void addPrivilege_Account(int Id, double amount, char* IBAN, double overdraft,const char* username, const char* password) {
		for (int i = 0; i < accounts_count; i++)
		{
				if (accounts[i].acc_exist(IBAN) == false) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreatePrivilege_Account(Id, amount, IBAN, overdraft, username, password);
			
		}
	}

	void transfer( char* FromIBAN,  char* ToIBAN, double amount) {
		for (int i = 0; i < accounts_count; i++) {
			if (strcmp(accounts[i].getIBAN(i), FromIBAN)==0) {
				for (int j = 0; j < accounts_count; j++) {
					if (strcmp(accounts[j].getIBAN(j), ToIBAN) == 0)
					{
						accounts[i].Witdraw(amount, FromIBAN);
						accounts[j].Deposit(amount, ToIBAN);
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
		for (int i = 0; i < accounts_count; i++) {
				accounts[i].Print_Accounts();
		}

	}
	void listCustomerAccounts(int id) {
		for (int i = 0; i < accounts_count; i++) {
			if (accounts[i].getID() == id) {
				accounts[i].Print_Accounts();
				break;
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
		delete[] accounts;
		delete[] BankName;
		delete[] BankAdress;

	}
	void copyFrom(const Bank& other) {

		customers = new Customer[other.customers_count];
		for (int i = 0; i < other.customers_count; i++) {
			this->customers[i] = other.customers[i];
		}
		accounts = new CreateAccounts[other.accounts_count];
		for (int i = 0; i < other.accounts_count; i++) {
			this->accounts[i] = other.accounts[i];
		}
		int len = strlen(other.BankName);
		BankName = new char[len + 1];
		strcpy(this->BankName, other.BankName);

		int lenght = strlen(other.BankAdress);
		BankAdress = new char[lenght + 1];
		strcpy(this->BankAdress, other.BankAdress);

		this->customers_count = other.customers_count;
		this->accounts_count = other.accounts_count;
	}



};
