#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <exception>

namespace Math{
    
    // CLASS ROW
    template <unsigned int n, unsigned int m>
    class Row;

    // CLASS MATRIX
    template <unsigned int n, unsigned int m>
    class Matrix{
    private:
        bool undef;
        bool transposed;
        float matrix[n][m]{};
        const unsigned int rows{n};
        const unsigned int columns{m};
    
    public:
        Matrix();
        Matrix(const Matrix& source);
        Matrix(Matrix&& source);
        template<unsigned int a, unsigned int b>
        Matrix(const Row<a, b>& source);
        Matrix(Row<n, m>&& source);
        Row<n, m> operator[](const unsigned int& row);
        const Row<n, m> at(const unsigned int& row)const;
        void print(std::ostream& os = std::cout)const;
        Matrix<n, m>& inplace_transpose();
    
    friend class Row<n, m>;
    };

    template <unsigned int n, unsigned int m>
    std::ostream& operator<<(std::ostream& os, const Math::Matrix<n, m>& matrix){
        matrix.print(os);
        return os;
    }

    // CLASS ROW
    template <unsigned int n, unsigned int m>
    class Row{
    private:
        Matrix<n, m>* matrix;
        const unsigned int row;
        const bool transposed;
    public:
        Row(Matrix<n, m>* const matrix, const unsigned int& row);
        float& operator[](const unsigned int& ind);
        const float& at(const unsigned int& ind) const;
        Row& operator=(const Row& rhs);
        Row operator*(const float& rhs) const;
        void print(std::ostream& os = std::cout) const;

        ~Row();
    };

    template <unsigned int n, unsigned int m>
    std::ostream& operator<<(std::ostream& os, const Math::Row<n, m>& row){
        row.print(os);
        return os;
    }

    // EXCEPTIONS
    class ZeroIndexEXCEPTION : public std::exception{
    public:
        virtual const char* what(){
            return "Matrix index starts from 1!";
        }
    };
    class OutOfBoundsIndexEXCEPTION : public std::exception{
    public:
        virtual const char* what(){
            return "Matrix index is out of bounds!";
        }
    };
    class IncampatibleMatrixEXCEPTION : public std::exception{
    public:
        virtual const char* what(){
            return "Matrix sizes aren't the same!";
        }
    };
};

#endif