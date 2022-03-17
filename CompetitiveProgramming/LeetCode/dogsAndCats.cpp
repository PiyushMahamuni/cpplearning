// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771
#include<iostream>
// INCOMPLETE
int main(){
    size_t T, i{};
    std::cin >> T;
    size_t N, D, C, M;
    for(i = 0; i<T; i++){
        A:
        std::cin >> N >> D >> C >> M;
        std::string s;
        std::cin >> s;
        for(size_t i{}; i<s.length(); i++){
            if(s[i] == 'C'){
                if(!C){
                    for(size_t j{i + 1}; j < s.length(); j++){
                        if(s[i] == 'D'){
                            std::cout << "Case " << i << ": " << "NO\n";
                            goto A;
                        }
                    }
                    std::cout << "Case " << i << ": " << "YES\n";
                    goto A;
                }
                C--;
            }
            else if(s[i] == 'D'){
                if(!D){
                    std::cout << "Case " << i << ": " << "NO\n";
                    goto A;
                }
                C += M;
                D--;
            }
        }
        std::cout << "Case " << i << ": " << "YES\n";
    }
    return 0;
}