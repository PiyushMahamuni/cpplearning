#include "Account_util.h"
//Account
void deposit(std::vector <Account> &vec, double amnt){
    std::cout << "\n=== Depositing to Accounts ===================================" << std::endl;
    for(Account& accnt: vec){
        if(accnt.deposit(amnt)) std::cout << "deposited " << amnt << " to " << accnt << std::endl;
        else std::cout << "Failed to deposit " << amnt << " to " << accnt << std::endl;
    }
}

void withdraw(std::vector <Account> &vec, double amnt){
    std::cout << "\n=== Withdrawing from Accounts ================================" << std::endl;
    for(Account& accnt: vec){
        if(accnt.withdraw(amnt)) std::cout << "withdrew " << amnt << " from " << accnt << std::endl;
        else std::cout << "Failed to withdraw " << amnt << " form " << accnt << std::endl;
    }
}

void display(const std::vector <Account>& vec){
    std::cout << "\n=== Displaying Accounts =======================================" << std::endl;
    for(const Account& accnt: vec){
        std::cout << accnt << std::endl;
    }
}

//Saving_Account

void deposit(std::vector <Saving_Account>& vec, double amnt){
    std::cout << "\n=== Depositing to Savings Accounts ===================================" << std::endl;
    for(Saving_Account& accnt: vec){
        if(accnt.deposit(amnt)) std::cout << "deposited " << amnt << " to " << accnt << std::endl;
        else std::cout << "Failed to deposit " << amnt << " to " << accnt << std::endl;
    }
}

void withdraw(std::vector <Saving_Account>& vec, double amnt){
    std::cout << "\n=== Withdrawing from Savings Accounts ================================" << std::endl;
    for(Saving_Account& accnt: vec){
        if(accnt.withdraw(amnt)) std::cout << "withdrew " << amnt << " from " << accnt << std::endl;
        else std::cout << "Failed to withdraw " << amnt << " form " << accnt << std::endl;
    }
}

void display(const std::vector <Saving_Account>& vec){
    std::cout << "\n=== Displaying Savings Accounts =======================================" << std::endl;
    for(const Saving_Account& accnt: vec){
        std::cout << accnt << std::endl;
    }
}

//Checking_Account
void deposit(std::vector <Checking_Account> &vec, double amnt){
    std::cout << "\n=== Depositing to Checking Accounts ===================================" << std::endl;
    for(Checking_Account& accnt: vec){
        if(accnt.deposit(amnt)) std::cout << "deposited " << amnt << " to " << accnt << std::endl;
        else std::cout << "Failed to deposit " << amnt << " to " << accnt << std::endl;
    }
}

void withdraw(std::vector <Checking_Account> &vec, double amnt){
    std::cout << "\n=== Withdrawing from Checking Accounts ================================" << std::endl;
    for(Checking_Account& accnt: vec){
        if(accnt.withdraw(amnt)) std::cout << "withdrew " << amnt << " from " << accnt << std::endl;
        else std::cout << "Failed to withdraw " << amnt << " form " << accnt << std::endl;
    }
}

void display(const std::vector <Checking_Account>& vec){
    std::cout << "\n=== Displaying Checking Accounts =======================================" << std::endl;
    for(const Checking_Account& accnt: vec){
        std::cout << accnt << std::endl;
    }
}

//Trust Account
void deposit(std::vector <Trust_Account>& vec, double amnt){
    std::cout << "\n=== Depositing to Trust Accounts ===================================" << std::endl;
    for(Trust_Account& accnt: vec){
        if(accnt.deposit(amnt)) std::cout << "deposited " << amnt << " to " << accnt << std::endl;
        else std::cout << "Failed to deposit " << amnt << " to " << accnt << std::endl;
    }
}

void withdraw(std::vector <Trust_Account>& vec, double amnt){
    std::cout << "\n=== Withdrawing from Trust Accounts ================================" << std::endl;
    for(Trust_Account& accnt: vec){
        if(accnt.withdraw(amnt)) std::cout << "withdrew " << amnt << " from " << accnt << std::endl;
        else std::cout << "Failed to withdraw " << amnt << " form " << accnt << std::endl;
    }
}

void display(const std::vector <Trust_Account>& vec){
    std::cout << "\n=== Displaying Trust Accounts =======================================" << std::endl;
    for(const Trust_Account& accnt: vec){
        std::cout << accnt << std::endl;
    }
}