#ifndef _QUATERNION_H_
#define _QUATERNION_H_
#include "Matrix.cpp"

class Quaternion
{
// friends
friend std::ostream &operator<<(std::ostream &os, const Quaternion &obj);
friend Matrix matrixFromQuaternion(const Quaternion& q);
friend Matrix vectorFromQuaternion(const Quaternion& q);

private:
    float scalar;
    Matrix vector{3, 1};

public:
    // default constructor
    Quaternion();
    // parametrized constructor
    Quaternion(const float &s, const float &x, const float &y, const float &z);
    Quaternion(const float &s, const Matrix &vector);
    // copy constructor
    Quaternion(const Quaternion &source);
    // move constructor
    Quaternion(const Quaternion &&source);

    // copy assignment
    Quaternion &operator=(const Quaternion &source);
    // move assignment
    Quaternion &operator=(Quaternion &&source);

    // equality operator
    bool operator==(const Quaternion &rhs) const;
    // inequality operator
    bool operator!=(const Quaternion &rhs) const;

    // returns reference to element
    float &operator[](const unsigned int &ind);
    // returns constant reference to element
    const float &at(const unsigned int &ind) const;

    // Arithmetic Operators
    Quaternion operator*(const Quaternion &rhs) const;
    Quaternion operator*(const float &s) const;
    Quaternion operator+(const Quaternion &rhs) const;
    Quaternion operator+(const float &s) const;
    Quaternion operator-(const Quaternion &rhs) const;
    Quaternion operator-(const float &s) const;
    Quaternion operator-() const;

    // augmented assignments
    Quaternion &operator+=(const Quaternion &rhs);
    Quaternion &operator+=(const float &s);
    Quaternion &operator-=(const Quaternion &rhs);
    Quaternion &operator-=(const float &s);
    Quaternion &operator*=(const Quaternion &rhs);
    Quaternion &operator*=(const float &s);

    // prints the quaternion onto to given std::ostream
    void print(std::ostream &os = std::cout) const;

    // EXCEPTIONS
    class OutOfBoundsEXCEPTION : public std::exception
    {
        virtual const char *what()
        {
            return "Quaternion index is out of bounds";
        }
    };
    class NotColumnVectorInR3 : public std::exception
    {
        virtual const char *what()
        {
            return "Given matrix in not a column vector in R3";
        }
    };
};

#endif