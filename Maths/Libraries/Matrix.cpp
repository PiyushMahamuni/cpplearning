#include "Matrix.hpp"

// CLASS MATRIX

// creates new matrix - primary creation
Math::Matrix::Matrix(const unsigned int &rows, const unsigned int &columns)
    : undef{false}, transposed{false}, rows{rows}, columns{columns},
      row1{0}, row2{rows}, col1{0}, col2{columns}, matrix{new float[rows * columns]{}}
{
}

// creates a 1*1 matrix - primary creation
Math::Matrix::Matrix(const float &scalar)
    : undef{false}, transposed{false}, rows{1},
      columns{1}, row1{0}, row2{1}, col1{0}, col2{1},
      matrix{new float}
{
    *matrix = scalar;
}

// creates new matrix - secondary creation
Math::Matrix::Matrix(const Matrix &source)
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
Math::Matrix::Matrix(const Matrix &source, const unsigned int &row1,
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
        throw Math::SubMatrixIsMatrixEXCEPTION();
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

Math::Matrix::Matrix(Matrix &&source) : undef{source.undef}, transposed{source.transposed}, rows{source.rows}, columns{source.columns},
                                        row1{source.row1}, row2{source.row2}, col1{source.col1}, col2{source.col2}, matrix{source.matrix}
{
    source.matrix = nullptr;
}

Math::Matrix::~Matrix()
{
    if (row2 - row1 == rows && col2 - col1 == columns) // means this was the Matrix object that allocated this memory
        delete[] matrix;
}

Math::Matrix &Math::Matrix::inplace_transpose()
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

Math::Matrix Math::Matrix::transpose() const
{
    Math::Matrix obj{*this};
    return obj.inplace_transpose();
}

Math::Matrix Math::Matrix::sub_mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2)
{
    return Math::Matrix{*this, r1, r2, c1, c2, true};
}

Math::Matrix Math::Matrix::mat(const unsigned int &r1, const unsigned int &r2, const unsigned int &c1, const unsigned int &c2) const
{
    return Math::Matrix{*this, r1, r2, c1, c2};
}

Math::Matrix Math::Matrix::operator[](unsigned int ind)
{
    if (ind == 0)
        throw Math::ZeroIndexEXCEPTION();
    else if (transposed ? ind > columns : ind > rows)
        throw Math::OutOfBoundsIndexEXCEPTION();
    if (row1 == row2 - 1)
    {
        return Math::Matrix{*this, 0, 1, ind - 1, ind, true};
    }
    if (col1 == col2 - 1)
    {
        return Math::Matrix{*this, ind - 1, ind, 0, 1, true};
    }
    return Matrix{*this, ind - 1, ind, col1, col2, true};
}

const Math::Matrix Math::Matrix::at(unsigned int ind) const
{
    if (ind == 0)
        throw Math::ZeroIndexEXCEPTION();
    else if (transposed ? ind > columns : ind > rows)
        throw Math::OutOfBoundsIndexEXCEPTION();
    if (row1 == row2 - 1)
    {
        return Math::Matrix{*this, 0, 1, ind - 1, ind};
    }
    if (col1 == col2 - 1)
    {
        return Math::Matrix{*this, ind - 1, ind, 0, 1};
    }
    return Matrix{*this, ind - 1, ind, col1, col2};
}

// STATIC VARIABLE THRSH - ALLOWABLE DIFFERENCE BETWEEN ELEMENTS BEFORE THEY ARE CONSIDERED EQUAL
float Math::Matrix::thresh{0.00001};
bool Math::Matrix::operator==(const Matrix &rhs) const
{
    if (this == &rhs)
        return true;
    if (transposed == rhs.transposed)
    {
        if (col2 - col1 != rhs.col2 - rhs.col1 || row2 - row1 != rhs.row2 - rhs.row1)
            return false;
    }
    else
    {
        if (col2 - col1 != rhs.row2 - rhs.row1 || row2 - row1 != rhs.col2 - rhs.col1)
            return false;
    }

    if (matrix == rhs.matrix)
    {
        if (transposed == rhs.transposed)
        {
            if (row1 == rhs.row1 && row2 == rhs.row2 && col1 == rhs.col1 && col2 == rhs.col2)
                return true;
        }
        else
        {
            if (row1 == rhs.col1 && row2 == rhs.col2 && col1 == rhs.row1 && col2 == rhs.row2)
                return true;
        }
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
                    if (temp < -Math::Matrix::thresh || temp > Math::Matrix::thresh)
                        return false;
                }
        else
            for (unsigned int i{0}; i < _rows_; i++)
                for (unsigned int j{0}; j < _cols_; j++)
                {
                    temp = matrix[(i + row1) * rows + col1 + j] - rhs.matrix[(i + rhs.row1) * rhs.rows + j + rhs.col1];
                    if (temp < -Math::Matrix::thresh || temp > Math::Matrix::thresh)
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
                    if (temp < -Math::Matrix::thresh || temp > Math::Matrix::thresh)
                        return false;
                }
        else
            for (unsigned int i{}; i < _rows_; i++)
                for (unsigned int j{}; j < _cols_; j++)
                {
                    temp = matrix[(i + row1) * columns + col1 + j] - rhs.matrix[(j + col1) * columns + row1 + i];
                    if (temp < -Math::Matrix::thresh || temp > Math::Matrix::thresh)
                        return false;
                }
    }
    return true;
}

