#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include "Account.h"

class Saving_Account : public Account{
private:
    static constexpr const char* def_name = "Unamed Saving Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Saving_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amnt) override; //overriding base class method
    //inherits Account::withdraw as it is, no need to change it
    virtual bool withdraw(double amnt) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Saving_Account() = default;
};

#endif