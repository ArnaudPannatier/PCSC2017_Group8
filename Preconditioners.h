//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// PCSC 2017
//

#include "Matrix.h"

#ifndef PROJECT_PRECONDITIONERS_H
#define PROJECT_PRECONDITIONERS_H

class Preconditioners {

public:

    /// @brief Gauss-Seidel preconditioning
    Matrix GaussSeidel(const Matrix & A);

    /// @brief Jacobi preconditioning
    Matrix Jacobi(const Matrix & A);

};

#endif //PROJECT_PRECONDITIONERS_H
