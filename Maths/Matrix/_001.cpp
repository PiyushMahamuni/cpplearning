#include "../Libraries/Matrix.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    Math::Matrix R{3, 3};

    std::cout << R;
    std::cout << R.inplace_transpose();
    R[1][2] = -2;
    R[2][1] = 2;
    std::cout << R;
    Math::Matrix M{R[1][2]};
    std::cout << M << std::endl;
    Math::Matrix K{R.inplace_transpose() * 2};
    std::cout << K << std::endl;
    std::cout << K.inplace_transpose() << std::endl;

    std::cout << "\n\n\n###########################\n\n\n";
    Math::Matrix A {1, 3}, B{3, 1};
    A = R[1] + R[2];
    std::cout << A;
    A = A * 3;
    std::cout << A;
    std::cout << B;
    std::cout << "\n------\n\n";
    return 0;
}