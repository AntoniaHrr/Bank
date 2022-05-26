#pragma warning(disable : 4996)/* time_t, time, ctime */
using namespace std;
#include "Account.h"

#include <ctime>
#include <iostream>

int main() {
    char* name;
    name = new char[10];
    cin.getline(name, 10);
    char* email;
    email = new char[10];
    cin.getline(email, 10);
    char* iban;
    iban = new char[10];
    cin.getline(iban, 10);

    /*Account acc(name, email, 111, iban, 30);
   cout<< acc.getTime();*/
    //std::time_t t = std::time(0);   // get time now
    //std::tm* now = std::localtime(&t);
    //std::cout << (now->tm_year + 1900) << '-'
    //    << (now->tm_mon + 1) << '-'
    //    << now->tm_mday
    //    << "\n";
}