#include "Account_util.h"
//Account
void deposit(std::vector <Account> &vec, double amnt){
    std::cout << "\n=== Depositing to Accounts ===================================" << std::endl;
    for(Account& accnt: vec){
        if(accnt.deposit(amnt)) std::cout << "deposited " << amnt << " to " << accnt << std::endl;
        else std::cout << "Failed to deposit " << amnt << " to\n" << accnt << std::endl;
    }
}

void withdraw(std::vector <Account> &vec, double amnt){
    std::cout << "\n=== Withdrawing from Accounts ================================" << std::endl;
    for(Account& accnt: vec){
        if(accnt.withdraw(amnt)) std::cout << "withdrew " << amnt << " from " << accnt << std::endl;
        else std::cout << "Failed to withdraw " << amnt << " form\n " << accnt << std::endl;
    }
}

void display(const std::vector <Account>& vec){
    std::cout << "\n=== Displaying Accounts =======================================" << std::endl;
    for(const Account& accnt: vec){
        std::cout << accnt << std::endl;
    }
}
