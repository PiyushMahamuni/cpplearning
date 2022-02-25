// https://leetcode.com/problems/repeated-substring-pattern/
// UNSOLVED
#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s){
    if(s.size() == 1) return false;
    size_t right {s.length()}, left{}, len{};
    
    bool is{false};
    while(left < right && !is){
        is = true;
        while(--right, right > s.length() / 2 && s[right]!= s[0]){}
        if(s[right] != s[0]) return false;
        size_t r{right + 1};
        for(left = len = 1; r < s.length(); left++, r++, len++){
            if(s[left] != s[r]){
                is = false;
                break;
            }
        }
        if(is && !(s.length() % len)) is = false;
    }
    return is;
}

int main(){
    std::string ip, quit{"quit"};
    while(std::cin >> ip && ip != quit){
        std::cout << repeatedSubstringPattern(ip) << '\n';
    }
    return 0;
}