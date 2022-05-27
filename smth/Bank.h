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

	Customer ReturnCustomer() const {
		return customers[0];
	}


	void addCustomer(char* name, char* email, int id, char* username, char* password) {
		for (int i = 0; i < customers_count; i++)
		{
			if (customers[i].getId()==id) //check by name?
			{
				cout << "Customer is already registered!";
				return;
			}
		}
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
		newAccount.setPassword(password);
		newAccount.setUsername(username);
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

	void addSavings_Account(Customer customer, double amount, char* IBAN, double ineterstRate) {
		for (int i = 0; i < accounts_count; i++)
		{
			if (accounts[i].getID() == customer.getId())
			{	
				if (accounts[i].SavingsAcc_exist(IBAN) == false) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreateSavings_Account(customer.getId(),amount,IBAN, ineterstRate);
			}
		}
		cout << "Added new account!";
	}
	void addNormal_Account(Customer customer, double amount, char* IBAN) {
		for (int i = 0; i < accounts_count; i++)
		{
			if (accounts[i].getID() == customer.getId())
			{
				if (accounts[i].NormalAcc_exist(IBAN) == false) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreateNormal_Account(customer.getId(), amount, IBAN);
			}
		}
	}
	void addPrivilege_Account(Customer customer, double amount, char* IBAN, double overdraft) {
		for (int i = 0; i < accounts_count; i++)
		{
			if (accounts[i].getID() == customer.getId())
			{
				if (accounts[i].PrivilegeAcc_exist(IBAN) == false) {
					cout << "Can't create account with same IBAN!";
					return;
				}
				accounts[i].CreatePrivilege_Account(customer.getId(), amount, IBAN, overdraft);
			}
		}
	}



	//fix
	//void transfer(const char* FromIBAN, const char* ToIBAN, double amount);



	void listCustomers() {
		for (int i = 0; i < customers_count; i++) {
			cout << customers[i].getName() << endl;
		}
	}
	void listAccounts() {
		for (int i = 0; i < accounts_count; i++) {
				accounts[i].PrintNormal_Accounts();
				//accounts[i].PrintSavings_Accounts();
				//accounts[i].PrintPrivilege_Accounts();
		}

	}
	void listCustomerAccounts(int id) {
		for (int i = 0; i < accounts_count; i++) {
			if (accounts[i].getID() == id) {
				accounts[i].PrintNormal_Accounts();
				//accounts[i].PrintSavings_Accounts();
				//accounts[i].PrintPrivilege_Accounts();
				
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
