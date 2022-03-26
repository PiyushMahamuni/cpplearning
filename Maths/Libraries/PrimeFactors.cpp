#include "PrimeFactors.h"
#include<math.h>

// no arg constructor
PrimeFactors::PrimeFactors(): size{0}, is_undef{false} {}

// int arg constructor
PrimeFactors::PrimeFactors(const int32_t& n): size{0},
                                              is_undef{n==0}{
    add_factors_of(n);
}

// copy constructor
PrimeFactors::PrimeFactors(const PrimeFactors& source): size{source.size},
                                                        is_undef{source.is_undef},
                                                        set_of_factors{ source.set_of_factors }{
}

// move constructor
PrimeFactors::PrimeFactors(PrimeFactors&& source): size{source.size},
                                                   is_undef{source.is_undef},
                                                   set_of_factors{ std::move(source.set_of_factors) }{
}

void PrimeFactors::add_factors_of(int32_t n){
    if(n==0){
        // if we're adding 0's factors that means we're representing x*0= 0's factors which are all prime
        // prime factors raised to infinity or any sub set of it, hence undefined
        set_of_factors.clear();
        is_undef = true;
        size = 0;
        return;
    }
    int32_t UL { static_cast<int32_t>(ceil(sqrt(n))) };
    int32_t power {};
    for(int i{2}; i<=UL; i++){
        power = 0;
        while(!(n%i)){
            n /= i;
            power++;
        }
        if(power){
            if( (set_of_factors[i] += power) == 0 ){
                set_of_factors.erase(i); // remove the factor from set
            }
            size += power;
            UL = ceil(sqrt(n));
        }
    }
    if(n>1){
        if( (set_of_factors[n] += 1) == 0 ) set_of_factors.erase(n);
        size++;
    }
}

void PrimeFactors::sub_factors_of(int32_t n){
    if(n==0){
        // if we're subtracting 0's factors that means x/0= infinity/undef's factors are stored in this set
        // which are all primes raised to infinity and hence undefined
        set_of_factors.clear();
        is_undef = true;
        size = 0;
        return;
    }
    int32_t UL { static_cast<const int32_t>(ceil(sqrt(n))) };
    int32_t power {};
    for(int i{2}; i<=UL; i++){
        power = 0;
        while(!(n%i)){
            n /= i;
            power++;
        }
        if(power){
            if( (set_of_factors[i] -= power) == 0 ) {
                set_of_factors.erase(i);
            }
            size -= power;
            UL = ceil(sqrt(n));
        }
    }
    if(n>1){
        if( (set_of_factors[n] -= 1) == 0 ) set_of_factors.erase(n);
        size--;
    }
}

void PrimeFactors::add_factors_of(const PrimeFactors& pf){
    if(pf.is_undef){
        set_of_factors.clear();
        is_undef = true;
        size = 0;
        return;
    }
    for(const std::pair<const int32_t, int>& factor: pf.set_of_factors){
        if( (set_of_factors[factor.first] += factor.second) == 0 ){
            set_of_factors.erase(factor.first);
            size += factor.second;
        }
    }
}

void PrimeFactors::sub_factors_of(const PrimeFactors& pf){
    if(pf.is_undef){
        set_of_factors.clear();
        is_undef = true;
        size = 0;
        return;
    }
    for(const std::pair<const int32_t, int>& factor: pf.set_of_factors){
        if( (set_of_factors[factor.first] -= factor.second) == 0 ){
            set_of_factors.erase(factor.first);
            size -= factor.second;
        }
    }
}

// Move assignment
PrimeFactors& PrimeFactors::operator=(PrimeFactors&& rhs){
    size = rhs.size;
    is_undef = rhs.is_undef;
    set_of_factors = std::move(rhs.set_of_factors);
    return *this;
}

// Copy assignment
PrimeFactors& PrimeFactors::operator=(const PrimeFactors& rhs){
    size=rhs.size;
    is_undef=rhs.is_undef;
    set_of_factors = rhs.set_of_factors;
    return *this;
}

// set addition translating to algebraic multiplication of Numbers they represent
PrimeFactors PrimeFactors::operator+(const PrimeFactors& rhs)const{
    PrimeFactors temp{*this};
    temp.add_factors_of(rhs);
    return temp;
}

PrimeFactors& PrimeFactors::operator+=(const PrimeFactors& rhs){
    add_factors_of(rhs);
    return *this;
}

// set subtraction translating to algebraic division of Numbers they represent
PrimeFactors PrimeFactors::operator-(const PrimeFactors& rhs)const{
    PrimeFactors temp{*this};
    temp.sub_factors_of(rhs);
    return temp;
}

PrimeFactors& PrimeFactors::operator-=(const PrimeFactors& rhs){
    sub_factors_of(rhs);
    return *this;
}


