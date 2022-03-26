#include "Trust_Account.h"

//conct
Trust_Account::Trust_Account(std::string name, double balance, double int_rate) :
    Saving_Account{name, balance, int_rate}, rem_withdrawl {3}{
        
}

//overriding Saving_Account's deposit and withdrawl methods
bool Trust_Account::deposit(double amnt){
    if(amnt >= 5000) amnt+=50;
    return Saving_Account::deposit(amnt);
}

bool Trust_Account::withdraw(double amnt){
    if(rem_withdrawl<1 || amnt > balance*0.2) return false;
    rem_withdrawl--;
    return Saving_Account::withdraw(amnt);
}
