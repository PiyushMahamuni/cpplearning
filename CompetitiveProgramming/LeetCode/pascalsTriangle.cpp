// https://leetcode.com/problems/pascals-triangle/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int  numRows){
    std::vector<std::vector<int>> triangle;
    triangle.push_back(std::vector<int> {1});
    for(size_t i{1}; i<numRows; i++){
        std::vector<int> temp {};
        temp.push_back(1);
        for(size_t j{1}; j<i; j++){
            temp.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
        }
        temp.push_back(1);
        triangle.push_back(temp);
    }
    return triangle;
}