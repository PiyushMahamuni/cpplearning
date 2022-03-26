#include <iostream>
#include "Account.h"

using namespace std;

int main(){
    Account Piyush;
    Piyush.set_name("Piyush");
    cout << endl;
    Piyush.set_name();
    cout << endl;    
    Piyush.get_name();
    cout << endl;
    Piyush.set_balance(1000);
    cout << endl;
    Piyush.set_balance();
    cout << endl;
    Piyush.withdraw(10);
    cout << endl;
    Piyush.withdraw();
    cout << endl;
    Piyush.deposit(10);
    cout << endl;
    Piyush.deposit();
    
    return 0;
}