// https://cses.fi/problemset/task/1094
#include <iostream>

int main(){
    size_t n, mx{}, val, ans{};
    std::cin >> n;
    for(size_t i{}; i<n; i++){
        std::cin >> val;
        mx = std::max(val, mx);
        ans += (mx - val);
    }
    std::cout << ans;
    return 0;
}