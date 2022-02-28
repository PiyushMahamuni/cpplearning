//https://leetcode.com/problems/plus-one/

#include<iostream>
#include<vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    for(auto it{--digits.end()}; it >= digits.begin(); it--){
        if(*it > 8) *it = 0;
        else {
            *it += 1;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec){
    os << "[ ";
    for(const int& elem: vec){
        os << elem << ", ";
    }
    return os << " ]";
}

int main(){
    std::cout << "Enter elements of a digits vector, -1 is a sentinal, any other character exits\n\n";
    std::vector<int> vec;
    int elem;
    while(std::cin>>elem){
        if(elem == -1){
            std::cout << plusOne(vec) << '\n';
            vec.clear();
        }
        else{
            vec.push_back(elem);
        }
    }
    return 0;
}