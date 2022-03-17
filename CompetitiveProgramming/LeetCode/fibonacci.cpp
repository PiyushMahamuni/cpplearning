// https://leetcode.com/problems/fibonacci-number/
#include <iostream>

int fib(int n){
    int fibn[3] {0, 1, 1};
    for(int i{3}; i<=n; i++){
        fibn[i%3] = fibn[(i-1)%3] + fibn[(i-2)%3];
    }

    return fibn[n%3];
}

int main(){
    int n;
    while(std::cin >> n){
        std::cout << fib(n) << '\n';
    }
    return 0;
}