#include <iostream>
#include <vector>
#include "Trust_Account.h"
#include "Checking_Account.h"
#include "Account_util.h"

using namespace std;

int main(){
    vector <Account> accounts;
    try{
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    display(accounts);
    deposit(accounts, 1000);
    try{
    withdraw(accounts, 2000);
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    vector <Saving_Account> sav_accnts;
    try{
    sav_accnts.push_back(Saving_Account{});
    sav_accnts.push_back(Saving_Account{"Superman"});
    sav_accnts.push_back(Saving_Account{"batman", 2000});
    sav_accnts.push_back(Saving_Account{"WonderWoman", 5000, 5});
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    display(sav_accnts);
    deposit(sav_accnts, 1000);
    try{
    withdraw(sav_accnts, 2000);
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    vector <Trust_Account> turst_accounts;
    try{
    turst_accounts.push_back(Trust_Account{});
    turst_accounts.push_back(Trust_Account{"Lawda"});
    turst_accounts.push_back(Trust_Account{"Gandu", 2000});
    turst_accounts.push_back(Trust_Account{"Chutiya", 5000, 5});
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    display(turst_accounts);
    deposit(turst_accounts, 1000);
    try{
    withdraw(turst_accounts, 1200);
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    vector <Checking_Account> checking_accounts;
    try{
    checking_accounts.push_back(Checking_Account{});
    checking_accounts.push_back(Checking_Account{"Madarchod"});
    checking_accounts.push_back(Checking_Account{"Aaighala", 2000});
    checking_accounts.push_back(Checking_Account{"Randacha", 5000});
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    display(checking_accounts);
    deposit(checking_accounts, 1000);
    try{
    withdraw(checking_accounts, 2000);
    }
    catch (exception& ex){
        cerr << ex.what() << endl;
    }
    
    Trust_Account test {"testing", 10000, 5 };
    while(test.withdraw(1000)){
        cout << "withdrew 100 from test accnt" << endl;
    }
    
    return 0;
}