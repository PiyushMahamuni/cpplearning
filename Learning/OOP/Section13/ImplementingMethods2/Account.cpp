#include "Account.h"
#include <iostream>

void Account::set_name(){
    std::cout << "Enter Account Holder's Name: ";
    getline(std::cin,name);
    std::cout << "name set: " << name << std::endl;
}

void Account::set_name(std::string temp){
    name = temp;
    std::cout << "name set: " << name << std::endl;
}

std::string Account::get_name(){
    return name;
}

void Account::set_balance(){
    std::cout << "Account Holder: " << name << std::endl;
    char temp;
    try_again:
    std::cout << "Proceed to change balance? (y/n): ";
    std::cin >> temp;
    switch(temp){
        case 'y':
        case 'Y':
            std::cout << "Enter amount to set to balance: ";
            std::cin >> balance;
            std::cout << "balance set to: " << balance << std::endl;
            break;
        case 'n':
        case 'N':
            std::cout << "Operation Aborted." << std::endl;
            break;
        default:
            std::cout << "Invalide Option! try again!" << std::endl;
            goto try_again;
    }
}

void Account::set_balance(double amnt){
    balance = amnt;
    std::cout << "balance set to: " << balance << std::endl;
}

double Account::get_balance(){
    return balance;
}

bool Account::deposit(){
    std::cout << "Account Holder's name: " << name << std::endl;
    try_again:
    std::cout<< "Proceed with depositing? (y/n): ";
    char temp;
    std::cin >> temp;
    switch(temp){
        case 'y':
        case 'Y':
            double amnt;
            std::cout << "Enter amount to be deposited: ";
            std::cin >> amnt;
            balance += amnt;
            std::cout << amnt << " deposited successfully." << std::endl
                 << "balance: " << balance << std::endl;
            return true;
        case 'n':
        case 'N':
            std::cout << "Operation Cancelled." << std::endl;
            return false;
        default:
            std::cout << "Invalide entry, try again!" << std::endl;
            goto try_again;
    }
}

bool Account::deposit(double amnt){
    balance += amnt;
    std::cout << "Account Holder: " << name << std::endl
         << "Amount deposited: " << amnt << std::endl
         << "Balance: " << balance << std::endl;
    return true;
}

bool Account::withdraw(){
    std::cout << "Account Holder's name: " << name << std::endl;
    try_again:
    std::cout<< "Proceed with withdrawl? (y/n): ";
    char temp;
    std::cin >> temp;
    switch(temp){
        case 'y':
        case 'Y':
            double amnt;
            std::cout << "Enter amount to be withdrawed: ";
            std::cin >> amnt;
            if(amnt>balance){
                std::cout << "Error: Insufficient balance!" << std::endl
                     << "Operation Terminated!" << std::endl;
                return false;
            }
            balance -= amnt;
            std::cout << amnt << " withdrawed successfully." << std::endl
                 << "balance: " << balance << std::endl;
            return true;
        case 'n':
        case 'N':
            std::cout << "Operation Cancelled." << std::endl;
            return false;
        default:
            std::cout << "Invalide entry, try again!" << std::endl;
            goto try_again;
    }
}

bool Account::withdraw(double amnt){
    if(amnt>balance){
        std::cout << "Error: Insufficient balance!" << std::endl;
        return false;
    }
    balance -= amnt;
    std::cout << "Account Holder: " << name << std::endl
         << "Amount withdrawn: " << amnt << std::endl
         << "Balance: " << balance << std::endl;
    return true;
}