#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_

#include <iostream>

class I_Printable{
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
    virtual void print(std::ostream& os) const = 0;
    // a pure virtual function that doesn't change I_Printable objects
    virtual ~I_Printable() = default;
};


//friend function to insert any object that conforms to I_Printable interface
//onto an output stream
std::ostream& operator<<(std::ostream& os, const I_Printable& obj){
    obj.print(os);
    return os;
}
#endif