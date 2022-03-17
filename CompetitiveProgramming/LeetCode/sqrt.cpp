#include<iostream>
#include<sstream>

// https://leetcode.com/problems/sqrtx/

int mySqrt(int c) {
    if(c <= 1) return c;
    double x{static_cast<double>(c/2)}, x1;
    int x_prime, x_prime2{-1};
    while(true){
        x1 = x - (x * x - c) / (2 * x);
        x = x1;
        x_prime = static_cast<int>(x1);
        if(x_prime == x_prime2) return x_prime;
        x_prime2 = x_prime;
    }
}

int main(){
    std::string ip, quit{"quit"};
    int32_t c;
    while(std::cin >> ip && ip != quit && std::stringstream(ip)>>c){
        std::cout << mySqrt(c) << '\n';
    }
    return 0;
}