#include "../Libraries/Matrix.cpp"
#include <math.h>

// TESTING SKEW-SYMMETRIC MATRICES, NORM

int main(int argc, char **argv){
    Math::Matrix w{3, 1};
    w[1] = 2;
    w[2] = 2;
    w[3] = 3;
    w = w / w.norm();
    Math::Matrix Jofw1 {Math::Matrix::J(w)};
    Math::Matrix Jofw2 {Jofw1};

    for(unsigned int i{}; i<8; i++){
        std::cout << Jofw1 << "\n---------\n"
                  << (Jofw1 == Jofw2) << "\n---------\n";
        Jofw1 *= Jofw2;
    }
    std::cout << "\n\n\n\n -----------------\n\n\n";
    
    return 0;
}