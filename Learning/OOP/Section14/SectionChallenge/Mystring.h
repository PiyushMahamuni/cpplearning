#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& obj);
    friend std::istream& operator>>(std::istream& is, Mystring& obj);
private:
    char *str;
    unsigned len;
public:

    //Constructors
    Mystring(char *source = nullptr); //constructing Mystring from c style string, no args consturctor
    Mystring(char source); //constructing string from a single character rvalue/lvalue
    Mystring(const Mystring& source); //copy constructor
    Mystring(Mystring&& source); //Move constructor
    
    //Destructor
    ~Mystring();
    
    //overloading operators as member methods
    bool operator==(const Mystring& rhs)const;//check for equality
    bool operator!=(const Mystring& rhs)const;//check for inequality
    bool operator<(const Mystring& rhs)const;//comparing string lengths
    bool operator>(const Mystring& rhs)const;//comparing string lengths
    Mystring& operator=(const Mystring& rhs);//assignment, copy ver
    Mystring& operator=(Mystring&& rhs);//assignment, move ver
    Mystring operator+(const Mystring& rhs)const;//return concatenated string
    void operator+=(const Mystring& rhs);//concatenate rhs to this string
    Mystring& operator<<(const Mystring& rhs);//appending to this string
    Mystring operator-()const;
};

#endif