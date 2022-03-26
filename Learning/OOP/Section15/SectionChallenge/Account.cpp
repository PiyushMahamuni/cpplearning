#include "Account.h"

//conct
Account::Account(std::string name, double balance) : name {name}, balance {balance} {
    if(balance < 0)
        throw IllegalBalanceException();
}

//Friend function to insert to ouput stream
std::ostream& operator<<(std::ostream& os, const Account& accnt){
    os << "[ name: " << accnt.name << ", balance: " << accnt.balance << "]";
    return os;
}

//deposit method, returns true if successful
bool Account::deposit(double amnt){
    if(amnt>0){
        balance += amnt;
        return true;
    }
    return false;
}

//withdraw method, returns true if successful
bool Account::withdraw(double amnt){
    if(amnt>balance) 
        throw InsufficientFundsException();
    balance -= amnt;
    return true;
}

