#include<iostream>
#include<math.h>
#include<map>
#include "prime_factors.h"

using namespace std;

void prime_factoriaztion_of_N_factorial(int32_t N, PrimeFactors& prime_factors);

int main(){
//    int32_t n, k;
//    cin >> n >> k;
//    
//    // reading the `n` sized array
//    int32_t arr[n];
//    for(int32_t i{}; i<n; i++){
//        cin >> arr[i];
//    }
//    
//    PrimeFactors pf_arr;
//    for(int i{}; i<n; i++){
//        pf_arr.add_factors_of(arr[i]);
//    }
//    
//    int size { pf_arr.sum_of_powers() };
//    PrimeFactors size_fact_factors{}, sub_size_fact_factors{};
//    cout << "Size: " << size << endl;
//    prime_factoriaztion_of_N_factorial(size, size_fact_factors);
//    int temp;
//    while(temp = pf_arr.ind_power()){
//        prime_factoriaztion_of_N_factorial(temp, sub_size_fact_factors);
//    }
//    
//    for(const pair<const int32_t, size_t>& elem: sub_size_fact_factors.){
//        cout << elem.first << "^" << elem.second << endl;
//        size_factors[elem.first] -= elem.second;
//    }
//    int32_t A{1}, N{1}, D{1}; //A{1} = size!/(power1!*power2!*power3!...)
//    for(const pair<const int32_t, size_t>& elem: size_factors){
//        for(size_t i{0}; i<elem.second; i++){
//            A *= elem.first;
//        }
//    }
//    cout << "A = " << A << endl;
//    
//    prime_factors.clear();
//    
//    cout << prime_factorization(2, prime) << " " << prime_factoriaztion(3) << " " << prime_factoriaztion(6) << " "
//         << prime_factorization(12) << " " << prime_factoriaztion(11);
    
    // chose_k_part = pich k-1 from size-1 = (size-1)!/((size-1-k+1)!(k-1)!) = (size-1)!/((size-k)!(k-1)!)
    // chose_k_part * summation of { 1/ki! }, ki = is partition size
    
    PrimeFactors pf_2(2), pf_3(3), pf_24(24), pf_11(11), pf_7(7);
    int temp{};
    cout << pf_24 << endl;
    while( temp = pf_24.ind_power()){
        cout << temp << endl;
    }
    pf_24.sub_factors_of(7);
    cout << pf_24 << endl;
    pf_24.sub_factors_of(4);
    cout << pf_24 << endl;
}


inline void prime_factoriaztion_of_N_factorial(int32_t N, PrimeFactors& prime_factors){
    for(int32_t i{2}; i<=N; i++){
        prime_factors.add_factors_of(i);
    }
}