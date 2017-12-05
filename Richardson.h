//
// Created by Arnaud Pannatier on 05.12.17.
//

#ifndef PROJECT_RICHARDSON_H
#define PROJECT_RICHARDSON_H

#include "Matrix.h"

class Richardson {
public:
    // TODO : remove as it will be inherited.
    Richardson(const Matrix& nA, const Matrix& nB, double omega_);

    Matrix solve();
    void step();

    //TODO : compute omega with the condition number \omega_opt = 2/(\lambda_min(A) +\lambda_max(A))


protected:
    Matrix A;
    Matrix B;
    Matrix X;

    double eps = 1e-12;
    double error = 0.0;
    size_t max_iter = 100000;
    double omega;
};


#endif //PROJECT_RICHARDSON_H
