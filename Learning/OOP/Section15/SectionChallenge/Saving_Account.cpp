#include "Saving_Account.h"

//conct
Saving_Account::Saving_Account(std::string name, double balance, double int_rate) :
    Account{name, balance}, int_rate {int_rate} {
}

//overloaded << operator
std::ostream& operator<<(std::ostream& os, const Saving_Account& accnt){
    os << "[name: " << accnt.name << ", balance: " << accnt.balance << ", int_rate: " << accnt.int_rate << "]";
    return os;
}


//overriding deposit method
bool Saving_Account::deposit(double amnt){
    amnt *= (1+int_rate/100);
    return Account::deposit(amnt);
}
