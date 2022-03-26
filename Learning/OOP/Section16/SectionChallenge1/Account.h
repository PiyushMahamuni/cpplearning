#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "Account_Exceptions.h"
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account : public I_Printable{
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
    
    virtual bool deposit(double amnt) = 0;
    virtual bool withdraw(double amnt) = 0;
    // It doesn't make any sense to override print() since we won't be 
    //instantiating any Account objects
    
    virtual ~Account() = default;
};

#endif