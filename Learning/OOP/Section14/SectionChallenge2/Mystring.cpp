#include "Mystring.h"
#include <iostream>

//Constructors----------------------------------------------------------
//no arg, c-string arg
Mystring::Mystring(char *source) : str{source}, len { 0 } {
    //figure out the lenght of the string
    if(str != nullptr){
        for(; source[len]!= '\0' && source[len] != '\n' && len<1000; len++){
        }
        
        //allocate storage on heap
        str = new char[len];
        
        //read into this storage
        for(unsigned i{}; i<len; i++){
            str[i] = source[i];
        }
    }
}

//char arg
Mystring::Mystring(char source) : len { 1 }, str {new char}{
    *str = source;
}

//copy
Mystring::Mystring(const Mystring& source) : len { source.len }, str { new char[len] } {
    for(unsigned i{}; i<len; i++){
        str[i] = source.str[i];
    }
}

//move
Mystring::Mystring(Mystring&& source): len { source.len }, str { source.str } {
    source.str = nullptr;
    source.len = 0;
}

//----------------------------------------------------------Constructors




//Destructor------------------------------------------------------------
Mystring::~Mystring(){
    delete [] str;
}
//------------------------------------------------------------Destructor




//Overloading op as methods---------------------------------------------
//move assignment
Mystring& Mystring::operator=(Mystring&& rhs){
    delete [] str;
    len = rhs.len;
    str = rhs.str;
    rhs.len = 0;
    rhs.str = nullptr;
    return *this;
}

//copy assignment
Mystring& Mystring::operator=(const Mystring& rhs){
    if(this == &rhs) return *this;
    delete [] str;
    len = rhs.len;
    str = new char[len];
    for(unsigned i{}; i<len; i++){
        str[i] = rhs.str[i];
    }
    return *this;
}

//attatching to this string
Mystring& Mystring::operator+=(const Mystring& rhs){
    (*this) = (*this) + rhs;
    return *this;
}

//inserting into object
Mystring& Mystring::operator<<(const Mystring& rhs){
    return (*this = (*this) + rhs);
}

//return lowercased, this remains same
Mystring Mystring::operator-()const{
    Mystring temp { *this };
    for(unsigned i{}; i<len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            temp.str[i] -= 'A' - 'a';
        }
    }
    return temp;
}

//returns a string which is a num times concatenated ver of *this
Mystring Mystring::operator*(unsigned num){
    Mystring temp;
    for( ; num > 0; num--){
        temp += (*this);
    }
    return temp;
}

//saves the mutliplied string in *this
Mystring& Mystring::operator*=(unsigned num){
    Mystring temp { *this };
    for( ; num > 1; num--){
        *this += temp;
    }
    return *this;
}

//converts *this into uppercase // pre increment
Mystring& Mystring::operator++(){
    for(unsigned i{}; i<len; i++){
        if(str[i] >= 'a' && str[i] <= 'z') str[i] += ('A' - 'a');
    }
    return *this;
}

//returns *this and then converts to uppercase // post increment
Mystring Mystring::operator++(int){
    Mystring temp { *this };
    operator++();   //calling pre increment
    return temp;
}
//---------------------------------------------Overloading op as methods




//Overloading op as global functions------------------------------------
//return concatenated strings as one string
Mystring operator+(const Mystring& lhs, const Mystring& rhs){
    Mystring temp;
    temp.len = lhs.len + rhs.len;
    temp.str = new char [temp.len];
    unsigned i;
    for(i=0; i<lhs.len; i++){
        temp.str[i] = lhs.str[i];
    }
    for(; i<lhs.len+rhs.len; i++){
        temp.str[i] = rhs.str[i-lhs.len];
    }
    return temp;
}

//test for equality
bool operator==(const Mystring& lhs, const Mystring& rhs){
    if( &lhs == &rhs ) return true;
    if(lhs.len == rhs.len){
        for(unsigned i{}; i<lhs.len; i++){
            if(lhs.str[i] != rhs.str[i]) return false;
        }
        return true;
    }
    return false;
}

//test for inequality
bool operator!=(const Mystring& lhs, const Mystring& rhs){
    return !(lhs == rhs);
}

//comparison
bool operator<(const Mystring& lhs, const Mystring& rhs){
    if (&lhs == &rhs) return false;
    if(lhs.len < rhs.len) return true;
    else if (lhs.len > rhs.len) return false;
    for(unsigned i{}; i<lhs.len; i++){
        if(lhs.str[i] > rhs.str[i]) return false;
    }
    return true;
}

//comparison
bool operator>(const Mystring& lhs, const Mystring& rhs){
    if (&lhs == &rhs) return false;
    return !(lhs<rhs);
}

//inserting into stream
std::ostream& operator<<(std::ostream& os, const Mystring& obj){
    for(unsigned i{}; i<obj.len; i++){
        os << obj.str[i];
    }
    return os;
}

//extracting from stream
std::istream& operator>>(std::istream& is, Mystring& obj){
    char *buff = new char [1000];
    is.getline(buff, 1000);
    obj = Mystring { buff };
    delete [] buff;
    return is;
}
//------------------------------------Overloading op as global functions