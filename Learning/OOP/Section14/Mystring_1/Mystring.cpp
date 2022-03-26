#include "Mystring.h"
#include <iostream>


//implementing 1 arg and no args constructor
Mystring::Mystring(char source[]) : str { source } {
//    std::cout << "Inside no args and 1 args constructor" << std::endl;
    if(str == nullptr) len = 0;
    else{
        for(len = 0; source[len]!='\0' && len < 1000; len++){
            
        }
        //index starts at 0, so won't decrement len
        
        str = new char[len];//creating storage at heap of len, i.e. number of characters exactly
        for(unsigned i{}; i<len; i++){
            str[i] = source[i]; // copying characters one at a time.
        }
    }
//    std::cout << "Leaving no args and 1 arg constructor" << std::endl;
}


Mystring::Mystring(char source) : len { 1 } {
    str = new char;
    *str = source;
//    std::cout << "Inside no args and 1 args constructor" << std::endl;
//    std::cout << "Leaving no args and 1 arg constructor" << std::endl;
}


//implementing copy constructor
Mystring::Mystring(const Mystring &source) : len { source.len } {
//    std::cout << "Inside copy constructor" << std::endl;
    str = new char [len];
    //creating storage at heap
    for(unsigned i{}; i<len; i++){
        str[i] = source.str[i];
    }
//    std::cout << "Leaving copy constructor" << std::endl;
}


//implementing move constructor
Mystring::Mystring(Mystring &&source) : str { source.str }, len { source.len } {
//    std::cout << "Inside move constructor" << std::endl;
    source.len = 0;
    source.str = nullptr;
    //clearing out data of source;
//    std::cout << "Leaving move constructor" << std::endl;
}


//implementing Destructor
Mystring::~Mystring(){
//    std::cout << "Inside destructor for string: "
//              << (*this)
//              << std::endl;
    delete [] str; // freeing storage from the heap
    // deleting len is taken care of stack management.
}


//overloading = operator, copy ver
Mystring& Mystring::operator=(const Mystring &rhs){
    
//    std::cout << "Inside operator overloading (=copy) function" << std::endl;
    if(this == &rhs) return (*this); //avoid the work for self assignment.
    len = rhs.len;
    delete [] str; // release the current storage occupied by the this object
    str = new char[len]; // allocate new storage with proper size
    for(unsigned i {}; i<len; i++){
        str[i] = rhs.str[i]; // copy character by character.
    }
//    std::cout << "Leaving operator=() [copy ver]" << std::endl;
    return (*this);
}


//overloading = operator, move ver
Mystring& Mystring::operator=(Mystring &&rhs){
//    std::cout << "Inside operator overloading (=move) function" << std::endl;
    if(this == &rhs) return (*this);//check for self assignment
    delete [] str; //free space occupied by current string
    len = rhs.len; //copy lenght
    str = rhs.str; //copy heap address of string to be copied
    rhs.str = nullptr;
    rhs.len = 0;
//    std::cout << "Leaving operator=() [move ver]" << std::endl;
    return (*this);
    // you can return ref to this because this object still has scope and and is being used in assignment/ chained assignment
}


//overloading ! operator to toggle cases and return, this remains const
Mystring Mystring::operator!()const{
//    std::cout << "inside operator!(): Toggling case for string: "
//              << (*this)
//              << std::endl;
    Mystring temp;
    temp.str = new char[len]; //giving temp.str same memory size on heap as this
    temp.len = len;
    for(unsigned i{}; i<len; i++){
        if(str[i] <= 'z' && str[i] >= 'a') temp.str[i] = str[i] + 'A' - 'a';
        else if (str[i] <= 'Z' && str[i] >= 'A') temp.str[i] = str[i] + 'a' - 'A';
        else temp.str[i] = str[i];
    }
//    std::cout << "Toggled string to: "
//              << temp
//              << std::endl
//              << "Leaving operator!()" << std::endl;
    return temp;
}