// set union represents set of lowest franction that both numbers which are represented by *this and rhs set can
// divide in an integer multiple
PrimeFactors PrimeFactors::U(PrimeFactors& rhs){
    if(is_undef || rhs.set_of_factors.size()==0) return *this;
    if(rhs.is_undef || set_of_factors.size()==0) return rhs; // return a undefined prime factor set
    PrimeFactors temp;
    if(set_of_factors.size()>rhs.set_of_factors.size()){
        temp = *this;
        for(const std::pair<const int32_t, int>& factor: rhs.set_of_factors){
            auto it { set_of_factors.find(factor.first) };
            int target{ ((it->second)>factor.second)?(it->second):factor.second };
            if(target){
                temp.size += temp.set_of_factors[factor.first] = target;
            }
        }
    }
    else{
        temp = rhs;
        for(const std::pair<const int32_t, int>& factor: set_of_factors){
            auto it{ rhs.set_of_factors.find(factor.first) };
            int target{ ((it->second)>factor.second)?(it->second):factor.second };
            if(target){
                temp.size += temp.set_of_factors[factor.first] = target;
            }
        }
    }
    return temp;
}

// set intersection representing highest factor that integer divides numbers represented by both *this and rhs set
PrimeFactors PrimeFactors::I(PrimeFactors& rhs){
    if(is_undef || (rhs.set_of_factors.size()==0 && !rhs.is_undef)) return rhs;
    if(rhs.is_undef || (set_of_factors.size()==0 && !is_undef)) return *this;
   PrimeFactors temp;
    for(const std::pair<const int32_t, int>& factor: set_of_factors){
        int rval { rhs.set_of_factors.find(factor.first)->second };
        int target { (rval<factor.second)?rval:factor.second };
        if(target) temp.size += temp.set_of_factors[factor.first] = target;
    }
    for(const std::pair<const int32_t, int>& factor: rhs.set_of_factors){
        int lval { set_of_factors.find(factor.first)->second };
        int target { (lval<factor.second)?lval:factor.second };
        if(target) temp.size += temp.set_of_factors[factor.first] = target;
    }
    return temp;
}

// emplace U
PrimeFactors& PrimeFactors::emplace_U(const PrimeFactors& rhs){
    if(is_undef || rhs.set_of_factors.size() == 0) return *this;
    if(rhs.is_undef || set_of_factors.size() == 0) return (*this = rhs);
    size_t sz{ rhs.set_of_factors.size() };
    auto it{ rhs.set_of_factors.begin() };
    for(size_t i{}; i<sz ; i++, it++){
        int lval{ set_of_factors.find(it->first)->second };
        int target{ (lval>(it->second))?lval:it->second };
        if(target){
            set_of_factors[it->first] = target;
        }
        else set_of_factors.erase(it->first);
        size += (target - lval);
    }
    it = set_of_factors.begin();
    sz = set_of_factors.size();
    for(size_t i{}; i<sz; it++, i++){
        int lval { it->second };
        int rval { rhs.set_of_factors.find(it->first)->second };
        int target { (rval>lval)?rval:lval };
        if(target){
            set_of_factors[it->first] = target;
        }
        else set_of_factors.erase(it);
        size += (target - lval);
    }
    return *this;
}

// emplace I
PrimeFactors& PrimeFactors::emplace_I(PrimeFactors& rhs){
    if(is_undef || (rhs.set_of_factors.size()==0 && !rhs.is_undef)) return *this = rhs;
    if(rhs.is_undef || (set_of_factors.size()==0 && !is_undef)) return *this;
    PrimeFactors temp;
    for(const std::pair<const int32_t, int>& factor: set_of_factors){
        int rval { rhs.set_of_factors.find(factor.first)->second };
        int target { (rval>factor.second)?rval:factor.second };
        if(target) temp.size += temp.set_of_factors[factor.first] = target;
    }
    for(const std::pair<const int32_t, int>& factor: rhs.set_of_factors){
        int lval { set_of_factors.find(factor.first)->second };
        int target { (lval<factor.second)?lval:factor.second };
        if(target) temp.size += temp.set_of_factors[factor.first] = target;
    }
    return *this = std::move(temp);
}


std::ostream& operator<<(std::ostream& os, const PrimeFactors& obj){
    if(obj.is_undef){
        os << "{ undefined }";
        return os;
    }
    if(obj.set_of_factors.size()==0){
        os << "{ }";
        return os;
    }
    os << "{ ";
    size_t sz { obj.set_of_factors.size() };
    for(const std::pair<const int32_t, int>& factor: obj.set_of_factors){
        os << factor.first << "^" << factor.second << ((sz==1)? " }": ", ");
        sz--;
    }
    return os;
}