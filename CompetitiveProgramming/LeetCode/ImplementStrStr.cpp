// https://leetcode.com/problems/implement-strstr/

#include <iostream>
#include <string>
#include <cstring>

int strStr(std::string haystack, std::string needle) {
    if(needle.empty()) return 0;
    const char *ptr {std::strstr(haystack.c_str(), needle.c_str())};
    if(ptr)
        return (ptr - haystack.c_str());
    else
        return -1;
}

int main(){
    std::string haystack, needle, quit{"quit"};
    while(std::cin >> haystack, haystack != quit && std::cin >> needle){
        std::cout << strStr(haystack, needle) << '\n';
    }
    return 0;
}