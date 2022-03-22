// https://leetcode.com/problems/add-digits
#include <iostream>

int addDigits(int num){
    int sum{num};
    while(sum > 9){
        num = sum;
        sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

int main(){
    int temp;
    while(std::cin >> temp) std::cout << addDigits(temp) << '\n';
    return 0;
}