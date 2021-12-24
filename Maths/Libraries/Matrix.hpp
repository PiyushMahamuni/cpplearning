#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <exception>

namespace Math
{

    // CLASS ROW
    class Matrix;

    // CLASS MATRIX
    class Matrix
    {
    private:
        bool undef;
        bool transposed;
        unsigned int rows;
        unsigned int columns;
        unsigned int row1;
        unsigned int row2;
        unsigned int col1;
        unsigned int col2;
        float *matrix;

    public:
        Matrix(const unsigned int &rows, const unsigned int &columns);
        Matrix(const float &scalar);
        Matrix(const Matrix &source);
        Matrix(const Matrix &source, const unsigned int &row1, const unsigned int &row2, const unsigned int &col1, const unsigned int &col2, bool sub_matrix = false);
        Matrix(Matrix &&source);
        Matrix operator[](unsigned int ind);
        const Matrix at(unsigned int ind) const;
        bool operator==(const Matrix &rhs) const;
        Matrix &operator=(const Matrix &rhs);
        Matrix &operator=(const float &scalar);
        Matrix operator*(const float &scalar)const;
        Matrix operator*(const Matrix& rhs)const;
        Matrix &operator*=(const float &scalar);
        Matrix operator+(const Matrix &rhs)const;
        Matrix& operator+=(const Matrix& rhs);
        void print(std::ostream &os = std::cout) const;
        Matrix &inplace_transpose();
        Matrix transpose()const;

        // Destructor
        ~Matrix();
    };

    // EXCEPTIONS
    class ZeroIndexEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Matrix index starts from 1!";
        }
    };
    class OutOfBoundsIndexEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Matrix index is out of bounds!";
        }
    };
    class IncampatibleMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Matrix sizes aren't compatible!";
        }
    };
    class SubMatrixIsMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Submatrix trying to be created is the same as the Matrix it is being created from!";
        }
    };
    class UndefinedMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "One of the matrix from given expression is undefined!";
        }
    };
    class NotScalarMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Assignment of a scalar is only permitted with 1x1 matrices!";
        }
    };
};

#endif