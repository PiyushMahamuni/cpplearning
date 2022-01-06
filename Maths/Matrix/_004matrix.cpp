#include "../Libraries/Matrix.cpp"
#include <math.h>

int main(){
    Math::Matrix I{3, 3};
    Math::Matrix w{3, 1};
    w[1] = w[2] = w[3] = 1/sqrt(3);
    I[1][1] = I[2][2] = I [3][3] = 1;
    std::cout << I << std::endl;
    std::cout << w << std::endl;
    Math::Matrix J {Math::Matrix::J(w)};
    Math::Matrix R{ I + J * J * 2};
    std::cout << R << std::endl;
    return 0;
}