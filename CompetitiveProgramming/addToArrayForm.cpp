// https://leetcode.com/problems/add-to-array-form-of-integer/
#include <iostream>
#include <vector>

std::vector<int> addToArrayForm(std::vector<int>& num, int& k){
    int carry{0};
    for(auto it{--num.end()}; it >= num.begin(); it--){
        carry += *it + k % 10;
        *it = carry % 10;
        carry /= 10;
        k /= 10;
    }
    if(!k && carry){
        num.insert(num.begin(), carry);
        return num;
    }
    else if(k += carry){
        auto it {num.begin()};
        while(k){
            it = num.insert(it, k %10);
            k /= 10;
        }
    }
    return num;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec){
    os << "[ ";
    for(const int& elem: vec){
        os << elem << ", ";
    }
    return os << " ]";
}

int main(){
    int num;
    std::cout << "Keep Entering vector array, anythin other than number is a sentinal and then enter k\n";
    std::vector<int> vec;
    while(std::cin >> num){
        vec.push_back(num);
    }
    int k {1900}; // can't get k from keyboard anymore, have to hardcode it.
    std::cout << addToArrayForm(vec, k) << std::endl;
    return 0;
}