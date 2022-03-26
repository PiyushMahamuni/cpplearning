#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void prime_generation(vector<int>& primes, int UL){
    primes.push_back(2);
    for(int i{3}; i<=UL; i++){
        int ul{ ceil(sqrt(i)) };
        bool is_prime{true};
        for(int j{}; j < primes.size() && primes[j]<=ul;j++){
            if(!(i%primes[j])){
                is_prime = false;
                break;
            }
        }
        if(is_prime) primes.push_back(i);
    }
}

int main(){
    vector<int> primes{};
    int UL;
    cin >> UL;
    prime_generation(primes, UL);
    for(const int& prime:primes){
        cout << prime << endl;
    }
    
    return 0;
}