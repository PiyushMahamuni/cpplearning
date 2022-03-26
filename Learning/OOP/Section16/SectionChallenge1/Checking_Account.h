#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account final: public Account{//can't derive a class from this class
private:
    static constexpr const char* d_name = "Unnamed Checking Account";
    static constexpr double d_balance = 0.0;
public:
    //conct
    Checking_Account(std::string name = d_name, double balance = d_balance);
    virtual bool withdraw(double amnt) override;//will be overriden
    virtual bool deposit(double amnt) override;
    virtual void print(std::ostream& os) const override;//implement here
    
    virtual ~Checking_Account() = default;
};

#endif