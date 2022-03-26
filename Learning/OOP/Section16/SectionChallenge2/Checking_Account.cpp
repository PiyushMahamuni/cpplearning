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

//deposit
bool Checking_Account::deposit(double amnt){
    return Account::deposit(amnt);
}
void Checking_Account::print(std::ostream& os) const{
    os << "Account Type: Checking Account" << std::endl
       << "[Name: " << name << " Balance: " << balance << ']' <<  std::endl;
}