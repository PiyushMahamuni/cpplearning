#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "Account_Exception.h"
#include <iostream>
#include <string>

class Account{
    //friend func to output to stream
    friend std::ostream& operator<<(std::ostream& os, const Account& accnt);
    
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    //Derived class won't need access to these

protected:
    std::string name;
    double balance;
    //Derived class may need access to these, but still can't be accessed directly by object
    
public:
    //conct
    Account(std::string name = def_name, double balance = def_balance);
    
    bool deposit(double amnt);
    bool withdraw(double amnt);
};

#endif