#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_
#include "Matrix.hpp"
// CLASS MATRIX

// creates new matrix - primary creation
Matrix::Matrix(const unsigned int &rows, const unsigned int &columns)
    : undef{false}, transposed{false}, rows{rows}, columns{columns},
      row1{0}, row2{rows}, col1{0}, col2{columns}, matrix{new float[rows * columns]{}}
{
}

// creates a 1*1 matrix - primary creation
Matrix::Matrix(const float &scalar)
    : undef{false}, transposed{false}, rows{1},
      columns{1}, row1{0}, row2{1}, col1{0}, col2{1},
      matrix{new float}
{
    *matrix = scalar;
}

// creates new matrix - secondary creation
Matrix::Matrix(const Matrix &source)
    : undef{source.undef}, transposed{source.transposed},
      rows{source.row2 - source.row1},
      columns{source.col2 - source.col1}, row1{0}, row2{rows},
      col1{0}, col2{columns},
      matrix{(undef) ? nullptr : new float[rows * columns]}
{
    if (!undef)
    {
        for (unsigned int i{}; i < rows; i++)
        {
            for (unsigned int j{}; j < columns; j++)
                matrix[i * columns + j] = source.matrix[(source.row1 + i) * source.columns + source.col1 + j];
        }
    }
}

// creates a submatrix. the pointer matrix is inherited as is from source object while the limiting values of rows and
// columns are passed as arguments or could create a new matrix as well based on default bool para, sub_matrix
Matrix::Matrix(const Matrix &source, const unsigned int &row1,
               const unsigned int &row2, const unsigned int &col1,
               const unsigned int &col2, bool sub_matrix)
    : undef{source.undef || (row2 - row1 == source.rows && col2 - col1 == source.columns)},
      transposed{source.transposed},
      rows{sub_matrix ? source.rows : row2 - row1},
      columns{sub_matrix ? source.columns : col2 - col1},
      row1{sub_matrix ? row1 + source.row1 : 0},
      row2{sub_matrix ? row2 + source.row1 : rows},
      col1{sub_matrix ? col1 + source.col1 : 0},
      col2{sub_matrix ? col2 + source.col1 : columns},
      matrix{sub_matrix ? source.matrix : (undef ? nullptr : new float[rows * columns])}
{
    if (!source.undef && undef)
    {
        throw SubMatrixIsMatrixEXCEPTION();
    }
    if (!sub_matrix && !undef)
    {
        const unsigned int _rows_{row2 - row1};
        const unsigned int _cols_{col2 - col1};
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + i] = source.matrix[(j + source.col1) * source.columns + source.row1 + i];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] = source.matrix[(i + source.row1) * source.columns + source.col1 + j];
    }
}

Matrix::Matrix(Matrix &&source) : undef{source.undef}, transposed{source.transposed}, rows{source.rows}, columns{source.columns},
                                  row1{source.row1}, row2{source.row2}, col1{source.col1}, col2{source.col2}, matrix{source.matrix}
{
    source.matrix = nullptr;
}

Matrix::~Matrix()
{
    if (row2 - row1 == rows && col2 - col1 == columns) // means this was the Matrix object that allocated this memory
        delete[] matrix;
}

Matrix &Matrix::inplace_transpose()
{
    transposed = !transposed;
    unsigned int temp{row1};
    row1 = col1;
    col1 = temp;
    temp = row2;
    row2 = col2;
    col2 = temp;
    return *this;
}

Matrix Matrix::transpose() const
{
    Matrix obj{*this};
    return obj.inplace_transpose();
}

Matrix Matrix::sub_mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2)
{
    return Matrix{*this, r1, r2, c1, c2, true};
}

Matrix Matrix::mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2) const
{
    return Matrix{*this, r1, r2, c1, c2};
}

const Matrix Matrix::size() const
{
    Matrix size{1, 2};
    size[1] = row2 - row1;
    size[2] = col2 - col1;
    return size;
}

Matrix Matrix::operator[](unsigned int ind)
{
    if (ind == 0)
        throw ZeroIndexEXCEPTION();
    if (row1 == row2 - 1)
    {
        if (ind > col2 - col1)
            throw OutOfBoundsIndexEXCEPTION();
        return Matrix{*this, 0, 1, ind - 1, ind, true};
    }
    if (col1 == col2 - 1)
    {
        if (ind > row2 - row1)
            throw OutOfBoundsIndexEXCEPTION();
        return Matrix{*this, ind - 1, ind, 0, 1, true};
    }
    return Matrix{*this, ind - 1, ind, col1, col2, true};
}

