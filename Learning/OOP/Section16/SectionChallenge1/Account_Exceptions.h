#ifndef _ACCOUNT_EXCEPTION_H_
#define _ACCOUNT_EXCEPTION_H_

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    //default constructor which won't throw any exceptions
    ~IllegalBalanceException() = default;
    //default destructor which won't throw any exceptions
    virtual const char* what() const noexcept{
        return "Balance Can't Be Negative";
    }
    //implementing virtual function
};

class InsufficientFundsException : public std::exception {
public:
    InsufficientFundsException() noexcept = default;
    //default constructor which won't throw any exceptions
    ~InsufficientFundsException() = default;
    //default destructor which won't throw any exceptions
    virtual const char* what() const noexcept {
        return "Balance is Insufficient to withraw given amount";
    }
    //implementing virtual function
};
#endif