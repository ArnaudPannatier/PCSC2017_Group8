//
// Created by pcsc on 12/1/17.
//

#ifndef PROJECT_LU_H
#define PROJECT_LU_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

class LU {
public:

    // Constructor
    LU(const Matrix& A, const Matrix& b);

    /** \brief Conjugate Gradient Descent
     * \param x_0 initial guess for the solution
     * \param iterations maximum number of iterations
     * \param tolerance convergence test
     * \return solution to the problem Ax = b
     *
     * This method implements Crout's algorithm for factorizing a matrix A as the product of a lower triangular matrix
     * and a unit upper triangular matrix. https://en.wikipedia.org/wiki/LU_decomposition
     */

    void solve();

    Matrix getL();
    Matrix getU();
    Matrix getX();

protected:

    Matrix A;
    Matrix b;
    Matrix L;
    Matrix U;

    int size = 0;
};

#endif //PROJECT_LU_H
