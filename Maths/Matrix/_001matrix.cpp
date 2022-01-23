#include "../Libraries/Matrix.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Matrix R{3, 3};

    R[1][2] = -3;
    R[3][3] = R[2][1] = 1;
    std::cout << R << std::endl;
    R[3] += R[2] * 2 + R[1];
    Matrix V{3, 1};
    V = R[3].inplace_transpose();
    std::cout << R << std::endl;
    std::cout << V << std::endl;
    Matrix R2{R * V};
    std::cout << R2 << std::endl;
    std::cout << R.inplace_transpose() << std::endl;
    return 0;
}