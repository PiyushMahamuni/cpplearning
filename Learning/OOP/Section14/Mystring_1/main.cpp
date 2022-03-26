#include <iostream>
#include "Mystring.h"

using namespace std;

int main(){
    Mystring empty; // creates an empty str;
    empty = "I can assign c style str to it"; // using move assignment
    cout << empty << endl; // I can insert it into stream easily
    empty << ". I can append another str to it";
    cout << empty << endl;
    Mystring another {empty}; // I can create a Mystring from a Mystring
    Mystring example { "or with a c style str" };
    cout << (example == empty) << " I can compare two strs" << endl
         << (example < empty) << endl
         << (example > empty);
    Mystring name { 'P' }; //construct a str with just a single character
    name << 'i' << 'y' << 'u' << 's' << 'h';
    cout << name << " I can insert one character at a time to it" << endl;
    cout << "Enter a str: ";
    Mystring str;
    cin >> str; //read from istream objects
    cout << (!str) << endl;//toggle
    cout << ++str << endl //toupper
         << --str << endl //tolower
         << (str + name) << endl //concatenate
         << ("like this too" + name) << endl
         << (str + "and like this too") << endl
         << ('a' + str) << endl;
    return 0;
}