// https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums){
    std::vector<int> sums;
    int sum, sum2{};
    for(size_t start{}; start<nums.size(); start++){
        sum = 0;
        for(size_t end{start}; end<nums.size(); end++){
            sums[end] = sum += nums[end] - sum2;
        }
        sum2 += nums[start];
    }
}