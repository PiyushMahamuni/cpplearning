#include "../Libraries/Matrix.hpp"
// checking if cross product and dot product functionalities are working properly
int main(){
    Matrix a{3, 1};
    a[1] = 1;
    a[2] = -2;
    a[3] = 0.5;
    Matrix b{a * 2};
    std::cout << "a.a = " << Matrix::dot(a, a) << std::endl;
    std::cout << "axa = " << Matrix::cross(a, a) << std::endl;
    std::cout << "bxa = " << Matrix::cross(b, a) << std::endl;
    b[1] = 3;
    std::cout << "bxa = " << Matrix::cross(b, a) << std::endl;
    std::cout << "axb = " << Matrix::cross(a, b) << std::endl;
    return 0;
}