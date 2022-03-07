
// https://leetcode.com/problems/climbing-stairs
#include<iostream>
#include<bitset>
// This one uses comprehensible algorithm that returns ith fibonacci element.

int climbStairs(int& steps){
    int ways[3], i;
    ways[0] = 1;
    ways[1] = 2;
    ways[2] = 0;
    for(i = 2; i < steps; i++){
        ways[i % 3] = ways[(i - 1) % 3] + ways[(i - 2) % 3];
    }
    return ways[(steps-1)%3];
}

int main(){
    int steps;
    while(std::cin >> steps){
        std::cout << climbStairs(steps) << '\n';
    }
    return 0;
}