Matrix Matrix::at(unsigned int ind) const
{
    if (ind == 0)
        throw ZeroIndexEXCEPTION();
    else if (transposed ? ind > columns : ind > rows)
        throw OutOfBoundsIndexEXCEPTION();
    if (row1 == row2 - 1)
    {
        return Matrix{*this, 0, 1, ind - 1, ind};
    }
    if (col1 == col2 - 1)
    {
        return Matrix{*this, ind - 1, ind, 0, 1};
    }
    return Matrix{*this, ind - 1, ind, col1, col2};
}

// STATIC VARIABLE THRSH - ALLOWABLE DIFFERENCE BETWEEN ELEMENTS BEFORE THEY ARE CONSIDERED EQUAL
float Matrix::thresh{0.00001};
bool Matrix::operator==(const Matrix &rhs) const
{
    if (this == &rhs)
        return true;
    if (col2 - col1 != rhs.col2 - rhs.col1 || row2 - row1 != rhs.row2 - rhs.row1)
        return false;
    if (matrix == rhs.matrix)
    {
        if (row1 == rhs.row1 && row2 == rhs.row2 && col1 == rhs.col1 && col2 == rhs.col2)
            return true;
        else
            return false;
    }
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    float temp;
    if (transposed == rhs.transposed)
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                {
                    temp = matrix[(j + col1) * columns + row1 + j] - rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + j];
                    if (temp < -Matrix::thresh || temp > Matrix::thresh)
                        return false;
                }
        else
            for (unsigned int i{0}; i < _rows_; i++)
                for (unsigned int j{0}; j < _cols_; j++)
                {
                    temp = matrix[(i + row1) * rows + col1 + j] - rhs.matrix[(i + rhs.row1) * rhs.rows + j + rhs.col1];
                    if (temp < -Matrix::thresh || temp > Matrix::thresh)
                        return false;
                }
    }
    else
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                {
                    temp = matrix[(j + col1) * columns + row1 + j] - rhs.matrix[(i + row1) * columns + col1 + j];
                    if (temp < -Matrix::thresh || temp > Matrix::thresh)
                        return false;
                }
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                {
                    temp = matrix[(i + row1) * columns + col1 + j] - rhs.matrix[(j + col1) * columns + row1 + i];
                    if (temp < -Matrix::thresh || temp > Matrix::thresh)
                        return false;
                }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &rhs) const
{
    return !(*this == rhs);
}

Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (rhs.undef)
        throw UndefinedMatrixEXCEPTION();
    if (*this == rhs)
        return *this;
    // check if *this and rhs have compatible sizes
    if (row2 - row1 != rhs.row2 - rhs.row1 || col2 - col1 != rhs.col2 - rhs.col1)
        throw IncompatibleMatrixEXCEPTION();
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    if (transposed == rhs.transposed)
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + i] = rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] = rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
    else
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + i] = rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] = rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
    }
    return *this;
}

Matrix &Matrix::reassign(const Matrix &source)
{
    if (source.undef)
        throw UndefinedMatrixEXCEPTION();
    if (this == &source)
        return *this;
    // delete the matrix if this owns it
    if (row2 - row1 == rows && col2 - col1 == columns)
        delete[] matrix;
    row1 = col1 = 0;
    rows = row2 = source.row2 - source.row1;
    columns = col2 = source.col2 - source.col1;
    transposed = source.transposed;
    matrix = new float[rows * columns];
    if (transposed)
        for (unsigned int i{}; i < rows; i++)
            for (unsigned int j{}; j < columns; j++)
                matrix[j * columns + i] = source.matrix[(j + source.col1) * columns + source.row1 + i];
    else
        for (unsigned int i{}; i < rows; i++)
            for (unsigned int j{}; j < columns; j++)
                matrix[i * columns + j] = source.matrix[(i + source.row1) * columns + source.col1 + j];
    return *this;
}

Matrix &Matrix::reassign(Matrix &&source)
{
    // see if rhs is undef
    if (source.undef)
        throw UndefinedMatrixEXCEPTION();
    if (this == &source)
        return *this;
    if (row2 - row1 != source.row2 - source.row1 || col2 - col1 != source.col2 - source.col1)
        throw IncompatibleMatrixEXCEPTION();
    // delete the matrix array if this owns it
    if (row2 - row1 == rows && col2 - col1 == columns)
        delete[] matrix;
    // copy all attributes
    undef = source.undef;
    transposed = source.transposed;
    row1 = source.row1;
    row2 = source.row2;
    rows = source.rows;
    col1 = source.col1;
    col2 = source.col2;
    columns = source.columns;
    matrix = source.matrix;
    source.matrix = nullptr;
    return *this;
}

