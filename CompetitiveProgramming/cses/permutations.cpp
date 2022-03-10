// https://cses.fi/problemset/task/1070
#include <iostream>

int main(){
    size_t n;
    std::cin >> n;
    if(n == 1){
        std::cout << n;
        return 0;
    }
    if(n < 4){
        std::cout << "NO SOLUTION";
        return 0;
    }
    for(size_t i{2}; i <= n; i+=2){
        std::cout << i << ' ';
    }
    for(size_t i{1}; i <=n; i+=2){
        std::cout << i << ' ';
    }
    return 0;
}