#ifndef _QUTERNION_CPP_
#define _QUTERNION_CPP_
#include "Quaternion.hpp"

// constructors ---

// default constructor
Quaternion::Quaternion() : scalar{0}, vector{3, 1}
{
}

// parametrized constructor
Quaternion::Quaternion(const float &s, const float &x, const float &y, const float &z) : scalar{s}
{
    vector[1] = x;
    vector[2] = y;
    vector[3] = z;
}

Quaternion::Quaternion(const float &s, const Matrix &vec) : scalar{s}
{
    if (vec.col2 - vec.col1 != 1 || vec.row2 - vec.row1 != 3)
        throw NotColumnVectorInR3();
    vector = vec;
}

// copy constructor
Quaternion::Quaternion(const Quaternion &source) : scalar{source.scalar}, vector{source.vector}
{
}

// move constructor
Quaternion::Quaternion(const Quaternion &&source) : scalar{source.scalar}, vector{std::move(source.vector)}
{
}

// ---

// assignments ---

// copy assignment
Quaternion &Quaternion::operator=(const Quaternion &rhs)
{
    scalar = rhs.scalar;
    vector = rhs.vector;
    return *this;
}

// move assignment
Quaternion &Quaternion::operator=(Quaternion &&rhs)
{
    scalar = rhs.scalar;
    vector = std::move(rhs.vector);
    return *this;
}

// augmented assignments
Quaternion &Quaternion::operator+=(const Quaternion &rhs)
{
    scalar += rhs.scalar;
    vector += rhs.vector;
    return *this;
}

Quaternion &Quaternion::operator+=(const float &s)
{
    scalar += s;
    return *this;
}

Quaternion &Quaternion::operator-=(const Quaternion &rhs)
{
    scalar -= rhs.scalar;
    vector -= rhs.vector;
    return *this;
}

Quaternion &Quaternion::operator-=(const float &s)
{
    scalar -= s;
    return *this;
}

Quaternion &Quaternion::operator*=(const Quaternion &rhs)
{
    float temp{scalar};
    scalar = scalar * rhs.scalar - Matrix::dot(vector, rhs.vector);
    vector = rhs.vector * temp + vector * rhs.scalar + Matrix::cross(vector, rhs.vector);
    return *this;
}

Quaternion &Quaternion::operator*=(const float &s)
{
    scalar *= s;
    vector *= s;
    return *this;
}

// ---

// logical operators

bool Quaternion::operator==(const Quaternion &rhs) const
{
    return scalar == rhs.scalar && vector == rhs.vector;
}

bool Quaternion::operator!=(const Quaternion &rhs) const
{
    return scalar != rhs.scalar || vector != rhs.vector;
}

// ---

// subscript operator and at method ---

float &Quaternion::operator[](const unsigned int &ind)
{
    if (ind > 4 || ind == 0)
        throw Quaternion::OutOfBoundsEXCEPTION();
    if (ind == 0)
        return scalar;
    if (vector.transposed)
        return vector.matrix[vector.col1 * vector.columns + vector.row1 + ind - 1];
    return vector.matrix[vector.row1 * vector.columns + vector.col1 + ind - 1];
}

const float &Quaternion::at(const unsigned int &ind) const
{
    if (ind > 4 || ind == 0)
        throw Quaternion::OutOfBoundsEXCEPTION();
    if (ind == 0)
        return scalar;
    if (vector.transposed)
        return vector.matrix[vector.col1 * vector.columns + vector.row1 + ind - 1];
    return vector.matrix[vector.row1 * vector.columns + vector.col1 + ind - 1];
}

// ---

// Arithmetic operations

Quaternion Quaternion::operator*(const Quaternion &rhs) const
{
    return Quaternion{scalar * rhs.scalar - Matrix::dot(vector, rhs.vector), rhs.vector * scalar + vector * rhs.scalar + Matrix::cross(vector, rhs.vector)};
}

Quaternion Quaternion::operator*(const float &s) const
{
    return Quaternion{scalar * s, vector * s};
}

Quaternion Quaternion::operator+(const Quaternion &rhs) const
{
    return Quaternion{scalar + rhs.scalar, vector + rhs.vector};
}

Quaternion Quaternion::operator+(const float &s) const
{
    return Quaternion{scalar + s, vector};
}

Quaternion Quaternion::operator-(const Quaternion &rhs) const
{
    return Quaternion(scalar - rhs.scalar, vector - rhs.vector);
}

Quaternion Quaternion::operator-(const float &s) const
{
    return Quaternion{scalar - s, vector};
}

Quaternion Quaternion::operator-() const
{
    return Quaternion{-scalar, -vector};
}
// ---

// others

void Quaternion::print(std::ostream &os) const
{
    os << "{ " << scalar << ", " << ((Matrix *)&vector)->inplace_transpose() << " }";
    ((Matrix *)&vector)->inplace_transpose();
}

std::ostream &operator<<(std::ostream &os, const Quaternion &obj)
{
    obj.print(os);
    return os;
}
// ---

#endif