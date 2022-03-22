// https://leetcode.com/problems/maximum-product-subarray/
#include<iostream>
#include<vector>
#include<climits>

int maxProduct(std::vector<int>& nums){
    int max {INT_MIN}, prod{1};
    for(const int& val: nums){
        prod *= val;
        max = (max > prod) ? max : prod;
        prod = (prod == 0) ? 1 : prod;
    }
    prod = 1;
    for(auto it {--nums.cend()}; it >= nums.cbegin(); it--){
        prod *= (*it);
        max = (max > prod) ? max : prod;
        prod = (prod == 0) ? 1 : prod;
    }
    return max;
}

int main(){
    std::vector<int> nums;
    int temp;
    while(std::cin >> temp) nums.push_back(temp);
    std::cout << maxProduct(nums) << '\n';
    return 0;
}