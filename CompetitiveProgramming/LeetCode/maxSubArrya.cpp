// https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
#include <climits>

int maxSubArray(std::vector<int>& nums){
    int sum{}, max {INT_MIN};
    for(const int& val: nums){
        sum += val;
        max = (max > sum) ? max : sum;
        sum = (sum > 0) ? sum : 0;
    }
    return sum;
}


int main(){
    std::vector<int> vec;
    int temp;
    while(std::cin >> temp)
        vec.push_back(temp);
    std::cout << maxSubArray(vec) << '\n';
    return 0;
}