Matrix &Matrix::operator=(const float &scalar)
{
    // check if the matrix is already a scalar
    if (row2 - row1 == 1 && col2 - col1 == 1)
    {
        if (transposed)
            matrix[col1 * columns + row1] = scalar;
        else
            matrix[row1 * columns + col1] = scalar;
    }
    else
    {
        throw NotScalarMatrixEXCEPTION();
    }
    return *this;
}

Matrix Matrix::operator*(const float &scalar) const
{
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    Matrix obj{_rows_, _cols_};
    if (transposed)
        for (unsigned int i{}; i < _rows_; i++)
            for (unsigned int j{}; j < _cols_; j++)
                obj.matrix[i * _cols_ + j] = scalar * matrix[(j + col1) * columns + row1 + j];
    else
        for (unsigned int i{}; i < _rows_; i++)
            for (unsigned int j{}; j < _cols_; j++)
                obj.matrix[i * _cols_ + j] = scalar * matrix[(i + row1) * columns + col1 + j];
    return obj;
}

Matrix &Matrix::operator*=(const float &scalar)
{
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    if (transposed)
        for (unsigned int i{}; i < _rows_; i++)
            for (unsigned int j{}; j < _cols_; j++)
                matrix[(j + col1) * columns + row1 + i] *= 2;
    else
        for (unsigned int i{}; i < _rows_; i++)
            for (unsigned int j{}; j < _cols_; j++)
                matrix[(i + row1) * columns + col1 + j] *= 2;
    return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) const
{
    if (undef || rhs.undef)
        throw UndefinedMatrixEXCEPTION();
    // check if this is a scalar matrix
    if (row2 - row1 == 1 && col2 - col1 == 1)
    {
        if (transposed)
            return rhs * matrix[col1 * columns + row1];
        else
            return rhs * matrix[row1 * columns + col1];
    }
    // check if rhs is a scalar matrix
    if (rhs.row2 - rhs.row1 == 1 && rhs.col2 - rhs.col1 == 1)
    {
        if (rhs.transposed)
            return (*this) * rhs.matrix[rhs.col1 * rhs.columns + rhs.row1];
        else
            return (*this) * rhs.matrix[rhs.row1 * rhs.columns + rhs.col1];
    }

    // check if *this and rhs have compatible sizes
    if (col2 - col1 != rhs.row2 - rhs.row1)
        throw IncompatibleMatrixEXCEPTION();
    Matrix product{row2 - row1, rhs.col2 - rhs.col1};
    const unsigned int _cols_{col2 - col1};
    if (product.columns == 1)
    {
        if (rhs.transposed)
            for (unsigned int j{}; j < _cols_; j++)
                product += Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[rhs.col1 * rhs.columns + rhs.row1 + j];
        else
            for (unsigned int j{}; j < _cols_; j++)
                product += Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(j + rhs.row1) * rhs.columns + rhs.col1];
        return product;
    }
    if (rhs.transposed)
    {
        for (unsigned int i{}; i < product.columns; i++)
        {
            Matrix column{product, product.row1, product.row2, i, i + 1, true};
            for (unsigned int j{}; j < _cols_; j++)
                column += Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(i + rhs.col1) * rhs.columns + rhs.row1 + j];
        }
    }
    else
    {
        for (unsigned int i{}; i < product.columns; i++)
        {
            Matrix column{product, product.row1, product.row2, i, i + 1, true};
            for (unsigned int j{}; j < _cols_; j++)
                column += Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(j + rhs.row1) * rhs.columns + rhs.col1 + i];
        }
    }
    return product;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
    if (undef || rhs.undef)
        throw UndefinedMatrixEXCEPTION();
    if (col2 - col1 != rhs.row2 - rhs.row1)
        throw IncompatibleMatrixEXCEPTION();
    else if (col2 - col1 != rhs.col2 - rhs.col1)
        throw IncompatibleMatrixEXCEPTION2();
    this->reassign(Matrix{(*this) * rhs});
    return *this;
}

Matrix Matrix::operator/(const float &scalar) const
{
    float recp{1 / scalar};
    return (*this) * recp;
}

Matrix &Matrix::operator/=(const float &scalar)
{
    float recp{1 / scalar};
    return (*this) *= recp;
}

