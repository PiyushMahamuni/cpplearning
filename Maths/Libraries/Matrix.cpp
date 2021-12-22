#include "Matrix.hpp"

// CLASS ROW
template <unsigned int n, unsigned int m>
Math::Row<n, m>::Row(Matrix<n, m>* const matrix, const unsigned int& row):
    matrix{matrix}, row{row}, transposed{matrix->transposed}{

}

// destructor
template <unsigned int n, unsigned int m>
Math::Row<n, m>::~Row(){
    delete matrix;
}

template <unsigned int n, unsigned int m>
float& Math::Row<n, m>::operator[](const unsigned int& ind){
    if(transposed? ind > n : ind > m)
        throw Math::OutOfBoundsIndexEXCEPTION();
    else if (ind == 0)
        throw Math::ZeroIndexEXCEPTION();
    return (transposed ? matrix->matrix[ind-1][row-1]: matrix->matrix[row-1][ind-1]);
}

template<unsigned int n, unsigned int m>
const float& Math::Row<n, m>::at(const unsigned int& ind)const{
    if(transposed ? ind > n : ind > m)
        throw Math::OutOfBoundsIndexEXCEPTION();
    else if (ind == 0)
        throw Math::ZeroIndexEXCEPTION();
    return (transposed ? matrix->matrix[ind-1][row-1] : matrix->matrix[row-1][ind-1]);
}

template <unsigned int n, unsigned int m>
Math::Row<n, m>& Math::Row<n, m>::operator=(const Math::Row<n, m>& rhs){
    if(transposed == rhs.transposed && matrix==rhs.matrix)
        return *this;
    if(matrix==rhs.matrix && n!=m){
        throw Math::IncampatibleMatrixEXCEPTION();
    }
    else{
        for(unsigned int i{1}; i<=n; i++){
            this->operator[](i) = rhs.at(i);
        }
    }
    return *this;
}

template <unsigned int n, unsigned int m>
Math::Row<n, m> Math::Row<n, m>::operator*(const float& rhs) const{
    if(transposed){
        Math::Row<1, n> new_row{new Math::Matrix<1, n>{}, 1};

    }
}

template <unsigned int n, unsigned int m>
void Math::Row<n, m>::print(std::ostream& os)const{
    os << "[ ";
    const unsigned int row_{row-1};
    if(transposed){
        const unsigned int temp {n-1};
        for(unsigned int i{}; i<n; i++)
            os << matrix->matrix[i][row_] << ((i==temp)? " ]": ", ");
    }
    else{
        const unsigned int temp {m-1};
        for(unsigned int i{}; i<m; i++)
            os << matrix->matrix[row_][i] << ((i==temp) ? " ]": ", ");
    }
    return;
}



// ------------
// CLASS MATRIX

template <unsigned int n, unsigned int m>
Math::Matrix<n, m>::Matrix() :
    undef{false}, transposed{false}{
}

template <unsigned int n, unsigned int m>
Math::Matrix<n, m>::Matrix(const Matrix<n, m>& source) :
    undef{source.undef}, transposed{source.transposed}, rows{source.rows}, columns{source.columns}{
    if(!undef)
    for(unsigned int i{}; i<rows; i++){
        for(unsigned int j{}; j<columns; j++)
            matrix[i][j] = source.matrix[i][j];
    }
}

template <unsigned int n, unsigned int m>
Math::Matrix<n, m>::Matrix(Matrix<n, m>&& source) :
    undef{source.undef}, transposed{source.transposed}, rows{n}, columns{m}, matrix{std::move(source.matrix)}{
}

//todo: rectify. this is wrong implementation
template <unsigned int n, unsigned int m>
template <unsigned int a, unsigned int b>
Math::Matrix<n, m>::Matrix(const Row<a, b>& source) :
    undef{source.matrix->undef}, transposed{source.matrix->transposed}, rows{n}, columns{m}{
    if(transposed){
        // 
    }
    for(unsigned int i{}; i<n; i++)
        for(unsigned int j{}; j<m; j++)
            matrix[i][j] = source.at(i * n +j);
}

template <unsigned int n, unsigned int m>
Math::Matrix<n, m>::Matrix(Row<n, m>&& source) :
    undef{source.matrix->undef}, transposed{source.matrix->transposed}, rows{n}, columns{m},
    matrix{std::move(source.matrix->matrix)}{
}

template <unsigned int n, unsigned int m>
Math::Matrix<n, m>& Math::Matrix<n, m>::inplace_transpose(){
    transposed = !transposed;
    return *this;
}

template <unsigned int n, unsigned int m>
Math::Row<n, m> Math::Matrix<n, m>::operator[](const unsigned int& row){
    if (row == 0)
        throw Math::ZeroIndexEXCEPTION();
    else if (transposed ? row > columns : row > rows)
        throw Math::OutOfBoundsIndexEXCEPTION();
    return Row<n, m>{this, row};
}

template <unsigned int n, unsigned int m>
const Math::Row<n, m> Math::Matrix<n, m>::at(const unsigned int& row)const{
    if (row == 0)
        throw Math::ZeroIndexEXCEPTION();
    else if (transposed ? row > columns : row > rows)
        throw Math::OutOfBoundsIndexEXCEPTION();
    return Row<n, m>{(Matrix<n, m>*)this, row};
}

template <unsigned int n, unsigned int m>
void Math::Matrix<n, m>::print(std::ostream& os)const{
    os << "\n[ ";
    if(transposed){
        for(unsigned int i{1}; i<=columns; i++){
            this->at(i).print(os);
            os  << ((i == columns) ? " ]": ",\n  ");
        }
    }
    else{
        for(unsigned int i{1}; i<=rows; i++){
            this->at(i).print(os);
            os << ((i == rows) ? " ]": ",\n  ");
        }
    }
    return;
}




// int main(int argc, char** argv){
//     Math::Matrix<3u, 3u> R;
//     std::cout << R ;
// }