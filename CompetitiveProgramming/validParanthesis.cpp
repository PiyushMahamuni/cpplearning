#include <string>
#include <stack>
#include <iostream>

//https://leetcode.com/problems/valid-parentheses

bool isValid(std::string s) {
        std::stack<char> stk;
        for(const char& ch: s){
            switch(ch){
                case ')':
                    if(stk.empty() || stk.top() != '(')
                        return false;
                    stk.pop();
                    break;
                case '}':
                    if(stk.empty() || stk.top() != '{')
                        return false;
                    stk.pop();
                    break;
                case ']':
                    if(stk.empty() || stk.top() != '[')
                        return false;
                    stk.pop();
                    break;
                default:
                    stk.push(ch);
            }
        }
        return stk.empty();    
    }

    int main() {
        std::string ip, quit{"quit"};
        while(std::cin >> ip && ip != quit){
            std::cout << isValid(ip) << '\n';
        }
    }