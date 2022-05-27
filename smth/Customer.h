#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Customer {
	char* name;
	char* email;
	int id;
public:
	Customer() {
		name = nullptr;
		email = nullptr;
		id = 0;
	}

	Customer(char* name, char* email, int id) {

		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);

		int lenght = strlen(email);
		this->email = new char[lenght + 1];
		strcpy(this->email, email);
		this->id = id;
	}

	Customer& operator=(const Customer& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	Customer(const Customer& other) {
		copyFrom(other);
	}

	void copyFrom(const Customer& other) {
		int len = strlen(other.name);
		this->name = new char[len + 1];
		strcpy(this->name, other.name);

		int lenght = strlen(other.email);
		this->email = new char[lenght + 1];
		strcpy(this->email, other.email);

		this->id = other.id;
	}

	void setName(char* username) {

		int len = strlen(username);
		this->name = new char[len + 1];
		strcpy(this->name, username);
	}
	void setEmail(char* email) {
		int lenght = strlen(email);
		this->email = new char[lenght + 1];
		strcpy(this->email, email);
	}
	void setId(int id) {
		this->id = id;
	}
	char* getName() const {
		return name;
	}
	char* getEmail() const {
		return email;
	}
	int getId() const {
		return id;
	}

	void free() {
		delete[] name;
		delete[] email;
	}

	~Customer() {
		free();
	}
};