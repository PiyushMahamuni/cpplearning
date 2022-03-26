#include <iostream>

// Modular Exponentiation, (x^n) % M
// Used whenever x^n is too big to be stored in memory without overflow
// %M is then used to infer whatever required subsequent arithmetic was required to be
// performed in a clever way

using namespace std;
int modularExponentiation_i(int x, int n, int M);
int modularExponentiation_r(int x, int n, int M);

void modularExponentiation(int x, int n, int M){
    cout << "Iteratively : " << modularExponentiation_i(x, n, M) << endl
         << "Recursively : " << modularExponentiation_r(x, n, M) << endl;
}

int main(){
    modularExponentiation(3, 3, 5);
    return 0;
}

// calculates modular exponentiation iteratively
int modularExponentiation_i(int x, int n, int M){
    int result{1};
    while( n > 0 ){
        if( n % 2 == 1 ){
            result = (result * x) % M;
        }
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}

// calculates modular exponentiation recursively
int modularExponentiation_r(int x, int n, int M){
    if( n == 0 ){
        return 1;
    }
    else if( n % 2 ){ //odd number
        return ( x * modularExponentiation_r( ( x * x ) % M, ( n - 1 ) / 2, M ) ) % M;
    }
    else{ //even
        return modularExponentiation_r( ( x * x ) % M, n / 2, M);
    }
}