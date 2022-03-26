#include <iostream>
#include "linkedlist.h"
#include <string>
using namespace std;

int main(){
    List<int> l;
    l.append(1);
    l.append(3);
    l.append(2);
    l.append(-7);
    cout << l << endl;
    l[0] = -1;
    cout << l << endl;
    l[-1] = l[-1]*2;
    cout << l << endl;
    List<int> list;
    for(int i{}; i<=10; i++){
        list.append(i);
    }
    list.extend(l);
//    cout << list << endl
//         << l << endl;
    cout << "list: " << list << endl;
    for(int i{}; i<list.getsize(); i++){
        cout << list[i] << "\n";
    }
    for(int i{-1}; i>=-list.getsize(); i--){
        cout << list[i] << '\n';
    }
    
    List<const char*> name;
    name.append("Piyush");
    name.append("Sunil");
    name.append("Mahamuni");
    cout << name << endl;
    List<size_t> sz;
    sz.append(1);
    sz.append(2);
    sz.append(3);
    cout << sz << endl;
    return 0;
}