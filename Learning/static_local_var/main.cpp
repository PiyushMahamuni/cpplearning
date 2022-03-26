#include <iostream>

using namespace std;

size_t fact(const int num){
    static int count{num};
    if(count>1){  // controls how many times the recursion will take place
        count--;
        return num * fact(count);
    }
    return 1;
}

int main(){
    cout << "Enter a number: ";
    size_t num;
    cin >> num;
    cout << "fact(" << num << "): " << fact(num) << endl;
    
    return 0;
}