#include "Saving_Account.h"

//conct
Saving_Account::Saving_Account(std::string name, double balance, double int_rate) :
    Account{name, balance}, int_rate {int_rate} {
}

//overriding deposit method
bool Saving_Account::deposit(double amnt) override{
    amnt *= (1+int_rate/100);
    return Account::deposit(amnt);
}

//overriding withdrawl method, trivial
bool Saving_Account::withdraw(double amnt) override{
    return Account::withdraw(amnt);
}

//overriding print method
void Saving_Account::print(std::ostream& os){
    os  << "Account Type: Savings Account" < std::endl
        << "[Name: " << name << " Balance: " << balance << " int_rate: " << int_rate << ']' << std::endl;
}