bool Math::Matrix::operator!=(const Matrix &rhs) const
{
    return !(*this == rhs);
}

Math::Matrix &Math::Matrix::operator=(const Matrix &rhs)
{
    if (rhs.undef)
        throw Math::UndefinedMatrixEXCEPTION();
    if (*this == rhs)
        return *this;
    // check if *this and rhs have compatible sizes
    if (row2 - row1 != rhs.row2 - rhs.row1 || col2 - col1 != rhs.col2 - rhs.col1)
        throw Math::IncompatibleMatrixEXCEPTION();
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

Math::Matrix &Math::Matrix::reassign(const Matrix &source)
{
    if (source.undef)
        throw Math::UndefinedMatrixEXCEPTION();
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

Math::Matrix &Math::Matrix::reassign(Matrix &&source)
{
    // see if rhs is undef
    if (source.undef)
        throw Math::UndefinedMatrixEXCEPTION();
    if (this == &source)
        return *this;
    if (row2 - row1 != source.row2 - source.row1 || col2 - col1 != source.col2 - source.col1)
        throw Math::IncompatibleMatrixEXCEPTION();
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

Math::Matrix &Math::Matrix::operator=(const float &scalar)
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
        throw Math::NotScalarMatrixEXCEPTION();
    }
    return *this;
}

Math::Matrix Math::Matrix::operator*(const float &scalar) const
{
    const unsigned int _rows_{row2 - row1};
    const unsigned int _cols_{col2 - col1};
    Math::Matrix obj{_rows_, _cols_};
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

Math::Matrix &Math::Matrix::operator*=(const float &scalar)
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

Math::Matrix Math::Matrix::operator*(const Matrix &rhs) const
{
    if (undef || rhs.undef)
        throw Math::UndefinedMatrixEXCEPTION();
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
        throw Math::IncompatibleMatrixEXCEPTION();
    Math::Matrix product{row2 - row1, rhs.col2 - rhs.col1};
    const unsigned int _cols_{col2 - col1};
    if (product.columns == 1)
    {
        if (rhs.transposed)
            for (unsigned int j{}; j < _cols_; j++)
                product += Math::Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[rhs.col1 * rhs.columns + rhs.row1 + j];
        else
            for (unsigned int j{}; j < _cols_; j++)
                product += Math::Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(j + rhs.row1) * rhs.columns + rhs.col1];
        return product;
    }
    if (rhs.transposed)
    {
        for (unsigned int i{}; i < product.columns; i++)
        {
            Math::Matrix column{product, product.row1, product.row2, i, i + 1, true};
            for (unsigned int j{}; j < _cols_; j++)
                column += Math::Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(i + rhs.col1) * rhs.columns + rhs.row1 + j];
        }
    }
    else
    {
        for (unsigned int i{}; i < product.columns; i++)
        {
            Math::Matrix column{product, product.row1, product.row2, i, i + 1, true};
            for (unsigned int j{}; j < _cols_; j++)
                column += Math::Matrix{*this, product.row1, product.row2, j, j + 1, true} * rhs.matrix[(j + rhs.row1) * rhs.columns + rhs.col1 + i];
        }
    }
    return product;
}

Math::Matrix &Math::Matrix::operator*=(const Matrix &rhs)
{
    if (undef || rhs.undef)
        throw Math::UndefinedMatrixEXCEPTION();
    if (col2 - col1 != rhs.row2 - rhs.row1)
        throw Math::IncompatibleMatrixEXCEPTION();
    else if (col2 - col1 != rhs.col2 - rhs.col1)
        throw Math::IncompatibleMatrixEXCEPTION2();
    this->reassign(Math::Matrix{(*this) * rhs});
    return *this;
}

Math::Matrix Math::Matrix::operator/(const float &scalar) const
{
    float recp{1 / scalar};
    return (*this) * recp;
}

Math::Matrix &Math::Matrix::operator/=(const float &scalar)
{
    float recp{1 / scalar};
    return (*this) *= recp;
}

Math::Matrix Math::Matrix::operator+(const Matrix &rhs) const
{
    // check if *this and rhs have compatible sizes
    if (row2 - row1 != rhs.row2 - rhs.row1 || col2 - col1 != rhs.col2 - rhs.col1)
        throw Math::IncompatibleMatrixEXCEPTION();
    Math::Matrix obj{*this}; // copy of this object
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

Math::Matrix &Math::Matrix::operator+=(const Matrix &rhs)
{
    // check for compatibility
    if (col2 - col1 != rhs.col2 - rhs.col1 || row2 - row1 != rhs.row2 - rhs.row1)
        throw Math::IncompatibleMatrixEXCEPTION();
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

Math::Matrix Math::Matrix::operator-() const
{
    return Math::Matrix{*this} * -1;
}

void Math::Matrix::print(std::ostream &os) const
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

std::ostream &operator<<(std::ostream &os, const Math::Matrix &matrix)
{
    matrix.print(os);
    return os;
}

float Math::Matrix::norm() const
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
    throw Math::NotVectorEXCEPTION();
}

// STATIC FUNCTIONS
Math::Matrix Math::Matrix::J(const Matrix &v)
{
    if (v.col2 - v.col1 != 1 && v.row2 - v.row1 != 3)
        throw Math::Not1By3VectorEXCEPTION();
    Math::Matrix Jofv{3, 3};
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
