#include "Mystring.h"
#include <iostream>
//Constructors ------------------------------------------------

//no args/ c style string arg constructor
Mystring::Mystring(char *source) : len { 0 } {
    if ( source != nullptr ){
        while(source[len] != '\0' && source[len] != '\n' && len < 1000){
            len++;
        }
        str = new char[len];
        for(unsigned i{}; i<len; i++){
            str[i] = source[i];
        }
    } else str = nullptr;
}

//char arg constructor
Mystring::Mystring(char source) : len { 1 } {
    str = new char;
    *str = source;
}

//Copy constructor
Mystring::Mystring(const Mystring& source) : len { source.len } {
    str = new char[len];
    for(unsigned i{}; i<len; i++){
        str[i] = source.str[i];
    }
}

//Move constructor
Mystring::Mystring(Mystring&& source) : str { source.str }, len { source.len } {
    source.str = nullptr;
    source.len = 0;
}

//-----------------------------------------------Consturcotrs


//Destructor-------------------------------------------------
Mystring::~Mystring(){
    delete [] str;
}

//-------------------------------------------------Destructor


//overloading operators as member methods--------------------

//checking for equality
bool Mystring::operator==(const Mystring& rhs)const{
    if(len==rhs.len){
        for(unsigned i{}; i<len; i++){
            if(str[i] != rhs.str[i]) return false;
        }
        return true;
    }
    return false;
}

//checking for inequality
bool Mystring::operator!=(const Mystring& rhs)const{
    return !(*(this) == rhs);
}

//comparing string lengths
bool Mystring::operator<(const Mystring& rhs)const{
    return (len < rhs.len);
}

//comparing string lengths
bool Mystring::operator>(const Mystring& rhs)const{
    return (len > rhs.len);
}

//assignment, move ver
Mystring& Mystring::operator=(Mystring&& rhs){
    str = rhs.str;
    len = rhs.len;
    rhs.str = nullptr;
    rhs.len = 0;
    return *this;
}

//assignment, copy ver
Mystring& Mystring::operator=(const Mystring& rhs){
    *this = Mystring { rhs };
    return *this;
}

//concatenate rhs to this string
void Mystring::operator+=(const Mystring& rhs){
    *this = (*this + rhs);
}

//appending to this string
Mystring& Mystring::operator<<(const Mystring& rhs){
    *this+=rhs;
    return *this;
}

//return concatenated string
Mystring Mystring::operator+(const Mystring &rhs)const{
    char *buff = new char[len + rhs.len];
    unsigned i;
    for(i=0; i<len; i++){
        buff[i] = str[i];
    }
    for(; i<len+rhs.len; i++){
        buff[i] = rhs.str[i-len];
    }
    Mystring temp { buff };
    delete [] buff;
    return temp;
}

//return lowercase string of this
Mystring Mystring::operator-()const{
    Mystring temp { *this };
    for(unsigned i{}; i<len; i++){
        if(str[i] >= 'A' and str[i] <= 'Z'){
            temp.str[i] -= 'A' - 'a';
        }
    }
    return temp;
}

//--------------------------------Overloading operators as member methods


//Overloading operators as global functions------------------------------

//inserting into stream
std::ostream& operator<<(std::ostream& os, const Mystring& obj){
    for(unsigned i{}; i<obj.len; i++){
        os << obj.str[i];
    }
    return os;
}

//extracting from stream
std::istream& operator>>(std::istream& is, Mystring& obj){
    char *buff = new char[1000];
    is.getline(buff, 1000);
    obj = Mystring { buff };
    delete [] buff;
    return is;
}

//------------------------------Overloading operators as global functions