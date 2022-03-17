// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    size_t pos{0}, cnt{};
    size_t len{nums.size()-1};
    for(size_t i{0}; i<len; i++){
        if(nums[i] != nums[i+1]){
            nums[pos] = nums[i];
            pos++;
            cnt++;
        }
    }
    nums[pos] = nums.back();
    return ++cnt;
}

int main(){
    std::vector<int> vec;
    int ip;
    while(std::cin >> ip && ip >= 0){
        vec.push_back(ip);
    }
    std::cout << removeDuplicates(vec) << '\n';
    for(const int& val: vec){
        std::cout << val << " ";
    }
    return 0;
}