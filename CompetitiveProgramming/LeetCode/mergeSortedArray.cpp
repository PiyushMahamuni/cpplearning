// https://leetcode.com/problems/merge-sorted-array/
#include<iostream>
#include<vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
    int i{m + n - 1};
    n--; m--;
    for( ; i>=0 && m>=0 && n>=0; i--){
        nums1[i] = (nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
    }
    if(i >= 0){
        if(m>=0){
            for( ;i>=0; i--){
                nums1[i] = nums1[m--]; 
            }
        }
        else{
            for( ; i>= 0; i--){
                nums1[i] = nums2[n--];
            }
        }
    }
}


std::ostream& operator<<(std::ostream& os, const std::vector<int>& nums){
    os << "{ ";
    for(const int& elem: nums){
        os << elem << ", ";
    }
    return os << "}";
}

int main(){
    int temp;
    std::vector<int> num1, num2;
    std::cout << "Enter n: ";
    std::cin >> temp;
    std::cout << "Enter nums1: ";
    while(temp--){
        int temp2;
        std::cin >> temp2;
        num1.push_back(temp2);
    }
    std::cout << "Enter m: ";
    std::cin >> temp;
    while(temp--){
        int temp2;
        std::cin >> temp2;
        num2.push_back(temp2);
    }
    for(size_t i{}; i<num2.size(); i++){
        num1.push_back(0);
    }
    merge(num1, num1.size()-num2.size(), num2, num2.size());
    std::cout << num1 << '\n';
}