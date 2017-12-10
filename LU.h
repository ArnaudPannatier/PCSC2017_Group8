//
// Created by Haziq on 12/1/17.
//

#ifndef PROJECT_LU_H
#define PROJECT_LU_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

/**
 * @brief LU decomposition
 *
 * This class implements the LU decomposition of a matrix based on Crout's algorithm that returns a lower triangular
 * matrix and a unit upper triangular matrix https://en.wikipedia.org/wiki/Crout_matrix_decomposition
 *
 * @code
 * LU LUSolvers(A, b);
 *
 * //Vector x = LUSolvers.solve();
 * //Matrix L = LUSolvers.getL();
 * //Matrix U = LUSolvers.getU();
 * @endcode
 *
 */

class LU : public Solver {
public:

    // Constructor
    using Solver::Solver;

    /// computes the LU decomposition of A, then the solution to LUx = B
    Vector solve() final;

    /// computes the LU decomposition of A
    void computeLU();

    /// computes the solution to LUx = B
    void computeX();

    Matrix getL();
    Matrix getU();

protected:

    Matrix L;
    Matrix U;
    size_t size;
};

#endif //PROJECT_LU_H
