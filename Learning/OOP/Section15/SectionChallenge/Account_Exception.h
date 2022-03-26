#ifndef _ACCOUNT_EXCEPTION_H_
#define _ACCOUNT_EXCEPTION_H_

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    // defualt constructor that won't throw any exceptions
    ~IllegalBalanceException() = default;
    // defualt destructor that won't throw any exception, noexcept by default
    
    virtual const char* what() const noexcept {
        return "Balance Can't Be Negative!";
    }
};

class InsufficientFundsException : public std::exception {
public:
    InsufficientFundsException() noexcept = default;
    // default constructor that won't throw any exceptions
    ~InsufficientFundsException() = default;
    // default destructor that also won't throw any excptions
    // destructors are marked noexcpet by default
    
    virtual const char* what() const noexcept {
        return "Balance Is Insufficient to Withraw Given Amount";
    }
};

#endif