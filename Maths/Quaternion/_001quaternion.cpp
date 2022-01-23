#include "../Libraries/Quaternion.hpp"
#include <math.h>

int main()
{
    float temp{1 / sqrt(3)};
    Quaternion q1{0, temp, temp, temp};
    Quaternion q2{q1 * q1};
    std::cout << q1 << '\n'
              << q2 << '\n'
              << (q1 * q2) << '\n'
              << (q2 * q1) << '\n';
}