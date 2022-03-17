// https://leetcode.com/problems/longest-substring-without-repeating-characters
#include<iostream>
#include<string>

int lengthOfLongestSubstring(std::string& s){
    bool charr[256] {false};
    size_t count{0}, count_max{0}, j{};
    for(size_t i{}; j < s.length() && i<s.length(); i++){
        count = 0;
        for(j = i; j<s.length(); j++)
        if(charr[s[j]]){
            count_max = (count_max < count) ? count : count_max;
            for(size_t i{}; i<128; i++){
                charr[i] = charr[255 - i] = false;
            }
            break;
        }
        else{
            charr[s[j]] = true;
            count++;
        }
    }
    return count > count_max ? count : count_max;
}


int main(){
    std::string s, quit{"quit"};
    while(std::cin >> s && s != quit){
        std::cout << lengthOfLongestSubstring(s) << '\n';
    }
    return 0;
}