Matrix Matrix::operator+(const Matrix &rhs) const
{
    // check if *this and rhs have compatible sizes
    if (row2 - row1 != rhs.row2 - rhs.row1 || col2 - col1 != rhs.col2 - rhs.col1)
        throw IncompatibleMatrixEXCEPTION();
    Matrix obj{*this}; // copy of this object
    if (transposed == rhs.transposed)
    {
        if (transposed)
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[j * obj.columns + i] += rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
        else
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[i * obj.columns + j] += rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
    }
    else
    {
        if (transposed)
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[j * obj.columns + i] += rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
        else
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[i * obj.columns + j] += rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
    }
    return obj;
}

Matrix &Matrix::operator+=(const Matrix &rhs)
{
    // check for compatibility
    if (col2 - col1 != rhs.col2 - rhs.col1 || row2 - row1 != rhs.row2 - rhs.row1)
        throw IncompatibleMatrixEXCEPTION();
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    if (transposed == rhs.transposed)
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + j] += rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] += rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
    }
    else
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + j] += matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] += matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &rhs) const
{
    // check if *this and rhs have compatible sizes
    if (row2 - row1 != rhs.row2 - rhs.row1 || col2 - col1 != rhs.col2 - rhs.col1)
        throw IncompatibleMatrixEXCEPTION();
    Matrix obj{*this}; // copy of this object
    if (transposed == rhs.transposed)
    {
        if (transposed)
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[j * obj.columns + i] -= rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
        else
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[i * obj.columns + j] -= rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
    }
    else
    {
        if (transposed)
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[j * obj.columns + i] -= rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
        else
            for (unsigned int i{}; i < obj.rows; i++)
                for (unsigned int j{}; j < obj.columns; j++)
                    obj.matrix[i * obj.columns + j] -= rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
    }
    return obj;
}

Matrix &Matrix::operator-=(const Matrix &rhs)
{
    // check for compatibility
    if (col2 - col1 != rhs.col2 - rhs.col1 || row2 - row1 != rhs.row2 - rhs.row1)
        throw IncompatibleMatrixEXCEPTION();
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    if (transposed == rhs.transposed)
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + j] -= rhs.matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] -= rhs.matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
    }
    else
    {
        if (transposed)
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(j + col1) * columns + row1 + j] -= matrix[(i + rhs.row1) * rhs.columns + rhs.col1 + j];
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                    matrix[(i + row1) * columns + col1 + j] -= matrix[(j + rhs.col1) * rhs.columns + rhs.row1 + i];
    }
    return *this;
}

Matrix Matrix::operator-() const
{
    return Matrix{*this} * -1;
}

void Matrix::print(std::ostream &os) const
{
    // check if this is a vector or a scalar at this point
    if (row1 == row2 - 1)
    {
        if (col1 == col2 - 1)
        { // at an element
            if (transposed)
                os << matrix[col1 * columns + row1];
            else
                os << matrix[row1 * columns + col1];
            return;
        }
        // at the row vector
        os << "[ ";
        const unsigned int last_col{col2 - 1};
        if (transposed)
            for (unsigned int i{col1}; i < col2; i++)
                os << matrix[i * columns + row1] << ((i == last_col) ? " ]" : ", ");
        else
            for (unsigned int i{col1}; i < col2; i++)
                os << matrix[row1 * columns + i] << ((i == last_col) ? " ]" : ", ");
        return;
    }
    else if (col1 == col2 - 1)
    {
        os << "[ ";
        const unsigned int last_row{row2 - 1};

        if (transposed)
            for (unsigned int i{row1}; i < row2; i++)
                os << matrix[col1 * columns + i] << ((i == last_row) ? "]  " : ",\n  ");
        else
            for (unsigned int i{row1}; i < row2; i++)
                os << matrix[i * columns + col1] << ((i == last_row) ? " ]" : ",\n  ");
        return;
    }

    os << "\n{ ";
    const unsigned int _rows_{row2 - row1};
    for (unsigned int i{1}; i <= _rows_; i++)
    {
        ((Matrix *)this)->operator[](i).print(os);
        os << ((i == _rows_) ? " }" : ",\n  ");
    }
    return;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    matrix.print(os);
    return os;
}

