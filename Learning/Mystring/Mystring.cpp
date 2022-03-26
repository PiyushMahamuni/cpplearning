#include "Mystring.h"
#include<cctype>


// default no args constructor
Mystring::Mystring(): ptr{nullptr}, size{0} {
    
}

Mystring::Mystring(const char* ptr): size{0} {
    // measure lenght first
    while(ptr[size]) // will end when reaches the null character at end
        size++;
    // size is length of string
    this->ptr = new char[size];
    for(size_t i{}; i<size; i++)
        this->ptr[i] = ptr[i];
}

// std::string arg constructor
Mystring::Mystring(const std::string& str): size{str.size()} {
    this->ptr = new char[size];
    for(size_t i{}; i < size; i++){
        this->ptr[i] = str[i];
    }
}

// copy constructor
Mystring::Mystring(const Mystring& source): size{source.size} {
    this->ptr = new char[size];
    for(size_t i{}; i < size; i++)
        this->ptr[i] = source.ptr[i];
}

// Move constructor
Mystring::Mystring(Mystring&& source): size{source.size}, ptr{source.ptr} {
    source.ptr = nullptr;
}

// size_t arg and default const char* constructor
Mystring::Mystring(size_t size, const char* str){
    size_t o_len {};
    while(str[o_len])
        o_len++;
    this->size = size * o_len;
    ptr = new char[this->size];
    for(size_t i{}; i<size; i++){
        for(size_t j{}; j<o_len; j++){
            ptr[i*o_len+j] = str[j];
        }
    }
}

// Destructor
Mystring::~Mystring(){
    delete [] this->ptr;
}

// operator []
char& Mystring::operator[](size_t index){
    if(index >= size) throw OutOfBoundsException();
    return (this->ptr)[index];
}

// move assignment
Mystring& Mystring::operator=(Mystring&& rhs){
    size = rhs.size;
    delete [] ptr;
    ptr = rhs.ptr;
    rhs.ptr = nullptr;
    rhs.size = 0;
    return *this;
}

// copy assignment
Mystring& Mystring::operator=(const Mystring& rhs){
    delete [] ptr;
    size = rhs.size;
    ptr = new char[size];
    for(size_t i{}; i<size; i++)
        ptr[i] = rhs.ptr[i];
    return *this;
}

// unary negation
Mystring Mystring::operator-() const{
    Mystring temp;
    temp.size = this->size;
    temp.ptr = new char[temp.size];
    for(size_t i{}; i<size; i++){
        temp.ptr[i] = tolower(this->ptr[i]);
    }
    return std::move(temp);
}

// unary `+`
Mystring Mystring::operator+() const{
    Mystring temp;
    temp.size = size;
    temp.ptr = new char[size];
    for(size_t i{}; i<size; i++)
        temp.ptr[i] = toupper(this->ptr[i]);
    return std::move(temp);
}

// concatenation with +=
Mystring& Mystring::operator+=(const Mystring& rhs){
    char* temp = ptr;
    ptr = new char[size+rhs.size];
    size_t i{};
    for( ; i<size; i++){
        ptr[i] = temp[i];
    }
    size += rhs.size;
    for( ; i<size; i++){
        ptr[i] = rhs.ptr[i];
    }
    delete [] temp;
    return *this;
}

// pre increment
Mystring& Mystring::operator++(){
    for(size_t i{}; i<size; i++){
        ptr[i] = toupper(ptr[i]);
    }
    return *this;
}

// post increment
Mystring Mystring::operator++(int){
    Mystring temp{*this};
    for(size_t i{}; i<size; i++){
        ptr[i] = toupper(ptr[i]);
    }
    return std::move(temp); // can't return temp as it is, since it is returned as
    // reference and will go out of scope immediately.
}

// pre decrement.
Mystring& Mystring::operator--(){
    for(size_t i{}; i<size; i++){
        ptr[i] = tolower(ptr[i]);
    }
    return *this; // this exists beyond this scope and hence can be returned as it is.
}

// post decrement.
Mystring Mystring::operator--(int){
    Mystring temp{*this};
    for(size_t i{}; i<size; i++){
        ptr[i] = tolower(ptr[i]);
    }
    return std::move(temp);
}

// length of string
size_t Mystring::length(){
    return size;
}

// Stream extraction operator
std::ostream& operator<<(std::ostream& os, const Mystring& obj){
    for(size_t i{}; i<obj.size && obj.ptr[i] != '\0'; i++)
        os << obj.ptr[i];
    return os;
}

// Stream insertion operator
std::istream& operator>>(std::istream& is, Mystring& obj){
    delete [] obj.ptr;
    char temp;
    char* buff = new char[1000];
    obj.size = 0;
    while((temp = is.get()) != EOF && !isspace(temp)){
        buff[obj.size] = temp;
        obj.size++;
    }
    obj.ptr = new char[obj.size];
    for(size_t i{}; i<obj.size; i++)
        obj.ptr[i] = buff[i];
    delete [] buff;
    return is;
}

// other global functions for Mystring class
Mystring operator+(const Mystring& lhs, const Mystring& rhs){
    Mystring temp;
    temp.size = lhs.size + rhs.size;
    temp.ptr = new char[temp.size];
    size_t i{};
    for(; i<lhs.size; i++)
        temp.ptr[i] = lhs.ptr[i];
    for(; i<temp.size; i++)
        temp.ptr[i] = rhs.ptr[i-lhs.size];
    return std::move(temp); //move assignment
    // the temp is going to go out of scope anyway so why to release heap memory
    // just change the onwership of that area
    // you could have first created a buffer on heap, passed it onto
    // a constructor at the end with return statement, something like this
    // return Mystring{buff}; the buffer has one extra null char at end
    // this will also invoke move semantics but is still inefficient since when you
    // call the constructor, it treats buff as any other const char* and creates its
    // own copy on heap
}

// logical operators -
// equality
bool operator==(const Mystring& lhs, const Mystring& rhs){
    if(&rhs == & lhs) return true;
    if(rhs.size == lhs.size){
        for(size_t i{}; i<rhs.size; i++){
            if(rhs.ptr[i] != lhs.ptr[i]) return false;
        }
        return true;
    }
    return false;
}

//inequality
bool operator!=(const Mystring& lhs, const Mystring& rhs){
    if(&rhs == &lhs) return false;
    if(rhs.size == lhs.size){
        for(size_t i{}; i<rhs.size; i++){
            if(rhs.ptr[i] != lhs.ptr[i]) return true;
        }
        return false;
    }
    return true; // sizes are different if this executes.
}

// less than
bool operator<(const Mystring& lhs, const Mystring& rhs){
    if(lhs.size < rhs.size) return true;
    if(lhs.size == rhs.size){
        for(size_t i{}; i<lhs.size; i++)
            if(lhs.ptr[i] > lhs.ptr[i]) return false;
        return true;
    }
    return false;
}

// greater than
bool operator>(const Mystring& lhs, const Mystring& rhs){
    if(lhs.size > rhs.size) return true;
    if(lhs.size == rhs.size){
        for(size_t i{}; i<lhs.size; i++){
            if(lhs.ptr[i] < rhs.ptr[i]) return false;
        }
        return true;
    }
    return false;
}

// For exception classes
const char* OutOfBoundsException::what(){
    return "The index received for op [] is out of bounds for given Mystring object";
}

