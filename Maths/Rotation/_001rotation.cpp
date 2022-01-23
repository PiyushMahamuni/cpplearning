#include "../Libraries/Rotation.hpp"

int main(){
    float theta {-2 * pi / 3}; // 120 degrees
    Matrix vec {3, 1};
    vec[1] = vec[2] = vec[3] = theta/sqrt(3);
    Matrix R {matrixFromVector(vec)};
    Matrix I {Matrix::I(3)};
    std::cout << vec << '\n'
              << R * vec << '\n'
              << R * I << '\n'
              << R * R.transpose() << '\n';
    return 0;
}