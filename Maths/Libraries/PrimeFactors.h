#ifndef _PRIME_FACTORS_H_
#define _PRIME_FACTORS_H_

#include<map>
#include<iostream>

class PrimeFactors{
    friend std::ostream& operator<<(std::ostream& os, const PrimeFactors& obj);  // DONE, TESTED OK
private:
    int size; // sum of all powers of all prime factors
    bool is_undef; // set of prime factors for number 0 is undefined
    std::map<int32_t, int> set_of_factors;
public:
    PrimeFactors(); // default no arg constructor                   // Compiler Provided
    PrimeFactors(const int32_t& n); // int arg constructor          // DONE, TESTED OK
    PrimeFactors(const PrimeFactors& source); // copy constructor   // DONE, TESTED OK
    PrimeFactors(PrimeFactors&& source); // move constructor        // DONE, TESTED OK
    
    
    void add_factors_of(int32_t n);                 // DONE, TESTED OK
    void add_factors_of(const PrimeFactors& pf);    // DONE, TESTED OK
    void sub_factors_of(int32_t n);                 // DONE, TESTED OK
    void sub_factors_of(const PrimeFactors& pf);    // DONE, TESTED OK
    
    // Move assignment
    PrimeFactors& operator=(PrimeFactors&& rhs);        // DONE, TESTED OK
    // copy assignment
    PrimeFactors& operator=(const PrimeFactors& rhs);   // DONE, TESTED OK
    
    // set addition translating algebraic multiplication of numbers they represent
    PrimeFactors operator+(const PrimeFactors& rhs)const;                           // DONE, TESTED OK
    // set subtraction translating to algebraic division of numbers they represent
    PrimeFactors operator-(const PrimeFactors& rhs)const;                           // DONE, TESTED OK
    PrimeFactors& operator +=(const PrimeFactors& rhs);                             // DONE, TESTED OK
    PrimeFactors& operator -=(const PrimeFactors& rhs);                             // DONE, TESTED OK
    
    // set union, represents set of prime factors of lowest fraction that both numbers representing these sets
    // can divide in integer mulitple
    PrimeFactors U(PrimeFactors& rhs);                  // DONE
    PrimeFactors I(PrimeFactors& rhs);                  // DONE
    PrimeFactors& emplace_U(const PrimeFactors& rhs);   // DONE
    PrimeFactors& emplace_I(PrimeFactors& rhs);         // DONE
};

#endif