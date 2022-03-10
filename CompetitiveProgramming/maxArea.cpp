// https://leetcode.com/problems/container-with-most-water
#include <iostream>
#include <vector>


int maxArea(std::vector<int>& height){
    int area{}, left{}, right{static_cast<int>(height.size()-1)}, lh, rh;
    while(left<right){
        lh = height[left];
        rh = height[right];
        area = std::max(area, (right - left) * std::min(lh, rh));
        if(lh < rh) ++left;
        else --rh;
    }
    return area;
}

int main(){
    std::vector<int> height;
    int val;
    while(std::cin >> val){
        height.push_back(val);
    }
    std::cout << "Area: " << maxArea(height) << '\n';
    return 0;
}