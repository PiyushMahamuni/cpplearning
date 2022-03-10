// https://cses.fi/problemset/task/1069
#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    char ch{};
    size_t len{1}, ans{};
    for(const char& elem: s){
        if(ch != elem){
            ans = std::max(ans, len);
            len = 1;
            ch = elem;
        }
        else{
            len++;
        }
    }
    std::cout << std::max(len, ans);
    return 0;
}