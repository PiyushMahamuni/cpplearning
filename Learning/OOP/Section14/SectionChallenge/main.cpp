#include <iostream>
#include "Mystring.h"

using namespace std;

int main(){
    Mystring input;
    cout << "Enter a string: ";
    cin >> input;
    cout << input << endl
         << (-input) << endl
         << (input == "This is the input") << endl
         << (input < "is less than this") << endl
         << (input > "is greater than this") << endl
         << (input << "This will append " << 'a' << " string to input") << endl;
    input = "";
    input += "This will be concatenated to the input";
    cout << input << endl;
    
    return 0;
}