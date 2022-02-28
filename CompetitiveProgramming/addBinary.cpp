//https://leetcode.com/problems/add-binary/
#include<iostream>

std::string addBinary(std::string &A, std::string &B){
    std::string &a {A.length() < B.length() ? A : B}, &b{A.length() < B.length() ? B : A};
    bool carry {false};
    auto ait{--a.end()}, bit{--b.end()};
    for(; ait >= a.begin() && bit >= b.begin(); ait--, bit--){
        switch(*ait){
            case '0':
            {
                if(carry){
                    switch(*bit){
                        case '0':
                        {
                            *bit = '1';
                            carry = false;
                            break;
                        }
                        case '1':
                        {
                            *bit = '0';
                            break;
                        }
                    }
                }
                break;
            }
            case '1':
            {
                if (carry){
                    break;
                }
                switch (*bit){
                    case '0':
                    {
                        *bit = '1';
                        break;
                    }
                    case '1':
                    {
                        *bit = '0';
                        carry = true;
                        break;
                    }
                }
                break;
            }
        }
    }
    while(bit >= b.begin() && carry){
        switch(*bit){
            case '0':
            {
                carry = false;
                *bit = '1';
                break;
            }
            case '1':
            {
                *bit = '0';
                break;
            }
        }
        bit--;
    }
    if(carry) b.insert(0, "1");
    return b;
}

int main(){
    std::string a, b;
    std::cin >> a >> b;
    std::cout << addBinary(a, b) << '\n';
    return 0;
}