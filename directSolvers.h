//
// Created by pcsc on 12/1/17.
//

#ifndef PROJECT_LU_H
#define PROJECT_LU_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

class directSolvers {
public:

    // Constructor
    directSolvers(const Matrix& A, const Matrix& b);

    void LU();

    Matrix getL();
    Matrix getU();
    Matrix getX();

protected:

    Matrix A;
    Matrix b;
    Matrix L;
    Matrix U;
};

#endif //PROJECT_LU_H
