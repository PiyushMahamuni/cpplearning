#include <iostream>
#include <vector>

using namespace std;


// best, iterative, very fast, no use of extra memory, light on memory and fast in processing   -30
void fib_1(unsigned N){  // better than fib_2
    cout << "void fib_1(unsigned):\n";
    for(int p{0}, n{1}; ; N-= 2){
        if(N==0){
            cout << p << endl;
            break;
        }
        else{
            cout << p << endl;
            cout << n << endl;
        }
        p += n;
        n += p;
    }
}

// use of extra variable which could've been avoided with first algorithm, 2nd best for this type
void fib_2(unsigned N){
    cout << "void fib_2(unsigned)\n";
    int temp;
    for(int p{0}, n{1}; ; N--){
        cout << p << endl;
        temp = p;
        p = n;
        n += temp;
        if(N==0) break;
    }
}

// The best, works for both +ve and -ve indice, very fast and most opitmized for this type
void fib_3(int N){
    cout << "void fib_3(int)\n";
    int fn{0};
    int dn { (N<0)?-1:1 }, fnpdn{1}; // fn plus dn
    for( ; dn * N >= 0 ; N -= 2 * dn){
        if(N==0){
            cout << fn << endl;
            break;
        }
        else{
            cout << fn << endl
                 << fnpdn << endl;
        }
        fn = fn +  dn * fnpdn;
        fnpdn = fnpdn + dn * fn;
    }
}


// Just applies previous alg to print f(-n) to f(n) terms
void fib_4(int N){
    cout << "void fib_4(int)\n";
    vector<int> neg_inds{1, -1};  // stores indcise from -1, -2 and so on
    for(int i{2}; i < N; i++){
        neg_inds.push_back(neg_inds[i-2] - neg_inds[i-1]);
    }
    for(int n{N-1}; n>=0; n--){
        cout << neg_inds[n] << endl;
    }
    for(int fn{0}, fnp1{1} ; N >= 0 ; N-= 2){
        if(N==0){
            cout << fn << endl;
            break;
        }
        else{
            cout << fn << endl;
            cout << fnp1 << endl;
        }
        fn += fnp1;
        fnp1 += fn;
    }
}


// Fibonacci by dynamic programming, complicated, O(n), slower than iterative ones
int fib_5(int N, bool root = true){
    static int* arr { nullptr };
    static bool* state { nullptr };
    if(root){
        arr = new int[(N<0)?(-N+1):N+1];
        state = new bool[(N<0)?(-N+1):N+1];
        cout << "int fib_5(int)\n" << endl;
        for(int i{0}; i<=N; i++) state[i] = false;
        for(int i{0}; i>=N; i--) state[-i] = false;
        arr[0] = 0;
        arr[1] = 1;
        state[0] = true;
        state[1] = true;
    }
    int res;
    if(N<0 && state[-N]) return arr[-N];
    else if(N>=0 && state[N]) return arr[N];
    if(N<0){
        res = fib_5(N+2, false) - fib_5(N+1, false);
        state[-N] = true;
        arr[-N] = res;
    }
    else{
        res = fib_5(N-1, false) + fib_5(N-2, false);
        state[N] = true;
        arr[N] = res;
    }
    if(root){
        if(N<0) N = -N;
        for(int i{}; i<=N; i++){
            cout << arr[i] << endl;
        }
        delete [] arr;
        delete [] state;
    }
    return res;
}

// recursively, NOT GREAT
int fib_6(int N){
    if(N==0) return 0;
    if(N>-2 && N < 2) return 1;
    if(N<0) return fib_6(N+2) - fib_6(N+1);
    return fib_6(N-1) + fib_6(N-2);
}

int main(){
//    unsigned N;
//    cin >> N;
//    fib_1(N);
//    fib_2(N);
//    fib_3(static_cast<int>(N));
//    fib_4(static_cast<int>(N));
    int n;
    cout << "Enter a -ve indice: ";
    cin >> n;
//    fib_3(n);
    fib_5(n);
//    cout << "fib_6: " << fib_6(n);
    cout << "Enter a +ve indice: ";
    cin >> n;
    fib_5(n);
//    cout << "fib_6: " << fib_6(n);
    return 0;
}

// f(n) = f(n-1) + f(n-2)
// f(0) = 0, f(1) =1
// f(1) = f(0) + f(-1) => f(-1) = f(1) - f(0)
// f(n) = f(n+2) - f(n+1) 
// f(n-2) = f(n) - f(n-1)
// N = n-2, n = N + 2, n-1 = N + 1