#include <iostream>
#include "Mystring.h"

using namespace std;

int main(){
    Mystring str;
    cin >> str;
    cout << str << endl
         << (str == "This is a string") << endl
         << ("is not equal to" != str) << endl
         << (str < "is less than") << endl
         << (str << "This will be" << ' ' << " APPENDED") << endl
         << (-str) << endl;
    Mystring another;
    cout << "Enter another: ";
    cin >> another;
    cout << "another * 3: " << (another * 3) << endl;
    another *= 2;
    cout << another << endl
         << (another++) << endl
         << another << endl;
    return 0;
}