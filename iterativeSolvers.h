//
// Created by pcsc on 12/1/17.
//

#ifndef PROJECT_CG_H
#define PROJECT_CG_H

#include<iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

class iterativeSolvers {
public:

    // Constructor
    iterativeSolvers(const Matrix& A, const Matrix& B);

    // Solvers
    Matrix conjugateGradientDescent(Matrix& x_0, int iterations = 20, double tolerance = 1e-10);

protected:

    Matrix A;
    Matrix b;
};

#endif //PROJECT_CG_H
