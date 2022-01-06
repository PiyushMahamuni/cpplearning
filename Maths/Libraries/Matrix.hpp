#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <exception>
#include <math.h>

namespace Math
{
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
        static float thresh;

    public:
        Matrix(const unsigned int &rows, const unsigned int &columns);
        Matrix(const float &scalar);
        Matrix(const Matrix &source);
        Matrix(const Matrix &source, const unsigned int &row1, const unsigned int &row2, const unsigned int &col1, const unsigned int &col2, bool sub_matrix = false);
        Matrix(Matrix &&source);
        Matrix operator[](unsigned int ind);
        const Matrix at(unsigned int ind) const;
        bool operator==(const Matrix &rhs) const;
        bool operator!=(const Matrix &rhs) const;
        // changes values of corresponding elements if this and rhs have compatible sizes
        Matrix &operator=(const Matrix &rhs);
        // reassigns this matrix to a new one which may have different size
        Matrix &reassign(const Matrix &source);
        // reassign this matrix reference to the source object
        Matrix &reassign(Matrix&& source);
        // assigns value of scalar if this is an element matrix
        Matrix &operator=(const float &scalar);
        Matrix operator*(const float &scalar) const;
        Matrix operator*(const Matrix &rhs) const;
        Matrix &operator*=(const float &scalar);
        Matrix &operator*=(const Matrix &rhs);
        Matrix operator/(const float &scalar)const;    // unfinished
        Matrix &operator/=(const float &scalar);  // unfinished
        Matrix operator+(const Matrix &rhs) const;
        Matrix &operator+=(const Matrix &rhs);
        Matrix operator-() const;

        // prints this matrix on the passed std::ostream
        void print(std::ostream &os = std::cout) const;

        // transposes *this matrix and then returns it
        Matrix &inplace_transpose();

        // creates a new matrix which is transpose of *this and then returns it
        Matrix transpose() const;

        // creates a sub matrix and any changes to it are also reflected in *this object
        Matrix sub_mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2);

        // creates a sub matrix that is unrelated to *this matrix and changes in it aren't reflected back
        Matrix mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2) const;

        // returns the norm if *this matrix is a vector
        float norm() const;

        // Creates a skew symmetric matrix from a 3x1 matrix
        static Matrix J(const Matrix &v);
        // Computes the determenant of the matrix passed
        static float det(const Matrix& mat);

        // Destructor
        ~Matrix();
    };

    // FUNCTIONS
    

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
    class IncompatibleMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Matrix sizes aren't compatible!";
        }
    };
    class IncompatibleMatrixEXCEPTION2 : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Matrix product of lhs matrix and rhs matrix aren't compatible with current size of lhs matrix!";
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
    class Not1By3VectorEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "The concerned matrix is not a vector in R^3!";
        }
    };
    class NotVectorEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "The concerned matrix is not 1 dimensional, aka vector!";
        }
    };
    class NotSquareMatrixEXCEPTION : public std::exception
    {
    public:
        virtual const char *what()
        {
            return "Cannot compute determinant of non square matrix!";
        }
    };
};

#endif