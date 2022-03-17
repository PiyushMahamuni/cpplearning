// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int pnum{-1000};
    auto it{--nums.end()};
    while(it >= nums.begin()){
        if(pnum == *it)
            it = --nums.erase(it);
        else
            pnum = *(it--);
    }
    return nums.size();
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