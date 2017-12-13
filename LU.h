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

    /**
     * @param A_ Square matrix where each row represents a single observation
     * @param B_ Column vector
     * @param X_ Not required
     */
    LU(const Matrix &A_, const Vector &B_, const Vector &X_ = Vector()) : Solver(A_,B_,X_){ size = A.size().lines;}

    /// @brief computes the LU decomposition of A, then the solution to LUx = B
    Vector solve() final;

    /// @brief computes the LU decomposition of A
    void computeLU();

    /// @brief computes the solution to LUx = B
    void computeX();

    /// @brief Returns the lower triangular matrix
    Matrix getL();

    /// @brief Returns the upper triangular matrix
    Matrix getU();

protected:

    /// @brief Lower triangular matrix
    Matrix L;

    /// @brief Upper triangular matrix
    Matrix U;

    /// @brief Size of matrix A
    size_t size;
};

#endif //PROJECT_LU_H
