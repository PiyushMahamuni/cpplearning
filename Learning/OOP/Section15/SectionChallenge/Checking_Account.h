#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account : public Account{
    friend std::ostream& operator<<(std::ostream& os, const Account& accnt);
    //making these func friends is all that we need to do
private:
    static constexpr const char* d_name = "Unnamed Checking Account";
    static constexpr double d_balance = 0.0;
public:
    //conct
    Checking_Account(std::string name = d_name, double balance = d_balance);
    bool withdraw(double amnt);
};

#endif