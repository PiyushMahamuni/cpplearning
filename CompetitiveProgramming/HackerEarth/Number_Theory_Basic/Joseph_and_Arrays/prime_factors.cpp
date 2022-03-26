#include "prime_factors.h"
// no arg constructor
PrimeFactors::PrimeFactors():N{0}, D{1}, sop{0}{}

// int arg constructor
PrimeFactors::PrimeFactors(const int32_t& n) : N{ 0 }, D{1}, sop{0} {
    add_factors_of(n);
}

// copy constructor
PrimeFactors::PrimeFactors(const PrimeFactors& source) : N{ source.N }, D{ source.D }, prime_factors{ source.prime_factors }, sop{ source.sop } {}
// move constructor
PrimeFactors::PrimeFactors(const PrimeFactors&& source) : N{ source.N }, D{ source.D }, sop{ source.sop} {
    prime_factors = std::move(source.prime_factors);
}

// destructor
PrimeFactors::~PrimeFactors(){}

// private method to find the prime factors of a number
void PrimeFactors::add_factors_of(int32_t n){
    if(n == 0) return;
    if(N == 0) N = 1;
    int32_t UL{ static_cast<int32_t>(ceil(sqrt(n))) };
    int power{};
    for(int32_t i{2}; i<=UL; i++){
        power = 0;
        while(!(n%i)){
            n /= i;
            power++;
        }
        if(power){
            int cp {prime_factors[i]};
            int target{ cp + power };
            if(cp<0){
                // power can only be +ve here so we'll never have to add i factor to D
                // first we need to take away i from D by div and reach the target power
                // we can keep taking away from D until 0 power is reached, after that we need to add i to N by multiplying
                int ul{ (target>0)? 0 : target };
                for(int j{cp}; j < ul; j++) D /= i;
                for(int j{}; j<target; j++) N *= i;
            }
            else{
                // power is +ve, cp is +ve, just add extra `power` `i` factors in N
                for(int j{}; j<power; j++) N *= i;
            }
            prime_factors[i] += power;
            sop += power;
            UL = ceil(sqrt(n));
        }
    }
    if(n>1){
        prime_factors[n] += 1; // since we might call add_factors_of more than twice when there already are factors in 
        // prime_factors map, the key `n` might already exist and hence += instead of = compared other times when
        // prime factors of a single no are stored in a map
        sop++;
        if(prime_factors[n] > 0) N *= n;
        else D /= n;
    }
}

void PrimeFactors::sub_factors_of(int32_t n){
    if(n == 0) return;
    if(N == 0) N = 1;
    int32_t UL{ static_cast<int32_t>(ceil(sqrt(n))) };
    
    int power{};
    for(int i{2}; i<=UL; i++){
        power = 0;
        while(!(n%i)){
            n /= i;
            power++;
        }
        if(power){
            int cp{ prime_factors[i] };
            int target{ cp - power };
            // since power can only be +ve here, target < cp
            if(cp>0){
                // going down in Numerator first and if necessary give `i` factors to Denominator later
                int ll { (target>0) ? target : 0 };
                for(int j{cp}; j>ll; j--) N /= i;
                for(int j{}; j>target; j--) D *= i;
            }
            else{
                for(int j{}; j<power; j++) D *= i; // cp was -ve, target<cp just had to give more `i` factors to D
            }
            prime_factors[i] -= power;
            sop -= power;
            UL = ceil(sqrt(n));
        }
    }
    if(n > 1){
        prime_factors[n] -= 1;
        if(prime_factors[n] >= 0) N /= n;
        else D *= n;
        sop--;
    }
}

inline void PrimeFactors::add_factors_of(const PrimeFactors& obj){
    for(const std::pair<const int32_t, int>& elem: obj.prime_factors){
        int cp { prime_factors[elem.first] }; // current power of elem.first prime (key) from this->prime_factors
        int target{ cp + elem.second };
        if(cp<0){
            int ul { (target>0)? 0 : target };
            for(int i{cp}; i<ul; i++) D /= elem.first; // elem.second +ve, taking away elem.first from the Denominator first
            for(int i {0}; i<target; i++) N *= elem.first; // if still target is to be reached, giving elem.first to Numerator
            for(int i{cp}; i>target; i--) D *= elem.first; // elem.second -ve, increasing Denominator
        }
        else{
            for(int i{cp}; i < target; i++) N *= elem.first; // elem.second +ve, target>cp, increasing Numerator
            // if elem.second was -ve => target is low than cp and it could also be -ve meaning we'll have to increase D
            // calculating lower limit of iterations of taking away elem.first from N -> 0 or target from cp, whichever higher
            int ll{ (target>0) ? target : 0 };
            for(int i{cp}; i>target; i--) N /= elem.first;
            // if target is still to be reached, more elem.first needs to be taken away i.e. given to D
            for(int i{}; i>target; i--) D *= elem.first;
        }
        prime_factors[elem.first] += elem.second;
    }
    sop += obj.sop;
}

void PrimeFactors::sub_factors_of(const PrimeFactors& obj){
    for(const std::pair<const int32_t, int>& elem: obj.prime_factors){
        int cp{ prime_factors[elem.first] };
        int target { cp - elem.second };
        if(cp>0){
            int ll { (target<0) ? 0 : target };
            for(int i{cp}; i>target; i--) N /= elem.first; // elem.second was +ve, target < cp, Decreasing Numerator until power of
            // elem.first is reduced to 0, will increase Denominator if still target is not reached
            for(int i{}; i>target; i--) D *= elem.first; // remaining iteration to deduct elem.first power from set
            for(int i{cp}; i<target; i++) N *= elem.first; // elem.second was -ve, target > cp,  increased Numerator
        }
        else{
            int ul { (target>0)? 0 : target };  // if target is +ve, elem.second was negative and larger than cp in magnitude
            for(int i{cp}; i>target; i--) D *= elem.first; // elem.second +ve => target > cp, increasing Denominator
            for(int i{cp}; i<ul; i++) D /= elem.first; // elem.second was -ve, taking away Denominator
            for(int i{}; i<target; i++) N *= elem.first; // target > 0, increasing Numerator after taking away Denominator
        }
    }
    sop -= obj.sop;
}

// public method to clear the prime factors stored in this object
void PrimeFactors::clear(){
    N = 0;
    sop = 0;
    prime_factors.clear();
}

// getter to return sum of powers
int PrimeFactors::sum_of_powers(){
    return sop;
}


// getter to return individual power of prime factors
int PrimeFactors::ind_power(){
    static auto it {prime_factors.begin()};
    int pw { it->second };
    if(it!=prime_factors.end())return it++, pw;
    else return it = prime_factors.begin(), 0;
}

// set addition translating to algebraic multiplication, returns PrimeFactors object
PrimeFactors PrimeFactors::operator+(const PrimeFactors& rhs){
    PrimeFactors temp(*this);
    temp.add_factors_of(rhs);
    return temp;
}

// set subtraction translating to albegraic division, returns PrimeFactors object
PrimeFactors PrimeFactors::operator-(const PrimeFactors& rhs){
    PrimeFactors temp(*this);
}

// global friend function for output stream
std::ostream& operator<<(std::ostream& os, const PrimeFactors& pf){
    os << "{ ";
    size_t size{ pf.prime_factors.size() - 1 };
    for(const std::pair<int32_t, int>& elem: pf.prime_factors){
        os << elem.first << "^" << elem.second << ((size)? (--size, ", ") : " } = ");
    }
    os << pf.N << "/" << pf.D;
    return os;
}