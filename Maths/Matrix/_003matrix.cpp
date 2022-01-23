#include "../Libraries/Matrix.hpp"
#include <math.h>

// TESTING SKEW-SYMMETRIC MATRICES, NORM

int main(int argc, char **argv){
    Matrix w{3, 1};
    w[1] = 1;
    w[2] = 1;
    w[3] = 1;
    w = w / w.norm();
    Matrix Jofw1 {Matrix::J(w)};
    Matrix Jofw2 {Jofw1};

    for(unsigned int i{}; i<32; i++){
        std::cout << Jofw1 << "\n---------\n"
                  << (Jofw1 == Jofw2) << "\n---------\n";
        Jofw1 *= Jofw2;
    }
    std::cout << "\n\n\n\n -----------------\n\n\n";
    
    return 0;
}