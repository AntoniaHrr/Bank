#pragma warning(disable : 4996)/* time_t, time, ctime */
using namespace std;
#include "Bank.h"
#include <ctime>
#include <iostream>

int main() {
    cout << "Enter name: ";
    char* name;
    name = new char[100];
    cin.getline(name, 100);
   
    cout << "Enter email: ";
    char* email;
    email = new char[100];
    cin.getline(email, 100);
   

    cout << "Enter ID: ";
    int id;
    cin >> id;

    cin.ignore();

    cout << "Eneter username: ";
    char* username;
    username = new char[100];
    cin.getline(username, 100);
    

    cout << "Enter password: ";
    char* password;
    password = new char[100];
    cin.getline(password, 100);

    cout << "Enter name: ";
    char* nameA;
    nameA = new char[100];
    cin.getline(nameA, 100);

    cout << "Enter email: ";
    char* emailA;
    emailA = new char[100];
    cin.getline(emailA, 100);


    cout << "Enter ID: ";
    int idA;
    cin >> idA;

    cin.ignore();

    cout << "Eneter username: ";
    char* usernameA;
    usernameA = new char[100];
    cin.getline(usernameA, 100);


    cout << "Enter password: ";
    char* passwordA;
    passwordA = new char[100];
    cin.getline(passwordA, 100);
    


    Bank bank;
    bank.addCustomer(name, email, id, username, password);
    bank.addCustomer(nameA, emailA, idA, usernameA, passwordA);
    bank.listCustomers();
    cout << endl;
    char* IBAN;
    IBAN = new char[100];
    cout << "Enter IBAN: ";
    cin.getline(IBAN, 100);
    double amount;
    cout << "Enter amount: ";
    cin >> amount;
    cin.ignore();
    double interestRate;
    cin >> interestRate;
    bank.addSavings_Account(bank.ReturnCustomer(), amount, IBAN, interestRate);



    /*Account acc(name, email, 111, iban, 30);
   cout<< acc.getTime();*/
    //std::time_t t = std::time(0);   // get time now
    //std::tm* now = std::localtime(&t);
    //std::cout << (now->tm_year + 1900) << '-'
    //    << (now->tm_mon + 1) << '-'
    //    << now->tm_mday
    //    << "\n";
}