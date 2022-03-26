#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <iostream>
#include <vector>
#include "Account.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

//Account class global func
void deposit(std::vector <Account>& vec, double amnt);
void withdraw(std::vector <Account>& vec, double amnt);
void display(const std::vector <Account>& vec);

//Saving_Account class global func
void deposit(std::vector <Saving_Account>& vec, double amnt);
void withdraw(std::vector <Saving_Account>& vec, double amnt);
void display(const std::vector <Saving_Account>& vec);

//Checking account class global func
void deposit(std::vector <Checking_Account>& vec, double amnt);
void withdraw(std::vector <Checking_Account>& vec, double amnt);
void display(const std::vector <Checking_Account>& vec);

//trust account class global func
void deposit(std::vector <Trust_Account>& vec, double amnt);
void withdraw(std::vector <Trust_Account>& vec, double amnt);
void display(const std::vector <Trust_Account>& vec);
#endif