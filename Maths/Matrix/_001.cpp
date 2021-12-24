#include "../Libraries/Matrix.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    Math::Matrix R{3, 3};

    R[1][2] = -3;
    R[3][3] = R[2][1] = 1;
    std::cout << R << std::endl;
    std::cout << R.inplace_transpose() << std::endl;
    return 0;
}