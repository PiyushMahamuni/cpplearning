// https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <vector>

// INCOMPLETE

int trap(std::vector<int>& height){
    size_t first_max{}, second_max{};
    for(size_t i{}; i<height.size()-1; i++){
        if(height[i+1] >= height[i]){
            first_max = ++i;
            while(height[i+1] < height[i]) ++i;
            second_max = ++i;
            for(size_t j{first_max}; j<second_max)
        }
    }
}

int main(){
    std::vector<int> height;
    int val;
    while(std::cin >> val){
        height.push_back(val);
    }
    std::cout << "Trapped water: " << trap(height) << '\n';
    return 0;
}