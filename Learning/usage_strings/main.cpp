#include <iostream>

using namespace std;

int main(){
    string s1; // emtpy string
    string s2 {"Piyush"};  // Piyush
    string s3 {s2};  // Piyush
    string s4 {"Piyush", 3};  // Piy
    string s5 {s3, 1, 3};  // iyu
    string s6(3, 'X'); // XXX
    cout << "s1: " << s1 << endl
         << "s2: " << s2 << endl
         << "s3: " << s3 << endl
         << "s4: " << s4 << endl
         << "s5: " << s5 << endl
         << "s6: " << s6 << endl;
    
    s1 = "C++ Rocks"; // can assign C-style string literla to C++ string
    // objects.
    s2 = s1;
    cout << "s1: " << s1 << endl
         << "s2: " << s2 << endl;
    
    // NOTES -
    // [] operator does work with C++ string though it doesn't provide bounds
    // checking. .at() method does provide bounds checking
    
    return 0;
}