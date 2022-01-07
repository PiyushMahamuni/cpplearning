#include "../Libraries/Matrix.cpp"
// checking if cross product and dot product functionalities are working properly
int main(){
    Math::Matrix a{3, 1};
    a[1] = 1;
    a[2] = -2;
    a[3] = 0.5;
    Math::Matrix b{a * 2};
    std::cout << "a.a = " << Math::Matrix::dot(a, a) << std::endl;
    std::cout << "axa = " << Math::Matrix::cross(a, a) << std::endl;
    std::cout << "bxa = " << Math::Matrix::cross(b, a) << std::endl;
    b[1] = 3;
    std::cout << "bxa = " << Math::Matrix::cross(b, a) << std::endl;
    std::cout << "axb = " << Math::Matrix::cross(a, b) << std::endl;
    return 0;
}