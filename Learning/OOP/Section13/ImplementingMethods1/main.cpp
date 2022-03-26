#include <iostream>
#include <string>
using namespace std;

class Account{
private:
    double balance;
    string name;
public:
    void set_balance(double amnt){ balance = amnt; }
    double get_balance(){ return balance; }
    //declaring inline functions ^
    
    
    //methods will be implemented outside of the class declaration ->
    void set_name();
    bool withdraw(double amnt);
    bool deposit(double amnt);
};

void Account::set_name(){
    cout << "Enter account holder's name: ";
    getline(cin,name);
    cout << "Name set: " << name << endl;
}

bool Account::deposit(double amnt){
    if(amnt<1){
        cout << "Error: amnt can be at the least 1 $" << endl;
        return false;
    }
    balance += amnt;
    cout << "name: " << name << endl
         << amnt << "$ deposited. balance: " << balance << '$' << endl;
    return true;
}

bool Account::withdraw(double amnt){
    if(amnt>balance){
        cout << "Error: insufficient balance!" << endl;
        return false;
    }
    balance -= amnt;
    cout << "name: " << name << endl
         << amnt << "$ withdrawn. balance: " << balance << '$' << endl;
    return true;
}

int main(){
    Account piyush_accnt;
    piyush_accnt.set_name();
    piyush_accnt.set_balance(0);
    piyush_accnt.deposit(-10);
    piyush_accnt.deposit(10000);
    piyush_accnt.withdraw(20000);
    piyush_accnt.withdraw(10000);
    cout << "balance in Piyush's Account: " << piyush_accnt.get_balance() << endl;
    return 0;
}