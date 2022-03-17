// https://leetcode.com/problems/length-of-last-word

#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    auto it{s.end()};
    int len{};
    while(--it, *it == ' ');
    while(it >= s.begin() && *it != ' ')
        --it, ++len;
    return len;
}

int main(){
    std::string ip, quit{"quit"};
    while(std::getline(std::cin, ip) && ip != quit){
        std::cout << lengthOfLastWord(ip) << '\n';
    }
    return 0;
}