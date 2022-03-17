// https://leetcode.com/problems/n-th-tribonacci-number/
#include <iostream>

int tribonacci(int n){
    int tn[4] {0, 1, 1, 2};
    for(int i{3}; i<=n; i++){
        tn[i%4] = tn[(i - 1) % 4] + tn[(i - 2) % 4] + tn[(i - 3) % 4];
    }
    return tn[n % 4];
}