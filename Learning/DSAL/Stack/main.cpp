#include<iostream>
#include "stack.h"
#include <string>

using namespace std;

int main(){
    Stack<int> integers;
    integers.push(2);
    integers.push(5);
    integers.push(4);
    integers.push(3);
    cout << integers.pop() << endl;
    integers.push(2);
    while(integers.size()){
        cout << integers.pop() << endl;
    }
    Stack<const char*> cstrings{"Piyush"};
    cstrings.push("Sunil");
    cstrings.push("Mahamuni");
    cout << cstrings.top() << endl;
    cstrings.top() = "Master of the Secret Arts!";
    while(cstrings.size()){
        cout << cstrings.pop() << endl;
    }
    cout << cstrings.type() << endl
         << integers.type() << endl;
    
    Stack<std::string> strng;
    strng.push("Master");
    strng.push("Secret");
    strng.push("Arts");
    cout << strng.type() << endl;
    return 0;
}