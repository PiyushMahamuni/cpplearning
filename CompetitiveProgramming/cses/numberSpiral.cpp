// https://cses.fi/problemset/task/1071
#include<iostream>
// INCOMPLETE - OVERFLOW ISSUE  

int main(){
    unsigned long long t, x, y;
    std::cin >> t;
    while(t--){
        std::cin >> y >> x;
        if(x > y){
            if(x%2){
                std::cout << x * x - y + 1 << '\n';
            }
            else{
                std::cout << x * x - 2 * x + y << '\n';
            }
        }else if(y > x){
            if(y%2){
                std::cout << y * y - 2 * y + x << '\n';
            }else{
                std::cout << y * y - x + 1 << '\n';
            }
        }
        else{
            std::cout << x * x - x + 1 << '\n';
        }
    }
    return 0;
}