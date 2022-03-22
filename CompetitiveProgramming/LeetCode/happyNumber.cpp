// https://leetcode.com/problems/happy-number/
#include <iostream>
#include <map>

bool isHappy(int n){
    std::map<int, bool> mp;
    int sum{}, temp;
    while(!mp[sum]){
        mp[sum] = true;
        sum = 0;
        while(n){
            temp = n % 10;
            n /= 10;
            sum += temp * temp;
        }
        if(sum == 1) return 1;
        n = sum;
    }
    return false;
}

int main(){
    int n;
    while(std::cin >> n) std::cout << isHappy(n) << '\n';
    return 0;
}