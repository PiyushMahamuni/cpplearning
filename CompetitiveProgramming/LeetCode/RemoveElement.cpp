// https://leetcode.com/problems/remove-element
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    if(!nums.size())return 0;
    for(auto it{--nums.end()}; it>=nums.begin();){
        if(*it == val){
            it = --nums.erase(it);
        }
        else{
            --it;
        }
    }
    return nums.size();
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
    }
}