//overloading ++ (pre) to convert to uppercase and return too
Mystring Mystring::operator++(){
//    std::cout << "Insidde operator++()" << std::endl
//              << " converting string: "
//              << (*this)
//              << ", to uppercase" << std::endl;
    for(unsigned i{}; i<len; i++){
        if(str[i] <= 'z' && str[i] >= 'a') str[i] += ('A' - 'a');
    }
//    std::cout << "After conversion, this becomes: "
//              << (*this)
//              << std::endl
//              << "Leaving operator++()" << std::endl;
    return (*this);
}


//overloading -- (pre) to convert to lowercase and return too
Mystring Mystring::operator--(){
//    std::cout << "Insidde operator--()" << std::endl
//              << " converting string: "
//              << (*this)
//              << ", to lowercase" << std::endl;
    for(unsigned i{}; i<len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] -= ('A' -'a');
    }
//    std::cout << "After conversion, this becomes: "
//              << (*this)
//              << std::endl
//              << "Leaving operator--()" << std::endl;
    return (*this);
}


//overloading + operator to concatenate two strigns
//declaring this function as method necessiates that lhs side is already an object of Mystring. so
//we'll define it as global function instead
Mystring operator+(const Mystring& lhs, const Mystring& rhs){
//    std::cout << "Inside operator+()" << std::endl
//              << "lhs: "
//              << lhs
//              << std::endl
//              << "rhs: "
//              << rhs
//              << std::endl;
              
    Mystring temp;
    temp.len = rhs.len + lhs.len;
    temp.str = new char[temp.len];
    unsigned i;
    for(i=0; i<lhs.len; i++){
        temp.str[i] = lhs.str[i];
    }
    for(; i<temp.len; i++){
        temp.str[i] = rhs.str[i-lhs.len];
    }
//    std::cout << "result of concatenation: "
//              << temp
//              << std:: endl
//              << "Leaving operator+()" << std::endl;
    return temp;
    // you can't return reference to temp here because as soon as the function call is ended, the temp goes out of scope
    // and if you do return ref, it will cause segmentation fault.
}


//overloading == operator to check for equality
bool operator==(const Mystring& lhs, const Mystring& rhs){
//    std::cout << "Inside operator==()" << std::endl
//              << "lhs: "
//              << lhs
//              << std::endl
//              << "rhs: "
//              << rhs
//              << std::endl;
    
    if(lhs.len == rhs.len){
        for(unsigned i{}; i<lhs.len; i++){
            if(lhs.str[i] != rhs.str[i]){
//                std::cout << "operaotr==() returning false" << std::endl;
                return false;
            }
        }
//        std::cout << "operaotr==() returning true" << std::endl;
        return true;
    }
//    std::cout << "operaotr==() returning false" << std::endl;
    return false;
}


//overloading < operator to compare string length
bool Mystring::operator<(const Mystring& rhs) const{
    return len < rhs.len;
}


//overloading > operator to compare string length
bool Mystring::operator>(const Mystring& rhs) const{
    return len > rhs.len;
}


//overloading stream insertion operator for inserting into stream
std::ostream& operator<<(std::ostream& os, const Mystring& obj){
    for(unsigned i{}; i<obj.len; i++){
        os << obj.str[i];
    }
    return os;
}


//overloading stream insertion operator to insert into object
Mystring& Mystring::operator<<(const Mystring& rhs){
    *this = (*this) + rhs;
    return *this;
}


//overloading stream extraction operator
std::istream& operator>>(std::istream& is, Mystring& obj){
    delete []obj.str;
    obj.str = nullptr;
    obj.len = 0;
    char temp[1000];
    is.getline(temp, 1000, '\n');
    obj << Mystring {temp};
    return is;
}


void Mystring::display()const{
    std::cout << "---------------------------------" << std::endl
              << "displaying object info:" << std::endl
              << "len: " << len << std::endl
              << "string: "
              << (*this)
              << std::endl
              << "---------------------------------" << std::endl;
}