// https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <string>

bool backspaceCompare(std::string s, std::string t) {
    int skips{}, skipt{};
    for(std::string::iterator its{--s.end()}, itt{--t.end()}; its >=s.begin() && itt >= t.begin(); --its, --itt){
        A:
        while(*its == '#' && its > s.begin()){
            ++skips;
            --its;
        }
        while(skips-- && its > s.begin())
            --its;
        if(*its == '#') goto A;
        // if(its < s.begin()){
        //     skips = 0;
        //     while(itt >= t.begin()){
        //         if(*itt == '#') ++skips;
        //         --itt;
        //     }
        //     if(static_cast<size_t>(skips) * 2 >= t.length()) return true;
        //     return false;
        // }
        B:
        skips = 0;
        while(*itt == '#'){
            ++skips;
            --itt;
        }
        while(skips-- && itt > t.begin())
            --itt;
        if(skips > 0) return false;
        if(*itt == '#') goto B;
        if(*its != *itt)
            return false;
    }
    return true;
}

int main(){
    std::string ip1, ip2, quit{"quit"};
    while(std::cin >> ip1 && ip1 != quit && std::cin >> ip2){
        std::cout << backspaceCompare(ip1, ip2) << '\n';
    }
    return 0;
}