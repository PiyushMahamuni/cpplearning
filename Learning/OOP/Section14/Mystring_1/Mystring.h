#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

class Mystring{
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);    //concatenate two strings
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);       //compare two strings for equality
    friend std::ostream& operator<<(std::ostream& os, const Mystring& obj); //inserting into output stream
    friend std::istream& operator>>(std::istream& is, Mystring& obj);       //extracting from input stream
    

    
private:
    char *str;
    unsigned len;

public:
    //friend class Mystring;          //friend of itself

    Mystring(char source[] = nullptr);  //1 and no arg consturctor
    Mystring(char source);             //1 arg constructor

    
    Mystring(const Mystring &source);//copy constructor
    Mystring(Mystring &&source);//Move constructor
    
    ~Mystring();//Destructor
    
    //overloaded assignment operator functions
    Mystring& operator=(const Mystring& rhs);   //overloaded operator assignment, copy ver
    Mystring& operator=(Mystring&& rhs);        //overloaded operator assignment, move ver
    
    //overloading unary operators
    Mystring operator!() const;                 //overloaded to toggle cases and return, this remains same
    Mystring operator++();                      //overloaded to convert to upper case and return
    Mystring operator--();                      //overloaded to convert to lower case and return
    
    //overloading binary operators
    bool operator<(const Mystring& rhs) const;        //for less than
    bool operator>(const Mystring& rhs) const;        //for greater than
    
    Mystring& operator<<(const Mystring& rhs);        //inserting into object
    
    void display()const;//to display object's info
};
#endif