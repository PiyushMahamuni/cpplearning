#include <string>
#include <array>
#include <iostream>
// INCOMPLETE
bool isValid(std::string s) {
    std::array<int, 3> stk {};
    std::array<char, 3> paranthesis{')', '}', ']'};
    int ind {-1};
    for(const char& ch: s){
        switch(ch){
            case '(':
                ind = 0;
                stk[ind]++;
                break;
            case '{':
                ind = 1;
                stk[ind]++;
                break;
            case '[':
                ind = 2;
                stk[ind]++;
                break;
            default:
                if(ch != paranthesis[ind])
                    return false;
                stk[ind]--;
        }
    }
    for(size_t i{}; i<3; i++)
        if(stk[ind])
            return false;
    return true;  
}

int main() {
    std::string ip, quit{"quit"};
    while(std::cin >> ip && ip != quit){
        std::cout << isValid(ip) << '\n';
    }
}