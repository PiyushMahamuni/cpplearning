#ifndef PRIME_FACTORS_H_
#define PRIME_FACTORS_H_

#include<math.h>
#include<iostream>
#include<map>

class PrimeFactors{
    friend std::ostream& operator<<(std::ostream& os, const PrimeFactors& pf); // DONE
private:
    int32_t N, D; // Numerator and Denominator
    int sop; // sum of powers
    std::map<int32_t, int> prime_factors;
public:
    PrimeFactors(); // NO arg constructor, //DONE
    PrimeFactors(const int32_t& n); // int arg constructor, // DONE
    PrimeFactors(const PrimeFactors& source); // copy constructor // DONE
    PrimeFactors(const PrimeFactors&& source); // move constructor // DONE
    ~PrimeFactors(); //destructor // DONE
    void clear(); // to clear the data stored in map // DONE
    
    void add_factors_of(const PrimeFactors& obj);  // DONE
    void add_factors_of(int32_t n);  // DONE
    void sub_factors_of(const PrimeFactors& obj);
    void sub_factors_of(int32_t n);
    
    // set addition translating to algebraic multiplication
    PrimeFactors operator+(const PrimeFactors& rhs);
    // set subtraction translating to albegraic division
    PrimeFactors operator-(const PrimeFactors& rhs);
    // set union translating to finding out LCM
    PrimeFactors union_(const PrimeFactors& rhs);
    // set intersection translating to finding out HCF
    PrimeFactors intersection(const PrimeFactors& rhs);
    
    // getter
    int sum_of_powers(); // returns sum of power of all prime factors // DONE
    int ind_power(); // returns individual power one at a time using a static variable
};

#endif