#include <iostream>
#include <string>
using namespace std;

class Account{
public:
    double balance;
    string name;
    
    bool withdraw(double amount){
        if(amount > balance)
            return false;
        balance -= amount;
        cout << "Account: " << name << endl;
        cout << amount << " withdrawn. Balance: " << balance << endl;
        return true;
    }
    
    bool deposit(double amount){
        if(amount < 1){
            cout << "Sorry, amount should be atleast $1" << endl;
            return false;
        }
        balance += amount;
        cout << "Account: " << name << endl;
        cout << amount << " deposited. Balance: " << balance << endl;
        return true;
    }
};

int main(){
    Account Piyush_Accnt;
    Piyush_Accnt.name = "Piyush's Account";
    Piyush_Accnt.balance = 0;
    
    if(Piyush_Accnt.withdraw(100)){
        cout << "Withdraw successful" << endl;
    } else {
        cout << "Withdraw unsuccessful" << endl;
    }
    cout << endl;
    
    if(Piyush_Accnt.deposit(10000)){
        cout << "Deposit successful" << endl;
    } else {
        cout << "Deposit unsuccessful" << endl;
    }
    cout << endl;
    
    if(Piyush_Accnt.withdraw(100)){
        cout << "Withdraw successful" << endl;
    } else {
        cout << "Withdraw unsuccessful" << endl;
    }
    cout << endl;
    
    Account *New_Account = new Account();
    
    (*New_Account).name = "New Account";
    New_Account->balance = 0;
    
    if((*New_Account).withdraw(100)){
        cout << "Withdraw successful" << endl;
    } else {
        cout << "Withdraw unsuccessful" << endl;
    }
    cout << endl;
    
    
    if(New_Account->deposit(10000)){
        cout << "Deposit successful" << endl;
    } else {
        cout << "Deposit unsuccessful" << endl;
    }
    cout << endl;
    
    if(New_Account->withdraw(100)){
        cout << "Withdraw successful" << endl;
    } else {
        cout << "Withdraw unsuccessful" << endl;
    }
    cout << endl;
    
    delete New_Account;
    
    return 0;
}