// https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <climits>

int reverse(int &b){
    int res{};
    // The first thing first
    // Range [-2^31, 2^31 - 1] a.k.a. [-2147483648, 2147483647]
    // When would an integer will go beyond this range while reversing?
    //[-2147483648, 2147483647]
    //[-8463847412, 7463847412]
    const int limit{214748364};
    for(int i{}; b && i<9; i++){
        res = res * 10 + b % 10;
        b /= 10;
    }
    if(b){
        if(res < -limit || res > limit) return 0;
        return res * 10 + b;
    }
    return res;
}


int main(){
    return 0;
}