/* return nth number of fibonacci sequence */

#include <iostream>

using namespace std;

// naive recursive solution

unsigned int fib_n(unsigned int n){
    if(n <= 2)
        return 1;
    return fib_n(n-1) + fib_n(n-2);
}

void print_res(unsigned int n){
    cout << "Naive :" 
         << fib_n(n) << endl;
}


int main(){
    
    print_res(6);
    print_res(7);
    print_res(8);
    print_res(50);
    return 0;
}