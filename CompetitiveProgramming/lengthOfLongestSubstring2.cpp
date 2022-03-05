// https://leetcode.com/problems/longest-substring-without-repeating-characters
// Better solution
#include<iostream>
#include<bitset>

int lengthOfLongestSubstring(std::string& s){
    size_t count{}, count_max{};
    std::bitset<256> set;
    for(size_t i{}; i < s.length() && s.length() - i > count_max; i++){
        count = 0;
        set.reset();
        for(size_t j{i}; j < s.length(); j++){
            if(set[s[j]]){
                break;
            }
            else{
                set[s[j]] = 1;
                count++;
            }
        }
        count_max = count > count_max ? count : count_max;
    }
    return count_max;
}
