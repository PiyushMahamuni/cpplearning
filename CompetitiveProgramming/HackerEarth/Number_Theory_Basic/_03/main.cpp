#include <iostream>

using namespace std;


int main(){
    int T;
    uint32_t N, K, mod { 1000000007 };
    cout << mod << endl;
    cin >> T;
    while(T--){
        cin >> N >> K;
        // calculate K choose N * K!
        // N * (N-1) * ... * (N-K+1) % mod
        uint32_t ans { N%mod };
        for(uint32_t i{N-1}; i>(N-K); i--){
            ans = (ans * (i%mod)) % mod;
        }
        cout << ans << endl;
    }
    
    return 0;
}