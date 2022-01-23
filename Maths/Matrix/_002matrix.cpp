#include "../Libraries/Matrix.hpp"

int main(int argc, char** argv){
    Matrix w{3, 1};
    w[1] = 1;
    w[2] = 2;
    w[3] = 3;
    Matrix Jofw{Matrix::J(w)};
    std::cout << Jofw << "\n\n\n\n\n";
    return 0;
}