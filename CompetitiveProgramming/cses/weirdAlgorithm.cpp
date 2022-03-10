// https://cses.fi/problemset/task/1068
#include <iostream>

int main(){
    size_t n;
    std::cin >> n;
    std::cout << n << ' ';
    while(n!=1){
        n = (n%2) ? n * 3 + 1 : n / 2;
        std::cout << n << ' ';
    }
    return 0;
}