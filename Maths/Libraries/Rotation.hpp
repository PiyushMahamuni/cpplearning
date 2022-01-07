#ifndef _ROTATION_H_
#define _ROTATION_H_
#include "Matrix.cpp"
#include "Quaternion.cpp"
#include <math.h>

const float pi {3.141592654};
Matrix matrixFromVector(const Matrix& vec);

Matrix matrixFromQuaternion(const Quaternion& q);

Matrix vectorFromQuaternion(const Quaternion& q);

// INCOMPLETE
Matrix vectorFromMatrix(const Matrix& mat);
#endif