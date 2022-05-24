#include <iostream>
#include <cstring>

using namespace std;

class Customer {
	char* username;
	char* email;
	int id;
public:
	Customer() {
		username = nullptr;
		email = nullptr;
		id = 0;
	}

	Customer(char* username, char* email, int id) {

		int len = strlen(username);
		this->username = new char[len + 1];
		strcpy(this->username, username);

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
		int len = strlen(other.username);
		this->username = new char[len + 1];
		strcpy(this->username, other.username);

		int lenght = strlen(other.email);
		this->email = new char[lenght + 1];
		strcpy(this->email, other.email);

		this->id = other.id;
	}

	void setUsername(char* username) {

		int len = strlen(username);
		this->username = new char[len + 1];
		strcpy(this->username, username);
	}
	void setEmail(char* email) {
		int lenght = strlen(email);
		this->email = new char[lenght + 1];
		strcpy(this->email, email);
	}
	void setId(int id) {
		this->id = id;
	}
	char* getUsername() const {
		return username;
	}
	char* getEmail() const {
		return email;
	}
	int getId() const {
		return id;
	}

	void free() {
		delete[] username;
		delete[] email;
	}

	~Customer() {
		free();
	}
};