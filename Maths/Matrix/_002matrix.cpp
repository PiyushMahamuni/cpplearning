#include "../Libraries/Matrix.cpp"

int main(int argc, char** argv){
    Math::Matrix w{3, 1};
    w[1] = 1;
    w[2] = 2;
    w[3] = 3;
    Math::Matrix Jofw{Math::Matrix::J(w)};
    std::cout << Jofw << "\n\n\n\n\n";
    return 0;
}