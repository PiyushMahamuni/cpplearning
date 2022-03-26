#include <iostream>
#include "mod.h"
#include <sstream>
using namespace std;

int main(){
    long long a,b,c;
    string s;
    getline(cin, s);
    stringstream* ss = new stringstream{s};
    while((*ss)>>a>>b>>c){
        cout << div_mod(a, b, c) << endl;
        getline(cin, s);
        delete ss;
        ss = new stringstream{s};
    }
    delete ss;
    return 0;
}