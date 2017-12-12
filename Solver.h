//
// Created by Arnaud Pannatier on 08.12.17.
//

#ifndef PROJECT_SOLVER_H
#define PROJECT_SOLVER_H

#include "Matrix.h"
#include "Vector.h"
#include <string>

/**
 * @brief Base class for linear solvers
 *
 */

class Solver {
public :

    /**
     * @param A_ Square matrix where each row represents a single observation
     * @param B_ Column vector
     *
     * Base class constructor for linear solvers. An exception will be raised if the number of rows in A_ do not match
     * the number of elements in B_
     *
     */
    Solver(const Matrix &A_, const Vector &B_, const Vector &X_ = Vector());

    /// Computes the solution to AX = B
    virtual Vector solve() = 0;

protected:

    /// Square matrix where each row represents a single observation
    Matrix A;

    /// Column vector
    Vector B;

    /// Solution to AX = B
    Vector X;
};

#endif //PROJECT_SOLVER_H
