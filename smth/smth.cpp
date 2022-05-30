#pragma warning(disable : 4996)/* time_t, time, ctime */
using namespace std;
#include "Bank.h"
#include <ctime>
#include <iostream>

int main() {
    Bank bank;
    int number=0;

    ////menu///
    cout << "1.Register new customer"<<endl;
    cout << "2.Remove customer from system"<<endl;
    cout << "3.Add account to customer" << endl;
    cout << "4.Remove customer's account" << endl;
    cout << "5.List customers" << endl;
    cout << "6.List accounts" << endl;
    cout << "7.List customers's accounts" << endl;
    cout << "8.Export log information" << endl;
    cout << "9.Transfer money" << endl;
    cout << "10.Get bank information" << endl;
    while (true) {
        cout << "Command:";
        cin >> number;
        cin.ignore();
        if (number == 1) {
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

            bank.addCustomer(name, email, id);
        }
        else if (number == 2) {
            int Id;
            cout << "Enter Id:";
            cin >> Id;
            cin.ignore();
            if (bank.CustomerExist(Id) == true) {
                bank.DeleteCustomer(Id);
            }
        }
        else if (number == 3) {
            int Id, type;
            double amount, interestRate, overdraft;
            char password[100], username[100];
            char* Iban = new char[100];
            cout << "Enter ID:";
            cin >> Id;
            if (bank.CustomerExist(Id) == true) {
            cout << "Type of account: 1.Normal" << endl;
            cout << "                 2.Savings" << endl;
            cout << "                 3.Privilege" << endl;
            cin >> type;
            cin.ignore();
            if (type == 1) {
                cout << "Enter IBAN:";
                cin.getline(Iban, 100);
                cout << "Enter username:";
                cin.getline(username, 100);
                cout << "Enter password:";
                cin.getline(password, 100);
                cout << "Enter amount:";
                cin >> amount;
                cin.ignore();
                bank.addNormal_Account(Id, amount, Iban, username, password);
            }
            else if(type == 2) {
                cout << "Enter IBAN:";
                cin.getline(Iban, 100);
                cout << "Enter InterestRate:";
                cin >> interestRate;
                cin.ignore();
                cout << "Enter username:";
                cin.getline(username, 100);
                cout << "Enter password:";
                cin.getline(password, 100);
                cout << "Enter amount:";
                cin >> amount;
                cin.ignore();
                bank.addSavings_Account(Id, amount, Iban, username, password, interestRate);
                delete[] Iban;
            }
            else if(type == 3) {
                cout << "Enter IBAN:";
                cin.getline(Iban, 100);
                cout << "Enter overdraft:";
                cin >> overdraft;
                cin.ignore();
                cout << "Enter username:";
                cin.getline(username, 100);
                cout << "Enter password:";
                cin.getline(password, 100);
                cout << "Enter amount:";
                cin >> amount;
                cin.ignore();
                bank.addPrivilege_Account(Id, amount, Iban,overdraft, username, password);
                delete[] Iban;
            }
            }
            
        }
        else if (number == 4) {
            char* Iban = new char[100];
            cout << "Enter IBAN:";
            cin.getline(Iban, 100);
            bank.DeleteAccount(Iban);
        }
        else if (number == 5) {
            bank.listCustomers();
        }
        else if (number == 6) {
            bank.listAccounts();
        }
        else if (number == 7) {
            int Id;
            cout << "Enter Id of customer:";
            cin >> Id;
            cin.ignore();
            if (bank.CustomerExist(Id) == true) {
                bank.listCustomerAccounts(Id);
            }
        }
        else if (number == 9) {
        char* from = new char[100];
        char* to = new char[100];
        double amount;
        cout << "Enter FromIBAN:";
        cin.getline(from, 100);
        cout << "Enter ToIBAN:";
        cin.getline(to, 100);
        cout << "Enter amount:";
        cin >> amount;
        cin.ignore();

        bank.transfer(from, to, amount);
}
       
    }
    /*cout << "Enter name: ";
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

    bank.addCustomer(name, email, id);

    cin.ignore();

    cout << "Eneter username: ";
    char* username;
    username = new char[100];
    cin.getline(username, 100);
    

    cout << "Enter password: ";
    char* password;
    password = new char[100];
    cin.getline(password, 100);*/



    /*Account acc(name, email, 111, iban, 30);
   cout<< acc.getTime();*/
    //std::time_t t = std::time(0);   // get time now
    //std::tm* now = std::localtime(&t);
    //std::cout << (now->tm_year + 1900) << '-'
    //    << (now->tm_mon + 1) << '-'
    //    << now->tm_mday
    //    << "\n";
}