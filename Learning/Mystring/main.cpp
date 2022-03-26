#include <iostream>
#include <stdlib.h>
#include "Mystring.h"

using namespace std;

int main(){
    Mystring name{"piyush"};
    Mystring last_name;
    name[0] = 'P';
    char last;
    try{
        last = name[5]; // h has the index 5, changing it to 6 will cuase an exception
    }
    catch(OutOfBoundsException& ex){
        cout << ex.what() << endl;
    }
    cout << "Last char: " << last << endl
         << "name: " << name << endl;
        
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "last_name: " << last_name << endl
         << "length: " << last_name.length() << endl;
    
    Mystring fullname;
    
    cout << "name + last_name = " << (fullname = name + last_name) << endl;
    
    cout << fullname++ << endl
         << fullname << endl
         << ++name << endl
         << -fullname << endl
         << "fullname > name " << (fullname > name) << endl
         << "fullname == fullname " << (fullname == fullname) << endl
         << "fullname != name " << (fullname != name) << endl
         << "fullname == name " << (fullname == name) << endl
         << "fullname < name " << (fullname < name) << endl;
    
    cout << "Hit enter to continue";
    cin.get();
    system("clear");
    
    Mystring a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "+a: " << (+a) << endl
         << "--b: " << (--b) << endl
         << "c += a+b: " << (c += a+b) << endl;
    
    // this means I can chain concatenation
    c = "";
    c += (a+b) + a + (+b);
    cout << c << endl;
    
    return 0;
}