// https://leetcode.com/problems/roman-to-integer/
#include <iostream>
#include <string>

int romanToInt(std::string s) {
    int ans{};
    char pch{};
    
    for(auto it{s.end()--}; it >= s.begin(); it--){
        switch(*it){
            case 'I':
                if(pch == 'V' || pch == 'X')
                    ans--;
                else
                    ans++;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if(pch == 'L' || pch == 'C')
                    ans -= 10;
                else
                    ans += 10;
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if(pch == 'D' || pch == 'M')
                    ans -= 100;
                else
                    ans += 100;
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
        }
        pch = *it;
    }
    return ans;
}

int main(){
    std::string ip, quit{"quit"};
    while(std::cin >> ip && ip != quit){
        std::cout << romanToInt(ip) << '\n';
    }
    return 0;
}