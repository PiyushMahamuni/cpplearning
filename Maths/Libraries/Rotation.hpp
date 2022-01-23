#ifndef _ROTATION_H_
#define _ROTATION_H_
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include <math.h>

const float pi{3.141592654};
Matrix matrixFromVector(const Matrix &vec);

Matrix matrixFromQuaternion(const Quaternion &q);

Matrix vectorFromQuaternion(const Quaternion &q);


// INCOMPLETE
Matrix vectorFromMatrix(const Matrix &mat);

Quaternion quaternionFromMatrix(const Matrix &mat);


// IMPLEMENTATIONS -

Matrix matrixFromVector(const Matrix& vec){
    if(vec.row2 - vec.row1 != 3 && vec.col2 - vec.col1 != 1)
        throw Matrix::Not3By1VectorEXCEPTION();
    float theta {vec.norm()};
    Matrix J { Matrix::J(vec / theta) };
    return Matrix {Matrix::I(3) + J * sin(theta) + (J * J) * (1 - cos(theta))};
}

Matrix matrixFromQuaternion(const Quaternion& q){
    return Matrix::I(3) * (q.scalar * q.scalar - Matrix::dot(q.vector, q.vector)) + Matrix::J(q.vector) * (2 * q.scalar) + q.vector.transpose() * q.vector * 2;
}

Matrix vectorFromQuaternion(const Quaternion& q){
    float sintb2 {q.vector.norm()};
    float theta {atan2(sintb2, q.scalar) * 2};
    return q.vector * (theta / sintb2);
}

Quaternion quaternionFromVector(const Matrix& vec){
    const float thetab2 {vec.norm()/2};
    return Quaternion{cos(thetab2), vec * sin(thetab2) / (2 * thetab2)};
}

// INCOMPLETE
// Matrix vectorFromMatrix(const Matrix& mat){
//     if(mat.col2 - mat.col1 != 3 || mat.col2 - mat.col1 != 3)
//         throw Matrix::NotRotationMatrixEXCEPTION();
//     if(mat.transpose() * mat != Matrix::I(3))
//         throw Matrix::NotRotationMatrixEXCEPTION();
//     float det{Matrix::dot(Matrix::cross((mat.at(2)).inplace_transpose(), (mat.at(3)).inplace_transpose()), (mat.at(1)).inplace_transpose())};
//     if( det > 1 + Matrix::thresh || det < 1 - Matrix::thresh)
//         throw Matrix::NotRotationMatrixEXCEPTION();
    
// }

#endif