#include "../Libraries/Matrix.cpp"
#include <iostream>

int main(int argc, char** argv){
    Math::Matrix<3u, 3u> R;
    R[1][2] = -1;
    R[2][1] = -2;
    std::cout << R ;
    std::cout << R.inplace_transpose();
    Math::Matrix<3u, 3u> M{R};
    M[2] = R[1];
    std::cout << M ;

    std::cout << "\n------\n\n";
    return 0;
}