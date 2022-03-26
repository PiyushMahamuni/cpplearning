#include "Checking_Account.h"

//conct
Checking_Account::Checking_Account(std::string name, double balance):
    Account{name, balance} {
        
}

//overriding withdrawl method
bool Checking_Account::withdraw(double amnt){
    amnt +=1.5;
    if(amnt>balance) return false;
    return Account::withdraw(amnt);
}

//Don't need to oveload << op for Checking_Account since it is an Account and without any extra
//info to display to console