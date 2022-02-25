// https://leetcode.com/problems/remove-element
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    size_t pos{};
    for(size_t i{}; i<nums.size(); i++){
        if(nums[i] == val)
            continue;
        nums[pos] = nums[i];
        pos++;
    }
    return pos;
}

int main(){
    std::vector<int> vec;
    int ip, val;
    while(std::cout << "\nVal: ", std::cin >> val && val >= 0){
        while(std::cin >> ip && ip >=0){
            vec.push_back(ip);
        }
        std::cout << "Size: " << removeElement(vec, val) << '\n';
        for(const int& elem: vec){
            std::cout << elem << " ";
        }
        vec.clear();
    }
}