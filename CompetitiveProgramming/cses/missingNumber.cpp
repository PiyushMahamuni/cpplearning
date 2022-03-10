// https://cses.fi/problemset/task/1083
#include <iostream>

int main(){
    size_t n, sum{}, temp;
    std::cin >> n;

    for(size_t i{1}; i < n; i++){
        std::cin >> temp;
        sum += temp;
    }

    std::cout << ((n * (n+1) / 2) - sum);
    return 0; 
}