float Matrix::norm() const
{
    // check if *this is a vector
    if (row2 - row1 == 1)
    {
        float nm{}, temp;
        if (transposed)
            for (unsigned int i{col1}; i < col2; i++)
            {
                temp = matrix[i * columns + row1];
                nm += temp * temp;
            }
        else
            for (unsigned int i{col1}; i < col2; i++)
            {
                temp = matrix[row1 * columns + i];
                nm += temp * temp;
            }
        return sqrt(nm);
    }
    else if (col2 - col1 == 1)
    {
        float nm{}, temp;
        if (transposed)
            for (unsigned int i{row1}; i < row2; i++)
            {
                temp = matrix[col1 * columns + i];
                nm += temp * temp;
            }
        else
            for (unsigned int i{row1}; i < row2; i++)
            {
                temp = matrix[i * columns + col1];
                nm += temp * temp;
            }
        return sqrt(nm);
    }
    throw NotVectorEXCEPTION();
}

// STATIC FUNCTIONS
Matrix Matrix::J(const Matrix &v)
{
    if (v.col2 - v.col1 != 1 && v.row2 - v.row1 != 3)
        throw Not3By1VectorEXCEPTION();
    Matrix Jofv{3, 3};
    for (unsigned int i{}; i < Jofv.rows; i++)
        Jofv.matrix[i * Jofv.columns + i] = 0;
    if (v.transposed)
    {
        Jofv.matrix[1] = -(Jofv.matrix[3] = v.matrix[v.col1 * v.columns + v.row1 + 2]);
        Jofv.matrix[6] = -(Jofv.matrix[2] = v.matrix[v.col1 * v.columns + v.row1 + 1]);
        Jofv.matrix[5] = -(Jofv.matrix[7] = v.matrix[v.col1 * v.columns + v.row1]);
    }
    else
    {
        Jofv.matrix[1] = -(Jofv.matrix[3] = v.matrix[(v.row1 + 2) * v.columns + v.col1]);
        Jofv.matrix[6] = -(Jofv.matrix[2] = v.matrix[(v.row1 + 1) * v.columns + v.col1]);
        Jofv.matrix[5] = -(Jofv.matrix[7] = v.matrix[v.row1 * v.columns + v.col1]);
    }
    return Jofv;
}

// Returns identity matrix of size nxn
Matrix Matrix::I(const unsigned int& n)
{
    Matrix id {n, n};
    for(unsigned int i{}; i<n; i++)
        id.matrix[i * n + i] = 1;
    return id;
}

Matrix Matrix::cross(const Matrix &a, const Matrix &b)
{
    return Matrix::J(a) * b;
}

float Matrix::dot(const Matrix &a, const Matrix &b)
{

    const unsigned int rows{a.row2 - a.row1}, cols{a.col2 - a.col1};
    if (rows != b.row2 - b.row1 || cols != b.col2 - b.col1)
        throw IncompatibleMatrixEXCEPTION();
    if (rows != 1 && cols != 1)
        throw NotVectorEXCEPTION();
    float product{0};
    if (rows == 1)
    {
        if (a.transposed == b.transposed)
        {
            if (a.transposed)
                for (unsigned int i{}; i < cols; i++)
                    product += a.matrix[(a.col1 + i) * a.columns + a.row1] * b.matrix[(b.col1 + i) * b.columns + b.row1];
            else
                for (unsigned int i{}; i < cols; i++)
                    product += a.matrix[a.row1 * a.columns + a.col1 + i] * b.matrix[b.row1 * b.columns + b.col1 + i];
        }
        else
        {
            if (a.transposed)
                for (unsigned int i{}; i < cols; i++)
                    product += a.matrix[(a.col1 + i) * a.columns + a.row1] * b.matrix[b.row1 * b.columns + b.col1 + i];
            else
                for (unsigned int i{}; i < cols; i++)
                    product += a.matrix[a.row1 * a.columns + a.col1 + i] * b.matrix[(b.col1 + i) * b.columns + b.row1];
        }
    }
    else
    {
        if (a.transposed == b.transposed)
        {
            if (a.transposed)
                for (unsigned int i{}; i < rows; i++)
                    product += a.matrix[a.col1 * a.columns + a.row1 + i] * b.matrix[b.col1 * b.columns + b.row1 + i];
            else
                for (unsigned int i{}; i < rows; i++)
                    product += a.matrix[(a.row1 + i) * a.columns + a.col1] * b.matrix[(b.row1 + i) * b.columns + b.col1];
        }
        else
        {
            if (a.transposed)
                for (unsigned int i{}; i < rows; i++)
                    product += a.matrix[a.col1 * a.columns + a.row1 + i] * b.matrix[(b.row1 + i) * b.columns + b.col1];
            else
                for (unsigned int i{}; i < rows; i++)
                    product += a.matrix[(a.row1 + i) * a.columns + a.col1] * b.matrix[b.col1 * b.columns + b.row1 + i];
        }
    }
    return product;
}

#endif