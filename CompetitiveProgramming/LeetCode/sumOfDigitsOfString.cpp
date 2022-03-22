// https://leetcode.com/problems/sum-of-digits-of-string-after-convert
#include <iostream>

int getLucky(std::string& s, int k) {
    int sum{};
    if(k--){
        for(const char& ch: s){
            switch (ch){
                case 'a':
                    ++sum;
                    break;
                case 'b':
                    sum += 2;
                    break;
                case 'c':
                    sum += 3;
                    break;
                case 'd':
                    sum += 4;
                    break;
                case 'e':
                    sum += 5;
                    break;
                case 'f':
                    sum += 6;
                    break;
                case 'g':
                    sum += 7;
                    break;
                case 'h':
                    sum += 8;
                    break;
                case 'i':
                    sum += 9;
                    break;
                case 'j':
                    sum += 1;
                    break;
                case 'k':
                    sum += 2;
                    break;
                case 'l':
                    sum += 3;
                    break;
                case 'm':
                    sum += 4;
                    break;
                case 'n':
                    sum += 5;
                    break;
                case 'o':
                    sum += 6;
                    break;
                case 'p':
                    sum += 7;
                    break;
                case 'q':
                    sum += 8;
                    break;
                case 'r':
                    sum += 9;
                    break;
                case 's':
                    sum += 10;
                    break;
                case 't':
                    sum += 2;
                    break;
                case 'u':
                    sum += 3;
                    break;
                case 'v':
                    sum += 4;
                    break;
                case 'w':
                    sum += 5;
                    break;
                case 'x':
                    sum += 6;
                    break;
                case 'y':
                    sum += 7;
                    break;
                case 'z':
                    sum += 8;
                    break;
            }
        }
    }
    int num {sum};
    while(k--){
        num = sum;
        sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

int main(){
    std::string s;
    int t;
    while(std::cin >> s && std::cin >> t) std::cout << getLucky(s, t) << '\n';
    return 0;
}