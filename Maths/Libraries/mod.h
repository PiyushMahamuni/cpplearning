#ifndef _MOD_H_
#define _MOD_H_

template<typename T>
T mult_mod(T& a, T& b, T& c){ // returns (a*b) % c
    return T{ ((a%c) * (b%c)) % c };
}


// INCOMPLETE
template<typename T> // returns (a/b)%c;
T div_mod(T& a, T& b, T& m){
    // ans is smallest c where (b*c) % m = a % m
    T bmodm{b%m}, amodm{a%m};
    if(bmodm==0 && amodm){
        return -1;
    }
    for(T c{0}; c<m; c++){
        if((bmodm * c)%m == amodm) return c;
    }
}

#endif _MOD_H_