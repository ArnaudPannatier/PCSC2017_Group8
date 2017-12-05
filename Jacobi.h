//
// Created by Arnaud Pannatier on 04.12.17.
//

#ifndef PROJECT_JACOBI_H
#define PROJECT_JACOBI_H

#include "Matrix.h"
#include "Vector.h"

// TODO : inherit of Iterative Solver
// TODO : TESTS
class Jacobi {
public:
    // TODO : remove as it will be inherited.
    Jacobi(const Matrix& nA, const Vector& nB);

    Matrix solve();
    void step();

    //TODO : verify that A is a diagonally dominant matrix

protected:
    Matrix A;
    Vector B;
    Vector X;

    double eps = 1e-12;
    double error = 0.0;
};


#endif //PROJECT_JACOBI_H
