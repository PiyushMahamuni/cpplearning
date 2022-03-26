#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring{
    //return concatenated strign
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
    
    //test for equality
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);
    
    //test for inequality
    friend bool operator!=(const Mystring& lhs, const Mystring& rhs);
    
    //comparison
    friend bool operator<(const Mystring& lhs, const Mystring& rhs);
    
    //comparison
    friend bool operator>(const Mystring& lhs, const Mystring& rhs);
    
    //inserting into stream
    friend std::ostream& operator<<(std::ostream& os, const Mystring& obj);
    
    //extracting from stream
    friend std::istream& operator>>(std::istream& is, Mystring& obj);
    
private:
    unsigned len;
    char *str;

public:
    
    //Constructors
    Mystring(char *source=nullptr);     //no args, c-string arg
    Mystring(char source);              //char arg
    Mystring(const Mystring& source);   //copy
    Mystring(Mystring&& source);        //move
    
    //overloading operators
    Mystring& operator=(Mystring&& rhs);        //Move assignment
    Mystring& operator=(const Mystring& rhs);   //copy assignment
    Mystring& operator+=(const Mystring& rhs);  //appending rhs to this
    Mystring& operator<<(const Mystring& rhs);  //appending cont. to this string like inserting to stream
    Mystring operator-()const;                  //return lowercase
    Mystring operator*(unsigned num);           //Multiply this string n times and return it
    Mystring& operator*=(unsigned num);         //Multiply this and store in this
    Mystring& operator++();                     //pre increment, converts to uppercase
    Mystring operator++(int);                   //post increment, returns this and then converts

    //destructor
    ~Mystring();
};

#endif