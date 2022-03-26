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