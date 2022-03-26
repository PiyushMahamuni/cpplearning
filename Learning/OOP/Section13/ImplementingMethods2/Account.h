#ifndef _ACCOUNT_H_
#define _ACCOUTN_H_
#include <string>
class Account{
private:
    std::string name;
    double balance;
public:
    void set_name();
    void set_name(std::string temp);

    std::string get_name();
    void set_balance();
    void set_balance(double amnt);

    double get_balance();
    bool deposit(double amnt);
    bool deposit();
    bool withdraw(double amnt);
    bool withdraw();
};
#endif