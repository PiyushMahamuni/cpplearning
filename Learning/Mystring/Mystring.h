// Mystring.h file declares all specification for Mystring class
// This class is very similar to std::string and is implemented to delibrately
// to practice all C++ concepts and skills

// Include Guard.
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<string> // needed since we could be passing std::string as arguments
#include<iostream> // for friend functions
#include<exception>

class Mystring{
    // stream extraction and insertion
    friend std::ostream& operator<<(std::ostream& os, const Mystring& obj);
    friend std::istream& operator>>(std::istream& is, Mystring& obj);
    
    // other global overloaded operators for Mystring class
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
    
    // logical operators
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);
    friend bool operator!=(const Mystring& lhs, const Mystring& rhs);
    friend bool operator<(const Mystring& lhs, const Mystring& rhs);
    friend bool operator>(const Mystring& lhs, const Mystring& rhs);
private:
    char* ptr; // pointer that will point to char array on heap
    size_t size; // size of the string
public:
    // constructors
    // default - no-args constructor
    Mystring();
    // const char* arg constructor
    Mystring(const char* ptr);
    // std::string constructor
    Mystring(const std::string& str);
    // size_t arg and default const char* constructor
    Mystring(size_t size, const char* str = "\0");
    // copy constructor
    Mystring(const Mystring& source); // deep copy
    // Move constructor
    Mystring(Mystring&& source); // source refers to a temp object, and we
    // will be nulling out its ptr hence no const.
    
    // Destructor
    ~Mystring();
    
    // move assignment
    Mystring& operator=(Mystring&& rhs);
    // copy assignment
    Mystring& operator=(const Mystring& rhs);
    
    
    // operator [], returning ref so you can use it on lhs of assignment too
    char& operator[](size_t index);
    // unary negation
    Mystring operator-() const; // won't change this object hence const
    //unary +
    Mystring operator+() const;
    Mystring& operator++(); // pre increment
    Mystring operator++(int); // post increment.
    Mystring& operator--(); // pre decrement.
    Mystring operator--(int); // post decrement.
    // concatenation with +=
    Mystring& operator+=(const Mystring& rhs);
    
    // length(), returns size
    size_t length();
};

class OutOfBoundsException:public std::exception{
public:
    virtual const char* what();
};



#endif