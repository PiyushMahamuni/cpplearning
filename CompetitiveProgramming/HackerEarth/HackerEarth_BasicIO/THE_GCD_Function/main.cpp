#include <iostream>
#include <map>

using namespace std;

map<size_t, size_t> primefactors; // prime and it's power pair


// is not exact primefactorization rather primefactorization of i!, (fact(i))
inline void primefactorization(size_t& i, size_t start = 2){
    size_t no;
    size_t power;
    for(size_t j{start}; j<=i; j++){
        no = j;
        for(pair<const size_t, size_t>& prime: primefactors){
            power = 0;
            while(no%prime.first==0){
                power++;
                no /= prime.first;
            }
            if(power && power > prime.second) prime.second = power;
        }
        if(no==j){
            primefactors[no] = 1; // no is prime since nothing divided no in
            // above for loop
        }
    }
    
}

int main(){
    size_t T, N, prevN, res{1};
    cin >> T;
    if(T--){
        cin >> N;
        if(N==0){
            cout << 0 << endl;
        }
        else{
            prevN = N;
            primefactors[2] = 0;
            primefactorization(N);
            for(pair<const size_t, size_t>& prime: primefactors){
                for(size_t i{}; i<prime.second; i++)
                res *= prime.first;
            }
            cout << res << endl;
        }
    }
    while(T--){
        cin >> N;
        if(N==0){
            cout << 0 << endl;
            continue;
        }
        if(N>prevN){ // for optimization
            primefactorization(N, prevN+1);
        }
        else{
            primefactors.clear();
            primefactors[2] = 0;
            // inserting first prime `2` with 0 power
            primefactorization(N);
        }
        prevN = N;
        res = 1;
        for(pair<const size_t, size_t>& prime: primefactors){
            for(size_t i{}; i<prime.second; i++)
                res *= prime.first;
        }
        cout << res << endl;
    }
    
    return 0;
}