//
// Created by Haziq on 12/1/17.
//

#ifndef PROJECT_CG_H
#define PROJECT_CG_H

#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"

using namespace std;

/**
 * @brief Abstract class for several iterative methods
 *
 */

class IterativeSolvers: public Solver  {
public:

    /**
     * @param A_ Square matrix where each row represents a single observation
     * @param B_ Column vector
     * @param X_ Initial guess to the solution
     * @param eps_ Stopping criteria i.e. the algorithm terminates if the norm of the error is below eps_
     * @param max_iter_ Maximum number of iterations
     *
     */
    IterativeSolvers(const Matrix& A_, const Vector& B_, const Vector& X_ = Vector(), double eps_ = 1e-6, size_t max_iter_ = 10000) : Solver(A_,B_, X_) {
        eps = eps_;
        error = 0.0;
        max_iter = max_iter_;
    };


    /**
     * This method computes the solution to AX = B. It repeatedly calls step()
     */

    Vector solve() final;


    virtual void step() = 0;

protected:

    double eps;
    double error;
    size_t max_iter;
};

#endif //PROJECT_CG_H