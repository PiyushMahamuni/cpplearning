// https://cses.fi/problemset/task/1071
#include<iostream>
// INCOMPLETE - OVERFLOW ISSUE  

int main(){
    unsigned long long t, x, y, z;
    std::cin >> t;
    while(t--){
        std::cin >> y >> x;
        z = std::max(x, y);
        std::cout << z * z - (std::min(x, y) - 1) << '\n';
    }
    return 0;
}