#include <iostream>
#include <string>
#include <cctype>
#include "datatype.h"

using namespace std;

struct temp{
    int j;
};

struct a_struct{
    temp a;
};

class a_class{
    temp a;
};

class b_class: public a_class{
    int jj;
};

struct b_struct{
    char ch;
};

template <typename T>
class abc{
    T elem;
};

int main(){
    datatype<int>();
    datatype<char>();
    datatype<float>();
    datatype<double>();
    datatype<long>();
    datatype<unsigned>();
    datatype<unsigned long>();
    datatype<long double>();
    datatype<short>();
    datatype<const char*>();
    datatype<const int*>();
    datatype<const double*>();
    datatype<const float*>();
    datatype<const long*>();
    datatype<temp>();
    datatype<a_class>();
    datatype<a_struct>();
    datatype<b_class>();
    datatype<b_struct>();
    datatype<long int>();
    datatype<long unsigned int>();
    datatype<size_t>();
    datatype<uint32_t>();
    datatype<short int>();
    datatype<short int*>();
    datatype<char*>();
    datatype<float*>();
    datatype<double*>();
    datatype<char*>();
    datatype<const char*>();
    datatype<const a_class*>();
    datatype<const b_struct>();
    datatype<const a_class>();
    datatype<const int>();
    datatype<abc<char>>();
    datatype<abc<temp>>();
    datatype<abc<const char*>>();
    datatype<abc<const temp*>>();
    datatype<abc<temp*>>();
    datatype<abc<abc<temp*>>>(); // Doesn't work for this one
    cout << datatype<std::string>();
    return 0;
    
}