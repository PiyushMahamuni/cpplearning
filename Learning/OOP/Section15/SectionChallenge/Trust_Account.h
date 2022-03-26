#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Saving_Account.h"

class Trust_Account : public Saving_Account {
    friend std::ostream& operator<<(std::ostream& os, const Saving_Account& accnt);
private:
    static constexpr const char * d_name = "Unnamed Trust Account";
    static constexpr double d_balance = 0.0;
    static constexpr double d_int_rate = 0.0;
protected:
    int rem_withdrawl;
public:
    //conct
    Trust_Account(std::string name = d_name, double balance = d_balance, double int_rate = d_int_rate);
    bool deposit(double amnt);
    bool withdraw(double amnt);
};

#endif